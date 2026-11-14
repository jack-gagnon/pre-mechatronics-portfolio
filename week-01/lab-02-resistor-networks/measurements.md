
# Lab 02 — Series & Parallel Resistor Networks
## Experimental Measurements and Analysis

**Course:** Mechatronics Preparatory Course  
**Week:** 01 — Thursday  
**Date:** November 12, 2026  
**Experiment:** Series-Parallel DC Resistor Network  
**Status:** Electrical measurements completed; portfolio documentation in progress

---

## 1. Experiment Objective

Construct and analyze a mixed series-parallel DC resistor network using an Arduino Uno as the low-voltage power source.

Experimentally verify:

1. Ohm's Law
2. Kirchhoff's Voltage Law (KVL)
3. Kirchhoff's Current Law (KCL)
4. Equivalent resistance
5. Electrical power conservation

Compare theoretical predictions against physical measurements and calculate percentage differences.

---

## 2. Equipment

- Arduino Uno
- ELEGOO breadboard and jumper wires
- Commercial Electric DMM-8301S digital multimeter
- Alligator clip adapters
- Three resistors:
  - R1: 220 Ω nominal
  - R2: 330 Ω nominal
  - R3: 1 kΩ nominal
- USB power connection

---

## 3. Circuit Configuration

The circuit consists of R1 in series with the parallel combination of R2 and R3.

```text
Arduino 5V
     |
     |
 R1 = 217.6 Ω
     |
     ● Node A
     |
     +----------------+
     |                |
 R2 = 328 Ω      R3 = 992 Ω
     |                |
     +--------+-------+
              |
         Arduino GND
```

### Breadboard Connections

| Component     | Start       | End |
|---------------|-------------|-----|
| R1            | H50         | H54 |
| R2            | F54         | F58 |
| R3            | E54         | E58 |
| Node A jumper | G54         | D54 |
| Ground jumper | H58         | D58 |
| Supply jumper | Arduino 5V  | J50 |
| Ground jumper | Arduino GND | J58 |

The existing DC motor-control circuit remained unpowered and electrically isolated.

---

## 4. Individual Resistor Measurements

Resistance was measured before applying power.

| Resistor | Nominal | Measured | Deviation |
|---|---:|---:|---:|
| R1 | 220 Ω | 217.6 Ω | -1.09% |
| R2 | 330 Ω | 328 Ω | -0.61% |
| R3 | 1,000 Ω | 992 Ω | -0.80% |

Percentage deviation:

\[
\%\text{ deviation}
=
\frac{R_{\text{measured}}-R_{\text{nominal}}}
{R_{\text{nominal}}}
\times 100
\]

The measured resistance values were used in all subsequent theoretical calculations.

---

## 5. Equivalent Resistance Verification

### Parallel resistance

\[
R_{23}
=
\frac{R_2R_3}{R_2+R_3}
\]

\[
R_{23}
=
\frac{328(992)}{328+992}
\]

\[
R_{23}=246.497\ \Omega
\]

### Total resistance

\[
R_T=R_1+R_{23}
\]

\[
R_T=217.6+246.497
\]

\[
R_T=464.097\ \Omega
\]

### Experimental measurement

The fully assembled circuit was measured with the Arduino supply disconnected.

| Quantity | Predicted | Measured |
|---|---:|---:|
| Equivalent resistance | 464.10 Ω | 465 Ω |

Absolute difference:

\[
\Delta R=|465-464.097|=0.903\ \Omega
\]

Percentage difference:

\[
\%\text{ difference}
=
\frac{0.903}{464.097}\times100
\]

\[
\boxed{0.195\%}
\]

**Conclusion:** The assembled circuit's equivalent resistance closely matched the theoretical prediction.

---

## 6. Original Pre-Power Predictions

Initial calculations assumed an ideal 5.00 V supply.

