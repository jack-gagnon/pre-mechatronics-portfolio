# Capstone 01 — Pre-Power Electrical Predictions

**Course:** Mechatronics Preparatory Course
**Week:** 01 — Friday
**Date:** November 13, 2026
**Student:** Jack Gagnon
**Experiment:** Voltage Divider Design & Fault Diagnosis

---

## 1. Objective

Calculate the expected electrical behavior of an unloaded
and loaded voltage divider before applying power.

The experiment will investigate:

1. Ohm's law
2. Series and parallel resistance
3. Voltage division
4. Current division
5. Kirchhoff's Current Law (KCL)
6. Kirchhoff's Voltage Law (KVL)
7. Electrical power conservation
8. The effects of circuit loading

All initial predictions assume a nominal 5.00 V DC supply.

Actual measurements will be recorded separately.

---

## 2. Equipment

- Arduino Uno
- ELEGOO breadboard
- Jumper wires
- Commercial Electric DMM-8301S
- Alligator clip adapters
- R1: 220 Ω nominal
- R2: 330 Ω nominal
- R3: 1 kΩ nominal

### Measured Component Values

| Component | Nominal | Measured | Deviation |
|---|---:|---:|---:|
| R1 | 220 Ω | 217.8 Ω | -1.00% |
| R2 | 330 Ω | 328.2 Ω | -0.55% |
| R3 | 1000 Ω | 992 Ω | -0.80% |

These resistance measurements were performed with
the components disconnected from power.

The measured values will be used for all predictions.

---

# PART A — UNLOADED VOLTAGE DIVIDER

## 3. Circuit Configuration

R1 and R2 are connected in series.

```text
Arduino 5V
    |
    |
 R1 = 217.8 Ω
    |
    ● Node A (Vout)
    |
 R2 = 328.2 Ω
    |
    |
Arduino GND
```

The output voltage is measured between Node A and GND.

R3 is not connected in this configuration.

---

## 4. Equivalent Resistance

For two resistors in series:

Rtotal = R1 + R2

Substitute:

Rtotal = 217.8 + 328.2

**Predicted equivalent resistance:**

Rtotal = 546.00 Ω

---

## 5. Total Circuit Current

Using Ohm's law:

I = V / R

I = 5.00 / 546.00

I = 0.00915751 A

**Predicted current:**

I = 9.158 mA

Because R1 and R2 are connected in series,
the same current flows through both resistors.

---

## 6. Voltage Across R1

Using Ohm's law:

V_R1 = I × R1

V_R1 = 0.00915751 × 217.8

**Predicted R1 voltage:**

V_R1 = 1.9945 V

---

## 7. Output Voltage

Using Kirchhoff's Voltage Law:

Vs - V_R1 - Vout = 0

Rearrange:

Vout = Vs - V_R1

Vout = 5.00 - 1.9945

**Predicted unloaded output voltage:**

Vout = 3.0055 V

### Independent Voltage-Divider Verification

Vout = Vs × (R2 / (R1 + R2))

Vout = 5.00 × (328.2 / 546.00)

Vout = 3.0055 V

Both methods agree.

---

## 8. Power Calculations

### R1 Power

P_R1 = I² × R1

P_R1 = (0.00915751)² × 217.8

P_R1 = 0.018265 W

**R1 power = 18.265 mW**

### R2 Power

P_R2 = I² × R2

P_R2 = (0.00915751)² × 328.2

P_R2 = 0.027523 W

**R2 power = 27.523 mW**

### Source Power

P_source = Vs × I

P_source = 5.00 × 0.00915751

**Source power = 45.788 mW**

### Power Conservation

P_R1 + P_R2 = P_source

18.265 + 27.523 = 45.788 mW

Power conservation is satisfied within rounding.

---

## 9. Unloaded Prediction Summary

| Quantity | Predicted |
|---|---:|
| Source voltage | 5.00 V |
| Total resistance | 546.00 Ω |
| Total current | 9.158 mA |
| Voltage across R1 | 1.995 V |
| Voltage across R2 | 3.005 V |
| Node A voltage | 3.005 V |
| R1 power | 18.265 mW |
| R2 power | 27.523 mW |
| Total source power | 45.788 mW |

---

# PART B — LOADED VOLTAGE DIVIDER

## 10. Circuit Configuration

R3 is connected in parallel with R2.

```text
Arduino 5V
    |
    |
 R1 = 217.8 Ω
    |
    ● Node A (Vout)
    |
    +----------------+
    |                |
 R2 = 328.2 Ω   R3 = 992 Ω
    |                |
    +--------+-------+
             |
        Arduino GND
```

The output voltage remains measured between
Node A and GND.

---

## 11. Parallel Equivalent Resistance

Rparallel = (R2 × R3) / (R2 + R3)

Rparallel = (328.2 × 992) / (328.2 + 992)

**Predicted parallel resistance:**

Rparallel = 246.610 Ω

---

## 12. Total Equivalent Resistance

Rtotal = R1 + Rparallel

Rtotal = 217.8 + 246.610

**Predicted total resistance:**

Rtotal = 464.410 Ω

---

## 13. Total Circuit Current

I_total = Vs / Rtotal

I_total = 5.00 / 464.410

I_total = 0.01076635 A

**Predicted total current:**

I_total = 10.766 mA

---

## 14. Voltage Across R1

V_R1 = I_total × R1

V_R1 = 0.01076635 × 217.8

**Predicted R1 voltage:**

V_R1 = 2.3449 V

---

## 15. Loaded Output Voltage

