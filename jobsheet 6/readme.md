# Jobsheet 6 - TRANSMISI DATA MENGGUNAKAN MESSAGE QUEUING TELEMETRY TRANSPORT (MQTT) PROTOCOL
Jobsheet 6 merupakan latihan untuk memahami cara kerja protokol MQTT, yang merupakan suatu protokol komunikasi yang berjalan di atas stack TCP/IP, didesain untuk komunikasi Machine-toMachine (M2M), bersifat open sources dan lightweight, mempunyai protocol overhead yang rendah (minimum 2 bytes) sehingga berefek pada konsumsi daya yang kecil dan mampu bekerja pada latency yang tinggi serta bandwidth yang kecil

Protokol `MQTT` menggunakan model publish/subscribe untuk melakukan komunikasi data antara pengirim (publisher) dan penerima (subscriber), serta terdapat broker yang berperan sebagai middleman yang bertugas meneruskan pesan (message) dari publisher menuju subscriber. Pesan di dalam broker dibedakan dan difilter menggunakan topic yang mana setiap pesan yang dikirimkan ke broker diberi tag atau penanda oleh publisher untuk membedakan setiap data.

MQTT mengizinkan setiap user untuk menggunakan Quality of Service (QoS) yang berbeda sesuai dengan kebutuhannya.
- QoS 0  dapat melakukan pengiriman pesan ke broker hanya sekali, apabila terdapat pesan yang mengalami kegagalan dalam proses transmisi, maka broker tidak akan meminta untuk mengirimkan pesan kembali.
- QoS 1 melakukan pengiriman pesan ke broker dengan pemberian sinyal kontrol ACK (acknowlegment) pada setiap pesan yang dikirimkan, pesan yang dikirimkan dijamin akan sampai ke broker namun setiap pesan tersebut tidak dijamin bersih dari adanya duplikasi.
- QoS 2 merupakan tingkatan tertinggi dari QoS MQTT, dimana semua pesan yang dikirim pasti diterima dan tidak ada pesan yang terduplikasi. MQTT menggunakan ID pada setiap pesan untuk melakukan filter agar tidak ada pesan yang terduplikasi.

Keuntungan dari penggunaan protokol `MQTT` diantaranya:

**1. Publisher dan Subcriber bersifat loosely coupled** artinya keduanya tidak saling bergantung satu sama lain, berbeda dengan metode tradisional seperti client/server yang saling bergantung satu sama lain.

**2. Publisher dan Subscriber bersifat Scalable** artinya kita dapat menambahkan broker lain ke dalam sistem IoT untuk mengurangi beban pada broker tunggal dengan cara membagi topic di antara kedua broker tersebut

**3. Space, Time, dan Synchronization Decoupling** artinya Publisher dan subscriber tetap akan bekerja walaupun mereka tidak saling mengetahui letak atau keberadaan satu sama lain, karena adanya broker diantara publisher dan subscriber. Keduanya juga tetap akan bekerja walaupun mereka tidak saling terkoneksi, kalaupun ada data yang dikirimkan publisher saat `offline` maka data akan dikirimkan saat keduanya sudah terkoneksi `(online)`.

Pada jobsheet ini terdapat beberapa percobaan, diantaranya:
### A. Koneksi ke MQTT Broker

Mempelajari bagaimana cara mengkoneksikan node-red ke mosquitto, yang merupakan `MQTT Broker` yang akan digunakan.
### B. Menerima Data JSON Melalui Protokol MQTT

Melakukan ujicoba pengiriman data menggunakan protokol `MQTT`.
### C. Mengirim Dummy Data untuk Simulasi I/O Menggunakan Hardware

Mensimulasikan windows sebagai `Publisher/Subsciber` dengan menggunakan software `MQTT Box`.
### D. Project

- Mengembangkan flow program yang telah dibuat agar ketika terdapat input nilai metane > 5, maka akan ditampilkan pada log atau debug node “Warning”. Jika input metane <=5, tampilkan data pada debug node “Save”.
- Menyimpan data output flow program ke dalam database mysql, serta mencatat waktu saat data tersimpan menggunakan tipe data `timestamp`
- Membandingkan Publisher dengan QoS yang berbeda

