# ESP32 Capacitive Touch Sensor
Melakukan ujicoba kontrol LED pada ESP32 menggunakan input berupa sentuhan. Terdapat 5 percobaan yang dilakukan, diantaranya:

## 1. Membaca data input yang berupa sentuhan

### Alat dan Bahan
- ESP32 (1 buah)
- Kabel jumper (secukupnya)

### Hasil dan Pembahasan

Program ini adalah contoh penggunaan fitur *touch* pada ESP32. Fitur ini memungkinkan ESP32 membaca nilai dari sensor sentuh yang terhubung ke pin tertentu. Fungsi yang digunakan untuk membuat sensor ini adalah `touchRead()`. Nilai input tersebut akan ditampilkan pada Serial Monitor. Berikut analisis singkat dari program:

**A. Setup Komunikasi Serial:**

```cpp
Serial.begin(115200); // komunikasi ini akan digunakan untuk membaca data lewat `serial monitor`
delay(1000);
```
   - Baudrate serial diatur pada 115200 bps.
   - Terdapat delay sebesar 1000 ms untuk memberikan waktu ESP32 untuk stabil.

**B. Loop:**

```cpp
Serial.println(touchRead(4));
delay(1000);
```
   - Pada setiap iterasi, nilai dari input berupa sentuhan yang terhubung ke pin GPIO 4 dibaca menggunakan fungsi `touchRead(4)`.
   - Nilai tersebut kemudian ditampilkan melalui Serial Monitor.
   - Terdapat delay 1000 ms untuk memberikan interval waktu antar pembacaan.

Jika tidak terdapat input yang terbaca, maka garis pada grafik akan naik. Sedangkan jika terdapat sentuhan, maka garis akan turun ke level tertentu. Fungsi touchRead() sendiri memiliki nilai analog yang berkisar antara 0 hingga 1023. Angka tersebut akan direpresentasikan sesuai dengan grafik pada serial monitor.

### Kesimpulan
Variasi nilai yang ditampilkan menunjukkan level sentuhan pada sensor. Perlu dipahami bahwa nilai yang dibaca dari sensor sentuh bersifat relatif dan dapat bervariasi, hal ini bisa disebabkan oleh faktor lingkungan atau alat dan komponen yang digunakan.

## 2. Menyalakan LED dengan sensor sentuh

### Alat dan Bahan
- ESP32 (1 buah)
- Kabel jumper (secukupnya)
- Resistor 220 Ohm (1 buah)
- Lampu LED (1 buah)

### Hasil dan Pembahasan

Percobaan ini adalah pengembangan dari percobaan sebelumnya, dimana nilai inputan sensor sentuh dimanfaatkan untuk menyalakan atau mematikan LED. Berikut analisis singkat dari program yang digunakan:

**A. Pengaturan Pin:**

```cpp
const int touchPin = 4;
const int ledPin = 16;
```
   - `touchPin` diatur ke GPIO4, yang merupakan pin sensor sentuh.
   - `ledPin` diatur ke GPIO16, yang merupakan pin untuk mengendalikan LED.

**B. Setup():**

```cpp
pinMode(ledPin, OUTPUT);
Serial.begin(115200);
delay(1000);
```
   - `ledPin` diinisialisasi sebagai output.
   - Komunikasi serial diatur pada baudrate 115200.
   - Terdapat delay awal 1000 ms untuk memastikan kestabilan ESP32.

**C. Loop():**

```cpp
touchValue = touchRead(touchPin); // memasukkan nilai input (sentuhan) ke variabel baru
Serial.print(touchValue);
delay(500);

if (touchValue == 0) {
  digitalWrite (ledPin, HIGH);
} else {
  digitalWrite (ledPin, LOW);
}
delay(1000);
```
   - Nilai dari sensor sentuh (`touchValue`) dibaca menggunakan fungsi `touchRead(touchPin)`.
   - Nilai tersebut ditampilkan pada Serial Monitor.
   - Jika sensor sentuh mendeteksi sentuhan (nilai sama dengan 0), maka LED akan menyala.
   - Jika sensor sentuh tidak mendeteksi sentuhan (nilai tidak sama dengan 0), maka LED akan mati.

