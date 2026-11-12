
# Lab 02 — Demonstration Evidence

**Course:** Mechatronics Preparatory Course  
**Week:** 01 — Thursday  
**Date:** November 12, 2026

## Purpose

Document the physical construction and electrical verification
of a mixed series-parallel resistor network.

## Circuit

- R1 = 217.6 ohms
- R2 = 328 ohms
- R3 = 992 ohms
- Configuration: R1 + (R2 || R3)
- Source: Arduino Uno 5V and GND

## Verified Measurements

| Quantity | Measured |
|---|---:|
| Equivalent resistance | 465 ohms |
| Arduino supply voltage | 4.460 V |
| Breadboard input voltage | 4.430 V |
| Node A voltage | 2.357 V |
| Total current | 9.41 mA |
| R2 current | 7.04 mA |
| R3 current | 2.34 mA |

## Verification Results

- KVL Loop 1 residual: -10 mV
- KVL Loop 2 residual: -8 mV
- KCL residual: 0.03 mA
- KCL imbalance: 0.319%

## Demonstration Media

Add the actual video or photograph filename here
after capturing and saving the evidence.

## Safety

USB power was disconnected before modifying wiring.

The existing DC motor-control circuit remained isolated.

Current measurements were performed by inserting the
multimeter in series with the appropriate circuit path.
