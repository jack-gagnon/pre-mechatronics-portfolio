
# Safety — Week 1 Friday Capstone

## Project

**Voltage Divider Design and Fault Diagnosis**

This experiment investigates series and parallel resistor networks, voltage-divider loading, and controlled open-circuit fault diagnosis.

## 1. Power Source

The circuit was powered by the Arduino Uno's regulated 5 V output, supplied through USB.

Measured operating voltages:

| Measurement | Voltage |
|---|---:|
| Arduino 5V-to-GND | 4.45 V |
| Breadboard supply, initial | 4.43 V |
| Breadboard supply, final recovery | 4.44 V |

The experiment used low-voltage DC only.

**No mains voltage was used.**

## 2. Component Ratings

The resistors were identified through kit specifications as 0.25 W axial-lead components.

| Component | Measured Resistance | Rated Power |
|---|---:|---:|
| R1 | 217.8 Ω | 0.25 W |
| R2 | 328.2 Ω | 0.25 W |
| R3 | 992 Ω | 0.25 W |

Pre-power calculations established that expected power dissipation was below the resistor ratings.

The highest calculated resistor dissipation at the nominal 5 V supply was approximately 27.52 mW.

This represents approximately 11.01% of a 0.25 W rating.

The resistor power ratings were verified from the reported kit specifications rather than individually measured.

## 3. Multimeter Safety

The Commercial Electric DMM-8301S was used for resistance and DC voltage measurements.

Procedures followed:

- Resistance measurements were performed only with circuit power disconnected.
- Voltage measurements were performed with the meter configured for DC voltage.
- The black probe was connected to the COM socket.
- The red probe was connected to the voltage-measurement socket.
- The meter was never connected across the power rails in current-measurement mode.
- Separate jumper-wire extensions were used to establish accessible measurement points.
- Meter connections were checked before applying power.

**Never connect an ammeter directly between the Arduino 5 V and GND terminals.**

Such a connection could create a short circuit and damage the meter, Arduino, or USB power source.

## 4. Breadboard Safety

The circuit was assembled around breadboard rows 50–58.

- Arduino 5V connected to J50.
- Arduino GND connected to J58.
- The resistor network was inspected for unintended shorts.
- Power was disconnected before modifying resistor connections.
- Components were not moved while the circuit was energized.

The separate DC motor control circuit remained electrically isolated throughout the experiment.

## 5. Controlled Fault Procedure

The controlled fault consisted of disconnecting the upper lead of R3 from E54.

This created an **open circuit**, not a short circuit.

The following precautions were observed:

1. Disconnect USB power.
2. Isolate the resistor network before resistance measurements.
3. Remove R3's upper lead.
4. Keep the disconnected lead clear of surrounding conductors.
5. Verify the resulting equivalent resistance.
6. Inspect the circuit before restoring power.
7. Measure the faulted output voltage.
8. Disconnect USB power.
9. Restore R3 to E54–E58.
10. Verify equivalent resistance before applying power again.
11. Perform final voltage verification.
12. Disconnect USB power afterward.

## 6. Fault Recovery Verification

| Verification | Result |
|---|---:|
| Normal loaded equivalent resistance | 465 Ω |
| Open-R3 equivalent resistance | 547 Ω |
| Restored equivalent resistance | 465 Ω |
| Normal loaded output | 2.357 V |
| Open-R3 output | 2.668 V |
| Restored output | 2.357 V |

These measurements confirmed that the fault was successfully introduced, diagnosed, and corrected.

## 7. Final Shutdown

At the conclusion of the experiment:

- USB power was disconnected.
- R3 was restored to its normal position.
- The motor circuit remained isolated.
- No energized wiring modifications were performed.
- All measurements were completed using low-voltage DC.

## 8. Safety Conclusion

The circuit operated within the reported resistor power ratings.

The experiment demonstrated safe measurement practices, controlled fault introduction, and verification of circuit restoration.

No safety incidents were reported.
