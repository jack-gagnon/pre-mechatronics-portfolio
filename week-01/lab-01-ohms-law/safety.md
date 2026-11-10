# Lab 01 — Electrical Safety Documentation

**Course:** Mechatronics Preparatory Course  
**Experiment:** Ohm's Law Verification  
**Date:** November 10, 2026  
**Equipment:** Arduino Uno, 330 Ω resistor, breadboard, jumper wires, Commercial Electric DMM-8301S

---

## 1. Experiment Overview

This experiment verifies Ohm's law by measuring the electrical behavior of a resistor connected between an Arduino Uno's 5 V and GND terminals.

The Arduino is powered through USB. The circuit operates at low DC voltage and does not involve mains wiring.

**Circuit configuration:**

Arduino 5V → R1 (328.6 Ω measured) → Arduino GND

The circuit uses no digital or analog Arduino I/O pins.

## 2. Electrical Operating Conditions

| Parameter | Value |
|---|---:|
| Nominal source voltage | 5.00 V |
| Initial measured resistor voltage | 4.41 V |
| Later measured resistor voltage | 4.42 V |
| Measured resistor resistance | 328.6 Ω |
| Measured circuit current | 13.13 mA |
| Calculated power at 4.42 V | 59.45 mW |
| Assumed resistor rating | 0.25 W (verify component specification) |

At the nominal 5.00 V supply voltage, the calculated maximum power for this test condition is:

\[
P=\frac{V^2}{R}
\]

\[
P=\frac{5.00^2}{328.6}
=0.07608\text{ W}
\]

\[
\boxed{P=76.08\text{ mW}}
\]

If the resistor is rated for 0.25 W, this operating point uses approximately 30.4% of its nominal power rating.

This provides a reasonable power margin for the experiment, assuming the resistor's rating is confirmed and it is used within its specified operating conditions.

## 3. Identified Hazards

### Hazard A — Short Circuit Between Supply Rails

**Risk:** Connecting Arduino 5V directly to GND can create excessive current, potentially damaging the board, USB source, wiring, or connected components.

**Precautions:**
- Inspect breadboard connections before applying power.
- Ensure the resistor is correctly placed between 5V and GND.
- Avoid direct jumper-wire connections between the supply rails.
- Disconnect USB power immediately if abnormal heating, smoke, or unexpected behavior occurs.

### Hazard B — Incorrect Multimeter Current Measurement

**Risk:** Connecting a multimeter configured for current measurement directly across a voltage source can create a near-short circuit.

**Precautions:**
- Measure voltage with the multimeter connected in parallel.
- Measure current with the multimeter inserted in series.
- Use the appropriate current input and fused measurement range.
- Verify the meter configuration before applying power.
- Disconnect power before changing between voltage and current measurement configurations.

### Hazard C — Excessive Resistor Power Dissipation

**Risk:** A resistor that dissipates more power than its rated capacity may overheat, drift in resistance, or fail.

**Precautions:**
- Calculate expected power before energizing the circuit.
- Verify the resistor's actual power rating.
- Choose a resistor with sufficient power margin.
- Never assume that a resistor's resistance value determines its wattage rating.

### Hazard D — Accidental Contact or Wiring Failure

**Risk:** Loose jumper wires, exposed conductive surfaces, or incorrectly connected alligator clips may cause intermittent connections or short circuits.

**Precautions:**
- Keep conductive clips separated.
- Check that jumper wires are securely seated.
- Place resistor leads in electrically separate breadboard rows.
- Avoid adjusting wiring while the circuit is powered.

### Hazard E — Improper External Power Supply

**Risk:** Applying an unsuitable voltage or incorrect polarity through the Arduino's barrel-jack input can damage the board.

**Precautions:**
- Use only a properly specified, compatible DC supply.
- Verify voltage and polarity before connecting external power.
- Follow the requirements for the specific Arduino board.
- Do not connect experimental power sources directly to the 5 V rail without verifying compatibility.
- Avoid powering through USB and external inputs simultaneously unless the board's documented power-selection behavior and source compatibility have been verified.

## 4. Safe Operating Procedure

### Before Power-Up

1. Disconnect Arduino USB power.
2. Inspect the breadboard and jumper connections.
3. Confirm that the resistor connects between 5V and GND.
4. Verify the resistor's measured resistance.
5. Calculate expected circuit current.
6. Calculate expected resistor power dissipation.
7. Confirm that the resistor's power rating is sufficient.
8. Verify the multimeter configuration.

### During Measurements

1. Apply USB power only after completing the circuit inspection.
2. Measure voltage with the multimeter connected in parallel.
3. Disconnect power before reconfiguring the circuit for current measurement.
4. Measure current with the multimeter connected in series.
5. Observe the circuit for unexpected heating or unstable behavior.
6. Record measurements without changing connections unnecessarily.

### After Measurements

1. Disconnect USB power.
2. Remove the multimeter from the circuit.
3. Return the multimeter leads to the voltage/resistance configuration.
4. Inspect the circuit for damaged components or loose connections.
5. Store the equipment safely.

## 5. Observed Results

During this experiment:

- The measured resistor resistance was 328.6 Ω.
- The resistor voltage was approximately 4.4 V during USB operation.
- The measured current was 13.13 mA.
- Calculated resistor power remained below 0.08 W under the tested conditions.
- No component damage or hazardous behavior was reported.

The Arduino's supply voltage was lower than its nominal 5 V output when USB-powered.

An earlier barrel-powered experiment produced a 5.02 V rail measurement, suggesting that the power-input configuration may influence the observed supply voltage.

The exact cause of the USB voltage reduction was not isolated.

## 6. Safety Conclusions

The experimental circuit operated at low voltage with a calculated current of approximately 13–15 mA and resistor power below 0.08 W.

The main risks were incorrect wiring, short circuits, and improper multimeter configuration.

These risks were managed through pre-power calculations, connection inspections, and appropriate voltage and current measurement procedures.

**Final safety principle:** Always verify the circuit, power source, component ratings, and measurement configuration before applying power.

---

**Safety documentation status:** Prepared for inclusion in the GitHub project repository.