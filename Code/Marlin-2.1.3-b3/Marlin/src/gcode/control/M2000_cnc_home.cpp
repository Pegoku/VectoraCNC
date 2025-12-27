/*
 * M2000 - CNC Homing with Tool Length Probing
 *
 * Sequence:
 *   1. Stop spindle
 *   2. Home X then Y
 *   3. Raise Z, move to tool setter
 *   4. Probe Z without tool (reference)
 *   5. Raise Z, move aside for tool change
 *   6. Wait for user to insert tool
 *   7. Return to setter, probe again
 *   8. Calculate and report tool length
 *
 * Usage: M2000 [X<pos>] [Y<pos>] [F<feedrate>] [S<probe_feedrate>]
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

#ifndef CNC_TOOL_SETTER_X_OFFSET
  #define CNC_TOOL_SETTER_X_OFFSET -5
#endif
#ifndef CNC_TOOL_SETTER_Y_OFFSET
  #define CNC_TOOL_SETTER_Y_OFFSET 15
#endif
#ifndef CNC_Z_CLEARANCE
  #define CNC_Z_CLEARANCE 10
#endif
#ifndef CNC_PROBE_FEEDRATE
  #define CNC_PROBE_FEEDRATE 300
#endif
#ifndef CNC_TRAVEL_FEEDRATE
  #define CNC_TRAVEL_FEEDRATE 3000
#endif
#ifndef CNC_TOOL_CHANGE_X_OFFSET
  #define CNC_TOOL_CHANGE_X_OFFSET -50
#endif
#ifndef CNC_TOOL_CHANGE_Y_OFFSET
  #define CNC_TOOL_CHANGE_Y_OFFSET -30
#endif

void GcodeSuite::M2000() {
  const float tool_x = parser.floatval('X', X_MAX_POS + CNC_TOOL_SETTER_X_OFFSET);
  const float tool_y = parser.floatval('Y', Y_MAX_POS + CNC_TOOL_SETTER_Y_OFFSET);
  const feedRate_t travel_fr = parser.floatval('F', CNC_TRAVEL_FEEDRATE);
  const feedRate_t probe_fr = parser.floatval('S', CNC_PROBE_FEEDRATE);

  const float change_x = tool_x + CNC_TOOL_CHANGE_X_OFFSET;
  const float change_y = tool_y + CNC_TOOL_CHANGE_Y_OFFSET;

  SERIAL_ECHOLNPGM("M2000 CNC Homing Start");

  // Stop spindle
  #if HAS_CUTTER
    cutter.set_enabled(false);
    planner.synchronize();
    safe_delay(500);
  #endif

  // Home X and Y
  SERIAL_ECHOLNPGM("Homing XY");
  homeaxis(X_AXIS);
  planner.synchronize();
  homeaxis(Y_AXIS);
  planner.synchronize();

  // Raise Z
  SERIAL_ECHOLNPGM("Raising Z");
  current_position.z += CNC_Z_CLEARANCE;
  line_to_current_position(travel_fr);
  planner.synchronize();

  // Move to tool setter
  SERIAL_ECHOLNPGM("Moving to tool setter");
  do_blocking_move_to_xy(tool_x, tool_y, travel_fr);
  planner.synchronize();

  // First probe: reference (no tool)
  SERIAL_ECHOLNPGM("Probing reference height");
  endstops.enable(true);
  current_position.z = Z_MIN_POS;
  line_to_current_position(probe_fr);
  planner.synchronize();

  const float z_reference = current_position.z;
  SERIAL_ECHOPGM("Reference Z: ");
  SERIAL_ECHOLN(z_reference);

  // Raise and move to tool change position
  SERIAL_ECHOLNPGM("Moving to tool change position");
  current_position.z += CNC_Z_CLEARANCE * 3;
  line_to_current_position(travel_fr);
  planner.synchronize();

  do_blocking_move_to_xy(change_x, change_y, travel_fr);
  planner.synchronize();

  // Wait for user
  SERIAL_ECHOLNPGM("Insert tool then send M108");
  wait_for_user_response();

  // Return to tool setter
  SERIAL_ECHOLNPGM("Returning to tool setter");
  do_blocking_move_to_xy(tool_x, tool_y, travel_fr);
  planner.synchronize();

  // Second probe: with tool
  SERIAL_ECHOLNPGM("Probing tool length");
  current_position.z = Z_MIN_POS;
  line_to_current_position(probe_fr);
  planner.synchronize();

  const float z_with_tool = current_position.z;
  const float tool_length = z_with_tool - z_reference;

  SERIAL_ECHOPGM("Tool Z: ");
  SERIAL_ECHOLN(z_with_tool);
  SERIAL_ECHOPGM("Tool length: ");
  SERIAL_ECHOLN(tool_length);

  // Lift off probe
  current_position.z += 5.0f;
  line_to_current_position(probe_fr);
  planner.synchronize();

  SERIAL_ECHOLNPGM("M2000 Complete");
  SERIAL_ECHOPGM("Pos X:");
  SERIAL_ECHO(current_position.x);
  SERIAL_ECHOPGM(" Y:");
  SERIAL_ECHO(current_position.y);
  SERIAL_ECHOPGM(" Z:");
  SERIAL_ECHOLN(current_position.z);
}

#endif
