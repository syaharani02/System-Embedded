# Mengirim Data JSON ke Server dan Menyimpannya ke Database

### Alat dan Bahan

Software :

- Ubuntu Virtual Machine
- Node-red
- Postman
- XAMPP
- MySQL Server

Node :
- Http in (1 buah)
- Function (2 buah)
- Debug (1 buah)
- Switch (1 buah)
- Http response (2 buah)
- Mysql (1 buah)

### Hasil dan Pembahasan

Pada gambar hasil percobaan terlihat bahwa ketika request `POST` dilakukan, muncul pesan pada debug node sekaligus menambahkan properti dari pesan tersebut ke tabel `banjir_table` yang ada pada database `nodered`. Berikut adalah tahap-tahap pembuatan dari flow program: 

**1. Pesan dikirim ke URL *server/sensor/node1***

POST merupakan metode HTTP yang digunakan untuk mengirimkan suatu data baru ke server, jadi si pengirim data atau pesan adalah client. Sedangkan URL `/testin` merupakan tempat tujuan dari pesan.

**2. Node http in menangkap metode POST dengan URL yang sama**

**3. Program Node Function Validation**
```javascript
// function ini berfungsi sebagai filter pesan yang akan menentukan HTTP Response
var status = 0;
if (msg.payload.dev_id && msg.payload.rainfall && msg.payload.level) {
    status = 1;  // mengubah nilai status menjadi 1 jika pada pesan yang dikirim terdapat properti: dev_id, rainfall, dan level
}
msg.payload.status = status;
return msg;
```

**4. Konfigurasi Node Switch, dan kedua node response sama seperti percobaan sebelumnya**

Yang menjadi pembeda dengan percobaan sebelumnya adalah output 1 dari switch node juga terhubung ke node `function query`.

**Node Response `OK`**

**Node Response `Bad`**

**5. Node Function Query**: berfungsi memasukkan properti dev_id, rainfall, dan level ke tabel `banjir_table`
```javascript
msg.topic = "INSERT INTO banjir_table(dev_id,rainfall,level) VALUES(" + msg.payload.dev_id + "," + msg.payload.rainfall + "," + msg.payload.level +");";
return msg;
```

- Value yang pertama (msg.payload.dev_id) akan dimasukkan ke kolom `dev_id` pada tabel.
- Value yang kedua (msg.payload.rainfall) akan dimasukkan ke kolom `rainfall` pada tabel.
- Value yang ketiga (msg.payload.level) akan dimasukkan ke kolom `level` pada tabel.
  
Hasil olahan pesan akan dikirimkan ke node `Database` (mysql) dan ditampilkan isinya pada node `Response` (debug).

**6. Node Mysql**

Karena tabel `banjir_table` saya buat pada database yang sama yaitu `nodered`, maka konfigurasi dari node `mysql` sama seperti percobaan sebelumnya. 

Seperti yang terlihat pada gambar hasil percobaan, bahwa: 
- Ketika pesan memiliki properti dev_id, rainfall, dan level, maka response yang diberikan adalah `200` atau OK. Properti dari pesan kemudian disimpan di database pada kolom tabel `banjir_table`.
- Ketika pesan tidak memiliki salah satu saja dari properti dev_id, rainfall, dan level, maka response yang diberikan adalah `400` atau Bad. Properti dari pesan tidak akan disimpan pada database.

### Kesimpulan
Protokol HTTP juga dapat digunakan untuk menyimpan data atau pesan ke dalam database server.