| Quantity | Prediction |
|---|---:|
| Source voltage | 5.00 V |
| Equivalent resistance | 464.10 Ω |
| Total current | 10.774 mA |
| Voltage across R1 | 2.344 V |
| Node A voltage | 2.656 V |
| Current through R2 | 8.097 mA |
| Current through R3 | 2.677 mA |
| Total source power | 53.87 mW |

These predictions were recorded before energizing the circuit.

They were retained separately from the revised calculations using the measured supply voltage.

---

## 7. Actual Supply and Node Voltages

After energizing the circuit, the following voltages were measured:

| Measurement | Measured value |
|---|---:|
| Arduino 5V to GND | 4.460 V |
| Breadboard J50 to GND | 4.430 V |
| Node A (J54) to GND | 2.357 V |

### Supply-to-breadboard difference

\[
\Delta V=4.460-4.430
\]

\[
\Delta V=0.030\ \mathrm V
\]

Percentage difference relative to Arduino 5V:

\[
\frac{0.030}{4.460}\times100
=
0.673\%
\]

This small difference could be associated with connection resistance, supply variation, or measurement uncertainty.

Its precise cause was not established.

### R1 voltage derived from node measurements

\[
V_{R1}=V_{J50}-V_A
\]

\[
V_{R1}=4.430-2.357
\]

\[
V_{R1}=2.073\ \mathrm V
\]

---

## 8. Revised Predictions at 4.430 V

Because the actual breadboard supply voltage was lower than the original 5.00 V assumption, the expected current and voltage values were recalculated.

The measured component resistances remained unchanged.

### Total current

\[
I_T=\frac{4.430}{464.097}
\]

\[
I_T=9.545\ \mathrm{mA}
\]

### Voltage across R1

\[
V_{R1}=I_TR_1
\]

\[
V_{R1}\approx2.077\ \mathrm V
\]

### Node A voltage

\[
V_A=4.430-V_{R1}
\]

\[
V_A\approx2.353\ \mathrm V
\]

### Parallel branch currents

\[
I_2=\frac{V_A}{328}
\]

\[
I_2\approx7.173\ \mathrm{mA}
\]

\[
I_3=\frac{V_A}{992}
\]

\[
I_3\approx2.372\ \mathrm{mA}
\]

---

## 9. Direct Voltage Measurements

Voltage was measured directly across each resistor.

| Resistor | Red probe | Black probe | Measured voltage |
|---|---|---|---:|
| R1 | H50 | H54 | 2.081 V |
| R2 | F54 | F58 | 2.359 V |
| R3 | E54 | E58 | 2.357 V |

### Comparison with revised predictions

| Resistor | Predicted | Measured | Approx. difference |
|---|---:|---:|---:|
| R1 | 2.077 V | 2.081 V | 0.17% |
| R2 | 2.353 V | 2.359 V | 0.28% |
| R3 | 2.353 V | 2.357 V | 0.19% |

Percentage difference is calculated using:

\[
\%\text{ difference}
=
\frac{|\text{Measured}-\text{Predicted}|}
{|\text{Predicted}|}
\times100
\]

The independently measured component voltages closely matched the revised theoretical predictions.

---

## 10. Kirchhoff's Voltage Law Verification

KVL states that the algebraic sum of voltage rises and drops around a closed loop is zero.

### Loop 1 — R1 and R2

\[
V_S-V_{R1}-V_{R2}=0
\]

Substituting measured values:

\[
4.430-2.081-2.359
=
-0.010\ \mathrm V
\]

**Loop 1 residual: -10 mV**

### Loop 2 — R1 and R3

\[
V_S-V_{R1}-V_{R3}=0
\]

\[
4.430-2.081-2.357
=
-0.008\ \mathrm V
\]

**Loop 2 residual: -8 mV**

### Results

| Loop | Ideal residual | Measured residual |
|---|---:|---:|
| R1 + R2 | 0 V | -0.010 V |
| R1 + R3 | 0 V | -0.008 V |

The small residuals are consistent with measurement uncertainty and possible supply fluctuations between readings.

**Conclusion:** Both independently measured voltage loops provide strong experimental support for KVL.

