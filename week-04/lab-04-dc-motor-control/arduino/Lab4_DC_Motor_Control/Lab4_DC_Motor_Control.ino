/*
  Lab 4 — Arduino + L293D DC Motor Control
  Portfolio version | Serial-controlled, time-limited tests

  Arduino Uno       L293D (notch facing top, straddling breadboard trench)
  D9 (PWM)          pin 1  / E5  (Enable 1,2; jumper C5)
  D7                pin 2  / E6  (Input 1; jumper C6)
  D8                pin 7  / E11 (Input 2; jumper C11)
  External 5V       pin 16 / F5  (VCC1; jumper H5)
  External 5V       pin 8  / E12 (VCC2; jumper A12)
  Shared GND        pins 4,5,12,13 (E8,E9,F9,F8)
  Motor red         pin 3  / E7  (Output 1; jumper A7)
  Motor black       pin 6  / E10 (Output 2; jumper A10)

  Arduino power: USB. Motor driver power: separately regulated 5V.
  Their GNDs MUST be connected. Do NOT connect external 5V to Arduino 5V.
  Only run with driver correctly powered, and motor/fan secured.

  Serial Monitor: 115200 baud; newline setting may be Any.
  f/r = select forward/reverse (names relative to motor wiring)
  1/2/3/4 = select ~25/~50/~75/100% duty
  g = run ONE timed pulse (3 seconds maximum)
  s = stop immediately (software stop; physical power switch for emergency)
  ? = show help and current settings

  Notes: PWM duty cycle changes average motor drive; not a direct RPM setting.
  A low duty cycle does not guarantee low instantaneous stall current.
*/

const byte MOTOR_ENABLE = 9;
const byte MOTOR_IN1 = 7;
const byte MOTOR_IN2 = 8;
const unsigned long MAX_RUN_MS = 3000UL;

byte selectedPWM = 128;            // Starts at ~50%; motor still OFF
bool forwardSelected = true;
bool motorRunning = false;
unsigned long startedAtMs = 0;

void stopMotor() {
  analogWrite(MOTOR_ENABLE, 0);    // Disable bridge before changing inputs
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, LOW);
  motorRunning = false;
}

void printStatus() {
  Serial.print(F("Direction: "));
  Serial.print(forwardSelected ? F("forward") : F("reverse"));
  Serial.print(F(" | PWM: "));
  Serial.print(selectedPWM);
  Serial.print(F("/255 | Motor: "));
  Serial.println(motorRunning ? F("RUNNING") : F("STOPPED"));
}

void printHelp() {
  Serial.println(F("\nLab 4 | L293D motor control"));
  Serial.println(F("f: forward  r: reverse"));
  Serial.println(F("1: 25%  2: 50%  3: 75%  4: 100%"));
  Serial.println(F("g: run once, up to 3 seconds"));
  Serial.println(F("s: stop  ?: help/status"));
  printStatus();
}

void startPulse() {
  // Call only after both supplies are on and the fan is clear.
  if (motorRunning) {
    Serial.println(F("Already running; send s to stop."));
    return;
  }
  stopMotor();
  digitalWrite(MOTOR_IN1, forwardSelected ? HIGH : LOW);
  digitalWrite(MOTOR_IN2, forwardSelected ? LOW : HIGH);
  startedAtMs = millis();
  analogWrite(MOTOR_ENABLE, selectedPWM);
  motorRunning = true;
  Serial.println(F("Motor pulse started (max 3 seconds)."));
}

void setup() {
  // Set output latches LOW before changing from INPUT to OUTPUT.
  digitalWrite(MOTOR_ENABLE, LOW);
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, LOW);
  pinMode(MOTOR_ENABLE, OUTPUT);
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  stopMotor();
  Serial.begin(115200);
  printHelp();
}

void loop() {
  // Nonblocking timeout: Serial stop commands stay responsive.
  if (motorRunning && (millis() - startedAtMs >= MAX_RUN_MS)) {
    stopMotor();
    Serial.println(F("Pulse finished; motor disabled."));
  }

  while (Serial.available() > 0) {
    char command = (char)Serial.read();
    if (command == '\n' || command == '\r' || command == ' ') continue;
    if (command >= 'A' && command <= 'Z') command += ('a' - 'A');

    if (command == 's') {
      stopMotor();
      Serial.println(F("STOP command: motor disabled."));
    } else if (command == '?') {
      printHelp();
    } else if (motorRunning) {
      Serial.println(F("Motor active; stop before changing settings."));
    } else {
      switch (command) {
        case 'f': forwardSelected = true; break;
        case 'r': forwardSelected = false; break;
        case '1': selectedPWM = 64;  break;
        case '2': selectedPWM = 128; break;
        case '3': selectedPWM = 191; break;
        case '4': selectedPWM = 255; break;
        case 'g': startPulse();     break;
        default: Serial.println(F("Unknown command; send ? for help.")); continue;
      }
      printStatus();
    }
  }
}
