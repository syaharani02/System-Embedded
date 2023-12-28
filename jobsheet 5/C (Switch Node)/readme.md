# Switch Node
Pada percobaan ini kita akan menggunakan `switch node` untuk memproses suatu data yang akan dikirimkan.

### Alat dan Bahan

Software :

- Ubuntu Virtual Machine
- Node-red

Node :
- Inject (2 buah)
- Debug (2 buah)
- Switch (1 buah)

### Hasil dan Pembahasan

Berbeda dengan node `function`, untuk memproses data pada node `switch` tidak memerlukan pemrograman sama sekali. Kita hanya menambahkan `action` atau aksi untuk dapat melakukan pemrosesan data. 

Ada berbagai macam action yang dapat dilakukan:

Karena pada percobaan ini kita hanya menentukan apakah jumlah inputan angka melebihi atau kurang dari 28, maka kita hanya menambahkan 2 aksi, yaitu > dan <=. Kemudian kita masukkan angka 28 pada kolom input, dan pastikan tipe data yang dipilih adalah number.

Aksi pertama akan meneruskan pesan ke output pertama jika benar, sedangkan apabila yang benar adalah aksi kedua, maka pesan akan diteruskan ke output kedua.

### Kesimpulan

Switch node berfungsi untuk merubah atau memodifikasi pesan atau data agar sesuai dengan apa yang kita inginkan, dimana kita hanya perlu menambahkan aksi saja tanpa perlu melakukan coding atau pemrograman seperti pada function node.

