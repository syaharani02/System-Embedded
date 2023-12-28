# Transmisi Data Menggunakan Protokol HTTP
Pada percobaan kali ini, ujicoba pengiriman pesan akan menggunakan protokol HTTP. Berbeda dengan MQTT, HTTP memerlukan koordinasi dari client dan server, keduanya harus aktif agar pesan dapat dikirimkan. Selain itu, protokol HTTP ini bekerja pada port 80. Untuk melakukan pengiriman menggunakan HTTP, kita bisa memanfaatkan software API Caller bernama `Postman`. Postman merupakan apikasi yang dapat melakukan pengujian dan debugging pada API menggunakan permintaan (`request`) HTTP, `response` atau hasilnya juga dapat dilihat secara langsung pada aplikasi Postman.

Terdapat 3 percobaan yang akan dilakukan:

## 1. Melakukan HTTP Request
### Alat dan Bahan

Software :

- Ubuntu Virtual Machine
- Node-red
- Postman

Node :
- Http in (1 buah)
- Debug (1 buah)


### Hasil dan Pembahasan

Pada gambar hasil percobaan terlihat bahwa ketika request `POST` dilakukan, muncul pesan pada debug node. Hal ini bisa terjadi pesan dikirimkan ke alamat atau URL dari server (node-red), dimana pada node-red sudah terdapat node `http in` yang menerima pesan tersebut. 

**1. Pesan dikirim ke URL *server/testin***
POST merupakan metode HTTP yang digunakan untuk mengirimkan suatu data baru ke server, jadi si pengirim data atau pesan adalah client. Sedangkan URL `/testin` merupakan tempat tujuan dari pesan.

**2. Node http in menangkap metode POST dengan URL yang sama**
Fungsi dari node `http in` adalah untuk membuat `HTTP endpoint` atau tujuan dari permintaan yang dilakukan oleh client, node ini juga dapat dikonfigurasikan untuk melakukan metode HTTP lainnya seperti GET, PUT, DELETE, dll.

### Kesimpulan
Dengan menggunakan `Postman` dan node `http in`, kita sudah bisa melakukan sebuah request HTTP untuk mengirimkan suatu pesan atau data.

## 2. Menampilkan Masing-masing Properti dari Pesan Menggunakan HTTP
### Alat dan Bahan

Software :

- Ubuntu Virtual Machine
- Node-red
- Postman

Node :
- Http in (1 buah)
- Debug (3 buah)
- Function (3 buah)

### Hasil dan Pembahasan
Tujuan dari percobaan ini adalah untuk menampilkan masing-masing properti dari pesan pada debug node, maka dari itu program yang saya buat pada function, kurang lebih sama seperti pada percobaan sebelumnya:

**Function validation temp**
```javascript
var obj = msg.payload;
msg.payload = obj.temp;  // mengisi pesan dengan nilai properti `temp`
return msg;
```

**Function validation humi**
```javascript
var obj = msg.payload;
msg.payload = obj.humi;  // mengisi pesan dengan nilai properti `humi`
return msg;
```

**Function validation light**
```javascript
var obj = msg.payload;
msg.payload = obj.light; // mengisi pesan dengan nilai properti `light`
return msg;
```

Namun yang perlu diperhatikan adalah walaupun data yang terkirim adalah **angka** 17, namun data yang diterima justru berbentuk *string*. Hal ini bisa terjadi dikarenakan tidak adanya node `JSON Parser` pada flow yang dibuat, jadi data (berbentuk JSON string) yang terkirim belum sepenuhnya menjadi objek saat sampai di node function. Maka dari itu, pesan yang diterima masih berbentuk **string**.

Setelah pesan dikirimkan, proses pengiriman pada Postman seakan-akan masih saja berjalan. Padahal pesan sudah sampai pada tujuan (debug node). Hal ini terjadi karena Postman tidak mendapatkan `HTTP response` dari server, maka dari itu tampilan pada aplikasi Postman seperti gambar diatas.

### Kesimpulan
Dalam mengirimkan suatu pesan atau data, pastikan terdapat node JSON Parse agar data dapat terbaca dengan benar. Hal ini dapat mengantisipasi kesalahan seperti pembacaan data yang salah.

## 3. Membuat HTTP Response
### Alat dan Bahan

Software :

- Ubuntu Virtual Machine
- Node-red
- Postman

Node :
- Http in (1 buah)
- Debug (2 buah)
- Function (1 buah)
- Switch (1 buah)
- Http response (2 buah)

### Hasil dan Pembahasan

Tujuan dari percobaan ini adalah untuk membuat sebuah jawaban atau `response` yang nantinya akan dikirimkan ke pengirim untuk memberi tahu pesan sudah diterima atau belum. Pada percobaan ini, terdapat 2 buah node `http response` yang berfungsi mengirimkan `Status Code` ke pengirim (Postman). Berikut adalah penjelasan dari proses pengiriman pesannya:

**Node Function**
```javascript
var status = 0;
if (msg.payload.temp && msg.payload.humi && msg.payload.light) {
    status = 1; // mengubah nilai status menjadi 1 jika pada pesan yang dikirim terdapat properti: temp, humi, dan light
}
msg.payload.status = status;
return msg;
```

**Node Switch**

Node switch akan membaca nilai status dari pesan yang dikirim. Jika nilai status adalah 1, maka pesan akan diteruskan ke output 1. Dan jika nilai status adalah 0, maka pesan akan diteruskan ke output 2. Output 1 dari switch terhubung ke node http `Response OK` sedangkan Output 2 dari switch terhubung ke node http `Response Bad`.

Seperti yang terlihat pada gambar hasil percobaan, bahwa: 
- Ketika pesan memiliki properti temp, humi, dan light, maka response yang diberikan adalah `200` atau OK.
- Ketika pesan tidak memiliki salah satu saja dari properti temp, humi, dan light, maka response yang diberikan adalah `400` atau Bad.

Response yang berupa `Status Code` atau kode status inilah yang akan dibaca oleh Postman, sehingga hasilnya akan berbeda dengan percobaan sebelumnya yang tidak menggunakan node `http response`. Postman akan menampilkan kondisi dari pesan yang dikirimkan, berikut adalah tampilan `response tab` pada aplikasi Postman

1. Ketika nilai kode status adalah `200`
2. Ketika nilai kode status adalah `400`

### Kesimpulan
Berbeda dengan node `http in`, node `http response` berfungsi mengirimkan `response` atau jawaban terhadap permintaan yang dibuat oleh pengirim (yang melakukan permintaan). Kedua node ini dapat menjelaskan bagaimana server merespons permintaan yang diminta oleh klien, dan sebaliknya.

