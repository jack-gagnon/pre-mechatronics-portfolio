# Week 2 Integrated Capstone — RC Timing, Instrument Loading, and Circuit Reliability

## Overview

This capstone investigates how measurement instruments, resistive loads, and component tolerances influence the behavior of an RC timing circuit.

The experiment combines the electrical principles developed throughout Weeks 1 and 2:

- Ohm's Law
- Kirchhoff's Voltage and Current Laws
- Series and parallel resistance
- Voltage dividers
- Capacitor charging and discharging
- RC time constants
- Digital multimeter loading
- Component tolerances and measurement uncertainty
- Electrical safety and systematic troubleshooting

The central engineering challenge was to evaluate an RC timing circuit designed to trigger a control event when its capacitor voltage reached **3.00 V**.

Experimental results demonstrate that a sufficiently low-resistance load can prevent the circuit from ever reaching the required threshold, despite producing a faster transient response.

## Engineering Objectives

1. Predict the charging behavior of an ideal RC circuit.
2. Determine how a digital multimeter affects the circuit's steady-state voltage and time constant.
3. Investigate the effect of connecting an additional resistor across the capacitor.
4. Evaluate how component tolerances affect threshold-crossing reliability.
5. Verify resistor power dissipation and capacitor voltage ratings.
6. Compare theoretical predictions against bench measurements.
7. Identify and investigate discrepancies through systematic troubleshooting.
8. Document experimental results and engineering conclusions.

## Equipment and Components

| Equipment / Component | Specification |
|---|---|
| Microcontroller | ELEGOO Arduino Uno |
| Breadboard | Solderless breadboard |
| Digital multimeter | Handheld DMM |
| R1 — Charging resistor | 99.2 kΩ |
| R2 — Load resistor | 9.95 kΩ |
| C1 — Electrolytic capacitor | 100 µF, 50 V |
| Pushbutton | Normally open |
| Arduino supply | Nominal 5 V |
| Measured Arduino supply | Approximately 4.45–4.46 V |
| DMM input resistance | Nominal 10 MΩ |

Resistor power ratings were treated as 0.25 W.

The capacitor's actual capacitance was not independently measured during this capstone.

## Circuit Description

The primary circuit consists of a DC supply, normally-open pushbutton, series charging resistor, and electrolytic capacitor.

The pushbutton connects the supply to the charging resistor. The resistor limits charging current, while the capacitor develops a time-dependent voltage across its terminals.

The multimeter measures the capacitor voltage.

A second configuration adds a 9.95 kΩ resistor in parallel with the capacitor to simulate an additional electrical load.

### Circuit Configurations

**Configuration A — RC Circuit with DMM**

- R1 = 99.2 kΩ
- C1 = 100 µF
- DMM input resistance ≈ 10 MΩ
- R2 disconnected

**Configuration B — RC Circuit with DMM and Additional Load**

- R1 = 99.2 kΩ
- R2 = 9.95 kΩ
- C1 = 100 µF
- DMM input resistance ≈ 10 MΩ
- R2 connected across C1

Both configurations used the same Arduino supply and pushbutton-controlled charging path.

## Theoretical Analysis

### Ideal RC Charging

The nominal time constant is:

\[
\tau=RC
\]

\[
\tau=(99{,}200)(100\times10^{-6})
\]

\[
\boxed{\tau=9.92\text{ s}}
\]

For an initially discharged capacitor:

\[
V_C(t)=V_S(1-e^{-t/\tau})
\]

Using an ideal 5.000 V supply, the predicted time to reach the 3.00 V control threshold is approximately:

\[
\boxed{t_{3V}=9.09\text{ s}}
\]

### Digital Multimeter Loading

Assuming a nominal 10 MΩ DMM input resistance, the effective charging resistance is:

\[
R_{th}=R_1\parallel R_m
\]

The corresponding time constant is approximately:

\[
\boxed{\tau_{\text{DMM}}=9.82\text{ s}}
\]

