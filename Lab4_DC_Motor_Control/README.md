# Arduino DC Motor Control | L293D H-Bridge + PWM

**Pre-Mechatronics — Lab 4** · ELEGOO UNO R3 starter kit · Hands-on laboratory and portfolio project

## Project overview

Built and measured an Arduino-controlled brushed DC motor circuit using an L293D H-bridge and a separately regulated 5V supply. Demonstrated motor enable/disable, electronic direction reversal, and variable-speed PWM operation. Logged voltage measurements to compare commanded duty cycle with the DC multimeter's motor-terminal readings.

**Demonstrated outcomes:** Motor rotated in both commanded directions; motor terminal polarity changed from **+3.39V** (forward) to **−3.39V** (reverse) without swapping motor leads. PWM increased apparent speed. The motor supply measured **5.00V at standby** and **4.94V** during a short **75% PWM** run.

## Hardware

- Arduino Uno R3, powered from computer USB
- L293D dual H-bridge IC, first channel used
- ELEGOO Power MB V2 module, independently powered by a 9V DC center-positive adapter
- Kit's 3–6V brushed DC motor and fan blade
- Breadboard, jumpers, DMM and clip adapters

The motor-driver logic supply and motor supply were both connected to the **power module's regulated 5V output**, with a common ground to the Arduino. **Do not connect the module's 9V input directly to the motor, or feed its regulated 5V output into the Arduino 5V pin.** Supply current rating is not a substitute for checking actual motor current and thermal limits.

## Wiring

![Logical motor-control wiring](docs/wiring-diagram.svg)

| Arduino / supply | L293D pin | Breadboard position | Role |
|---|---|---|---|
| Arduino D9 | 1 | E5, jumper C5 | Enable / PWM |
| Arduino D7 | 2 | E6, jumper C6 | Direction input 1 |
| Arduino D8 | 7 | E11, jumper C11 | Direction input 2 |
| Power MB V2 +5V | 16 | F5, jumper H5 | Logic supply VCC1 |
| Power MB V2 +5V | 8 | E12, jumper A12 | Motor supply VCC2 |
| Common ground (module and Arduino) | 4, 5, 12, 13 | E8, E9, F9, F8 | L293D ground pins |
| Motor red | 3 | E7, jumper A7 | Motor output 1 |
| Motor black | 6 | E10, jumper A10 | Motor output 2 |

**Reference:** IC notch faces breadboard row 5; IC spans E5–E12 and F5–F12 across the trench. This is a *logical wiring diagram*, not a to-scale breadboard layout. Confirm orientation and available holes before wiring.

## Recorded experiments

### H-bridge direction reversal

| Direction command | D7 (IN1) | D8 (IN2) | Voltage from motor red lead to black lead |
|---|---|---|---:|
| Forward | HIGH | LOW | +3.39 V |
| Reverse | LOW | HIGH | −3.39 V |

Changing direction inputs inverted the motor-terminal polarity without rewiring the motor. The original fan rotation direction was difficult to judge visually, which motivated this electrical verification.

### PWM and observed rotation

| `analogWrite` | Duty cycle (approx.) | DMM motor-terminal reading | Observation |
|---:|---:|---:|---|
| 64 | 25% | +0.364 V | Barely rotating during voltage test |
| 128 | 50% | +1.74 V | Moderate rotation |
| 191 | 75% | +2.50 V | Noticeably faster than 50% |
| 255 | 100% | +3.39 V | Fastest observed |

**Interpretation:** Commanded duty cycle correlated with higher displayed terminal voltage and greater apparent rotation speed. These are **DC multimeter readings of a switched, inductive motor load**, not direct measurements of PWM pulse amplitude, true cycle-averaged voltage, RPM, or mechanical output power. Results across test runs may depend on the motor's speed, load, settling time, and meter characteristics. The +3.39 V 100% datum comes from a separate forward-direction experiment.

### Supply regulation during short PWM test

