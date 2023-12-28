// Job 2-A 5
// Rani, Ayum, Alfan

// ESP32 Touch Test - Initialize touchValue to 0 and increment when touchPin is touched
// Just test touch pin - Touch0 is T0 which is on GPIO 4.
const int ledPin = 16;
const int ledPin1 = 18;
const int ledPin2 = 19;
const int touchPin = 4;
const int numLED = 3;
const int pinLED[numLED] = {16, 18, 19};
int touchValue = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin1, OUTPUT); // LED kedua
  pinMode(ledPin2, OUTPUT); // LED ketiga
  for (int i = 0; i < 3; i++) {
    pinMode(pinLED[i], OUTPUT);
  }
}

void loop() {
  if (touchRead(touchPin) <= 30) {
    touchValue++; // Menambah touchValue ketika sensor disentuh
    for (int i = 0; i < 3; i++) {
      digitalWrite(pinLED[i], HIGH);
      delay(500);
      digitalWrite(pinLED[i], LOW);
    }
  } else {
    // matikan LED
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  }

  Serial.println("jumlah sentuhan = " + String(touchValue)); // Tampilkan touchValue di Serial Monitor
  delay(500);
}