With a 5.000 V source, the final capacitor voltage is approximately:

\[
\boxed{V_{\infty,\text{DMM}}=4.951\text{ V}}
\]

This demonstrates that the measurement instrument affects the circuit under observation.

### Additional Resistive Loading

When R2 is connected across the capacitor, the equivalent load resistance is:

\[
R_L=R_2\parallel R_m
\]

\[
\boxed{R_L\approx9.940\text{ k}\Omega}
\]

The effective time constant becomes approximately:

\[
\boxed{\tau_{\text{loaded}}\approx0.9035\text{ s}}
\]

Using the measured 4.46 V supply, the predicted steady-state capacitor voltage is approximately:

\[
\boxed{V_{\infty,\text{loaded}}\approx0.406\text{ V}}
\]

Because this voltage is below the required 3.00 V threshold, the loaded circuit cannot satisfy the triggering requirement under the modeled conditions.

## Experimental Procedure

### Configuration A — Charging Without the Additional Load

1. Constructed the pushbutton-controlled RC circuit.
2. Verified capacitor polarity and resistor connections.
3. Confirmed the capacitor was discharged.
4. Measured the Arduino supply voltage.
5. Applied power and initiated charging using the pushbutton.
6. Recorded capacitor voltage at specified time intervals.
7. Compared the measured charging curve against theoretical predictions.
8. Conducted a second, longer charging experiment to investigate the initial discrepancy.
9. Disconnected power and discharged the capacitor through the charging resistor.

### Configuration B — Charging With the Additional Load

1. Confirmed capacitor discharge and disconnected USB power.
2. Installed R2 across C1.
3. Verified the load resistance measured approximately 9.95 kΩ.
4. Isolated the Arduino and measured approximately 109.2 kΩ through R1 and R2 in series.
5. Restored the Arduino supply connections.
6. Confirmed the capacitor's initial voltage was approximately zero.
7. Applied power and initiated charging using the pushbutton.
8. Recorded capacitor voltage at 5, 10, 20, and 30 seconds.
9. Released the pushbutton, disconnected USB, and verified the capacitor had discharged.

## Experimental Results

### Configuration A — Initial Charging Experiment

Arduino supply voltage: approximately 4.45 V.

| Time (s) | Measured Voltage (V) |
|---:|---:|
| 5 | 1.160 |
| 10 | 2.451 |
| 15 | 3.214 |
| 20 | 3.674 |
| 30 | 4.110 |
| 40 | 4.280 |
| 50 | 4.310 |
| 60 | 4.310 |

The measured voltage was initially below the ideal prediction and appeared to level off around 4.31 V.

The final readings were obtained after repeating part of the measurement process. Therefore, the data were not treated as a single uninterrupted charging record.

### Configuration A — Follow-Up Charging Experiment

Measured supply voltage: 4.46 V.

Initial capacitor voltage: 0.0039 V.

| Time (s) | Measured Voltage (V) |
|---:|---:|
| 30 | 4.170 |
| 60 | 4.380 |
| 90 | 4.390 |

The second experiment reached 4.39 V, closer to the approximately 4.416 V nominal DMM-loaded steady-state prediction.

This demonstrated that the earlier 4.31 V reading was not a confirmed final voltage limit.

The precise cause of the earlier discrepancy remains undetermined.

### Configuration B — Intentional Loading Experiment

| Time (s) | Measured Voltage (V) |
|---:|---:|
| 5 | 0.4040 |
| 10 | 0.4050 |
| 20 | 0.4059 |
| 30 | 0.4059 |

Predicted steady-state voltage:

**Approximately 0.406 V**

Measured voltage at 30 seconds:

**0.4059 V**

The measured result closely agreed with the predicted voltage-divider behavior.

Because the capacitor approached approximately 0.406 V, the 3.00 V threshold remained unreachable.

The measurements were taken after the nominal subsecond transient had largely completed and therefore do not directly validate the predicted 0.9035-second time constant.