| Condition | VCC2-to-GND reading |
|---|---:|
| Motor stopped | 5.00 V |
| Motor running at 75% PWM | 4.94 V |
| Observed voltage reduction | 0.06 V (1.2%) |

This short test indicates reasonably stable measured supply voltage *during the sample*, but **does not establish startup-current peaks, motor stall current, continuous-load performance, or regulator thermal margins**.

Raw entries are provided in [`data/measurements.csv`](data/measurements.csv).

## Portfolio sketch (new, not yet hardware-tested)

Source: [`arduino/Lab4_DC_Motor_Control/Lab4_DC_Motor_Control.ino`](arduino/Lab4_DC_Motor_Control/Lab4_DC_Motor_Control.ino).

The portfolio version replaces repeated edits and uploads with explicit commands using Arduino IDE **Serial Monitor at 115200 baud**. The motor **never starts automatically on reset**. Set the direction and duty, then send `g` to start one *maximum three-second* pulse. Send `s` to stop during the pulse. Changing speed or direction is disabled while the motor is running.

| Serial command | Action |
|---|---|
| `f` / `r` | Select forward or reverse |
| `1` / `2` / `3` / `4` | Select ~25% / ~50% / ~75% / 100% duty |
| `g` | Start one timed pulse (max 3 seconds) |
| `s` | Stop immediately in software |
| `?` | Help and current status |

**Important:** This refactored sketch is a *next-stage implementation*, not the exact code that generated the measurements above. Compile and validate it separately before claiming its operation as a tested outcome. Software stop and the three-second timeout are **not emergency-stop safety hardware**. Use the power switch/disconnect as the physical means of de-energizing the motor, and keep the test setup secured.

### Suggested validation procedure

1. Disconnect both supplies. Disconnect Arduino D7, D8, D9 from the unpowered L293D before uploading; leave their breadboard ends installed.
2. Upload the new sketch from the Arduino IDE with the driver supply disconnected, then remove USB.
3. Restore D7/D8/D9 with power off; verify all grounds and motor connections.
4. Reconnect Arduino USB; open Serial Monitor at 115200 and confirm the motor stays off at startup.
5. Power on the separate 5V motor supply, confirm standby. Select direction and duty; issue `g` once. Observe the motor and verify it disables within three seconds; test `s` separately.
6. Power down and disconnect the circuit before moving measurement leads or rewiring.

## Troubleshooting and engineering lessons

- **Unstable readings:** Damaged/loose alligator clip adapters caused uncertain contact; replaced them before proceeding with powered measurements.
- **Arduino 5V rail:** Earlier computer USB supply measured ~4.43–4.46 V at the Uno 5V pin. A 9V barrel-jack adapter yielded ~5.02 V at the Uno 5V pin, but powering the motor through the onboard 5V regulator was avoided.
- **Driver output voltage loss:** At 100% duty, motor terminals measured ±3.39 V with a nominal 5 V supply. The L293D's bipolar output stage can drop significant voltage. This is not an exact driver-drop measurement because supply voltage and motor voltage were not sampled simultaneously under the same conditions.
- **25% duty cycle:** The fan barely rotated in the three-second measurement test, illustrating startup torque and load sensitivity. The original short speed test described slow rotation.
- **Motor resistance:** Initial disconnected winding readings depended on rotor position; poor probe contact also caused erratic readings. Winding resistance alone does not determine motor's rated voltage.

## Next improvements

- Validate the new serial-controlled sketch on the assembled circuit.
- Measure actual motor speed with an optical or encoder-based method; compare RPM vs. duty cycle.
- Measure motor current safely with a suitable measurement method and characterize loaded voltage at multiple duty cycles.
- Add a labeled photograph of the finished circuit and a fully verified breadboard diagram.

## Safety

This is an educational, low-voltage demonstration, not a production motor controller. Keep USB and external module power disconnected for rewiring; never measure resistance or continuity on an energized circuit; never place a multimeter in current mode across supply or motor outputs. Secure fan blades, clips, and jumpers. Disconnect immediately for unexpected heating, dimming, smoke, or uncontrolled movement.
