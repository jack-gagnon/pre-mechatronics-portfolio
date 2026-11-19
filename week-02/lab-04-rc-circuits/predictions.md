# Lab 4 — RC Charging and Discharging: Predictions

**Course:** Mechatronics Preparatory Course  
**Week:** 2  
**Lab:** 4  
**Date:** November 19, 2026  
**Topic:** RC Transients, Measurement Uncertainty, and Instrument Loading

## 1. Purpose

This document records the theoretical calculations used to plan and evaluate the RC charging and discharging experiment.

The experiment investigates:

1. RC time constants.
2. Capacitor charging behavior.
3. Capacitor discharging behavior.
4. Resistor current and power.
5. Capacitor energy storage.
6. Digital multimeter loading.
7. The effect of actual supply voltage.
8. The influence of circuit switching and isolation.

The original theoretical predictions are distinguished from calculations made after experimental measurements became available.

## 2. Component Specifications

| Parameter | Value |
|---|---|
| Charging resistor R1 | 99.2 kΩ |
| Auxiliary discharge resistor R2 | 9.95 kΩ |
| Resistor power ratings | 0.25 W |
| Capacitor C1 | 100 µF |
| Capacitor voltage rating | 50 V |
| Capacitor type | Polarized electrolytic |
| Nominal Arduino supply | 5 V |
| Nominal DMM input resistance | 10 MΩ |
| Multimeter | Commercial Electric DMM-8301S |

The capacitor's negative polarity marking was identified before installation.

All component assembly was performed with Arduino USB disconnected.

## 3. Ideal RC Time Constant

The time constant of a series RC circuit is:

\[
\tau=RC
\]

Converting component values:

\[
R=99.2\text{ kΩ}=99,200\text{ Ω}
\]

\[
C=100\text{ µF}=100\times10^{-6}\text{ F}
\]

Therefore:

\[
\tau=(99,200)(100\times10^{-6})
\]

\[
\boxed{\tau_{\text{ideal}}=9.920\text{ s}}
\]

After one time constant, an initially discharged capacitor should reach approximately 63.2% of its final charging voltage.

After one discharge time constant, approximately 36.8% of its initial voltage should remain.

## 4. Ideal Charging Model

For a capacitor initially at zero volts:

\[
V_C(t)=V_S(1-e^{-t/RC})
\]

Using the nominal 5 V supply:

\[
V_C(t)=5(1-e^{-t/9.920})
\]

### Original Nominal Charging Predictions

| Time constant | Elapsed time (s) | Predicted voltage (V) |
|---|---:|---:|
| 0τ | 0.00 | 0.000 |
| 1τ | 9.92 | 3.161 |
| 2τ | 19.84 | 4.323 |
| 3τ | 29.76 | 4.751 |
| 4τ | 39.68 | 4.908 |
| 5τ | 49.60 | 4.966 |

These calculations assume:

- An ideal 5.000 V source.
- A capacitor with exactly 100 µF capacitance.
- A resistor with exactly 99.2 kΩ resistance.
- No instrument loading.
- No capacitor leakage.
- An initially discharged capacitor.

## 5. Initial Charging Current

At the beginning of charging:

\[
V_C(0)=0
\]

The full source voltage is initially across the charging resistor.

By Ohm's Law:

\[
I_0=\frac{V_S}{R}
\]

\[
I_0=\frac{5}{99,200}
\]

\[
\boxed{I_0\approx50.4\text{ µA}}
\]

As the capacitor charges, its voltage rises and the resistor voltage decreases.

Therefore, charging current decreases over time.

For the ideal circuit:

\[
I(t)=\frac{V_S}{R}e^{-t/RC}
\]

## 6. Maximum Charging Resistor Power

Maximum charging-resistor dissipation occurs at the beginning of charging.

\[
P_{\max}=\frac{V_S^2}{R}
\]

\[
P_{\max}=\frac{25}{99,200}
\]

\[
\boxed{P_{\max}\approx0.252\text{ mW}}
\]

The resistor is rated for 250 mW.

Percentage of rating:

\[
\frac{0.252}{250}\times100\approx0.10\%
\]

The predicted dissipation is substantially below the verified rating.

## 7. Maximum Capacitor Charge

Capacitor charge is:

\[
Q=CV
\]

At the nominal 5 V supply:

\[
Q=(100\times10^{-6})(5)
\]

\[
\boxed{Q=500\text{ µC}}
\]

This is the ideal stored charge at 5 V.

Actual stored charge depends on the capacitor's voltage and actual capacitance.

## 8. Maximum Capacitor Energy

The energy stored in a capacitor is:

\[
E=\frac12CV^2
\]

At 5 V:

