/*
  Project: Week 1 Friday Capstone
  Title: Voltage Divider Design and Fault Diagnosis

  HARDWARE PIN MAP
  ----------------
  Arduino 5V  -> Breadboard J50
  Arduino GND -> Breadboard J58

  R1: H50 to H54 (217.8 ohms measured)
  R2: F54 to F58 (328.2 ohms measured)
  R3: E54 to E58 (992 ohms measured)

  Parallel-branch bridges:
  G54 -> D54
  H58 -> D58

  Output node: I54
  Ground reference: I58

  No digital I/O pins are used.

  IMPORTANT:
  The Arduino supplies power only.
  All voltage and resistance measurements were
  performed using an external digital multimeter.

  SAFETY:
  Never measure resistance with circuit power applied.
  Never connect a current-mode meter across 5V and GND.
  Disconnect USB before changing breadboard connections.
*/

void setup() {
  Serial.begin(9600);

  Serial.println(F("Week 1 Friday Capstone"));
  Serial.println(F("Voltage Divider and Fault Diagnosis"));
  Serial.println();

  Serial.println(F("Circuit: R1 + (R2 || R3)"));
  Serial.println(F("Arduino 5V -> J50"));
  Serial.println(F("Arduino GND -> J58"));
  Serial.println(F("Vout measurement: I54 to I58"));
  Serial.println();

  Serial.println(F("Measured component resistances:"));
  Serial.println(F("R1: 217.8 ohms"));
  Serial.println(F("R2: 328.2 ohms"));
  Serial.println(F("R3: 992 ohms"));
  Serial.println();

  Serial.println(F("Use an external DMM for measurements."));
  Serial.println(F("Serial output is documentation, not live telemetry."));
}

void loop() {
  // No automated measurements or control operations.
}