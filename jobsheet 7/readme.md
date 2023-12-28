# Jobsheet 7 - TRANSMISI DATA MENGGUNAKAN HYPER TEXT TRANSFER PROTOCOL (HTTP)
Jobsheet 7 merupakan latihan untuk memahami cara kerja protokol HTTP, yang merupakan suatu protokol meminta/menjawab (`request/response`) antara klien dan server. Klien yang mengirimkan permintaan HTTP juga dikenal dengan user agent. Server yang meresponsnya, yang menyimpan sumber daya seperti berkas HTML dan gambar, dikenal juga sebagai origin server. Di antara user agent dan juga origin server, bisa saja ada penghubung, seperti halnya proxy, gateway, dan juga tunnel.

HTTP Verb, atau HTTP methods, adalah metode yang digunakan dalam protokol HTTP untuk menentukan tindakan yang akan dilakukan terhadap sumber daya yang ditargetkan. Terdapat beberapa HTTP Verb yang umum digunakan, di antaranya adalah GET, POST, PUT, DELETE, dan PATCH. GET digunakan untuk mengambil data dari sumber daya, POST digunakan untuk mengirim data ke server, PUT digunakan untuk mengganti atau memperbarui data yang ada, DELETE digunakan untuk menghapus sumber daya, dan PATCH digunakan untuk memperbarui sebagian data dari sumber daya. Salah satu software yang dapat digunakan untuk mensimulasikan HTTP methods adalah Postman.

Setiap HTTP Verb memiliki fungsi dan kegunaan yang berbeda-beda, dan digunakan sesuai dengan kebutuhan dalam pengembangan aplikasi web. Misalnya, GET digunakan untuk menampilkan halaman web atau mengambil data dari server, POST digunakan untuk mengirim data dari formulir ke server, PUT digunakan untuk memperbarui data yang ada, DELETE digunakan untuk menghapus data, dan PATCH digunakan untuk memperbarui sebagian data dari sumber daya. Dengan menggunakan HTTP Verb yang tepat, pengembang dapat mengontrol akses dan tindakan yang dilakukan terhadap sumber daya secara efisien dan aman. 

Pada jobsheet ini terdapat beberapa percobaan, diantaranya:
### A. . Instalasi SQL Server (MySQL)

Mempelajari bagaimana cara memasang dan mengoperasikan database server (MySQL) agar dapat digunakan sebagai tempat penyimpanan data.
### B. Basic Flow Transmisi Data Menggunakan Protokol HTTP

Melakukan ujicoba pengiriman data menggunakan protokol `HTTP` dengan software `Postman`.
### C. Mengirim Data JSON ke Server dan Menyimpannya ke Database

Melakukan ujicoba penyimpanan data ke database `MySQL`.
### D. Project

- Membandingkan flow program MQTT yang telah dibuat pada Jobsheet sebelumnya, kemudian gabungkan dalam satu Tab dengan flow program HTTP. Setelah
itu, kondisikan agar data yang dikirim dari MQTT Clients dapat disimpan pada database dan tabel yang sama pada mekanisme protokol HTTP.
- Membandingkan kecepatan transmisi data diantara kedua protokol.