---

## 11. Direct Current Measurements

The multimeter was inserted in series with each measured circuit path.

Power was disconnected before every wiring modification.

| Current | Predicted at 4.430 V | Measured | Approx. difference |
|---|---:|---:|---:|
| Total current (R1) | 9.545 mA | 9.41 mA | 1.42% |
| R2 branch current | 7.173 mA | 7.04 mA | 1.86% |
| R3 branch current | 2.372 mA | 2.34 mA | 1.34% |

### Total-current measurement

The ammeter replaced the supply jumper between Arduino 5V and J50.

Measured:

\[
I_T=9.41\ \mathrm{mA}
\]

### R2 current measurement

R2's upper lead was temporarily lifted from F54.

The meter was inserted in series between Node A and the lifted R2 lead.

Measured:

\[
I_2=7.04\ \mathrm{mA}
\]

### R3 current measurement

R2 was restored to its original position.

R3's upper lead was lifted from E54, and the meter was inserted in series with R3.

Measured:

\[
I_3=2.34\ \mathrm{mA}
\]

The USB supply was disconnected after each measurement.

---

## 12. Kirchhoff's Current Law Verification

KCL states that the sum of currents entering a node equals the sum of currents leaving that node.

At Node A:

\[
I_T=I_2+I_3
\]

### Measured incoming current

\[
I_T=9.41\ \mathrm{mA}
\]

### Measured outgoing current

\[
I_2+I_3=7.04+2.34
\]

\[
I_2+I_3=9.38\ \mathrm{mA}
\]

### Current residual

\[
\Delta I=I_T-(I_2+I_3)
\]

\[
\Delta I=9.41-9.38
\]

\[
\boxed{\Delta I=0.03\ \mathrm{mA}}
\]

### Percentage imbalance

\[
\%\text{ imbalance}
=
\frac{|\Delta I|}{I_T}\times100
\]

\[
\frac{0.03}{9.41}\times100
=
\boxed{0.319\%}
\]

### Experimental result

| Quantity | Measured |
|---|---:|
| Current entering Node A | 9.41 mA |
| Sum of currents leaving Node A | 9.38 mA |
| Residual | 0.03 mA |
| Percentage imbalance | 0.319% |

**Conclusion:** The measured currents provide strong experimental support for KCL.

The small residual may reflect the multimeter's burden voltage, supply variations, measurement uncertainty, or contact resistance. These measurements were performed sequentially rather than simultaneously.

---

## 13. Theoretical Power Calculations

Using the revised 4.430 V supply assumption:

\[
P=VI
\]

Equivalently, for each resistor:

\[
P=I^2R
\]

Theoretical component-power estimates:

| Component | Predicted power        |
| --------- | ---------------------- |
| R1        | Approximately 19.83 mW |
| R2        | Approximately 16.88 mW |
| R3        | Approximately 5.58 mW  |
| Total     | Approximately 42.29 mW |

### Source power

\[
P_S=V_SI_T
\]

\[
P_S=4.430(0.009545)
\]

\[
\boxed{P_S\approx42.29\ \mathrm{mW}}
\]

The sum of predicted resistor dissipation matches predicted source power, as required by energy conservation.

---

## 14. Experimental Power Estimates

Experimental resistor power was estimated by multiplying the independently measured resistor voltages and currents.

### R1

\[
P_{R1}=2.081(0.00941)
\]

\[
\boxed{P_{R1}=19.582\ \mathrm{mW}}
\]

### R2

\[
P_{R2}=2.359(0.00704)
\]

\[
\boxed{P_{R2}=16.607\ \mathrm{mW}}
\]

### R3

\[
P_{R3}=2.357(0.00234)
\]

\[
\boxed{P_{R3}=5.515\ \mathrm{mW}}
\]

### Total estimated resistor power

\[
P_R=19.582+16.607+5.515
\]

\[
\boxed{P_R\approx41.705\ \mathrm{mW}}
\]

### Estimated source power

