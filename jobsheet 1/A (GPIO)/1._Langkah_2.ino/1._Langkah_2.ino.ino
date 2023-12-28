// Job 1 A(Langkah 2)
// Rani, Ayum, Alfan

const int ledPin = 5; // Pin untuk LED
unsigned long previousMillis = 0; 
const long interval = 1000;  // interval waktu (1 detik)

void setup() {
  pinMode(ledPin, OUTPUT);  // mengatur pin LED sebagai OUTPUT
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // simpan waktu saat ini
    previousMillis = currentMillis;

    // baca status LED, jika LED menyala maka matikan, dan sebaliknya
    if (digitalRead(ledPin) == LOW) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
  }
}
