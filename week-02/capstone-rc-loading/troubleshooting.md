
# Week 2 Integrated Capstone — Troubleshooting Log

## 1. Purpose

This document records unexpected circuit behavior encountered during the Week 2 RC loading capstone.

Each investigation distinguishes:

- The expected behavior.
- The actual observation.
- Diagnostic measurements.
- Corrective actions.
- The evidence supporting the conclusion.
- Any remaining uncertainty.

The objective is to preserve a reproducible engineering troubleshooting record rather than retroactively assuming that every discrepancy has been explained.

---

## 2. Issue 1 — Unexpected Zero-Volt Supply Reading

### Expected Behavior

With the Arduino supplying approximately 4.45 V and its 5V jumper connected to D43, the voltage between C43 and I56 should be approximately 4.45 V, regardless of the pushbutton state.

D43 and C43 occupy the same connected breadboard row segment.

### Initial Observation

The voltage between C43 and I56 depended on the pushbutton state.

| Pushbutton state | Measured voltage |
|---|---:|
| Released | 0.0 V |
| Pressed | 4.45 V |

This was inconsistent with the intended supply-side measurement.

### Diagnostic Procedure

1. Verified the Arduino output directly between its 5V and GND pins.
2. Measured 4.45 V at the Arduino.
3. Reexamined the positive supply-jumper placement.
4. Identified that the jumper had likely been inserted into D45 instead of D43.
5. Corrected the positive supply connection.
6. Rechecked the supply and switch-output voltages.

### Verification Results

| Measurement | Result |
|---|---:|
| Arduino 5V-to-GND | 4.45 V |
| Breadboard supply at D43 after correction | 4.45 V |
| I50–I56, pushbutton released | −0.1 mV |
| I50–I56, pushbutton pressed | 4.45 V |

The corrected configuration produced the expected switching behavior.

The released switch-output node was effectively near zero during the measurement, but its voltage is not guaranteed when floating.

### Engineering Conclusion

The evidence supports an incorrect supply-jumper location as the likely cause of the initial discrepancy.

The problem was resolved by verifying the physical supply path rather than assuming the original jumper placement was correct.

### Lesson Learned

**Always verify the actual electrical node being measured, not merely the intended breadboard coordinate.**

For a standard breadboard, holes in the same five-hole terminal strip are connected, but adjacent numbered rows are isolated unless deliberately joined.

---

## 3. Issue 2 — Unexpected Resistance Measurement

### Expected Behavior

With R1 = 99.2 kΩ and R2 = 9.95 kΩ, the expected series-path resistance is:

`Rtotal = R1 + R2`

`Rtotal = 99.2 + 9.95`

**Expected resistance: 109.15 kΩ**

### Initial Observation

An unpowered resistance measurement between C43 and I56, with the pushbutton pressed, produced:

**Measured resistance: 1.149 kΩ**

This was significantly below the expected value.

### Diagnostic Hypotheses

Potential causes included:

- An unintended parallel resistance path.
- Incorrect breadboard connections.
- Interaction with electronics remaining connected to the circuit.
- An incorrect test configuration.

Although Arduino USB power was disconnected, the Arduino's 5V and GND connections remained attached to the breadboard.

### Diagnostic Procedure

1. Kept Arduino USB disconnected.
2. Released the pushbutton.
3. Disconnected the 5V and GND jumper ends from the Arduino.
4. Confirmed the capacitor voltage was 0.0 mV.
5. Measured resistance directly between I50 and I56.
6. Allowed the reading to stabilize.

### Verification Results

| Quantity | Expected | Measured |
|---|---:|---:|
| R2 | 9.95 kΩ | 9.95 kΩ |
| R1 + R2 | 109.15 kΩ | 109.2 kΩ |

The isolated passive resistor network agreed with the design prediction.

The difference between 109.2 kΩ and 109.15 kΩ is approximately 0.046%, based on the rounded values.

### Engineering Conclusion

The corrected resistance measurement supports the conclusion that the passive resistor network was connected properly.

The earlier 1.149 kΩ result was likely influenced by the connected, unpowered Arduino or another path present in the earlier measurement configuration.

The exact electrical path responsible for the earlier reading was not independently traced.

### Lesson Learned

**Removing power does not necessarily electrically isolate a device.**

For meaningful resistance measurements, connected electronics may need to be disconnected from the passive network being tested.

A meter's resistance mode applies its own test signal, which may interact with semiconductor junctions and other connected circuitry.

---

## 4. Issue 3 — Initial Charging Curve Below Prediction

### Expected Behavior

For the first charging experiment:

- Supply voltage: 4.45 V.
- Charging resistor: 99.2 kΩ.
- Capacitor: 100 µF nominal.
- DMM input resistance: 10 MΩ nominal.
- Additional load resistor: disconnected.

The predicted steady-state voltage was approximately:

**4.406 V**

The nominal DMM-loaded time constant was approximately:

**9.823 s**

### Initial Observation

The first experiment produced the following readings:

| Time (s) | Measured voltage (V) |
|---:|---:|
| 5 | 1.160 |
| 10 | 2.451 |
| 15 | 3.214 |
| 20 | 3.674 |
| 30 | 4.110 |
| 40 | 4.280 |
| 50 | 4.310 |
| 60 | 4.310 |