Using the earlier measured J50 supply voltage and total current:

\[
P_S=4.430(0.00941)
\]

\[
\boxed{P_S\approx41.686\ \mathrm{mW}}
\]

### Difference

\[
P_S-P_R\approx-0.019\ \mathrm{mW}
\]

The small discrepancy is approximately 0.045% of the estimated source power.

**Important limitation:** Voltage and current measurements were taken sequentially and in different meter configurations. Therefore, the calculated experimental powers are estimates rather than simultaneous measurements of an unchanged circuit.

The measurements are consistent with power conservation, but the numerical agreement should not be interpreted as proof of 0.045% measurement accuracy.

---

## 15. Summary of Experimental Results

| Verification          | Experimental result                        |
| --------------------- | ------------------------------------------ |
| Equivalent resistance | 0.195% difference                          |
| R1 voltage drop       | Close agreement with prediction            |
| R2 voltage drop       | Close agreement with prediction            |
| R3 voltage drop       | Close agreement with prediction            |
| KVL Loop 1            | -10 mV residual                            |
| KVL Loop 2            | -8 mV residual                             |
| Total current         | Approximately 1.42% difference             |
| R2 current            | Approximately 1.86% difference             |
| R3 current            | Approximately 1.34% difference             |
| KCL at Node A         | 0.319% imbalance                           |
| Power conservation    | Consistent within experimental limitations |

---

## 16. Experimental Observations

1. The actual Arduino supply voltage was lower than the nominal 5.00 V value used for the initial predictions.

2. The measured voltage at Arduino 5V was 4.460 V, while the measured input voltage at breadboard I50 was 4.430 V.

3. Recalculating theoretical values using the measured breadboard supply voltage improved agreement with the experimental results.

4. The measured parallel-branch voltages were nearly identical, as expected for resistors connected between the same two nodes.

5. The larger branch current flowed through the lower-resistance resistor R2.

6. The experimentally measured branch currents summed to within 0.03 mA of the independently measured total current.

7. The resistance, voltage, current, and power results were consistent with the expected behavior of a mixed series-parallel resistor network.

---

## 17. Measurement Limitations

Potential sources of uncertainty include:

- Multimeter accuracy and resolution
- USB supply-voltage variation
- Jumper and breadboard contact resistance
- Ammeter burden voltage
- Resistance measurement uncertainty
- Small temperature-dependent resistance changes
- Sequential rather than simultaneous measurements
- Changes to circuit connections between current measurements

The precise contribution of each source was not determined.

---

## 18. Final Experimental Conclusion

The mixed series-parallel resistor network was successfully constructed and tested.

The measured equivalent resistance closely matched the theoretical value.

Independent voltage measurements produced KVL residuals of -10 mV and -8 mV.

Independent current measurements produced a KCL residual of 0.03 mA, corresponding to a 0.319% imbalance.

Theoretical and experimental power calculations were consistent with electrical energy conservation, within the limitations of sequential measurements.

**Overall result:** The experiment provides strong physical verification of Ohm's Law, Kirchhoff's Voltage Law, Kirchhoff's Current Law, and the expected behavior of series-parallel resistive networks.

---

## 19. Circuit Restoration

After completing the measurements:

- R1 remained connected between H50 and H54.
- R2 was restored between F54 and F58.
- R3 was restored between E54 and E58.
- The Node A jumper remained connected between G54 and D54.
- The ground jumper remained connected between H58 and D58.
- The normal Arduino supply and ground jumpers were restored.
- The multimeter was removed from the circuit.
- Arduino USB power was disconnected.

**Final circuit state: Restored and unpowered.**

---

## 20. Portfolio Status

Electrical testing: **Complete**

Remaining project documentation:

- Confirm `measurements.md` saved locally.
- Finalize and commit schematic image.
- Create commented Arduino sketch / pin map.
- Complete `troubleshooting.md`.
- Complete `safety.md`.
- Capture demonstration evidence.
- Commit and push all project files to GitHub.

GitHub publication has not yet been verified.