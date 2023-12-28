# GPIO (General Purpose Input/Output)
Merupakan pin yang dapat digunakan untuk berbagai tujuan, baik sebagai pin input untuk membaca data dari sensor atau tombol, maupun sebagai pin output untuk mengontrol perangkat seperti LED atau motor.

Percobaan ini ditujukan agar dapat memahami penggunaan pin GPIO pada ESP32. Terdapat 4 percobaan yang berbeda :
## 1. Membuat Blink LED menggunakan millis()
**Alat dan Bahan**
- ESP32 (1 buah)
- LED (1 buah)
- Resistor 220 Ohm (1 buah)
- Resistor 10 kOhm (1 buah)
- Push Button (1 buah)
- Kabel Jumper (secukupnya)

**Hasil dan Pembahasan**

Program ini dibuat untuk mengatur kedipan LED setiap 1 detik. Pengendalian LED dilakukan menggunakan fungsi `millis()` yang merupakan metode non-blocking/asinkron. Metode asinkron akan terus dijalankan dan tidak terpaku pada program utama (berjalan terpisah). Beberapa variabel yang digunakan meliputi:

- `ledPin`: Menentukan pin yang terhubung ke Output (LED) (GPIO 5).
- `ledState`: Variabel yang mengindikasikan keadaan LED (HIGH atau LOW).
- `previousMillis`: Menyimpan waktu terakhir (LED) berubah keadaan.
- `interval`: Menyimpan interval waktu (dalam milidetik) untuk kedipan LED (1000 ms atau 1 detik).

Pada bagian setup(), `ledPin` diatur sebagai OUTPUT dengan menggunakan pinMode(), memberi tahu Arduino bahwa pin tersebut akan mengendalikan LED. Pada loop(), pertama-tama nilai `currentMillis` diperoleh menggunakan millis(), yang mencatat waktu sejak Arduino dinyalakan. Program kemudian memeriksa apakah selisih waktu antara `currentMillis` dan `previousMillis` lebih besar atau sama dengan `interval` (1 detik). Ini berfungsi sebagai mekanisme waktu untuk mengubah keadaan LED. Jika selisih waktu sudah mencapai atau melebihi interval, maka `previousMillis` diperbarui dengan `currentMillis`. Selanjutnya, program memeriksa keadaan `ledState`. Jika `ledState` adalah LOW (mati), maka akan diubah menjadi HIGH (nyala), dan sebaliknya. Terakhir, menggunakan digitalWrite(), LED akan diatur sesuai dengan nilai `ledState`, menciptakan efek kedipan LED dengan interval 1 detik.

**Kesimpulan**

Program ini berfungsi menghasilkan efek berkedip pada LED setiap 1 detik dengan menggunakan fungsi millis() untuk menghindari ketergantungan atau sinkronisasi waktu (blocking), sehingga cocok digunakan sebagai timer untuk program LED berkedip.

## 2. Membuat Blink LED saat penekanan button
**Alat dan Bahan**
- ESP32 (1 buah)
- LED (1 buah)
- Resistor 220 Ohm (1 buah)
- Resistor 10 kOhm (1 buah)
- Push Button (1 buah)
- Kabel Jumper (secukupnya)

**Hasil dan Pembahasan**

Program dimulai dengan melakukan inisialisasi variabel input dan output:

- `buttonPin` (pin 4) dan `ledPin` (pin 5) diumumkan sebagai konstanta yang menentukan pin yang akan digunakan dalam program.
- `buttonState` merupakan variabel yang akan menyimpan status (HIGH atau LOW) dari tombol tekan.
 
Dalam bagian `setup()`, program memulai inisialisasi komunikasi serial dengan Serial.begin(115200), memungkinkan program berkomunikasi dengan komputer melalui Serial Monitor dengan kecepatan 115200 baud. Selanjutnya, `pinMode()` digunakan untuk mengatur `buttonPin` sebagai input (untuk membaca tombol tekan) dan `ledPin` sebagai output (untuk mengendalikan LED).

Pada bagian `loop()`, program menjalankan beberapa tugas berulang kali:

- `buttonState` diisi dengan nilai yang dibaca dari `buttonPin` menggunakan `digitalRead()`. Ini akan menghasilkan nilai HIGH jika tombol tekan ditekan, dan LOW jika tidak.
- `Serial.println(buttonState)` digunakan untuk mencetak nilai `buttonState` ke Serial Monitor, memungkinkan kita melihat status tombol tekan dalam Serial Monitor.
- Program kemudian memeriksa nilai `buttonState` dalam suatu kondisi:
  - Jika `buttonState` bernilai HIGH (tombol tekan ditekan), maka `digitalWrite(ledPin, HIGH)` akan dijalankan untuk menyalakan LED dengan mengatur pin `ledPin` menjadi HIGH.
  - Jika `buttonState` bernilai LOW (tombol tekan tidak ditekan), maka `digitalWrite(ledPin, LOW)` akan dijalankan untuk mematikan LED dengan mengatur pin `ledPin` menjadi LOW.

**Kesimpulan**

Program ini berfungsi menyalakan LED hanya ketika button ditekan, jadi button berfungsi sebagai saklar atau switch. Selain itu, kondisi dari button juga tercatat pada serial monitor.

