# Hardware

⚠️ **Status:** Active development. PCB currently in bring-up and testing.

KiCad project for the Pixel Pet custom PCB, an ESP32-S3-based board with display, IMU, charging circuit, and user I/O.

## Opening the project

Requires [KiCad](https://www.kicad.org/) (developed in v8). Multiple custom part libraries are used, see  `/libraries`.
## Key design notes

- ESP32-S3-WROOM-1 module, 4-layer board
- BQ24079 LiPo charger with power path management
- BMI323 IMU (SPI), ST7789 TFT display
- Targeting JLCPCB fabrication + SMT assembly, with select hand-soldered THT parts

## Gerbers / BOM freshness

Files in `/gerbers` and `bom.csv` are re-exported directly from the current `.kicad_pcb`/`.kicad_sch` — if you're building from this repo, always pull these rather than any older exports that may exist elsewhere in project history.
