// Job 2-B 2
// Rani, Ayum, Alfan

#include <DHT.h>
#define DHT_PIN 4   // Pin yang digunakan untuk sensor suhu DHT
#define LED_PIN 5   // Pin yang digunakan untuk LED Merah
#define BUZZER_PIN 18 // Pin yang digunakan untuk Buzzer

DHT dht(DHT_PIN, DHT11); // Inisialisasi sensor DHT

void setup() {
  pinMode(LED_PIN, OUTPUT);     // Mengatur pin LED sebagai OUTPUT
  pinMode(BUZZER_PIN, OUTPUT); // Mengatur pin Buzzer sebagai OUTPUT

  Serial.begin(9600);
  dht.begin(); // Memulai sensor DHT
}

void loop() {
  float temperature = dht.readTemperature(); // Membaca suhu dari sensor DHT

  if (isnan(temperature)) {
    Serial.println(F("Gagal membaca suhu"));
    return;
  }

  Serial.print("Suhu: ");
  Serial.print(temperature);
  Serial.println(" °C");

  if (temperature >= 30.0) {
    digitalWrite(LED_PIN, HIGH);     // Menyalakan LED Merah
    tone(BUZZER_PIN, 1000, 100);      // Memainkan nada dengan frekuensi 1000Hz selama 100ms (beep)
    delay(100); // Memberi jeda agar buzzer bisa berbunyi dengan interval
  } else {
    digitalWrite(LED_PIN, LOW); // Mematikan LED Merah
    noTone(BUZZER_PIN);          // Mematikan Buzzer
  }

  delay(100); // Memberi jeda selama 100 ms sebelum membaca suhu lagi
}