The early charging readings were lower than predicted.

The last two recorded values were both 4.31 V, suggesting an apparent plateau below the expected steady-state voltage.

However, the complete 60-second record was not captured as one uninterrupted experiment.

Approximately 42 seconds of video were recorded, and the final measurements were obtained after repeating part of the measurement process.

This limitation prevented the original sequence from being treated as a single, continuous charging trace.

### Diagnostic Hypotheses

Potential causes included:

1. Stopwatch and switch-actuation timing differences.
2. Actual capacitance differing from the nominal 100 µF value.
3. Unmodeled loading or capacitor leakage.
4. Supply-voltage differences.
5. Differences in the repeated measurement procedure.

The data did not uniquely identify any of these explanations.

### Follow-Up Experiment

A second charging experiment was performed to investigate whether the circuit could approach the predicted final voltage.

The supply was measured at 4.46 V while the pushbutton remained pressed near the end of the test.

The initial capacitor voltage was 0.0039 V.

| Time (s) | Measured voltage (V) |
|---:|---:|
| 0 | 0.0039 |
| 30 | 4.170 |
| 60 | 4.380 |
| 90 | 4.390 |

The nominal predicted steady-state voltage with the 4.46 V supply and 10 MΩ meter model was approximately:

**4.416 V**

At 90 seconds, the measured voltage was:

**4.390 V**

The difference was approximately:

`4.390 - 4.416 = -0.026 V`

Relative difference:

**Approximately −0.59%**

### Engineering Conclusion

The second experiment established that the capacitor could reach at least 4.39 V under the tested conditions.

Therefore, the initial 4.31 V reading should not be interpreted as the confirmed steady-state voltage of the circuit.

The second experiment showed better agreement with the nominal model, but did not establish the precise cause of the original discrepancy.

### Lesson Learned

**A measured plateau should not automatically be interpreted as a physical steady-state limit.**

Before diagnosing additional loading or component failure, verify:

- That measurements belong to one consistently timed experiment.
- That sufficient settling time has elapsed.
- That the supply voltage remains stable.
- That the circuit configuration has not changed.
- That the data can be reproduced.

---

## 5. Issue 4 — Distinguishing Steady-State and Transient Validation

### Theoretical Prediction

With R2 connected across the capacitor, the predicted loaded time constant was:

**Approximately 0.9035 s**

The predicted final capacitor voltage with a 4.46 V supply was:

**Approximately 0.4062 V**

### Experimental Observation

| Time (s) | Measured voltage (V) |
|---:|---:|
| 5 | 0.4040 |
| 10 | 0.4050 |
| 20 | 0.4059 |
| 30 | 0.4059 |

The measured voltage closely approached the predicted steady-state value.

### Measurement Limitation

The first reading was taken at 5 seconds, corresponding to approximately:

`5 / 0.9035 = 5.53`

**5.53 nominal time constants**

By this time, the modeled transient was nearly complete.

Therefore, these measurements validate the loaded circuit's approximate steady-state behavior but do not independently establish the actual subsecond time constant.

### Engineering Conclusion

The steady-state voltage-divider prediction was strongly supported by the experimental data.

The predicted loaded time constant remains an analytical result, not an independently verified transient measurement.

### Future Improvement

Use a suitable data-acquisition device to sample the capacitor voltage at intervals substantially shorter than the loaded time constant.

An Arduino analog input could be considered, provided its input loading, sampling behavior, accuracy, and voltage limits are accounted for in the measurement plan.

---

## 6. Summary of Troubleshooting Outcomes

| Issue | Observation | Outcome |
|---|---|---|
| Supply jumper placement | 0 V with switch released | Likely misplaced jumper corrected |
| Resistance verification | Unexpected 1.149 kΩ | Passive network verified at 109.2 kΩ after Arduino isolation |
| Initial charging curve | Apparent 4.31 V plateau | Follow-up reached 4.39 V; original discrepancy unresolved |
| Loaded transient | Measurements began at 5 s | Steady-state agreement verified; transient time constant not independently measured |

---

## 7. General Engineering Lessons

### Verify Electrical Nodes

Breadboard coordinates, physical wire placement, and electrical connectivity must agree.

### Isolate Circuits Before Resistance Measurements

An unpowered microcontroller can still influence resistance readings through connected electronic paths.

### Preserve Unexpected Results

Experimental discrepancies are useful engineering evidence when documented faithfully.

### Separate Observation from Explanation

A measured result may support several possible physical explanations. Conclusions should identify only what the available evidence establishes.

### Understand Measurement Limitations

A data set that accurately captures steady-state voltage may not have sufficient time resolution to characterize the transient response.

### Reproduce Results

A controlled follow-up measurement is often more informative than making an unsupported assumption about the original discrepancy.

---

## 8. Related Files

- [Capstone Overview](README.md)
- [Analytical Predictions](predictions.md)
- [Experimental Measurements](measurements.md)
- [Electrical Safety](safety.md)
- [Charging Demonstration](demo/rc-charging-demo.mp4)
