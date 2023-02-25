# TugasBesar_SEKURO_Programming_Kel4
Tugas Besar Divisi Programming SEKURO 2023

## Table of Contents
* [General Info](#general-information)
* [How To Run](#how-to-run)
* [Tech Stack](#tech-stack)
* [Project Structure](#project-structure)
* [Credits](#credits)

## General Information
### Battle Ship Mechanism
- Kapal dapat membaca dan menampilkan posisinya saat ini
- Kapal dapat berlayar di empat kuadran pada koordinat kartesian
- Kapal dapat bergerak satu satuan ke maju, mundur, ke kanan, atau ke kiri.
- Kapal tidak dapat menabrak lawan.
- Kapal tidak dapat keluar dari peta (ukuran peta bebas, disarankan tidak terlalu besar agar - kondisi peta saat ini dapat ditampilkan di layar dengan mudah)
- Kapal memiliki atribut health
- Kapal dapat menyerang lawan dengan damage yang konstan. Besar damage dibebaskan kepada CAKRU.
- Meriam kapal memiliki jarak tembak maksimum untuk menyerang lawan. Besar jarak tembah - dibebaskan kepada CAKRU.
- Kapal dapat menghitung jarak dengan lawan.

### Program Specification
- Pada awal program, kapal berada pada koordinat (0,0) dan satu armada musuh akan muncul secara acak di koordinat yang tidak sama dengan posisi kapal sekarang.
- Kapal akan meminta perintah apakah ingin menembak, bergerak, atau diam di tempat.
- Jika kapal musuh berada di luar jarak tembak kapal maksimum, keluarkan pesan error.
- Program akan berhenti ketika health kapal kurang dari atau sama dengan 0.
- Saat program berhenti, keluarkan jumlah kapal musuh yang berhasil dikalahkan.
- Kapal musuh juga memiliki atribut health, damage, dan jarak serangan maksimum.
- nnti Nilai atribut dari kapal dan kapal musuh dibebaskan kepada CAKRU.
- Health musuh 5 dan akan spawn setiap 10 tick.
- Health player 10.
- Range attack masing-masing 2.
- Besar map 20 x 20.

#### Not Validated
- Move player tidak dibatasin, bisa keluar dari map.
- Pemilihan enemy tidak divalidasi dan apabila salah akan terminated program.

## How To Run
### Run Using Windows Batch File
1. Di terminal (cmd), jalankan:
```shell
./run
```
2. Atau double klik pada file `run.bat`

### Run Manually 
1. Pastikan anda berada pada dir `bin` dengan :
```shell
cd bin
```
2. Jalankan perintah berikut:
```shell
./out
```

## Tech Stack
### Programming Languange
* C++ language 6.3.0

### Libraries
* iostream
* string
* vector
* ctime
* cstdlib
* stdlib.h

## Project Structure
```bash
.
├── README.md
│
├── run.bat
│
├── .gitignore
│
├── doc
│    │
│    └── Dokumentasi_TugasBesar_Programming_Kel_4.pdf
│
└── src
     │
     ├── attribute
     │     |
     │     └── map
     │          ├── Map.cpp
     │          └── Map.hpp
     │
     ├── object 
     │     ├── EnemyCollection.cpp 
     │     ├── EnemyCollection.hpp 
     │     ├── EnemyPlayer.cpp 
     │     ├── EnemyPlayer.hpp 
     │     ├── ObjectPlayer.cpp
     │     └── ObjectPlayer.hpp  
     │     
     └── main.cpp
```

## Credits
This project is implemented by: 
1. Wilson Tansil (13521054) - entire program
2. Panji Sri Kuncara Wisma (19622140)