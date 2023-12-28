# Koneksi ke MQTT Broker
Pada percobaan ini kita akan mempelajari bagaimana cara mengkoneksikan publisher dan subscriber pada node-red menggunakan `Mosquitto`, yang merupakan MQTT Broker yang akan digunakan. Mosquitto akan kita gunakan dalam jobsheet 6 ini.

### Alat dan Bahan

Software :

- Ubuntu Virtual Machine
- Node-red
- Mosquitto Broker

Node :
- Inject (1 buah)
- Debug (1 buah)
- MQTT Out (1 buah)
- MQTT In (1 buah)

### Hasil dan Pembahasan

Node `MQTT Out` berfungsi sebagai publisher sedangkan node `MQTT In`berfungsi sebagai subscriber, dimana topik pesan yang digunakan adalah `livingroom/sensors`. Sesuai dengan prinsip Protokol MQTT, publisher dengan subscriber yang memiliki topik yang sama, akan dapat melakukan pertukaran pesan.

Namun untuk dapat melakukan percobaan diatas, kita diharuskan menginstall broker terlebih dahulu. Jika tidak, maka node MQTT Out dan In tidak akan dapat terhubung walaupun memiliki topik yang sama. 

Karena software node-red yang saya gunakan terinstall di OS Ubuntu, maka cara menginstallnya adalah seperti berikut:
```linux
sudo add-apt-repository ppa:mosquitto-dev/mosquitto-ppa
sudo apt install mosquitto mosquitto-clients
```
Untuk memastikan Mosquitto sudah berjalan atau tidak, dapat kita ketikkan **systemctl status mosquitto** pada CLI Ubuntu

Ini menandakan bahwa kita sudah bisa menggunakan protokol MQTT pada flow node-red kita. Selain itu pastikan kolom `host` pada node MQTT sudah kita atur menjadi `localhost` dan portnya menjadi 1883.

### Kesimpulan
Untuk menggunakan protokol MQTT pada node-red, kita harus menginstall broker terlebih dahulu, salah satunya adalah Mosquitto. Kemudian untuk menambah publisher, kita bisa menggunakan node `MQTT Out` yang sudah dikonfigurasikan pengaturan brokernya. Dan untuk menambah subscriber, kita bisa menggunakan node `MQTT In` yang juga sudah dikonfigurasikan pengaturan brokernya. Pastikan juga kedua node memiliki topik yang sama agar pesan dapat dikirimkan.

