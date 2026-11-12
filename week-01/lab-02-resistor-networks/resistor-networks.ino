
/*
 * Mechatronics Preparatory Course
 * Week 01 — Thursday Lab 02
 * Series & Parallel Resistor Networks
 *
 * Date: November 12, 2026
 *
 * PURPOSE
 * -------
 * Verify Ohm's Law, Kirchhoff's Voltage Law (KVL),
 * Kirchhoff's Current Law (KCL), and power conservation.
 *
 * CIRCUIT
 * -------
 *
 * Arduino 5V
 *     |
 *   R1 = 217.6 ohms (measured)
 *     |
 *     +---- R2 = 328 ohms ----+
 *     |                      |
 *     +---- R3 = 992 ohms ----+
 *                            |
 *                       Arduino GND
 *
 * BREADBOARD PIN MAP
 * ------------------
 * Arduino 5V -> J50
 * R1: H50 -> H54
 * R2: F54 -> F58
 * R3: E54 -> E58
 * Node A bridge: G54 -> D54
 * Ground bridge: H58 -> D58
 * Arduino GND -> J58
 *
 * ARDUINO PIN USAGE
 * -----------------
 * 5V: DC power supply
 * GND: Circuit return
 *
 * Digital pins: Not used
 * Analog pins: Not used
 * PWM outputs: Not used
 *
 * IMPORTANT
 * ---------
 * The Arduino's nominal 5V output was measured
 * at approximately 4.46 V during the experiment.
 *
 * No software-controlled outputs are required.
 * This sketch intentionally leaves all GPIO pins
 * in their default input state.
 *
 * Disconnect USB power before changing wiring.
 */

void setup() {
  // No pin configuration required.
  // The experiment uses only Arduino 5V and GND.
}

void loop() {
  // No software-controlled operation required.
}
