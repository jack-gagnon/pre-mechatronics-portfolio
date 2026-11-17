
# Troubleshooting Log — Precision DC Measurement and Instrument Loading

## Project Information

- Course: Mechatronics Preparatory Course
- Week: 2
- Session: Tuesday Lab 3
- Project: Precision DC Measurement and Instrument Loading

## 1. Unexpected Equipment or Wiring Problems

No unexpected hardware failures, wiring problems, or safety incidents
were reported during this experiment.

Both resistor networks were assembled and measured successfully.

The Arduino USB supply was disconnected before wiring changes and
resistance measurements.

## 2. Experimental Limitation — Instrument Loading

### Objective

Investigate the effect of voltmeter input resistance on the output
voltage of two resistor-divider networks.

### Expected Behavior

A real voltmeter has finite input resistance.

Connecting the meter across the lower resistor creates an additional
parallel current path, changing the effective lower resistance and
slightly reducing the output voltage.

The effect should be greater in the higher-resistance divider.

### Circuit A

Measured resistors:

- R1 = 217.9 ohms
- R2 = 328.3 ohms

Calculated Thevenin resistance:

Rth = 130.97 ohms

Specified DMM input resistance:

Rm = 10 megohms

Predicted loading error:

0.00131%

### Circuit B

Measured resistors:

- R3 = 99.2 kilohms
- R4 = 9.95 kilohms

Calculated Thevenin resistance:

Rth = 9,042.97 ohms

Specified DMM input resistance:

Rm = 10 megohms

Predicted loading error:

0.09035%

At the measured 4.45 V supply:

- Predicted unloaded output: 405.657 mV
- Predicted meter-loaded output: 405.291 mV
- Predicted loading disturbance: 0.367 mV

## 3. Measurement Observations

The initial Circuit B output reading was 405.6 mV.

Five subsequent readings were:

| Trial | Output Voltage |
|---|---:|
| 1 | 405.9 mV |
| 2 | 405.7 mV |
| 3 | 405.7 mV |
| 4 | 405.8 mV |
| 5 | 405.8 mV |

Calculated statistics:

- Arithmetic mean: 405.78 mV
- Minimum: 405.7 mV
- Maximum: 405.9 mV
- Range: 0.2 mV
- Sample standard deviation: approximately 0.0837 mV

The results demonstrated good short-term repeatability.

However, repeatability alone does not establish absolute accuracy.

## 4. Why the Loading Effect Was Not Independently Resolved

The DMM-8301S DC voltage input resistance is specified as
10 megohms.

Its published DC voltage accuracy is expressed as a percentage
of reading plus a number of display counts.

At approximately 405.6 mV, the calculated accuracy allowance
is about 2.53 mV when using a 0.1 mV display increment.

The predicted loading disturbance was only 0.367 mV.

Therefore, the predicted loading disturbance was substantially
smaller than the instrument's accuracy allowance.

The measured readings were consistent with the circuit model,
but the experiment did not independently establish the exact
magnitude of the loading effect.

## 5. Diagnostic Reasoning

The theoretical loading model is:

Vmeasured = Vth × Rmeter / (Rth + Rmeter)

The relative loading error is:

Loading error = Rth / (Rth + Rmeter)

Increasing the circuit's Thevenin resistance increases its
susceptibility to loading by a given meter.

Increasing the meter's input resistance reduces loading.

In this experiment, Circuit B was more susceptible to loading
than Circuit A, but its predicted disturbance remained too small
to verify conclusively with the available measurement setup.

## 6. Resolution and Auto-Ranging Observation

The DMM displayed 405.6 mV while operating in auto-ranging mode.

This was slightly above the nominal 400.0 mV range listed in
the published specifications.

The observed display was preserved exactly as reported.

The instrument's precise auto-ranging transition behavior was
not independently verified.

No equipment malfunction was inferred from this observation.

## 7. Corrective Approach for a Future Experiment

To make loading easier to observe experimentally:

1. Use a circuit with a greater Thevenin output resistance.
2. Calculate the expected loading effect before construction.
3. Compare the predicted disturbance with instrument resolution
   and accuracy limits.
4. Consider using a second instrument with different input
   resistance, if available.
5. Measure the supply during the experiment to account for
   source-voltage changes.
6. Avoid claiming a loading effect has been experimentally
   resolved when it is below the measurement capability.

No circuit modifications were made solely to amplify the
effect during this laboratory.

## 8. Engineering Conclusion

Both resistor networks operated consistently with circuit theory.

No unexpected hardware or wiring faults occurred.

The principal troubleshooting finding was a limitation of
the measurement method: the intended loading effect was too
small to distinguish confidently using the available DMM.

The experiment demonstrated the importance of evaluating
instrument capability before interpreting small voltage changes.

## 9. Final Status

- Hardware faults: None reported
- Wiring faults: None reported
- Safety incidents: None reported
- Experimental limitation: Identified and explained
- Improvement strategy: Documented
- Primary circuit measurements: Complete
- USB power: Disconnected after testing
a