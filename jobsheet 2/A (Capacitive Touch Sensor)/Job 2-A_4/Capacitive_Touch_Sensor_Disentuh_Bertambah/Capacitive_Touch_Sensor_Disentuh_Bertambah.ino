// Job 2-A 4
// Rani, Ayum, Alfan

// ESP32 Touch Test - Initialize touchValue to 0 and increment when touchPin is touched
// Just test touch pin - Touch0 is T0 which is on GPIO 4.
const int ledPin = 16;
const int touchPin = 4;
int touchValue = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (touchRead(touchPin) <= 30) {
    touchValue++; // Menambah touchValue ketika sensor disentuh
    digitalWrite(ledPin, HIGH); // Nyalakan LED ketika sensor disentuh
    delay(1000); // Tahan LED selama 1 detik
    digitalWrite(ledPin, LOW); // Matikan LED
    delay(1000); // Tunggu selama 1 detik
  }

  Serial.println("jumlah sentuhan = " + String(touchValue)); // Tampilkan touchValue di Serial Monitor
  delay(500);
}