\[
E=\frac12(100\times10^{-6})(5^2)
\]

\[
\boxed{E=1.25\text{ mJ}}
\]

The capacitor voltage rating is 50 V, exceeding the intended operating voltage.

The capacitor must still be treated as potentially charged after power removal.

## 9. Digital Multimeter Loading

An ideal voltmeter has infinite input resistance.

A real DMM has finite input resistance.

The selected DMM was modeled using a nominal input resistance of:

\[
R_M=10\text{ MΩ}
\]

When measuring capacitor voltage, the DMM is connected in parallel with the capacitor.

The equivalent resistance relevant to the transient response is:

\[
R_{\text{effective}}=R_1\parallel R_M
\]

\[
R_{\text{effective}}=
\frac{R_1R_M}{R_1+R_M}
\]

Substituting:

\[
R_{\text{effective}}=
\frac{(99,200)(10,000,000)}{99,200+10,000,000}
\]

\[
\boxed{R_{\text{effective}}\approx98.225\text{ kΩ}}
\]

### Meter-Loaded Time Constant

\[
\tau_{\text{loaded}}=R_{\text{effective}}C
\]

\[
\tau_{\text{loaded}}=
(98,225)(100\times10^{-6})
\]

\[
\boxed{\tau_{\text{loaded}}\approx9.823\text{ s}}
\]

The nominal meter loading reduces the time constant slightly relative to the ideal 9.920 s.

## 10. Meter-Loaded Charging Model

The DMM provides an additional path from the capacitor's positive node to ground.

Therefore, the steady-state capacitor voltage is determined by a voltage divider:

\[
V_\infty=V_S\frac{R_M}{R_1+R_M}
\]

Using nominal component values:

\[
V_\infty=
V_S\frac{10,000,000}{10,099,200}
\]

\[
\boxed{V_\infty\approx0.99018V_S}
\]

For a nominal 5.000 V supply:

\[
\boxed{V_\infty\approx4.951\text{ V}}
\]

The meter-loaded charging equation is:

\[
\boxed{
V_C(t)=V_\infty(1-e^{-t/\tau_{\text{loaded}}})
}
\]

This model accounts for the nominal DMM input resistance but does not account for capacitor leakage or other nonideal effects.

## 11. Supply-Adjusted Charging Calculations

An independent supply measurement performed during the laboratory indicated:

\[
4.45\text{ V}\leq V_S\leq4.46\text{ V}
\]

For calculation purposes, the midpoint was used:

\[
V_S=\frac{4.45+4.46}{2}
\]

\[
\boxed{V_S\approx4.455\text{ V}}
\]

This measurement was not taken simultaneously with the timed charging run.

Consequently, the adjusted calculations assume similar supply conditions during that run.

### Predicted Steady-State Voltage

\[
V_\infty=4.455(0.99018)
\]

\[
\boxed{V_\infty\approx4.411\text{ V}}
\]

### Adjusted Charging Equation

\[
\boxed{
V_C(t)\approx4.411(1-e^{-t/9.823})
}
\]

### Supply-Adjusted Predictions

| Elapsed time (s) | Approximate predicted voltage (V) |
|---:|---:|
| 0 | 0.000 |
| 10 | 2.818 |
| 20 | 3.835 |
| 30 | 4.203 |
| 40 | 4.336 |
| 50 | 4.384 |
| 60 | 4.401 |

These calculations were used to evaluate the recorded charging measurements.

## 12. Auxiliary Discharge Resistor

The initial controlled-discharge procedure used a separate resistor:

\[
R_2=9.95\text{ kΩ}
\]

With a nominal 100 µF capacitor:

\[
\tau=R_2C
\]

\[
\tau=(9,950)(100\times10^{-6})
\]

\[
\boxed{\tau\approx0.995\text{ s}}
\]

At a maximum capacitor voltage of 5 V:

\[
I_0=\frac{5}{9,950}
\]

\[
\boxed{I_0\approx0.503\text{ mA}}
\]

The maximum initial resistor power is:

\[
P_{\max}=\frac{25}{9,950}
\]

\[
\boxed{P_{\max}\approx2.51\text{ mW}}
\]

This is below the resistor's 250 mW rating.

The auxiliary resistor was used for controlled discharge and safety verification, not for the final timed discharge dataset.

## 13. Revised Pushbutton-Controlled Circuit

A normally-open pushbutton was introduced after the initial experiment revealed that removing USB power did not reliably preserve the capacitor's charge.

### Final Charging Connections

| Connection | Breadboard location |
|---|---|
| Pushbutton | E43, F43, E45, F45 |
| Positive supply input | D43 |
| Switch output jumper | D45–J50 |
| R1 | H50–H54 |
| Capacitor positive | F54 |
| Capacitor negative | F56 |
| Ground input | J56 |

