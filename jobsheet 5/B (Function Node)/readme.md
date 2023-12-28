# Function Node
Pada percobaan ini kita akan menggunakan `function node` untuk memproses suatu data yang akan dikirimkan. Terdapat 2 percobaan yang akan dilakukan:

## 1. Function Node Bawaan (Tanpa Pemrograman)
**Alat dan Bahan**

Software :

- Ubuntu Virtual Machine
- Node-red

Node :

- Inject (1 buah)
- Debug (1 buah)
- Function (1 buah)

**Hasil dan Pembahasan**

Simulasi ini merupakan pengembangan dari flow sebelumnya, dimana terdapat penampahan 1 buah `function` node. Node function ini memungkinkan kita agar dapat memodifikasi data sesuai apa yang kita inginkan, seperti:
- Memproses data, node ini dapat memproses data yang diterima dari input node dan mengirimkan data yang sudah diproses ke output node
- Mengubah data, data yang diubah dapat berupa format pesan atau tipe data dari pesan
- Mengambil data, jadi node dapat berfungsi untuk mengambil data dari suatu sumber (misalnya database).

Node ini menggunakan bahasa javascript sebagai bahasa pemrogramannya.

Pada percobaan ini, tidak ada proses tambahan yang dilakukan didalam node `function`. Jadi hasilnya akan seperti percobaan sebelumnya, yang hanya berupa input node dan output node.

**Kesimpulan**

Function node berfungsi untuk merubah atau memodifikasi pesan atau data agar sesuai dengan apa yang kita inginkan, tentunya dengan cara memprogramnya dengan bahasa `Javascript`.

## 2. Memprogram Function Node
**Alat dan Bahan**

Software :

- Ubuntu Virtual Machine
- Node-red

Node :

- Inject (2 buah)
- Debug (1 buah)
- Function (2 buah)

**Hasil dan Pembahasan**

Simulasi ini merupakan pengembangan dari flow sebelumnya, dimana terdapat penampahan 2 buah `inject` dan `debug` node. Tujuan utamanya adalah bagaimana caranya data dari `Input 1` ditampilkan pada `Output 1`, dan data dari `Input 2` ditampilkan pada `Output 2`. Untuk itu, kita perlu memodifikasi function node agar dapat memproses data-data yang akan dilewatkan. 

**Isi node `Fungsi`**
```javascript
var topic = msg.topic;
if(topic == 'test1') {
    return [msg,null];
}
else if (topic == 'test2') {
    return [null,msg];
}
return msg;
```

**1. Membuat variabel baru** 
```javascript
var topic = msg.topic;
```
kode ini digunakan untuk mempermudah pemanggilan msg.topic dengan cara menyamakan nilainya.

**2. Menentukan Arah Pesan**
```js
if(topic == 'test1') {
    return [msg,null];
}
else if (topic == 'test2') {
    return [null,msg];
}
```
Array yang terdapat pada kode merupakan nilai output dari function node, pada gambar hasil percobaan juga sudah terlihat bahwa terdapat 2 output pada function node.

Nilai pertama dari array merupakan `Output pertama`, maka nilai selanjutnya yang ada dalam array juga merupakan output selanjutnya. Isi dari node `Fungsi` menyatakan bahwa jika topik pesan bernilai `test1`, maka teruskan pesan ke output pertama. Selain itu, jika topik pesan bernilai `test2`, maka teruskan pesan ke output kedua.

**Kesimpulan**

Function node terbukti dapat digunakan sebagai filter pesan atau data, pesan yang melewati function akan diproses dan hasilnya akan diteruskan ke tujuan (node) selanjutnya.

