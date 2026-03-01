# VectoraCNC

VectoraCNC is a custom-designed desktop CNC machine that I built from scratch.  
It’s mainly made from 2020 and 2040 aluminum extrusions, linear rails, and NEMA 17 stepper motors.

The goal was simple: build a compact, rigid CNC that actually works well, without spending $1000+.

Total build cost: **~$400**

This project is focused on affordability, reliability, and being a solid base for future upgrades and mods.


## Why I Built This

I wanted a rigid desktop CNC to machine harder materials like aluminum, but most affordable machines use V-wheels instead of linear rails.
So I designed VectoraCNC to use **linear rails on all axes**, while still keeping the total cost around $400.

This is my attempt at building something serious, but still accessible for makers and students like me.


## Images

![main](media/main.png)

<details>

<summary>CAD - click to expand</summary>

![VectoraCNC CAD](https://blueprint.hackclub.com/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MTY0NDQsInB1ciI6ImJsb2JfaWQifX0=--b54ad720b085556fa216977bb398562e727d52ac/image.png)

</details>


## Features

- 230 × 160 × 80 mm Work Area  
- Rigid frame built with 2020 and 2040 aluminum extrusions  
- Linear rails on all axes for improved precision  
- NEMA 17 stepper motors with TMC2209 drivers  
- 15180 aluminum plate base  
- 500W spindle capable of cutting wood, plastics, and light aluminum  


## BOM (Bill of Materials)

Full parts list available here:
[ONLINE GOOGLE SHEETS](https://docs.google.com/spreadsheets/d/13GKgM2DIBkM6Ly_OZJB4GLy0vwwSqJ-mRrfgNgf3ems/edit?gid=1271841831#gid=1271841831)


## Design Specifications

- **Build Volume**: 230 × 160 × 80 mm  
- **Bed Type**: 15180 300 mm T-Slot Aluminum Plate  
- **Spindle**: 500W ER11 Collet Spindle  
- **Stepper Motors**: NEMA 17 with TMC2209 Drivers  
- **Motion System**: Linear rail guided on all axes  
- **Control Board**: BIGTREETECH SKR V1.4  
- **Firmware**: Marlin (CNC mode)


## Wiring Diagram

![Wiring Diagram](media/wiring.png)


## Future Improvements

- Enclosure  
- Proper cable management  
- Stronger spindle  

This project is still evolving.


## License

This work is licensed under a
[Creative Commons Attribution-NonCommercial 4.0 International License][cc-by-nc].

[![CC BY-NC 4.0][cc-by-nc-image]][cc-by-nc]

[cc-by-nc]: https://creativecommons.org/licenses/by-nc/4.0/
[cc-by-nc-image]: https://licensebuttons.net/l/by-nc/4.0/88x31.png
[cc-by-nc-shield]: https://img.shields.io/badge/License-CC%20BY--NC%204.0-lightgrey.svg
