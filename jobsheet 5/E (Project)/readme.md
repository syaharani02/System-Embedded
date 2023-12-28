# Project Jobsheet 5
Pada project ini kita diharuskan untuk membuat arsitektur sistem IoT menggunakan semua fungsi yang ada pada Hands-On. Format data yang dikirim adalah multi-input dengan format data String, Bolean, Number dan JSON (3 data). Setiap input mempunyai ditampilkan dalam Debug Node yang berbeda.

### Alat dan Bahan

Software :

- Ubuntu Virtual Machine
- Node-red

Node :
- Inject (4 buah)
- Debug (4 buah)
- Function (1 buah)

### Hasil dan Pembahasan

Sesuai soal bahwa terdapat 4 node input yang masing-masing berisi data berupa string, number, boolean, dan JSON. Untuk meneruskan pesan ke output yang benar, saya memilih untuk membuat program javascript pada node `function`. Berikut adalah program yang saya buat:

**Isi Function Node**
```js
if (typeof msg.payload === "string") { 
    return [msg];    // jika tipe pesan adalah string, maka teruskan pesan ke output pertama
}
else if (typeof msg.payload === "number") {
    return [null, msg];    // jika tipe pesan adalah number, maka teruskan pesan ke output kedua
}
else if (typeof msg.payload === "boolean") {
    return [null, null, msg];    // jika tipe pesan adalah boolean, maka teruskan pesan ke output ketiga
}
else if (typeof msg.payload === "object") {
    return [null, null, null, msg];    // jika tipe pesan adalah objek, maka teruskan pesan ke output keempat
}
return msg;
```

Karena tiap pesan memiliki tipe data yang berbeda, celah tersebut bisa saya jadikan patokan untuk membuat fungsi `if`. Dimana nantinya pesan dengan tipe data yang sesuai dengan fungsi `if` yang saya buat akan diteruskan ke output yang sudah saya tentukan.
- Pesan "string" akan diteruskan ke output 1 dari node function, yaitu menuju output "debug string"
- Pesan "number" akan diteruskan ke output 2 dari node function, yaitu menuju output "debug number"
- Pesan "boolean" akan diteruskan ke output 3 dari node function, yaitu menuju output "debug boolean"
- Pesan "JSON" akan diteruskan ke output 4 dari node function, yaitu menuju output "debug json"

### Kesimpulan
Dengan menggunakan program JavaScript pada node function, kita dapat memeriksa tipe data dari setiap pesan yang masuk dan meneruskannya ke output yang sesuai. Hal ini memungkinkan kita untuk memproses pesan dengan tipe data yang berbeda secara berbeda pula, sehingga memungkinkan untuk melakukan manipulasi data sesuai dengan kebutuhan.
