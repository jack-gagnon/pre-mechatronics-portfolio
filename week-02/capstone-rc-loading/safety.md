
# Week 2 Integrated Capstone — Electrical Safety

## 1. Purpose

This document records the electrical safety considerations, pre-power checks, operating precautions, controlled discharge procedures, and final shutdown verification for the Week 2 integrated capstone.

The experiment used a low-voltage RC timing circuit supplied by an ELEGOO Arduino Uno.

The principal hazards were:

- Accidental short circuits.
- Incorrect electrolytic capacitor polarity.
- Unexpected discharge of stored capacitor energy.
- Rewiring while power was applied.
- Incorrect measurement configurations.
- Energizing the circuit with a temporary discharge jumper installed.

All experiments were conducted using the Arduino's low-voltage DC supply.

---

## 2. Equipment and Electrical Ratings

| Component | Specification |
|---|---|
| Arduino | ELEGOO Uno |
| Supply voltage | Nominal 5 V |
| Measured supply voltage | 4.45–4.46 V |
| R1 — Charging resistor | 99.2 kΩ |
| R2 — Load resistor | 9.95 kΩ |
| Resistor power rating | Assumed 0.25 W each |
| C1 — Electrolytic capacitor | 100 µF, 50 V |
| Pushbutton | Normally open |
| DMM | DC voltage, resistance, and continuity functions |

Component ratings and the meter's input characteristics should be verified against manufacturer specifications when using this circuit in an actual engineered system.

---

## 3. Electrical Hazard Assessment

### 3.1 Low-Voltage Operation

The circuit was supplied from the Arduino's nominal 5 V output.

The maximum intended operating voltage was substantially below the capacitor's 50 V rating.

Nevertheless, low-voltage circuits can still be damaged by shorts, incorrect connections, or reverse-polarity components.

### 3.2 Accidental Supply Short

A direct connection between Arduino 5V and GND can produce excessive current.

Possible consequences include:

- Arduino resets or power interruptions.
- USB overcurrent protection activation.
- Component or conductor heating.
- Damage to the Arduino or connected equipment.

The circuit must be inspected for unintended supply-to-ground connections before applying power.

### 3.3 Electrolytic Capacitor Polarity

The capacitor is polarized.

Its positive lead must connect to the positive charging node, and its negative lead, identified by the polarity stripe, must connect to ground.

Reverse voltage can increase leakage current and cause heating, dielectric damage, or capacitor failure.

Polarity was checked before applying power and remained unchanged during the experiments.

### 3.4 Stored Electrical Energy

A capacitor can retain voltage after external power has been disconnected.

Stored energy is:

`E = 0.5 × C × V²`

For C = 100 µF and V = 5.000 V:

`E = 0.5 × 100 × 10^-6 × 5²`

**Stored energy: 1.25 mJ**

Although this is a relatively small amount of stored energy, uncontrolled discharge can still affect sensitive electronic components.

Capacitor voltage must be checked before modifying the circuit.

### 3.5 Measurement Hazards

Resistance measurements must only be performed on unpowered circuitry.

An unpowered Arduino can still introduce electrical paths that influence measurements when connected to a passive network.

DMM probe placement and function selection must be verified before measurement.

Current-measurement mode must not be used directly across the supply or capacitor as though it were voltage mode.

---

## 4. Power Dissipation Analysis

### 4.1 Maximum R1 Dissipation

At the start of charging an initially discharged capacitor, the full supply voltage appears across R1.

For the nominal 5.000 V supply:

`P_R1,max = Vs²/R1`

`P_R1,max = 25/99,200`

**Maximum R1 power: 0.2520 mW**

Assuming a 250 mW resistor rating:

`Utilization = 0.2520/250 × 100`

**Maximum utilization: 0.1008%**

This is far below the assumed resistor power rating.

### 4.2 R2 Steady-State Dissipation

With R2 connected in parallel with the capacitor, the nominal 5.000 V analytical model predicts a steady-state node voltage of approximately 0.45538 V.

`P_R2 = Vnode²/R2`

`P_R2 = 0.45538²/9,950`

**R2 steady-state power: approximately 0.02084 mW**

Percentage of the assumed 250 mW rating:

**Approximately 0.00834%**

At the measured 4.46 V supply, the modeled steady-state R2 power is approximately 0.0166 mW.

Both values are well below the assumed rating.

### 4.3 Capacitor Voltage Rating

Nominal supply voltage:

**5.000 V**

Capacitor rated voltage:

**50 V**

`Voltage utilization = 5/50 × 100`

**Voltage rating utilization: 10%**

The voltage rating provides substantial nominal margin, provided the capacitor is correctly polarized and operated within its other specified limits.

---

## 5. Pre-Power Verification

Before energizing the circuit, the following checks were performed or confirmed.

| Verification | Result |
|---|---|
| Arduino USB disconnected during assembly | Confirmed |
| Capacitor polarity visually checked | Confirmed |
| Capacitor voltage measured before reconfiguration | Confirmed |
| R1 charging resistor present | Confirmed |
| R2 load connection verified before powered test | Confirmed |
| Pushbutton charging path checked | Confirmed |
| Temporary discharge jumper removed before power | Confirmed |
| Supply and ground connections checked | Confirmed |
| Unexpected hardware concerns | None reported |

