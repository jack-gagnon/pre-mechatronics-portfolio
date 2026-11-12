
# Lab 02 — Electrical Safety Record

**Course:** Mechatronics Preparatory Course  
**Week:** 01 — Thursday  
**Date:** November 12, 2026  
**Experiment:** Series & Parallel Resistor Networks

---

## 1. Purpose

Document the safety precautions used while constructing,
energizing, measuring, and restoring a low-voltage DC
resistor network.

## 2. Equipment and Operating Conditions

- Arduino Uno powered through USB
- ELEGOO breadboard and jumper wires
- Commercial Electric DMM-8301S
- Alligator clip adapters
- R1 = 217.6 ohms
- R2 = 328 ohms
- R3 = 992 ohms

The circuit was designed around a nominal 5.00 V supply.

The actual Arduino supply voltage was measured at 4.46 V.

## 3. Pre-Power Safety Checks

Before energizing the circuit:

1. The Arduino USB connection was disconnected.
2. Resistor values were individually measured.
3. The circuit was assembled according to the schematic.
4. The equivalent resistance was measured at 465 ohms.
5. The expected current and resistor power dissipation
   were calculated.
6. The circuit connections were visually inspected.
7. The existing DC motor-control circuit remained
   unpowered and electrically isolated.

The calculated current and resistor power levels were
low for the intended experimental circuit.

Resistor ratings must be checked against calculated
dissipation before use.

## 4. Voltage Measurement Safety

Voltage measurements were performed with the multimeter
configured for DC voltage.

Voltage was measured in parallel with the appropriate
circuit nodes or components.

The multimeter's current-measurement configuration was
not used to measure voltage across the power supply.

## 5. Current Measurement Safety

Before inserting the multimeter into a current path:

1. Arduino USB power was disconnected.
2. The appropriate circuit connection was opened.
3. The multimeter was configured for DC current.
4. The meter was inserted in series with the selected
   component or supply path.
5. Probe and alligator clip placement was checked.
6. USB power was restored only for the measurement.
7. USB power was disconnected before changing wiring.

Current was measured separately through:

- The total supply path
- R2's branch
- R3's branch

The current-configured multimeter must never be connected
directly across the Arduino 5V and GND terminals.

## 6. Breadboard Safety

Care was taken to verify that:

- The two sides of the breadboard center gap were
  connected only by intended jumpers.
- Row 54 formed the common upper node.
- Row 58 formed the common ground node.
- No unintended connection shorted the supply.
- Temporary lifted resistor leads were kept isolated.
- Alligator clips did not contact adjacent conductors.
- The existing motor-control circuit remained isolated.

## 7. Measurement Limitations

The experimental results may be affected by:

- Multimeter burden voltage
- Breadboard and jumper contact resistance
- USB supply variation
- Multimeter accuracy and resolution

Measurements were taken sequentially rather than
simultaneously.

These limitations were documented without assuming
an unverified root cause.

## 8. Final Circuit Restoration

After completing the experiment:

- R1 was restored to H50-H54.
- R2 was restored to F54-F58.
- R3 was restored to E54-E58.
- Node A jumper remained G54-D54.
- Ground jumper remained H58-D58.
- Supply jumper remained Arduino 5V-J50.
- Ground return remained Arduino GND-J58.
- The multimeter was removed from the circuit.
- Arduino USB power was disconnected.

**Final state: Circuit restored and unpowered.**

## 9. Safety Conclusion

Low-voltage does not eliminate the possibility of
short circuits, component damage, or meter damage.

The experiment reinforced three essential practices:

1. Calculate expected electrical conditions before
   applying power.
2. Disconnect power before modifying the circuit.
3. Verify the meter configuration before every
   voltage or current measurement.
