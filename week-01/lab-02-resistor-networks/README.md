# Lab 02 — Series and Parallel Resistor Networks

**Course:** Mechatronics Preparatory Course  
**Session:** Week 01 · Thursday, November 12, 2026

## Objective

Build a mixed series-parallel DC resistor circuit, predict node voltages and branch currents, and verify Ohm's law, Kirchhoff's Current Law (KCL), Kirchhoff's Voltage Law (KVL), and power conservation using physical measurements.

## Why this matters

Mechatronic systems contain multiple current paths, loads, and reference nodes. Predicting electrical quantities before powering a circuit is critical for safe testing and reliable troubleshooting.

## Circuit

R1 (217.6 Ω measured) in series with R2 (328 Ω) in parallel with R3 (992 Ω):

```text
Arduino 5V ── R1 ──● Node A
                   ├── R2 ──┐
                   └── R3 ──┤
                            └── Arduino GND
```

## Equipment

- Arduino Uno and USB power
- Breadboard and jumper wires
- R1 nominal 220 Ω, measured 217.6 Ω
- R2 nominal 330 Ω, measured 328 Ω
- R3 nominal 1 kΩ, measured 992 Ω
- Commercial Electric DMM-8301S
- Alligator clips

## Breadboard wiring

| Item | Connection |
|---|---|
| R1 | H50 to H54 |
| R2 | F54 to F58 |
| R3 | E54 to E58 |
| Node A bridge | G54 to D54 |
| Ground bridge | H58 to D58 |
| Supply | Arduino 5V to J50 |
| Return | Arduino GND to J58 |

An existing motor-control build occupies another part of the breadboard and must remain electrically isolated and unpowered during this experiment.

## Pre-power results

Predicted total resistance: **464.10 Ω**.  
Measured unpowered resistance: **465 Ω**.  
Difference: **0.195%**.

Detailed calculations are in [`predictions.md`](predictions.md). Measurement entries and KCL/KVL checks are in [`measurements.md`](measurements.md).

## Status

- [x] Unpowered circuit assembled and resistance verified
- [x] Pre-power predictions recorded
- [ ] Powered voltage and current measurements
- [ ] Schematic image committed
- [ ] Bench photo committed
- [ ] Commented `.ino` sketch and pin map
- [ ] Troubleshooting log completed
- [ ] Demo evidence completed
- [ ] Final safety note
- [ ] Final GitHub commit and push

## Safety

Use only low-voltage DC. Disconnect USB before rewiring. Keep the motor-control circuit isolated. Verify no short between 5V and GND before powering. Connect a voltmeter in parallel and an ammeter in series; never place a current-configured meter directly across the supply. Confirm resistor power ratings.
