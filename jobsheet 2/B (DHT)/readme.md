# Mengakses Sensor DHT11
Melakukan ujicoba menggunakan sensor suhu dan kelembaban (DHT11) pada ESP32. Terdapat 2 percobaan yang dilakukan, diantaranya:

## 1. Membaca data suhu dan kelembaban ruangan

### Alat dan Bahan
- ESP32 (1 buah)
- Kabel jumper (secukupnya)
- DHT11 (1 buah)
- Resistor 10 kOhm (1 buah)

### Hasil dan Pembahasan

Program ini menggunakan sensor DHT11 untuk membaca suhu dan kelembapan. Berikut adalah penjelasan programnya:

**A. Inisialisasi Pin dan Tipe Sensor:**

```cpp
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
```
   - `DHTPIN` didefinisikan sebagai pin digital (GPIO) yang terhubung ke sensor DHT.
   - Tipe sensor DHT dipilih dengan mendefinisikan `DHTTYPE`. Untuk contoh ini, dipilih tipe DHT11, tetapi dapat diubah menjadi DHT22 atau DHT21 jika diperlukan.
   - Menambahkan juga library DHT pada awal program.
   - Untuk type dari DHT menggunakan DHT11

**B. Setup():**

```cpp
void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT11 Embedded System Test!"));
  dht.begin();
}
```
   - Komunikasi serial diatur pada baudrate 9600.
   - Pesan selamat datang ditampilkan di Serial Monitor.
   - Komunikasi dengan sensor DHT dimulai menggunakan `dht.begin()`.

**C. Loop():**

```cpp
  delay(2000); // jeda pembacaan data
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
```
   - Terdapat jeda waktu 2 detik (`delay(2000)`) antara pembacaan suhu dan kelembapan.
   - Pembacaan suhu dan kelembapan dilakukan menggunakan fungsi `dht.readTemperature()` dan `dht.readHumidity()`.
   - Hasil pembacaan dicek menggunakan `isnan()` untuk memastikan data yang valid, `isnan` merupakan fungsi untuk menentukan apakah variabel tersebut tidak memiliki nilai atau sebaliknya.
     - Jika `isnan()` bernilai true, maka akan muncul "Failed to read from DHT sensor" pada serial monitor.
     - Jika `isnan()` bernilai false, maka data akan muncul data kelembaban, suhu, dan heat index pada serial monitor.
   - Heat index dihitung baik dalam Fahrenheit maupun Celsius menggunakan fungsi `dht.computeHeatIndex()`.

### Kesimpulan
Sensor DHT11 dapat digunakan untuk mengetahui kondisi suhu (°C) dan kelembapan (%) di lingkungan sekitar serta dapat mengetahui indeks panas ruangan dalam derajat celcius maupun fahrenheit.

## 2. Menyalakan LED dan Buzzer menggunakan DHT11

### Alat dan Bahan
- ESP32 (1 buah)
- Kabel jumper (secukupnya)
- Resistor 10 kOhm (1 buah)
- DHT11 (1 buah)
- Resistor 220 Ohm (1 buah)
- Lampu LED (1 buah)

### Hasil dan Pembahasan

Program ini merupakan pengembangan dari percobaan sebelumnya, dimana sensor DHT11 akan digunakan untuk membaca suhu dan kelembapan, dan berdasarkan nilai suhu tertentu, akan mengendalikan LED dan buzzer (alat elektronik yang akan mengeluarkan suara jika diberi tegangan listrik). Berikut adalah pengembangan dari program sebelumnya:

**A. Inisialisasi Pin dan Tipe Sensor:**

```cpp
#include <DHT.h>
#define DHT_PIN 4   // Pin yang digunakan untuk sensor suhu DHT
#define LED_PIN 5   // Pin yang digunakan untuk LED Merah
#define BUZZER_PIN 18 // Pin yang digunakan untuk Buzzer

DHT dht(DHT_PIN, DHT11); // Inisialisasi sensor DHT

```
   - LED akan dikendalikan oleh pin 5 sedangkan buzzer akan dikendalikan oleh in 18 oleh ESP32.
   - Pembacaan suhu dan kelembapan menggunakan sensor DHT11 seperti pada program sebelumnya.

**B. Setup():**

```cpp
void setup() {
  pinMode(LED_PIN, OUTPUT);     // Mengatur pin LED sebagai OUTPUT
  pinMode(BUZZER_PIN, OUTPUT); // Mengatur pin Buzzer sebagai OUTPUT

  Serial.begin(9600);
  dht.begin(); // Memulai sensor DHT
}
```
   - Komunikasi serial diatur pada baudrate 9600.
   - Inisialisasi LED dan buzzer sebagai output.
   - Memulai komunikasi dengan sensor DHT.

**C. Loop():**

```cpp
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

  delay(100);
```
   - Pembacaan suhu dan kelembapan dilakukan seperti pada program sebelumnya.
   - Jika pembacaan suhu gagal, pesan kesalahan akan ditampilkan.
   - Jika suhu melebihi atau sama dengan 30°C, maka lampu LED dan buzzer akan menyala.
   - Jika suhu dibawah 30°C, maka lampu LED dan buzzer akan mati.

### Kesimpulan

Sensor DHT11 juga dapat dikembangkan agar dapat mengkontrol LED dan buzzer.