When pressed, the pushbutton connected the supply to R1.

When released, the pushbutton interrupted the positive charging path.

### Final Discharge Connection

The timed discharge used a temporary jumper between:

**I50 and H56**

With the pushbutton released, this connected R1 across the capacitor.

The USB supply remained disconnected during discharge.

## 14. Final Timed Discharge Model

For a capacitor discharging through R1 with the DMM connected:

\[
V_C(t)=V_0e^{-t/\tau_{\text{loaded}}}
\]

Using the predicted time constant:

\[
\tau_{\text{loaded}}\approx9.823\text{ s}
\]

the general prediction is:

\[
\boxed{
V_C(t)=V_0e^{-t/9.823}
}
\]

The initial discharge voltage must be measured at the moment the discharge path is connected.

## 15. Post-Measurement Discharge Calculations

**Important:** This section uses the experimentally observed initial voltage. These calculations are retrospective model comparisons, not independent predictions made before the test.

Video review established that the discharge jumper was connected at timestamp:

**1:14 (74 seconds)**

The measured capacitor voltage at that event was:

\[
\boxed{V_0=2.355\text{ V}}
\]

The corresponding theoretical model is:

\[
\boxed{
V_C(t)=2.355e^{-t/9.823}
}
\]

### Predicted Discharge Voltages

| Discharge time (s) | Approximate predicted voltage (V) |
|---:|---:|
| 0 | 2.355 |
| 10 | 0.851 |
| 20 | 0.307 |
| 30 | 0.111 |
| 40 | 0.0402 |
| 50 | 0.0145 |
| 60 | 0.0052 |

The measured discharge results are documented in `measurements.md`.

## 16. Experimental Time-Constant Estimation

The exponential discharge equation can be rearranged:

\[
V_C(t)=V_0e^{-t/\tau}
\]

Dividing by the initial voltage:

\[
\frac{V_C(t)}{V_0}=e^{-t/\tau}
\]

Taking natural logarithms:

\[
\ln\left(\frac{V_C(t)}{V_0}\right)
=-\frac{t}{\tau}
\]

Solving:

\[
\boxed{
\tau=-\frac{t}{\ln(V_C(t)/V_0)}
}
\]

This equation allows an experimental estimate of the time constant from measured voltage and elapsed time.

Using the verified discharge data at 30 seconds:

\[
V_0=2.355\text{ V}
\]

\[
V_C(30)=0.1115\text{ V}
\]

\[
\tau=-\frac{30}{\ln(0.1115/2.355)}
\]

\[
\boxed{\tau_{\text{experimental}}\approx9.83\text{ s}}
\]

This single-point estimate agrees closely with the predicted meter-loaded time constant.

Other observations produce somewhat different estimates, especially at low voltages.

Therefore, the supported overall conclusion is that the measured discharge time constant was near 10 seconds.

## 17. Measurement Uncertainty

Potential sources of uncertainty included:

- Actual capacitor capacitance.
- Capacitor leakage current.
- DMM input resistance.
- DMM voltage accuracy and resolution.
- DMM autoranging.
- Manual measurement timing.
- Video frame selection.
- Supply-voltage variation.
- Jumper and switch contact conditions.

The theoretical calculations use nominal capacitor and meter parameters.

The experimental results should not be interpreted as establishing exact component values.

## 18. Prediction Summary

| Parameter | Theoretical value |
|---|---:|
| Ideal RC time constant | 9.920 s |
| DMM-loaded time constant | Approximately 9.823 s |
| Initial charging current at 5 V | Approximately 50.4 µA |
| Maximum R1 power at 5 V | Approximately 0.252 mW |
| Maximum capacitor charge at 5 V | 500 µC |
| Maximum capacitor energy at 5 V | 1.25 mJ |
| Meter-loaded final voltage at 5 V | Approximately 4.951 V |
| Meter-loaded final voltage at 4.455 V | Approximately 4.411 V |
| Auxiliary discharge time constant | Approximately 0.995 s |

## 19. Conclusion

The theoretical analysis predicted a charging and discharging time constant near 10 seconds for the selected resistor-capacitor network.

The DMM's finite input resistance was expected to reduce the effective time constant slightly.

Experimental measurements showed a gradual charging response and a discharge curve consistent with a first-order exponential model.

The corrected discharge analysis supported a time constant near the predicted value.

The laboratory reinforced the importance of:

1. Using actual measured component and supply values.
2. Accounting for instrument loading.
3. Establishing the correct experimental time origin.
4. Separating original predictions from retrospective calculations.
5. Verifying capacitor isolation and controlled discharge.