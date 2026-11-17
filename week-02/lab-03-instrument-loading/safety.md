
# Safety — Precision DC Measurement and Instrument Loading

## Mechatronics Preparatory Course

- Week: 2
- Session: Tuesday Lab 3
- Project: Precision DC Measurement and Instrument Loading

## 1. Project Overview

This experiment investigated the accuracy and limitations
of DC voltage measurements using two resistor-divider
networks.

Circuit A used relatively low resistance values.

Circuit B used higher resistance values to investigate
increased susceptibility to voltmeter loading.

The experiment used an Arduino Uno as a low-voltage
DC power source.

No mains voltage was involved.

## 2. Equipment

- Arduino Uno
- ELEGOO breadboard
- Commercial Electric DMM-8301S
- Jumper wires
- Alligator clip adapters
- Four axial-lead resistors

## 3. Component Ratings

All four resistors were identified as 0.25 W components.

| Component | Measured Resistance | Rated Power |
|---|---:|---:|
| R1 | 217.9 Ω | 0.25 W |
| R2 | 328.3 Ω | 0.25 W |
| R3 | 99.2 kΩ | 0.25 W |
| R4 | 9.95 kΩ | 0.25 W |

## 4. Pre-Power Verification

Before energizing either circuit:

1. Resistor values were measured individually.
2. Power ratings were confirmed.
3. Equivalent resistance was calculated.
4. Expected voltage drops were calculated.
5. Expected current was calculated.
6. Resistor power dissipation was evaluated.
7. Circuit wiring was inspected.
8. Equivalent resistance was measured while unpowered.
9. Schematics and bench photographs were saved.
10. Final safety inspection was completed.

No circuit was powered before the pre-power checks passed.

## 5. Circuit A — Power Analysis

At the nominal 5.00 V supply:

R1 = 217.9 Ω

R2 = 328.3 Ω

Total resistance:

546.2 Ω

Predicted current:

9.154 mA

Predicted resistor power:

| Component | Predicted Power | Rated Power |
|---|---:|---:|
| R1 | 18.26 mW | 250 mW |
| R2 | 27.51 mW | 250 mW |

Both calculated dissipations were below the resistor ratings.

Measured operating supply:

4.43 V

## 6. Circuit B — Power Analysis

At the nominal 5.00 V supply:

R3 = 99.2 kΩ

R4 = 9.95 kΩ

Total resistance:

109.15 kΩ

Predicted current:

45.81 µA

Predicted resistor power:

| Component | Predicted Power | Rated Power |
|---|---:|---:|
| R3 | 0.2082 mW | 250 mW |
| R4 | 0.0209 mW | 250 mW |

Both calculated dissipations were far below the ratings.

Measured operating supply:

4.45 V

## 7. Multimeter Safety

Instrument:

Commercial Electric DMM-8301S

The following procedures were followed:

- Resistance measurements were performed only while
  the network was unpowered and isolated.
- Powered voltage measurements used DC voltage mode.
- The black meter lead was connected to COM.
- The red meter lead was connected to the voltage socket.
- The current-measurement sockets were not used
  across the power supply.
- Separate jumper-wire extensions were used where needed.
- Probe connections were checked before applying power.
- USB power was disconnected after each measurement stage.

WARNING:

Never connect a multimeter configured for current measurement
directly between the Arduino 5 V and GND connections.

This could create a short circuit and damage the meter,
Arduino, or USB power source.

## 8. Breadboard Safety

The resistor networks were assembled around rows 50–58.

Circuit A:

- R1: H50–H54
- R2: F54–F58

Circuit B:

- R3: H50–H54
- R4: F54–F58

Supply connections:

- Arduino 5 V: J50
- Arduino GND: J58

The circuits were operated separately.

No resistor leads were moved while USB power was connected.

The breadboard was placed on a nonconductive surface.

## 9. Measurement Procedure Safety

For each powered measurement:

1. Disconnect USB power.
2. Position the meter probes.
3. Confirm DC voltage measurement mode.
4. Inspect the connections.
5. Connect USB power.
6. Allow the reading to stabilize.
7. Record the reading.
8. Disconnect USB power.

Resistance measurements were not performed while energized.

## 10. Instrument Loading

The DMM's published DC voltage input resistance is 10 MΩ.

Connecting the meter across a resistor adds a parallel
current path and can change the circuit's operating voltage.

This effect was evaluated mathematically before measurement.

No unsafe method was used to increase or exaggerate
instrument loading.

## 11. Experimental Limitations

The predicted meter-loading effect in Circuit B was
approximately 0.367 mV at the measured supply voltage.

This was smaller than the instrument's calculated
accuracy allowance.

The experiment therefore did not independently resolve
the loading effect.

No additional powered measurements were performed solely
to force a measurable result.

## 12. Demonstration Evidence

A video demonstration was intentionally omitted for
this laboratory.

The project retains the following evidence:

- Circuit photographs
- Circuit schematics
- Pre-power predictions
- Measured-versus-predicted tables
- KVL verification
- Repeatability calculations
- Troubleshooting and experimental-limitations log

This was an explicit exception to the course's usual
demonstration-evidence requirement.

Future laboratory projects will resume video demonstrations.

## 13. Final Shutdown

At the conclusion of the experiment:

- USB power was disconnected.
- All powered measurements were complete.
- No energized wiring changes were reported.
- No unexpected safety incidents were reported.

## 14. Safety Conclusion

Both resistor networks were operated using low-voltage DC.

Calculated power dissipation remained within the reported
component ratings.

The experiment followed safe resistance and voltage
measurement procedures.

No safety incidents were reported.

The laboratory demonstrated the importance of verifying
instrument configuration, component ratings, and circuit
conditions before taking electrical measurements.