## Troubleshooting Summary

Three noteworthy issues were encountered.

**1. Supply jumper placement**

An initial 0 V breadboard supply measurement led to an inspection of the supply connections. The Arduino 5 V jumper was found to have likely been connected to D45 rather than D43.

After correcting the connection, the circuit produced the expected 4.45 V supply measurement.

**2. Resistance measurement with connected electronics**

An unexpected 1.149 kΩ resistance reading was obtained while the Arduino remained connected without USB power.

After electrically isolating the Arduino, the intended R1 + R2 network measured 109.2 kΩ, closely matching the predicted 109.15 kΩ.

This demonstrated the importance of electrically isolating external circuitry when measuring resistance.

**3. Initial charging discrepancy**

The initial experiment approached approximately 4.31 V, while a controlled follow-up reached approximately 4.39 V.

The investigation ruled out treating 4.31 V as a confirmed steady-state voltage. The exact reason for the difference could not be established from the available measurements.

## Component Tolerance and Reliability

An analytical tolerance study assumed:

- R1 tolerance: ±1%
- C1 tolerance: ±20%
- Fixed 5.000 V supply
- Fixed 3.00 V triggering threshold

The resulting RC time constants ranged from approximately:

\[
7.86\text{ s}\leq\tau\leq12.02\text{ s}
\]

The corresponding threshold-crossing times ranged from approximately:

\[
7.20\text{ s}\leq t_{3V}\leq11.02\text{ s}
\]

These limits exceeded the hypothetical control requirement of triggering between 8.0 and 11.0 seconds.

Therefore, the nominal RC circuit could not guarantee compliance across the assumed component tolerances.

Potential improvements include tighter-tolerance components, calibration, or a digital timing system using a sufficiently accurate clock.

## Safety Considerations

- Arduino USB power was disconnected before rewiring.
- Capacitor polarity was checked before energizing the circuit.
- Capacitor voltage was measured before changing circuit components.
- A controlled resistor-discharge procedure was used when stored charge remained.
- The temporary discharge jumper was removed before reconnecting power.
- Resistor dissipation was checked against the assumed 0.25 W rating.
- The capacitor's 50 V rating exceeded the operating supply voltage.
- The final capacitor voltage was verified at 0.0 mV.

The capacitor was never intentionally subjected to reverse polarity.

## Engineering Conclusions

The capstone demonstrated that circuit loading affects both the transient and steady-state behavior of an RC timing network.

A high-input-resistance DMM introduced a relatively small modeled change to the circuit.

By comparison, a 9.95 kΩ load resistor dramatically reduced the effective time constant and lowered the capacitor's final voltage.

The loaded circuit settled quickly, but its steady-state voltage remained far below the 3.00 V detection threshold.

The central finding is:

**A faster RC response does not necessarily produce a valid timing signal. Circuit loading, threshold compatibility, component tolerances, and measurement limitations must all be considered when evaluating timing-system reliability.**

## Project Files

- [Predictions](predictions.md)
- [Measurements](measurements.md)
- [Troubleshooting](troubleshooting.md)
- [Safety](safety.md)
- [Circuit Photograph](photos/rc-loaded-circuit.jpeg)
- [Charging Demonstration](demo/rc-charging-demo.mp4)
- [Circuit A — DMM Loading Schematic](schematics/circuit-a.png)
- [Circuit B — Additional Resistive Loading Schematic](schematics/circuit-b.png)

The demonstration video captures approximately 42 seconds of the initial charging experiment. Subsequent measurements and the intentional-loading experiment were documented separately.

## Future Improvements

- Record capacitor voltage using an Arduino analog input or other suitably characterized acquisition system for higher-resolution transient measurements.
- Measure capacitor capacitance independently.
- Investigate supply regulation and capacitor leakage.
- Compare actual threshold-crossing times against tolerance-derived predictions.
- Evaluate buffered timing circuits or digital timers for improved reliability.
