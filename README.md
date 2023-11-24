# WayangWave
### Tugas Besar Algoritma dan Struktur Data IF2111 
**Kelompok 3 (Contributors):**

| NIM | Nama     | Username                |
| :-------- | :------- | :------------------------- |
| 18222002 | Yasra Zhafirah |[@spacetimist](https://github.com/spacetimist)|
|18222006|Justin Lawrance|[@jstnlwrn](https://github.com/jstnlwrn)|
|18222012|Syakira Fildza Nazhifan|[@skiesinureyes](https://github.com/skiesinureyes)|
|18222054|Natanael Steven Simangunsong|[@natanael-ss](https://github.com/natanael-ss)|
|18222074|Kayla Dyara |[@kayla1410](https://github.com/kayla1410)|

## Deskripsi program

WayangWave merupakan pemutar lagu yang berbasis CLI (Command Line Interface). Terdapat beberapa fitur utama di dalam pemutar lagu ini, diantaranya yaitu memutar lagu, menampilkan daftar lagu, membuat dan menghapus playlist, mengatur urutan dimainkannya lagu, dan menampilkan status dari aplikasi. Ketika program dijalankan, pertama-tama, program akan memnampilkan main menu yang berisi welcome page dan beberapa command lainnya, seperti `START`, `LOAD`, dan juga `HELP`. Selain itu juga prgram meminta masukkan command dari user untuk menjalankan pemutar lagu WayangWave.  

 

Tugas besar ini dirangkai menggunakan bahasa C. Program memanfaatkan struktur-struktur data yang dipelajari pada mata kuliah IF2111 Algoritma dan Struktur data STI, meliputi ADT List, ADT Mesin Karakter dan Mesin Kata, ADT Queue, ADT Stack, ADT Set dan Map, dan ADT List dengan Struktur Berkait. Selain itu, program WayangWave juga menggunakan library `stdio.h`, `stdlib.h`, dan `time.h`.

## How to Compile
### Prerequisites
- Linux platform
- A C compiler (minimal gcc 5.4.0)
- The `stdio.h`, `stdlib.h`, and `time.h` library

### Compilation Steps
1. Open a terminal or command prompt.
2. Navigate to the directory containing src files.
3. Run the following command to compile your program:
    a. make main
    b. ./main

This command tells the compiler to compile the `main.c`, `console.c`, and all files in ../src/command and ../ADT and output an executable file named `main`.

### Makefile :
gcc -o main ../src/ADT/mesin/mesinkata.c ../src/ADT/mesin/mesinkalimat.c ../src/ADT/mesin/mesinkarakter.c ../src/ADT/map2/map2.c ../src/ADT/queue/queue.c ../src/ADT/stack/stack.c ../src/ADT/listlinier/listlinier.c ../src/ADT/listDin/listDin.c ../src/ADT/SongDetails.c ../src/command/start.c ../src/command/list.c ../src/command/playlist.c ../src/command/queuesong.c ../src/command/quit.c ../src/command/play.c ../src/command/status.c ../src/command/save.c ../src/command/song.c ../src/command/load.c ../src/console.c ../src/command/enhance.c ../src/main.c