Using KVL:

Vs - V_R1 - Vout = 0

Vout = Vs - V_R1

Vout = 5.00 - 2.3449

**Predicted loaded output voltage:**

Vout = 2.6551 V

Because R2 and R3 are connected in parallel:

V_R2 = V_R3 = Vout

---

## 16. Branch Currents

### Current Through R2

I_R2 = Vout / R2

I_R2 = 2.6551 / 328.2

**Predicted R2 current:**

I_R2 = 8.090 mA

### Current Through R3

I_R3 = Vout / R3

I_R3 = 2.6551 / 992

**Predicted R3 current:**

I_R3 = 2.677 mA

---

## 17. Kirchhoff's Current Law

At Node A:

I_total = I_R2 + I_R3

Using unrounded values:

10.76635 mA ≈ 8.08985 mA + 2.67650 mA

**KCL is satisfied within rounding.**

---

## 18. Kirchhoff's Voltage Law

### Loop 1 — R1 and R2

Vs - V_R1 - V_R2 = 0

5.00 - 2.3449 - 2.6551 = 0

### Loop 2 — R1 and R3

Vs - V_R1 - V_R3 = 0

5.00 - 2.3449 - 2.6551 = 0

**Both loops satisfy KVL within rounding.**

---

## 19. Loaded Circuit Power

### R1

P_R1 = I_total² × R1

**P_R1 = 25.246 mW**

### R2

P_R2 = I_R2² × R2

**P_R2 = 21.479 mW**

### R3

P_R3 = I_R3² × R3

**P_R3 = 7.106 mW**

### Total Source Power

P_source = Vs × I_total

P_source = 5.00 × 0.01076635

**P_source = 53.832 mW**

### Power Conservation

P_R1 + P_R2 + P_R3 = P_source

25.246 + 21.479 + 7.106 ≈ 53.832 mW

Power conservation is satisfied within rounding.

---

## 20. Loaded Prediction Summary

| Quantity | Predicted |
|---|---:|
| Source voltage | 5.00 V |
| Parallel resistance | 246.610 Ω |
| Total resistance | 464.410 Ω |
| Total current | 10.766 mA |
| R1 voltage | 2.345 V |
| Node A voltage | 2.655 V |
| R2 current | 8.090 mA |
| R3 current | 2.677 mA |
| R1 power | 25.246 mW |
| R2 power | 21.479 mW |
| R3 power | 7.106 mW |
| Total source power | 53.832 mW |

---

# PART C — LOADING COMPARISON

## 21. Unloaded Versus Loaded

| Quantity | Unloaded | Loaded |
|---|---:|---:|
| Equivalent resistance | 546.00 Ω | 464.41 Ω |
| Source current | 9.158 mA | 10.766 mA |
| R1 voltage | 1.995 V | 2.345 V |
| Output voltage | 3.005 V | 2.655 V |
| Source power | 45.788 mW | 53.832 mW |

### Predicted Output Voltage Change

Delta Vout = Vout_unloaded - Vout_loaded

Delta Vout = 3.0055 - 2.6551

**Predicted output reduction = 0.3504 V**

### Percentage Reduction

Percentage reduction =
(Delta Vout / Vout_unloaded) × 100

= (0.3504 / 3.0055) × 100

**Predicted output reduction ≈ 11.66%**

---

## 22. Engineering Interpretation

Connecting R3 in parallel with R2 reduces the
equivalent resistance of the lower divider branch.

The total circuit resistance decreases.

At constant supply voltage, the total source current
increases.

Because R1 carries the total current, its voltage
drop increases.

Kirchhoff's Voltage Law therefore requires the
remaining output voltage to decrease.

This demonstrates voltage-divider loading.

---

# PART D — PRE-POWER SAFETY

## 23. Predicted Operating Limits

The largest calculated resistor dissipation in
the two configurations is approximately 27.523 mW.

If each resistor has a verified power rating of
0.25 W or greater, the predicted operation is
below that rating.

However, resistor wattage ratings have not yet
been confirmed.

**Power-up is NOT authorized until the actual
component power ratings and wiring are verified.**

Additional precautions:

1. Use only low-voltage DC.
2. Disconnect Arduino USB before changing wiring.
3. Keep unrelated motor-control circuitry isolated.
4. Inspect breadboard connections for shorts.
5. Measure voltage in parallel.
6. Measure current only in series.
7. Never connect an ammeter directly across
   Arduino 5V and GND.

---

## 24. Measurement Plan

After the pre-power inspection is approved:

### Configuration A

- Measure actual source voltage.
- Measure unloaded Vout.
- Measure R1 and R2 voltage drops.
- Compare results with predictions.

### Configuration B

- Disconnect power.
- Add R3 in parallel with R2.
- Inspect connections.
- Measure actual source voltage.
- Measure loaded Vout.
- Measure resistor voltage drops.
- Measure branch currents if required.
- Verify KCL and KVL.

The original nominal 5.00 V predictions will
be preserved.

Revised predictions based on measured supply
voltage will be documented separately.

---

## 25. Pre-Power Documentation Status

- [x] Actual resistor values measured
- [x] Unloaded predictions calculated
- [x] Loaded predictions calculated
- [x] KCL and KVL predictions calculated
- [x] Power calculations completed
- [ ] Resistor wattage ratings verified
- [ ] Schematic saved
- [ ] Physical circuit constructed
- [ ] Pre-power wiring inspection passed
- [ ] Power-up authorized

**Experiment status: Unpowered — awaiting safety verification.**