### Kesimpulan
Untuk menyalakan LED dibutuhkan nilai acuan untuk penanda dimana LED akan menyala dan LED akan mati. Karena fungsi dari touchread sendiri memiliki nilai analog (0 - 1023).

## 3. Membuat Blink LED dengan sensor sentuh

### Alat dan Bahan
- ESP32 (1 buah)
- Kabel jumper (secukupnya)
- Resistor 220 Ohm (1 buah)
- Lampu LED (1 buah)

### Hasil dan Pembahasan

Percobaan ini adalah pengembangan dari percobaan sebelumnya, dimana nilai inputan sensor sentuh dimanfaatkan untuk menyalakan LED (Blink) atau mematikan LED. Berikut analisis singkat dari program yang digunakan:

**A. Pengaturan Pin:**

```cpp
const int touchPin = 4;
const int ledPin = 16;
```
   - `touchPin` diatur ke GPIO4, yang merupakan pin sensor sentuh.
   - `ledPin` diatur ke GPIO16, yang merupakan pin untuk mengendalikan LED.

**B. Setup():**

```cpp
pinMode(ledPin, OUTPUT);
Serial.begin(115200);
delay(1000);
```
   - `ledPin` diinisialisasi sebagai output.
   - Komunikasi serial diatur pada baudrate 115200.
   - Terdapat delay awal 1000 ms untuk memastikan kestabilan ESP32.

**C. Loop():**

```cpp
touchValue = touchRead(touchPin); // memasukkan nilai input (sentuhan) ke variabel baru
Serial.print(touchValue);
delay(500);

if (touchValue <= 30) {
  digitalWrite (ledPin, HIGH);
  delay(1000);
  digitalWrite (ledPin, LOW);
  delay(1000);
} else {
  digitalWrite (ledPin, LOW);
}
delay(1000);
```
   - Nilai dari sensor sentuh (`touchValue`) dibaca menggunakan fungsi `touchRead(touchPin)`.
   - Nilai tersebut ditampilkan pada Serial Monitor.
   - Jika sensor sentuh mendeteksi sentuhan (nilai kurang dari sama dengan 30), maka LED akan menyala (Blink).
   - Jika sensor sentuh tidak mendeteksi sentuhan (nilai lebih dari 30), maka LED akan mati.

### Kesimpulan
Berbeda dengan program sebelumnya, program kali ini lebih sensitif. Hal ini disebabkan nilai acuannya ditingkatkan menjadi 30 (analog), sehingga pembacaan sentuhan pada sensor akan lebih akurat dan cepat.

## 4. Menghitung jumlah sentuhan

### Alat dan Bahan
- ESP32 (1 buah)
- Kabel jumper (secukupnya)
- Resistor 220 Ohm (1 buah)
- Lampu LED (1 buah)

### Hasil dan Pembahasan

Percobaan ini adalah pengembangan dari percobaan sebelumnya, dimana nilai inputan sensor sentuh dimanfaatkan untuk menampilkan jumlah sentuhan pada layar serial monitor. Untuk itu terdapat beberapa perubahan pada program, berikut analisis singkat dari program yang digunakan:

**A. Pengaturan Pin:**

```cpp
const int ledPin = 16;
const int touchPin = 4;
int touchValue = 0; 
```
   - `touchPin` diatur ke GPIO4, yang merupakan pin sensor sentuh.
   - `ledPin` diatur ke GPIO16, yang merupakan pin untuk mengendalikan LED.
   - `touchValue` digunakan sebagai variabel untuk menghitung atau *Counter* jumlah sentuhan.

**B. Setup():**

```cpp
pinMode(ledPin, OUTPUT);
Serial.begin(115200);
```
   - `ledPin` diinisialisasi sebagai output.
   - Komunikasi serial diatur pada baudrate 115200.

