# Instalasi MySQL
### Alat dan Bahan

Software :

- Ubuntu Virtual Machine
- Node-red
- Mosquitto Broker
- MQTT Box
- XAMPP

### Hasil dan Pembahasan
Terdapat 2 opsi yang dapat dilakukan dalam menginstall MySQL:

1. Menginstall di Sistem Operasi Windows
2. Menginstall di Sistem Operasi Linux

Keduanya memiliki tata cara instalasi yang berbeda, saya sendiri memilih opsi nomor 1. Karena menurut saya pribadi, proses instalasinya lebih mudah dimengerti daripada opsi nomor 2. Pada sistem operasi windows, salah satu cara cepat untuk menginstall MySQL adalah dengan menginstall aplikasi XAMPP. Setelah menginstall maka akan muncul popup 

Selanjutnya adalah memulai service `Apache` dan `MySQL`. MySQL sebenarnya dapat berjalan tanpa harus mengaktifkan service Apache yang merupakan sebuah `web server`, namun jika kita ingin memanage atau mengkonfigurasi database `MySQL` pada sistem operasi `Windows` secara GUI, maka kita harus masuk ke halaman management systemnya. Nah, management system dari MySQL membutuhkan sebuah web server agar dapat berjalan, untuk itulah service `Apache` harus dinyalakan.

Management system dari MySQL dapat diakses pada browser dengan URL `localhost/phpmyadmin`. Berikut adalah tampilan dari phpMyAdmin yang merupakan database management system dari database MySQL

Jika nanti ada user lain yang ingin mengakses database, maka dapat menuliskan IP dari interface sistem operasi yang digunakan dengan tambahan `/phpmyadmin`. 

**Catatan**: Alamat 172.18.0.1 adalah IP Address dari interface WSL dari sistem operasi windows yang saya gunakan

Contoh lainnya adalah ketika saya ingin mengakses database lewat VM Ubuntu untuk digunakan pada aplikasi node-red, maka data-data seperti host, user, password, dan database harus dimasukkan pada node `mysql` agar dapat tersambung (connected). Berikut adalah contoh konfigurasinya

Konfigurasi tersebut digunakan untuk mengakses database `nodered` pada service Database Server pada perangkat dengan IP 172.18.0.1 yang memiliki privilege atau `hak akses` sesuai dengan akun yang digunakan (`syaharani`).

Isi dari sebuah database adalah `Tabel`, tabel inilah yang nantinya digunakan untuk menyimpan sebuah data pada database. Untuk percobaan selanjutnya, saya menambahkan tabel baru yang berisikan: `id, dev_id, rainfall, level, dan time`.

`Varchar(45)` merupakan tipe data berupa karakter yang jumlahnya dapat bervariasi, saya mengatur maksimal karakter adalah 45 untuk percobaan pada jobsheet kali ini. Kemudian untuk kolom data `time` digunakan untuk memasukkan waktu saat data tersimpan nantinya. Selain itu, kolom data `id` dijadikan sebagai `Primary Key`. Primary key sangat penting dalam sebuah tabel, jika primary key tidak ditentukan, maka akan terdapat duplikasi dari sebuah pesan sehingga nantinya akan menyulitkan kita atau user dalam mengidentifikas atau memperbarui data.

### Kesimpulan
Untuk menyimpan data dibutuhkan suatu database server, MySQL adalah salah satunya. Untuk mengkonfigurasi suatu database pada sistem operasi `Windows` menggunakan tampilan GUI (Graphical User Interface), dibutuhkan database management system (`DBMS`). Selain membuat database, juga harus membuat tabel yang bertujuan sebagai tempat penyimpanan data. Nama dari kolom dan tipe data yang digunakan haruslah sesuai dengan kebutuhan, karena jika tipe data dari pesan yang akan disimpan dan tipe data dari kolom tabel **tidak sinkron**, maka data **tidak akan dapat disimpan**. Mengatur `Primary Key` juga merupakan suatu kewajiban dalam membuat tabel, tujuannya agar dapat mempermudah user dalam mencari data serta mencegah adanya duplikasi data.

