# ADC dan DAC
Merupakan `Converter` atau pengubah sinyal dari analog ke digital atau sebaliknya yang ada pada pin mikrocontroller, salah satunya ESP32. ESP32 mampu membaca input channel ADC hingga resolusi 12 bit. Hal tersebut berarti bahwa ESP32 mampu membaca input analog mulai dari 0 hingga 4095, di mana 0 sesuai dengan 0V dan 4095 hingga 3.3V. Resolusi channel ADC tersebut dapat dikonversi juga menjadi lebih kecil menggunakan kode dan rentang ADC pada program.

Terdapat 2 percobaan yang dilakukan :

## 1. Membaca nilai potensiometer
**Alat dan Bahan**

- ESP32 (1 buah)
- Potensiometer 10 kOhm (1 buah)
- Kabel Jumper (secukupnya)


**Hasil dan Pembahasan**

Program ini mengimplementasikan pembacaan nilai potensiometer pada mikrokontroler. Berikut adalah cara kerjanya:

1. **Inisialisasi dan Penentuan Pin**: Potensiometer terhubung ke pin GPIO34 (Analog ADC1_CH6). Deklarasi tersebut ditunjukkan oleh `const int potPin = 34;`.

2. **Variabel Potensiometer**: Kode menggunakan variabel `potValue` untuk menyimpan nilai yang dibaca dari potensiometer.

3. **Setup()**: Dalam fungsi `setup()`, program menginisialisasi komunikasi serial dengan `Serial.begin(115200)` untuk berkomunikasi dengan Serial Monitor pada baudrate 115200. Terdapat juga jeda waktu 1 detik (`delay(1000)`) sebelum eksekusi program dimulai.

4. **Loop()**: Fungsi `loop()` berisi langkah-langkah yang akan diulang terus menerus.
```cpp
void loop(){
    potValue = analogRead(potPin);
    serial.println(potValue);
    delay(500);
)
```
Jadi pada setiap iterasi atau pengulangan, nilai analog dari potensiometer dibaca menggunakan `analogRead(potPin)`, dan nilai tersebut kemudian dicetak ke Serial Monitor dengan `Serial.println(potValue)`. Ada juga delay 500 milidetik (`delay(500)`) setelah setiap pembacaan nilai potensiometer untuk mengendalikan laju tampilan nilai pada Serial Monitor.

**Kesimpulan**

Program ini memberikan pemahaman dasar tentang penggunaan ADC (Analog-to-Digital Converter) pada Arduino. Salah satunya yaitu membaca nilai analog dari potensiometer dan menampilkannya melalui Serial Monitor setiap 500 milidetik. Variabel `potValue` merepresentasikan nilai analog tersebut, dan dapat digunakan untuk pengembangan atau development lebih lanjut sesuai kebutuhan proyek.

## 2. Mengendalikan LED menggunakan potensiometer
**Alat dan Bahan**

- ESP32 (1 buah)
- Potensiometer 10 kOhm (1 buah)
- Lampu LED (1 buah)
- Resistor 220 Ohm (1 buah)
- Kabel Jumper (secukupnya)


**Hasil dan Pembahasan**

Program ini berfungsi untuk mengendalikan intensitas cahaya LED berdasarkan nilai yang dibaca dari potensiometer. Berikut adalah cara kerjanya:

1. **Inisialisasi Pin dan Konstanta PWM**: Mendefinisikan pin-pin yang digunakan dan konstanta untuk pengaturan PWM. Potensiometer terhubung ke pin analog input 34 (`analogInPin`), sementara LED terhubung ke pin analog output 5 (`analogOutPin`). Selain itu, konstanta untuk properti PWM seperti frekuensi (`freq`), saluran LED (`ledChannel`), dan resolusi (`resolution`) juga ditetapkan. 

    - freq = 5000
    - ledChannel = 0
    - resolution = 8

2. **Setup()**: Dalam fungsi `setup()`, program menginisialisasi komunikasi serial dengan `Serial.begin(115200)`. Selain itu, konfigurasi PWM untuk LED diatur dengan `ledcSetup()` dan dihubungkan ke pin dengan `ledcAttachPin()`.

3. **Loop()**: Fungsi `loop()` berisi langkah-langkah yang diulang terus menerus.
```cpp
void loop() {
    sensorValue = analogRead(analogInPin); // read the analog in value:
    outputValue = map(sensorValue, 0, 4095, 0, 255); // map it to the range of the analog out:
    analogWrite(analogOutPin, outputValue);
}
```
Jadi pada setiap iterasi:

   - Nilai analog dari potensiometer dibaca menggunakan `analogRead()` dan disimpan dalam variabel `sensorValue`.
   
   - Nilai tersebut kemudian di-mapped dari rentang 0 hingga 4095 (rentang nilai pembacaan ADC) ke rentang 0 hingga 255, yang sesuai dengan rentang nilai PWM, menggunakan `map()`. Fungsi `map()` digunakan untuk melakukan iterasi objek dalam suatu array, kemudian memodifikasi isi dari setiap objek individu dan dijadikan array baru.
   
   - Nilai tersebut diterapkan sebagai output PWM ke LED menggunakan `analogWrite()`.
   
   - Selanjutnya, nilai-nilai dibaca dan hasilnya dicetak ke Serial Monitor.

   - Terdapat juga delay singkat (`delay(2)`) untuk memberikan waktu pada konverter analog-digital untuk stabil setelah pembacaan sebelumnya.

**Kesimpulan**

Program ini menciptakan efek perubahan intensitas cahaya pada LED yang terkendali oleh potensiometer. Nilai analog dari potensiometer dibaca, di-mapped, dan kemudian dikonversi menjadi sinyal PWM untuk mengatur tingkat kecerahan LED. Informasi nilai sensor dan output ditampilkan di Serial Monitor. Jeda waktu 2 milidetik memberikan waktu untuk proses ADC dan pemrosesan selanjutnya.