**C. Loop():**

```cpp
touchValue = touchRead(touchPin); // memasukkan nilai input (sentuhan) ke variabel baru
Serial.print(touchValue);
delay(500);

if (touchRead(touchPin) <= 30) {
    touchValue++; // Menambah touchValue ketika sensor disentuh
    digitalWrite(ledPin, HIGH); // Nyalakan LED ketika sensor disentuh
    delay(1000); // Tahan LED selama 1 detik
    digitalWrite(ledPin, LOW); // Matikan LED
    delay(1000); // Tunggu selama 1 detik
  }

  Serial.println("jumlah sentuhan = " + String(touchValue)); // Tampilkan touchValue di Serial Monitor
  delay(500);
```
   - Jika sensor sentuh (`touchPin`) mendeteksi sentuhan, maka program akan melakukan beberapa tindakan:
     - Menambah nilai `touchValue` sebanyak 1.
     - Menyalakan LED (`ledPin`).
     - Menampilkan informasi sentuhan ke Serial Monitor.
     - Menunggu 500 ms untuk menghindari deteksi berulang.
   - Jika sensor sentuh tidak mendeteksi sentuhan, maka LED dimatikan.
     
### Kesimpulan
Untuk menambahkan sebuah nilai variable dapat dilakukan dengan increment (++), salah satu contoh pemanfaatannya adalah pada program *Counter*

## 5. Menyalakan running LED dengan sentuhan

### Alat dan Bahan
- ESP32 (1 buah)
- Kabel jumper (secukupnya)
- Resistor 220 Ohm (3 buah)
- Lampu LED (3 buah)

### Hasil dan Pembahasan

Percobaan ini adalah pengembangan dari percobaan sebelumnya, dimana nilai inputan sensor sentuh dimanfaatkan untuk menyalakan LED (Running) atau mematikan LED. Berikut analisis singkat dari program yang digunakan:

**A. Pengaturan Pin:**

```cpp
const int ledPin = 16;
const int ledPin1 = 18;
const int ledPin2 = 19;
const int touchPin = 4;
const int numLED = 3;
const int pinLED[numLED] = {16,18,19};
int touchValue = 0;
```
   - `touchPin` diatur ke GPIO4, yang merupakan pin sensor sentuh.
   - `ledPin` diatur ke GPIO16, 18, dan 19, yang merupakan pin untuk mengendalikan LED 1, 2, dan 3.
   - 'pinLed' digunakan untuk menambahkan ketiga LED kedalam sebuah array.

**B. Setup():**

```cpp
Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin1, OUTPUT); // LED kedua
  pinMode(ledPin2, OUTPUT); // LED ketiga
  for(int i=0; i<3; i++){
   pinMode(pinLED[i], OUTPUT);
  }
```
   - `ledPin` dan 'pinLED' diinisialisasi sebagai output.
   - Komunikasi serial diatur pada baudrate 115200.

**C. Loop():**

```cpp
if (touchRead(touchPin) <= 30) {
    touchValue++; // Menambah touchValue ketika sensor disentuh
    for (int i = 0; i < 3; i++) { // pengulangan tindakan pada ketiga LED
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
```
   - Jika sensor sentuh (`touchPin`) mendeteksi sentuhan, maka program akan melakukan beberapa tindakan:
     - Melakukan looping for untuk menyalakan LED (Running):
       - Ketika nilai i = 0 (iterasi for pertama), menyalakan dan mematikan LED pertama.
       - Ketika nilai i = 1 (iterasi for kedua), menyalakan dan mematikan LED kedua.
       - Ketika nilai i = 2 (iterasi for ketiga), menyalakan dan mematikan LED ketiga.
   - Jika sensor sentuh tidak mendeteksi sentuhan, maka semua LED tidak akan menyala.
   - Menampilkan jumlah sentuhan terbaru (jika ada)

### Kesimpulan
Selain diimplementasikan untuk membuat blink LED, touchRead() juga dapat dikembangkan untuk membuat rangkaian running LED.
