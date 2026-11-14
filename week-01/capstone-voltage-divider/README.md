# Capstone 01 — Voltage Divider Design & Fault Diagnosis

**Course:** Mechatronics Preparatory Course  
**Week:** 01 — Friday  
**Date:** November 13, 2026  
**Student:** Jack Gagnon

## 1. Project Overview

This project investigates the behavior of unloaded and loaded DC voltage dividers.

Using an Arduino Uno as a low-voltage DC source, a resistor network is constructed to produce a predictable output voltage.

A third resistor is introduced as an electrical load to investigate how additional current demand changes circuit behavior.

The experiment combines theoretical calculations, physical measurements, Kirchhoff's laws, power conservation, and systematic fault diagnosis.

## 2. Why This Project Matters

Voltage dividers appear in electronic measurement systems, sensor interfaces, and control circuits.

Understanding how electrical loading affects their output is essential when designing reliable mechatronic systems.

This project demonstrates the importance of calculating expected circuit behavior before applying power and using measured evidence to identify unexpected results.

## 3. Learning Objectives

1. Derive the unloaded voltage-divider equation.
2. Calculate equivalent resistance and circuit current.
3. Predict output voltage before connecting power.
4. Determine how a parallel load changes the output voltage.
5. Verify Ohm's law, KCL, and KVL experimentally.
6. Calculate resistor power dissipation.
7. Diagnose discrepancies between theoretical and measured values.
8. Document results in a professional engineering portfolio.

## 4. Equipment

- Arduino Uno
- USB power cable
- ELEGOO breadboard
- Jumper wires
- Commercial Electric DMM-8301S multimeter
- Alligator clip adapters
- Three resistors:
  - R1: 220 Ω nominal
  - R2: 330 Ω nominal
  - R3: 1 kΩ nominal

Previously measured resistor values:

| Component | Measured resistance |
|---|---:|
| R1 | 217.6 Ω |
| R2 | 328 Ω |
| R3 | 992 Ω |

These values will be reverified before construction.

## 5. Circuit Description

### Configuration A — Unloaded Voltage Divider

R1 and R2 are connected in series between Arduino 5V and GND.

The output voltage is measured across R2, relative to ground.

### Configuration B — Loaded Voltage Divider

R3 is connected in parallel with R2.

The additional load changes the equivalent resistance of the lower branch, affecting total current, voltage distribution, and power dissipation.

Both circuit configurations will be analyzed mathematically before applying power.

## 6. Experimental Procedure

1. Measure the actual resistance of each component.
2. Calculate unloaded circuit predictions.
3. Calculate loaded circuit predictions.
4. Draw and save the circuit schematic.
5. Assemble the unloaded divider with power disconnected.
6. Perform a pre-power safety inspection.
7. Measure unloaded circuit voltages.
8. Disconnect power and connect R3.
9. Measure loaded circuit voltages and currents.
10. Verify KCL, KVL, and power conservation.
11. Investigate an observed circuit discrepancy.
12. Document the results and record a video demonstration.

## 7. Results

Pending physical measurements.

Detailed predictions will be recorded in `predictions.md`.

Experimental measurements and percentage differences will be recorded in `measurements.md`.

## 8. Troubleshooting

A controlled fault-diagnosis exercise will investigate an unexpected circuit measurement.

The troubleshooting log will document:

- Observed behavior
- Expected behavior
- Initial hypothesis
- Diagnostic measurements
- Corrective action
- Final verification

See `troubleshooting.md`.

## 9. Demonstration

A narrated video will demonstrate:

- Physical circuit construction
- Unloaded output-voltage measurement
- Loaded output-voltage measurement
- Explanation of circuit loading
- Fault-diagnosis procedure
- Final engineering conclusions

Video evidence will be saved in the `demo/` directory.

## 10. Safety

This experiment uses low-voltage DC.

- Disconnect USB power before modifying wiring.
- Calculate expected current and resistor power before energizing.
- Verify resistor power ratings.
- Measure voltage with the multimeter in parallel.
- Measure current with the multimeter in series.
- Never connect a current-configured meter directly across supply rails.
- Keep unrelated motor-control circuitry isolated and unpowered.

Detailed precautions will be documented in `safety.md`.

## 11. Project Status

- [ ] README saved
- [ ] Schematic image committed
- [ ] Physical build photograph
- [ ] Commented Arduino sketch with pin map
- [ ] Pre-power predictions saved
- [ ] Measured vs. predicted comparison completed
- [ ] Troubleshooting log completed
- [ ] Video demonstration recorded and documented
- [ ] Safety documentation completed

**Project completion:** Pending experimental verification and GitHub publication.