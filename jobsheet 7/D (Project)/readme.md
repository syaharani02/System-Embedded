# Project Jobsheet 7
Hal-hal yang harus dilakukan:

- Membandingkan flow program MQTT yang telah dibuat pada Jobsheet sebelumnya, kemudian gabungkan dalam satu Tab dengan flow program HTTP. Setelah itu, kondisikan agar data yang dikirim dari MQTT Clients dapat disimpan pada database dan tabel yang sama pada mekanisme protokol HTTP.
- Membandingkan kecepatan transmisi data diantara kedua protokol.

### Alat dan Bahan

Software :

- Ubuntu Virtual Machine
- Node-red
- Postman
- XAMPP
- MySQL Server
- Mosquitto Broker
- MQTT Box

Node :
- Http in (1 buah)
- Function (7 buah)
- Debug (8 buah)
- JSON Parser (1 buah)
- Switch (1 buah)
- Http response (2 buah)
- Mysql (2 buah)
- Mqtt in (1 buah)


### Hasil dan Pembahasan
Tujuan dari project jobsheet 7 ini adalah untuk membandingkan kecepatan transmisi antara protokol MQTT dan HTTP. Untuk itu saya menambahkan flow program pada Project jobsheet 6 untuk dibandingkan dengan flow program jobsheet 7 C yang sudah saya buat sebelumnya. Terdapat beberapa node dan program yang baru, imbas dari penggabungan flow program. Berikut adalah pengembangan dari flow program:

**1. Konfigurasi Publisher**

Topik dari pesan yang dikirim oleh Publisher, saya samakan dengan URL HTTP, yaitu sensor/node1.

**2. Konfigurasi MQTT In**

**3. Program Filter Tipe Data MQTT***
```javascript
// function ini berfungsi sebagai filter pesan yang akan menentukan output atau tujuan
if (typeof msg.payload === "object") {
    // Memproses pesan apabila tipe datanya adalah JSON string
    if (msg.payload.dev_id && msg.payload.rainfall && msg.payload.level) {
        // Pesan akan diteruskan ke node `JSON Parser` dan `Query MQTT` jika terdapat properti dev_id, rainfall, dan level pada pesan yang dikirim
        return [msg]; 
    }
}
else if (typeof msg.payload === "string") {
    // Pesan akan dikirim ke debug node `string` jika tipe data pesan adalah `string`
    return [null, msg];
}
else if (typeof msg.payload === "number") {
    // Pesan akan dikirim ke debug node `number` jika tipe data pesan adalah `number`
    return [null, null, msg];
}
else if (typeof msg.payload === "boolean") {
    // Pesan akan dikirim ke debug node `boolean` jika tipe data pesan adalah `boolean`
    return [null, null, null, msg];
}
```

**4. Program Query MQTT**
```javascript
// function ini berfungsi sebagai query untuk memasukkan properti pesan ke database
msg.topic = "INSERT INTO banjir_table(time,dev_id,rainfall,level) VALUES(NOW()," + msg.payload.dev_id + "," + msg.payload.rainfall + "," + msg.payload.level +");";
return msg;
```
- Value yang pertama (`NOW()`) digunakan untuk mencatat waktu, akan dimasukkan ke kolom `time` pada tabel.
- Value yang kedua (`msg.payload.dev_id`) akan dimasukkan ke kolom `dev_id` pada tabel.
- Value yang kedua (`msg.payload.rainfall`) akan dimasukkan ke kolom `rainfall` pada tabel.
- Value yang kedua (`msg.payload.level`) akan dimasukkan ke kolom `level` pada tabel.

Program untuk query MQTT saya samakan dengan program untuk query HTTP seperti pada jobsheet 7 C. Hasil olahan pesan akan dikirimkan ke node `Database` (mysql) dan ditampilkan isinya pada node `MQTT Response` (debug). Konfigurasi dari node `mysql` juga saya samakan seperti pada jobsheet 7 C. 

Seperti yang terlihat pada gambar hasil percobaan, bahwa kedua protokol berhasil menyimpan properti pesan kedalam database dan dapat menampilkan response pada debug. Dengan menggunakan MQTT publisher dengan QoS 0, sama seperti project jobsheet 6, tidak ada kesalahan sama sekali (tidak terjadi packet loss) pada proses pengiriman data. Jumlah dari data yang terkirim dan disimpan pada database adalah sama, begitupun hasil yang diperoleh saat menggunakan protokol HTTP.

Untuk kecepatannya sendiri tidak jauh berbeda, karena perbedaannya hanya berjarak milisekon. Mungkin karena pengiriman data terjadi pada perangkat yang sama, yaitu dari Sistem Operasi Windows ke VM Ubuntu. Jadi latensinya sangat rendah sehingga perbedaan kecepatan antara kedua protokol tidak terlihat signifikan.

### Kesimpulan
Protokol MQTT dan HTTP memiliki kecepatan transmisi data yang cepat (kisaran milisekon). Namun jika dilihat dari aspek lain, seperti keamanan, maka MQTT lebih baik, karena memiliki beberapa tipe QoS yang memiliki kelebihan dan kekurangan. Akan tetapi, perlu diingat bahwa faktor terpenting yang menentukan kecepatan transmisi data adalah jarak antara titik awal dan tujuan serta handal tidaknya suatu jaringan internet yang digunakan sebagai media transmisi.

