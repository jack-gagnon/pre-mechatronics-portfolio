# Lab 02 — Pre-Power Predictions

**Course:** Mechatronics Preparatory Course  
**Session:** Week 01 · Thursday · Lab 02  
**Date:** November 12, 2026  
**Circuit:** R1 in series with (R2 ∥ R3)  
**Prediction status:** Recorded before first power-up

## Circuit and measured components

```text
Arduino 5V ── R1 (217.6 Ω) ──● Node A
                               ├── R2 (328 Ω) ──┐
                               └── R3 (992 Ω) ──┤
                                                └── Arduino GND
```

The intent is **R1 + (R2 ∥ R3)**: the only return path from Node A to ground passes through either R2 or R3.

| Component | Nominal | Individually measured |
|---|---:|---:|
| R1 | 220 Ω | 217.6 Ω |
| R2 | 330 Ω | 328 Ω |
| R3 | 1,000 Ω | 992 Ω |

**Supply assumption:** 5.00 V nominal. The actual USB-powered voltage is not yet known for this lab and may differ.

## Calculations

### Parallel equivalent resistance

\[
R_{23}=\frac{R_2R_3}{R_2+R_3}=\frac{328\times 992}{328+992}=246.49697\ \Omega
\]

### Total resistance

\[
R_T=R_1+R_{23}=217.6+246.49697=464.09697\ \Omega
\]

### Source current

\[
I_T=\frac{V_S}{R_T}=\frac{5.00}{464.09697}=0.01077361\ \mathrm{A}=10.77361\ \mathrm{mA}
\]

### Series resistor voltage drop

\[
V_{R1}=I_TR_1=0.01077361\times217.6=2.34434\ \mathrm{V}
\]

### Node A and parallel resistor voltages

\[
V_A=V_S-V_{R1}=5.00-2.34434=2.65566\ \mathrm{V}
\]

Since R2 and R3 share Node A and ground, \(V_{R2}=V_{R3}=V_A\).

### Branch currents

\[
I_2=\frac{V_A}{R_2}=\frac{2.65566}{328}=8.09653\ \mathrm{mA}
\]

\[
I_3=\frac{V_A}{R_3}=\frac{2.65566}{992}=2.67708\ \mathrm{mA}
\]

### KCL and KVL checks

- **KCL at Node A:** \(I_T=I_2+I_3=8.09653+2.67708\approx10.77361\ \mathrm{mA}\).
- **KVL, R1–R2 loop:** \(+5.00-2.34434-2.65566\approx0\ \mathrm{V}\).
- **KVL, R1–R3 loop:** \(+5.00-2.34434-2.65566\approx0\ \mathrm{V}\).

### Power conservation

\[
P_{R1}=I_T^2R_1=25.25698\ \mathrm{mW}
\]

\[
P_{R2}=I_2^2R_2=21.50165\ \mathrm{mW}
\]

\[
P_{R3}=I_3^2R_3=7.10942\ \mathrm{mW}
\]

\[
P_{source}=V_SI_T=53.86805\ \mathrm{mW}
\]

\(P_{R1}+P_{R2}+P_{R3}=53.86805\ \mathrm{mW}\) (subject to rounding).

## Summary: original pre-power predictions

| Quantity | Predicted value |
|---|---:|
| Nominal supply | 5.00 V |
| R2 ∥ R3 | 246.50 Ω |
| Total resistance | 464.10 Ω |
| Total source current, I_T | 10.774 mA |
| Drop across R1 | 2.344 V |
| Node A voltage relative to ground | 2.656 V |
| Drop across R2 | 2.656 V |
| Drop across R3 | 2.656 V |
| Branch current, I2 | 8.097 mA |
| Branch current, I3 | 2.677 mA |
| Power in R1 | 25.26 mW |
| Power in R2 | 21.50 mW |
| Power in R3 | 7.11 mW |
| Total source power | 53.87 mW |

## Unpowered verification (separate from predictions)

The assembled network was measured with the Arduino unpowered and disconnected for the resistance measurement:

| Quantity | Calculated from measured components | Measured at assembled network |
|---|---:|---:|
| Total resistance | 464.10 Ω | 465 Ω |

Percentage difference: \(100\times|465-464.09697|/464.09697=0.195\%\).

## Wiring reference

- R1: H50–H54
- R2: F54–F58
- R3: E54–E58
- Node A bridge: G54–D54
- Ground bridge: H58–D58
- Arduino 5V: J50
- Arduino GND: J58

## Safety / assumptions

- Keep the existing motor-control lab isolated and unpowered.
- Check wiring and resistor wattage ratings before energizing.
- All calculations here assume a 5.00 V ideal source. Do **not** overwrite these baseline predictions with post-power recalculations.
- A standard 0.25 W resistor would have sufficient rating at the calculated operating points, **if** the actual installed resistors are rated at least 0.25 W.
- Never place a current-configured meter directly across power rails.
