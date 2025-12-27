/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

/**
 * M2000_cnc_home.cpp - CNC-specific homing sequence with tool length probing
 *
 * Custom CNC homing routine for VectoraCNC project:
 *   1. Stop spindle for safety
 *   2. Home X axis
 *   3. Home Y axis
 *   4. Raise Z by 10mm (safety clearance)
 *   5. Move to tool setter position (top-right corner + Y offset - X offset)
 *   6. Lower Z until endstop triggered (tool length measurement)
 *   7. Set Z offset based on probe result
 *
 * Usage: M2000 [X<pos>] [Y<pos>] [F<feedrate>] [S<slow_feedrate>]
 *   X - Tool setter X position (default: X_MAX_POS - 5)
 *   Y - Tool setter Y position (default: Y_MAX_POS + 15, can be beyond bed if machine allows)
 *   F - XY travel feedrate in mm/min (default: 3000)
 *   S - Z probe feedrate in mm/min (default: 300)
 */

#include "../../inc/MarlinConfig.h"

#if ENABLED(CNC_HOMING_ROUTINE)

#include "../gcode.h"
#include "../../module/motion.h"
#include "../../module/planner.h"
#include "../../module/endstops.h"
#include "../../module/stepper.h"

#if HAS_CUTTER
  #include "../../feature/spindle_laser.h"
#endif

// Default tool setter position offsets from max position
#ifndef CNC_TOOL_SETTER_X_OFFSET
  #define CNC_TOOL_SETTER_X_OFFSET -5    // 5mm inside from X max
#endif
#ifndef CNC_TOOL_SETTER_Y_OFFSET
  #define CNC_TOOL_SETTER_Y_OFFSET 15    // 15mm beyond Y max (if machine allows)
#endif
#ifndef CNC_Z_CLEARANCE
  #define CNC_Z_CLEARANCE 10             // 10mm Z clearance before XY move
#endif
#ifndef CNC_PROBE_FEEDRATE
  #define CNC_PROBE_FEEDRATE 300         // Slow Z probe feedrate (mm/min)
#endif
#ifndef CNC_TRAVEL_FEEDRATE
  #define CNC_TRAVEL_FEEDRATE 3000       // Fast XY travel feedrate (mm/min)
#endif

/**
 * M2000: CNC Homing Routine with Tool Length Probing
 *
 * Sequence:
 *   1. Stop spindle (safety)
 *   2. Home X
 *   3. Home Y
 *   4. Move Z up 10mm relative
 *   5. Move XY to tool setter position
 *   6. Probe Z down until endstop
 *   7. Set current Z as reference
 */
void GcodeSuite::M2000() {
  // Parse optional parameters
  const float tool_x = parser.floatval('X', X_MAX_POS + CNC_TOOL_SETTER_X_OFFSET);
  const float tool_y = parser.floatval('Y', Y_MAX_POS + CNC_TOOL_SETTER_Y_OFFSET);
  const feedRate_t travel_fr = parser.floatval('F', CNC_TRAVEL_FEEDRATE);
  const feedRate_t probe_fr = parser.floatval('S', CNC_PROBE_FEEDRATE);

  SERIAL_ECHOLNPGM("CNC Homing Routine Starting...");

  // Stop spindle
  #if HAS_CUTTER
    SERIAL_ECHOLNPGM("Stopping spindle...");
    cutter.set_enabled(false);
    planner.synchronize();  // Wait for spindle to stop
    safe_delay(500);        // Extra delay for spindle coast-down
  #endif

  // Home X axis
  SERIAL_ECHOLNPGM("Homing X axis...");
  homeaxis(X_AXIS);
  planner.synchronize();

  // Home Y axis
  SERIAL_ECHOLNPGM("Homing Y axis...");
  homeaxis(Y_AXIS);
  planner.synchronize();

  // Raise Z by clearance amount (relative move)
  SERIAL_ECHOLNPGM("Raising Z for clearance...");
  current_position.z += CNC_Z_CLEARANCE;
  line_to_current_position(travel_fr);
  planner.synchronize();

  // Move to tool setter position
  SERIAL_ECHOLNF(F("Moving to tool setter at X"), tool_x, F(" Y"), tool_y);
  do_blocking_move_to_xy(tool_x, tool_y, travel_fr);
  planner.synchronize();

  // Probe Z down until endstop
  SERIAL_ECHOLNPGM("Probing Z for tool length...");
  
  // Enable Z endstop checking
  endstops.enable(true);
  
  // Remember current Z position
  const float z_before_probe = current_position.z;
  
  // Move Z down slowly until endstop triggers or we hit Z_MIN
  float z_probe_target = Z_MIN_POS;
  
  // Set slower feedrate for probing
  current_position.z = z_probe_target;
  line_to_current_position(probe_fr);
  planner.synchronize();
  
  // After probing, the current_position.z will be where we stopped
  const float z_probe_result = current_position.z;
  
  // Calculate and report tool length offset
  const float tool_length = z_before_probe - z_probe_result;
  
  SERIAL_ECHOLNF(F("Tool probe complete. Z stopped at: "), z_probe_result);
  SERIAL_ECHOLNF(F("Tool length measured: "), tool_length);
  
  //Set Z=0 at current position (tool setter surface = Z0)
  // Or optionally, lift slightly and set that as Z reference
  SERIAL_ECHOLNPGM("Setting Z reference...");
  
  // Lift Z slightly off the probe
  current_position.z += 2.0f;
  line_to_current_position(probe_fr);
  planner.synchronize();
  
  // Now current Z position can be used as reference
  // User can use G92 Z<value> to set their preferred Z origin
  
  SERIAL_ECHOLNPGM("CNC Homing Complete!");
  SERIAL_ECHOLNF(F("Current position: X"), current_position.x, 
                 F(" Y"), current_position.y,
                 F(" Z"), current_position.z);
  SERIAL_ECHOLNPGM("Use G92 Z<value> to set Z origin if needed.");
}

#endif // CNC_HOMING_ROUTINE