The resistor-loaded configuration was verified using unpowered resistance measurements.

Measured resistance across the load:

**9.95 kΩ**

Measured series-path resistance with the Arduino electrically isolated:

**109.2 kΩ**

The expected series resistance was:

**109.15 kΩ**

---

## 6. Controlled Discharge Procedure

The experiment used a temporary jumper between breadboard holes I50 and H56 to discharge the capacitor through R1.

### Procedure

1. Disconnect Arduino USB power.
2. Release the pushbutton.
3. Measure capacitor voltage between I54 and I56.
4. Confirm no powered supply connection is present.
5. Install the temporary I50–H56 discharge jumper.
6. Observe capacitor voltage decreasing through R1.
7. Continue until capacitor voltage is below 50 mV.
8. Keep USB disconnected throughout the discharge.
9. Remove the temporary jumper before the next powered experiment.

### Critical Warning

**Never reconnect Arduino USB or press the pushbutton while the I50–H56 discharge jumper is installed.**

With the switch closed and the supply powered, the discharge jumper could create a direct short from Arduino 5V to GND.

This is the most important configuration-specific safety constraint in the experiment.

---

## 7. Recorded Discharge Events

### 7.1 Following Initial Charging

Residual capacitor voltage after USB disconnection:

**2.70 V**

Discharge method:

**R1 discharge path using temporary I50–H56 jumper**

Final recorded capacitor voltage:

**0.0 V**

No unexpected behavior was reported.

### 7.2 Following Follow-Up Charging

Residual capacitor voltage after USB disconnection:

**3.65 V**

Discharge method:

**R1 discharge path using temporary I50–H56 jumper**

Final recorded capacitor voltage:

**0.2 mV**

No unexpected behavior was reported.

### 7.3 Following Intentional Loading

With R2 installed across the capacitor, the resistor itself provided a discharge path after power was removed.

Final recorded capacitor voltage:

**0.0 mV**

No additional temporary discharge jumper was required.

---

## 8. Safe Measurement Practices

### DC Voltage Measurement

The DMM was connected in parallel across the capacitor.

- Positive probe: I54.
- Negative probe: I56.
- DMM function: DC voltage.

### Resistance Measurement

Resistance measurements were taken with USB power disconnected and the capacitor confirmed discharged.

For the final series-resistance verification, the Arduino 5V and GND jumpers were disconnected from the Arduino to isolate the passive circuit.

### Moving Connections

Components and jumpers were inserted, removed, or repositioned only with Arduino USB disconnected.

The capacitor was checked for residual voltage before reconfiguration.

### Powered Observation

The pushbutton was held during the required charging interval.

Power was disconnected after the measurement sequence.

No intentional short circuit or reverse-polarity test was performed.

---

## 9. Unexpected Behavior and Response

### Supply Measurement Discrepancy

An initial breadboard measurement returned 0 V.

Rather than proceeding, the Arduino supply was tested directly and the jumper placement was inspected.

The likely misplaced positive supply jumper was corrected.

### Unexpected Resistance Measurement

An initial series-path measurement of 1.149 kΩ was inconsistent with the expected resistance.

The Arduino was electrically isolated before repeating the measurement.

The passive network then measured 109.2 kΩ, consistent with its expected resistance.

### Charging Discrepancy

The first charging test produced lower-than-predicted voltages.

A longer follow-up test was conducted without assuming that the capacitor or meter was defective.

The follow-up produced a 90-second capacitor voltage of 4.39 V.

The precise cause of the original discrepancy was not conclusively established.

These investigations were completed without intentionally bypassing electrical safety checks.

---

## 10. Final Shutdown Verification

Following the intentional-loading experiment:

| Safety item | Final condition |
|---|---|
| Arduino USB | Disconnected |
| Pushbutton | Released |
| Temporary discharge jumper | Removed |
| R2 load resistor | Installed |
| Capacitor voltage | 0.0 mV |
| Unexpected behavior | None reported |

The circuit was left unpowered.

The capacitor was confirmed discharged before the documentation phase.

---

## 11. Engineering Safety Conclusions

The capstone demonstrated that safe low-voltage experimentation requires more than selecting components with adequate voltage and power ratings.

The essential practices were:

1. Verifying supply polarity and physical node connections.
2. Disconnecting power before modifying the breadboard.
3. Measuring stored capacitor voltage before reconfiguration.
4. Using a resistor-controlled discharge path.
5. Removing temporary discharge connections before restoring power.
6. Isolating connected electronics for reliable resistance measurements.
7. Investigating unexpected electrical measurements before proceeding.
8. Confirming the final shutdown state.

The experimental circuit remained within its intended low-voltage operating conditions, and no unexpected hardware damage was reported.

---

## 12. Related Documents

- [Capstone Overview](README.md)
- [Analytical Predictions](predictions.md)
- [Experimental Measurements](measurements.md)
- [Troubleshooting Log](troubleshooting.md)
