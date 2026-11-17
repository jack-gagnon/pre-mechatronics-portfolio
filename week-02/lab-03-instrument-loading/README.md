
# Lab 3 — Precision DC Measurement and Instrument Loading

## Mechatronics Preparatory Course

- Week: 2
- Day: Tuesday
- Topic: Measurement Uncertainty and Instrument Loading

## Project Overview

This laboratory investigates the accuracy and limitations of DC voltage measurements using a digital multimeter.

Two resistor voltage dividers are constructed and analyzed.

The first uses relatively low resistance values. The second uses higher resistance values, making its output more susceptible to instrument loading.

The experiment compares theoretical predictions with measured voltages and evaluates whether observed differences can be attributed to circuit behavior, supply variation, or measurement limitations.

## Learning Objectives

1. Verify actual resistor values using a digital multimeter.
2. Calculate voltage-divider outputs.
3. Determine the Thevenin resistance of each network.
4. Predict voltmeter loading.
5. Compare measured and predicted voltages.
6. Calculate percentage differences.
7. Evaluate measurement reliability.
8. Document experimental results and troubleshooting.

## Equipment

- Arduino Uno
- ELEGOO breadboard
- Commercial Electric DMM-8301S
- Jumper wires
- Alligator clip adapters
- Nominal 220-ohm resistor
- Nominal 330-ohm resistor
- Nominal 10-kilohm resistor
- Nominal 100-kilohm resistor

## Circuit A — Low-Resistance Divider

Nominal components:

- R1 = 220 ohms
- R2 = 330 ohms

Topology:

Arduino 5V -> R1 -> Output A -> R2 -> Arduino GND

## Circuit B — Higher-Resistance Divider

Nominal components:

- R3 = 100 kilohms
- R4 = 10 kilohms

Topology:

Arduino 5V -> R3 -> Output B -> R4 -> Arduino GND

Actual measured resistor values will be used for all final predictions.

## Measurement Method

The Arduino provides the low-voltage DC supply.

The DMM-8301S measures:

- Individual resistor resistance
- Equivalent circuit resistance
- Supply voltage
- Divider output voltage
- Individual resistor voltage drops

The meter's input resistance and accuracy specifications will be investigated before evaluating loading effects.

## Engineering Analysis

The experiment uses:

- Ohm's law
- Series resistance
- Voltage-divider equations
- Kirchhoff's Voltage Law
- Thevenin equivalent resistance
- Instrument loading calculations
- Measurement uncertainty

## Safety

All resistance measurements and wiring changes must occur with USB power disconnected.

No circuit will be energized until its predicted values, component ratings, and wiring have been verified.

The multimeter must never be connected across the power supply while configured for current measurement.

## Portfolio Evidence

The completed project will include:

- README
- Circuit schematics
- Bench photographs
- Commented Arduino sketch
- Pre-power predictions
- Measured-versus-predicted tables
- Troubleshooting log
- Video demonstration
- Safety documentation

## Project Status

Stage 1 — Component verification and pre-power preparation.

Measurements, findings, and conclusions will be added after the experiment.
