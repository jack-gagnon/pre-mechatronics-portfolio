# Lab 01 — Demonstration Evidence

## Purpose

Demonstrate the operation of a simple DC resistive circuit and verify the voltage across a 328.6 Ω resistor connected to an Arduino Uno's 5 V output.

## Demonstration Setup

**Equipment:**
- Arduino Uno, USB-powered
- Breadboard and jumper wires
- 328.6 Ω measured resistor (330 Ω nominal)
- Commercial Electric DMM-8301S
- Multimeter probes and alligator clip adapters

**Circuit:**

Arduino 5V → 328.6 Ω resistor → Arduino GND

The resistor is the only external load.

## Previously Recorded Experimental Results

| Quantity | Result |
|---|---:|
| Nominal supply voltage | 5.00 V |
| Measured resistor resistance | 328.6 Ω |
| Initial measured resistor voltage | 4.41 V |
| Follow-up resistor voltage | 4.42 V |
| Measured current (separate test) | 13.13 mA |
| Calculated current at 4.41 V | 13.42 mA |
| Current difference | 2.17% |

These values are from the earlier measurement stages. The demonstration video is separate evidence and should not be represented as a new measurement unless a reading is recorded from it.

## Demonstration Procedure

1. Inspect the unpowered resistor circuit.
2. Verify that the resistor connects between Arduino 5V and GND.
3. Configure the multimeter for DC voltage measurement.
4. Connect the voltmeter across the resistor.
5. Connect Arduino USB power.
6. Record the displayed voltage with the physical circuit visible.
7. Disconnect power after completing the demonstration.

## Video Evidence

**Filename:** `ohms-law-demo.mp4`

**Recording status:** Pending confirmation.

**Voltage displayed in video:** To be entered after recording.

## Engineering Interpretation

The experiment demonstrates that current through an ohmic resistor can be predicted using the voltage across it and its measured resistance.

Earlier measurements showed that the Arduino's USB-powered rail was lower than its nominal 5 V value.

Using the initial measured voltage of 4.41 V and resistance of 328.6 Ω produced a calculated current of 13.42 mA, compared with the separately measured 13.13 mA.

The close agreement supports the application of Ohm's law to this circuit.

## Safety

The experiment uses low-voltage DC supplied by an Arduino Uno.

- Disconnect power before modifying wiring.
- Verify correct meter mode and probe connections.
- Measure voltage in parallel.
- Measure current only with the meter properly connected in series.
- Never connect a meter configured for current measurement directly across the supply.
- Use a resistor with a power rating above the expected dissipation.

## Conclusion

The demonstration is intended to provide visual confirmation of the physical circuit and voltage measurement.

Final completion requires saving the recording and documenting its actual displayed voltage.