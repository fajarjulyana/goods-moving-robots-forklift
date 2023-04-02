# goods-moving-robots-forklift
robot pemindah barang dari titik A ke titik B dengan tambahan servo sebagai forklift menggunakan Arduino
## Bahan
1. Arduino board (misalnya Arduino Uno)

2. Motor DC (2 buah)

3. L293D Motor Driver Shield

4. Sensor jarak ultrasonik (misalnya HC-SR04)

5. Breadboard

6. Kabel jumper

7. Baterai atau power supply

8. Chassis robot atau bahan-bahan untuk membuat rangka robot

9. Roda dan motor penggerak

10. Arm servo (SG90 atau sejenisnya)

11. Roda gigi

12. Kabel servo

13. Potensiometer

14. Sensor Warna
## Pengkabelan
## Langkah Pengerjaan 
1. Pasang motor DC pada rangka robot dan sambungkan ke L293D Motor Driver Shield menggunakan kabel jumper

2. Sambungkan Motor Driver Shield ke Arduino board menggunakan kabel jumper
3. Pasang sensor jarak ultrasonik pada rangka robot dan sambungkan ke Arduino board menggunakan kabel jumper
4. Pasang arm servo pada rangka robot dan sambungkan ke Arduino board menggunakan kabel servo


5. Pasang roda gigi pada arm servo
6. Gunakan bahan-bahan yang tersedia untuk membuat rangka robot

7. Pasang roda penggerak dan motor penggerak pada rangka robot
## Kodenya 
https://github.com/fajarjulyana/goods-moving-robots-forklift/blob/0bbf06a296616613f1fd84f4c8f9f0343e17080a/src/code.cpp#L1-L20

<br>
Penjelasan singkat tentang kode program di atas:

1. Kita menggunakan library NewPing untuk membaca data dari sensor ultrasonik
2. Kita menggunakan library Servo untuk mengendalikan servo
3. Pertama-tama, kita mengatur pin untuk sensor ultrasonik, servo, dan motor DC
4. Kemudian, di dalam fungsi setup(), kita menginisialisasi servo dan mengatur pin untuk motor DC sebagai output
5. Di dalam fungsi loop(), kita membaca data dari sensor ultrasonik dan menentukan tindakan yang harus dilakukan berdasarkan jarak yang terdeteksi
6. Jika jarak kurang dari 30 cm, maka robot akan berhenti, menggerakkan servo untuk menaikkan barang, maju sebentar, menurunkan barang, dan mundur sebentar
7. Jika jarak lebih dari atau sama dengan 30 cm, maka robot akan bergerak maju terus
Fungsi forward(), backward(), dan stop() digunakan untuk menggerakkan motor DC ke depan, ke belakang, dan untuk berhenti
## Pengembangan 
penambahan sensor warna untuk mendeteksi barang 
<br>
robot pemindah barang dari titik A ke titik B dan sebaliknya dengan menggunakan Arduino, motor DC, dan servo forklift, serta sensor warna untuk mendeteksi barang yang diangkut.

## pengkabelan dengan senaor warna

## kode dengan sensor warna
berikut kodenya dengan sensor warna
