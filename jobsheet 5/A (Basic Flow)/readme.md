# Basic Flow
Simulasi awal menggunakan Node-RED : melakukan pengujian pengiriman pada node `input` dan menampilkannya pada node `output`

**Alat dan Bahan**

Software :

- Ubuntu Virtual Machine
- Node-red

Node :

- Inject (1 buah)
- Debug (1 buah)

**Hasil dan Pembahasan**

Pada gambar hasil percobaan terlihat bahwa flow yang dibuat merupakan simulasi sederhana dari suatu proses pengiriman data atau pesan (`msg`), dimana terdapat `Inject Node` yang berfungsi sebagai pengirim data dan `Debug Node` yang berfungsi sebagai penerima data. 

Data atau pesan yang dapat dikirimkan juga memiliki berbagai macam tipe, beberapa diantaranya yang umum digunakan adalah:
- String, contoh = "Halo Syaharani". Tipe data ini merupakan huruf.
- Number, contoh = 17. Tipe data ini merupakan angka.
- Boolean, contoh = true atau false. Tipe data ini merupakan representasi dari bilangan biner (1 dan 0).
- JSON, contoh = {"nama":"syaharani","absen":"23"}. Tipe data ini merupakan sebuah objek, dimana dalam suatu objek terdapat beberapa `key` yang memiliki `value` atau nilai. Pada contoh dapat dilihat bahwa terdapat 2 key, yaitu `nama` dan `absen`. Sedangkan `adriano` dan `17` merupakan `value` dari `key` tersebut.
- Timestamp, tipe data berfungsi untuk mengirimkan waktu saat ini.

Pesan yang akan dikirimkan dinamakan `payload`, kemudian `topic` dari pesan dapat digunakan untuk mengisi tujuan. Pada percobaan ini, `topic` belum berpengaruh pada proses pengiriman data, karena hanya terdiri dari Input/Output sederhana saja. Penggunaan dari `msg.topic` akan lebih terlihat pada jobsheet selanjutnya.

**Kesimpulan**

Aplikasi node-red dapat digunakan sebagai media pembelajaran atau simulasi yang berbentuk seperti flow (alur), dengan begitu kita dapat lebih mudah memahami alur kerja atau bagaimana data itu dikirimkan pada suatu sistem.