## 3. Membuat Blink LED berdurasi 500ms saat penekanan button
**Alat dan Bahan**
- ESP32 (1 buah)
- LED (2 buah)
- Resistor 220 Ohm (2 buah)
- Resistor 10 kOhm (2 buah)
- Push Button (2 buah)
- Kabel Jumper (secukupnya)

**Hasil dan Pembahasan**

Program ini merupakan lanjutan dari percobaan sebelumnya, dimana terdapat tambahan 1 buah LED dan 1 buah push button. Untuk itu kita harus memulai dengan mendeklarasikan pin GPIO untuk dua push button (`buttonPin1` dan `buttonPin2`) serta dua LED (`ledPin1` dan `ledPin2`).

Dalam fungsi `setup()`, pin-pin diatur sesuai dengan fungsinya, yaitu push button sebagai input dan LED sebagai output.

Dalam fungsi `loop()`, status dari kedua push button dibaca dan dicetak ke Serial Monitor. Selanjutnya, terdapat sebuah fungsi yang mengatur perilaku LED berdasarkan status push button:

   - Jika `buttonState2` (status dari push button kedua) adalah HIGH, maka LED akan berkedip bergantian dengan interval 0.5 sekon atau 500 ms.
   - Jika `buttonState1` (status dari push button pertama) adalah HIGH, maka kedua LED akan menyala bersamaan.
   - Jika keduanya tidak ditekan, kedua LED dimatikan.

Program ini secara umum memahami input dari push button dan mengendalikan LED sesuai dengan kondisi push button tersebut. 

**Kesimpulan**

Program ini berfungsi menghasilkan efek LED berkedip hanya ketika button ke-2 ditekan, dan hanya menyalakan (tidak berkedip) kedua LED ketika button ke-1 ditekan. Selain itu, kondisi dari setiap button juga tercatat pada serial monitor.

## 4. Membuat Running LED saat penekanan button
**Alat dan Bahan**
- ESP32 (1 buah)
- LED (3 buah)
- Resistor 220 Ohm (3 buah)
- Resistor 10 kOhm (3 buah)
- Push Button (3 buah)
- Kabel Jumper (secukupnya)

**Hasil dan Pembahasan**

Running LED merupakan beberapa lampu LED yang menyala bergantian dengan rapi (kiri ke kanan atau sebaliknya), maka setidaknya dibutuhkan 3 lampu LED untuk menerapkannya. Sama seperti sebelumnya, kita hanya menambahkan satu buah push button sekali lagi dan juga setidaknya 1 buah LED. Agar program kita terlihat lebih efisien, kita bisa menggunakan function `for()`. `For()` merupakan suatu fungsi berupa proses pengulangan tugas/kegiatan pada suatu statement atau lebih secara berulang ulang-ulang selama yang dijadikan acuan tersebut terpenuhi dengan baik.

Setelah itu kita deklarasikan beberapa pin GPIO untuk push button (`buttonPin1`, `buttonPin2`, dan `buttonPin3`) dan LED (`ledPin1`, `ledPin2`, dan `ledPin3`).

Berbeda dari sebelumnya yang langsung menggunakan digitalWrite(HIGH dan LOW) pada LED PIN, kali ini kita memanfaatkann fungsi for untuk mengulang programnya. Untuk itu kita harus membuat sebuah array bernama `pinLED` yang nantinya digunakan untuk menyimpan pin dari tiga LED. Kita hanya memasukkan saja nomor pin dari semua `pinLED` ke array tersebut secara urut (karena saya menginginkan LED menyala dari kiri ke kanan, maka disini saya mengurutkan dari ledPin1 hingga ledPin 3), setelah itu kita outputkan menggunakan fungsi `for()`.

Dalam fungsi `setup()`, pin-pin diatur sesuai dengan fungsinya, yaitu push button sebagai input dan LED sebagai output. Sedangkan fungsi `for()` saya gunakan untuk mengatur semua isi array `pinLED` menjadi output.

Dalam fungsi `loop()`, status dari ketiga push button dibaca dan dicetak ke Serial Monitor. Selanjutnya, terdapat kondisional yang mengatur perilaku LED berdasarkan status push button:

   - Jika `buttonState1` (status dari push button pertama) adalah HIGH, maka ketiga LED akan menyala bersamaan.
   - Jika `buttonState2` (status dari push button kedua) adalah HIGH, maka LED 1 dan LED 2 akan berkedip bergantian dengan interval waktu 500 ms.
   - Jika `buttonState3` (status dari push button ketiga) adalah HIGH, maka ketiga LED akan berkedip secara bergantian. Masing-masing LED akan menyala dan mati dengan interval waktu 500 ms yang dijalankan menggunakan `for()`.

**Kesimpulan**

Program ini menunjukkan implementasi yang baik dalam mengendalikan beberapa LED dengan beberapa push button. Ketika push button pertama ditekan, ketiga LED akan menyala secara bersamaan. Jika push button kedua ditekan, LED pertama akan menyala, kemudian mati, diikuti oleh LED kedua yang menyala dan mati. Sedangkan saat push button ketiga ditekan, ketiga LED akan berkedip bergantian. Kita juga dapat memanfaatkan penggunaan fungi `for()` untuk membuat running LED.
