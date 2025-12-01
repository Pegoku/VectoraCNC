# VectoraCNC

VectoraCNC is a custom-designed desktop CNC machine. Built using mainly 2020 and 2040 aluminum extrusions, linear rails, and NEMA 17 stepper motors, this CNC aims to deliver reliable performance in a compact design while maintaining a budget build cost of approximately $390 (Including discount codes).
Simple Desktop CNC

This design aims to deliver a reliable CNC machine for makers, foccused on affordability, while being a future-proof platform for upgrades and modifications.

## Images

![VectoraCNC CAD](https://blueprint.hackclub.com/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MTY0NDQsInB1ciI6ImJsb2JfaWQifX0=--b54ad720b085556fa216977bb398562e727d52ac/image.png)

<details>
<summary>Build — click to expand</summary>

TBD

<!-- ![VectoraCNC CAD Model](placeholder-cad-model.png) -->

</details>

## Features

- 300 x 180 x 90 mm Work Area
- Rigid Frame with 2020 and 2040 Aluminum Extrusions
- Linear Rail Motion System for Precision
- NEMA 17 Stepper Motors with Microstepping Drivers
- 15 Series T-Slot Aluminum Base

## BOM (Bill of Materials)

[ONLINE GOOGLE SHEETS](https://docs.google.com/spreadsheets/d/13GKgM2DIBkM6Ly_OZJB4GLy0vwwSqJ-mRrfgNgf3ems/edit?gid=1271841831#gid=1271841831)

| Item                  | Qtty needed | Qtty / Pack | Pack Qtty | Price / pack | Source                                                | Extra           | Category    | Item Total | Final Total | Final Total ($) |
| --------------------- | ----------- | ----------- | --------- | ------------ | ----------------------------------------------------- | --------------- | ----------- | ---------- | ----------- | --------------- |
| Stepper Motor Nema 17 | 3           | 1           | 3         | 7.69€        | https://www.aliexpress.com/item/1005008459399126.html |                 | Motor       | 23.07€     | 329.95€     | $383.22         |
| USB B cable           | 0           | 1           | 0         | 1.65€        | https://es.aliexpress.com/item/32700175631.html       |                 | Electronics | 0.00€      |             |                 |
| MainBoard             | 1           | 1           | 1         | 38.79€       | https://es.aliexpress.com/item/1005006046426892.html  | With TMC2209x5  | Electronics | 38.79€     |             |                 |
| 15180 extrusion       | 1           | 1           | 1         | 20.99€       | https://www.aliexpress.com/item/1005007601829278.html | 300 mm          | Bed         | 20.99€     |             |                 |
| Orange Pi zero        | 0           | 1           | 0         | 21.11€       | https://es.aliexpress.com/item/1005005785695181.html  |                 | Electronics | 0.00€      |             |                 |
| Spindle 500W          | 1           | 1           | 1         | 77.69€       | https://es.aliexpress.com/item/1005008660257525.html  |                 | Spindle     | 77.69€     |             |                 |
| Endstops              | 3           | 10          | 1         | 2.03€        | https://es.aliexpress.com/item/32273125391.html       |                 | Electronics | 2.03€      |             |                 |
| 2020 extrusion        | 4           | 4           | 1         | 16.49€       | https://es.aliexpress.com/item/1005001598712011.html  | 350 mm          | Structure   | 16.49€     |             |                 |
| 2040 extrusion        | 2           | 1           | 2         | 6.89€        | https://es.aliexpress.com/item/1005002652962344.html  | 350 mm          | Structure   | 13.78€     |             |                 |
| 2040 extrusion        | 2           | 1           | 2         | 5.59€        | https://es.aliexpress.com/item/1005002652962344.html  | 250 mm          | Structure   | 11.18€     |             |                 |
| 2080 extrusion        | 1           | 1           | 1         | 12.99€       | https://es.aliexpress.com/item/1005002652962344.html  | 350 mm          | Structure   | 12.99€     |             |                 |
| 2080 extrusion        | 1           | 1           | 1         | 6.59€        | https://es.aliexpress.com/item/1005002652962344.html  | 150 mm          | Structure   | 6.59€      |             |                 |
| Lead Screw T8         | 1           | 1           | 1         | 2.55€        | https://www.aliexpress.com/item/1005009554037590.html | 150 mm          | Linear      | 2.55€      |             |                 |
| Lead Screw T8         | 2           | 1           | 2         | 4.49€        | https://www.aliexpress.com/item/1005009554037590.html | 350 mm          | Linear      | 8.98€      |             |                 |
| Linear Rail MGN15H    | 4           | 1           | 4         | 12.39€       | https://es.aliexpress.com/item/1000007480470.html     | 350 mm          | Linear      | 49.56€     |             |                 |
| Linear Rail MGN15H    | 2           | 1           | 2         | 7.39€        | https://es.aliexpress.com/item/1000007480470.html     | 150 mm          | Linear      | 14.78€     |             |                 |
| MGN15C block          | 2           | 1           | 2         | 5.79€        | https://es.aliexpress.com/item/1000007480470.html     |                 | Linear      | 11.58€     |             |                 |
| 5x8 coupling          | 3           | 3           | 1         | 3.59€        | https://es.aliexpress.com/item/1005006305848755.html  |                 | Motor       | 3.59€      |             |                 |
| PWM to 0-10V          | 1           | 1           | 1         | 2.92€        | https://es.aliexpress.com/item/1005006246628087.html  |                 | Electronics | 2.92€      |             |                 |
| LRS-200-24            | 1           | 1           | 1         | 30.99€       | https://es.aliexpress.com/item/1005008946405294.html  |                 | Electronics | 30.99€     |             |                 |
| M3 screw              | 6           | 10          | 1         | 0.53€        | https://www.aliexpress.com/item/1005003189489793.html | 8 mm, ISO4762   | screws      | 0.53€      |             |                 |
| M3 screw              | 44          | 50          | 1         | 1.41€        | https://www.aliexpress.com/item/1005005832721555.html | 10 mm, ISO4762  | screws      | 1.41€      |             |                 |
| M3 screw              | 7           | 10          | 1         | 0.57€        | https://www.aliexpress.com/item/1005003189489793.html | 12 mm, ISO4762  | screws      | 0.57€      |             |                 |
| M3 screw              | 8           | 50          | 1         | 1.72€        | https://www.aliexpress.com/item/1005004029818219.html | 14 mm, ISO10642 | screws      | 1.72€      |             |                 |
| M3 screw              | 8           | 10          | 1         | 0.62€        | https://www.aliexpress.com/item/1005003189489793.html | 16 mm, ISO4762  | screws      | 0.62€      |             |                 |
| M3 screw              | 16          | 50          | 1         | 2.06€        | https://www.aliexpress.com/item/1005004029818219.html | 18 mm, ISO10642 | screws      | 2.06€      |             |                 |
| M3 screw              | 2           | 10          | 1         | 0.99€        | https://www.aliexpress.com/item/1005003189489793.html | 28 mm, ISO4762  | screws      | 0.99€      |             |                 |
| M3 screw              | 4           | 10          | 1         | 1.41€        | https://www.aliexpress.com/item/1005003189489793.html | 38 mm, ISO4762  | screws      | 1.41€      |             |                 |
| M5 screw              | 40          | 50          | 1         | 3.09€        | https://www.aliexpress.com/item/1005008380620769.html | 8 mm, ISO7380   | screws      | 3.09€      |             |                 |
| M5 screw              | 2           | 10          | 1         | 1.08€        | https://www.aliexpress.com/item/1005003189489793.html | 12 mm, ISO4762  | screws      | 1.08€      |             |                 |
| M6 screw              | 20          | 10          | 2         | 2.05€        | https://www.aliexpress.com/item/1005003189489793.html | 25 mm, ISO4762  | screws      | 4.10€      |             |                 |
| M3 T-Nut              | 90          | 100         | 1         | 4.39€        | https://www.aliexpress.com/item/1005007383347166.html | 2020-M3-50PCS   | screws      | 4.39€      |             |                 |
| M5 T-Nut              | 42          | 50          | 1         | 2.99€        | https://www.aliexpress.com/item/1005007383347166.html | 2020-M5-50PCS   | screws      | 2.99€      |             |                 |
| Corner Bracket        | 4           | 20          | 1         | 3.36€        | https://www.aliexpress.com/item/1005007540068610.html | 2020            | Structure   | 0          |             |                 |
| Shipping              | 1           | 1           | 1         | 0.71€        |                                                       |                 |             | 0.71€      |             |                 |
| Discount code         | 1           | 1           | 1         | -44.27€      |                                                       | IFPUQ5QW        |             | -44.27€    |             |                 |

**Estimated Total Cost**: 329.95€ ($383.22)

## Design Specifications

- **Build Volume**: 300 x 180 x 90 mm
- **Bed Type**: 15180 x 300mm Aluminum Extrusion
- **Spindle**: 500W ER11 Collet Spindle
- **Stepper Motors**: NEMA 17 with TMC2209 Drivers
- **Motion System**: Linear rail guided on all axes
- **Control Board**: BIGTREETECH SKR V1.4
- **Firmware**: Marlin CNC Firmware

## License

This work is licensed under a
[Creative Commons Attribution-NonCommercial 4.0 International License][cc-by-nc].

[![CC BY-NC 4.0][cc-by-nc-image]][cc-by-nc]

[cc-by-nc]: https://creativecommons.org/licenses/by-nc/4.0/
[cc-by-nc-image]: https://licensebuttons.net/l/by-nc/4.0/88x31.png
[cc-by-nc-shield]: https://img.shields.io/badge/License-CC%20BY--NC%204.0-lightgrey.svg
