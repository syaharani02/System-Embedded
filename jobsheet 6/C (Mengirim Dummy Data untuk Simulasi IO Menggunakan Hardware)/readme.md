# Mengirim Dummy Data untuk Simulasi I/O Menggunakan Hardware
Pada percobaan ini kita akan melakukan ujicoba pengiriman data menggunakan hardware, untuk itu diperlukan aplikasi `MQTT Box` yang dapat diinstall pada `Microsoft Store` atau dapat menginstall extensionnya pada browser `Google Chrome`. Terdapat 2 percobaan, yaitu:

## 1. Pengiriman 2 Topik Pesan berbentuk JSON dengan MQTT Box
### Alat dan Bahan

Software :

- Ubuntu Virtual Machine
- Node-red
- Mosquitto Broker
- MQTT Box

Node :
- Inject (2 buah)
- MQTT Out (2 buah)
- MQTT In (2 buah)
- JSON Parser (2 buah)
- Function (8 buah)
- Debug (7 buah)

### Hasil dan Pembahasan
Untuk mempercepat percobaan, saya menggunakan flow program yang sudah saya buat pada percobaan sebelumnya. Jika sebelumnya untuk mengirimkan pesan dapat menggunakan node `inject`, sekarang aplikasi MQTT Box-lah yang akan digunakan untuk mengirimkan pesan dengan menggunakan protokol MQTT. Untuk percobaan ini, saya menggunakan MQTT Box versi Microsoft Store

Setelah mengkoneksikan ke Mosquitto Broker, saya membuat 2 publisher baru dengan topik livingroom/sensors dan kitchen/sensors. Untuk mempercepat, saya menggunakan data yang sama seperti pada node `inject` pada percobaan sebelumnya. 

Jadi dengan menggunakan aplikasi MQTT Box, kita bisa mengirimkan pesan menggunakan protokol MQTT dengan cara `Add Publisher` kemudian mengisi kolom topic dan payload, jadi konsepnya sama seperti gabungan dari node `MQTT Out` dan `Inject Node`. Pesan yang dikirimkan akan ditampilkan pada bagian kosong dibawah tombol `Publish`. Selain itu, menu `Add Subscriber` dapat menjadikan MQTT Box sebagai penerima pesan (sama seperti node `MQTT In`). Pesan yang diterima juga akan ditampilkan pada bagian kosong dibawah tombol `Subscribe`

### Kesimpulan
MQTT Box dapat digunakan untuk melakukan pengiriman pesan (publisher) menggunakan protokol MQTT. Selain itu, juga bisa berfungsi sebagai penerima pesan (subscriber). Log atau riwayat dari pesan yang dikirim dan diterima juga dapat dilihat, sehingga aplikasi ini dapat digunakan sebagai pengganti node `Inject dan MQTT Out` atau node `Debug dan MQTT In` pada aplikasi node-red.

## 2. Multi-Input Tipe Data menggunakan MQTT Box
Percobaan ini merupakan pengembangan dari percobaan sebelumnya, dimana terdapat beberapa input dengan tipe data yang berbeda yang harus ditampilkan pada debug node khusus.
### Alat dan Bahan

Software :

- Ubuntu Virtual Machine
- Node-red
- Mosquitto Broker
- MQTT Box

Node :
- Inject (2 buah)
- MQTT Out (2 buah)
- MQTT In (2 buah)
- JSON Parser (2 buah)
- Function (10 buah)
- Debug (13 buah)

### Hasil dan Pembahasan
Pada percobaan ini saya menggunakan program pada node function untuk menyeleksi tipe data dari pesan, jadi letak pembedanya hanya ada pada node function yang berfungsi sebagai switch.

Karena output dari function memiliki urutan yang mengarah pada jenis debug node yang sama, yaitu: 
1. objek
2. string
3. number
4. boolean

Maka kedua function memiliki program yang sama. Berikut adalah programnya:

**Program pada Function yang difungsikan sebagai switch**
```javascript
if (typeof msg.payload === "object") {
    return [msg];
}
else if (typeof msg.payload === "string") {
    return [null, msg];
}
else if (typeof msg.payload === "number") {
    return [null, null, msg];
}
else if (typeof msg.payload === "boolean") {
    return [null, null, null, msg];
}
```

Sama seperti pada percobaan sebelumnya, saya memanfaatkan perbedaan dari topik pesan untuk dijadikan argumen dari fungsi `if`. Setiap function yang berfungsi mengambil nilai dari properti juga sama seperti percobaan sebelumnya. Berikut adalah hasilnya:

Selain pesan berbentuk JSON, MQTT Box juga dapat mengirimkan pesan string, number, atau boolean. Selain itu, juga terdapat tipe data lain yang dapat dikirimkan 

### Kesimpulan
Dengan menggunakan MQTT Box, pengiriman format data yang berbeda atau Multi-Input akan menjadi lebih mudah dan cepat tanpa harus membuat node `inject` atau input yang banyak pada flow program node-red.

