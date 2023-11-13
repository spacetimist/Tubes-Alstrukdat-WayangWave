#include <stdio.h>
#include <stdlib.h>
#include "console.h"
#include "console2.h"

// -------------------------------------------------- HELP -----------------------------------------------------------
void HelpBeforeStart() {
    printf("-------------------- [ Menu Help WayangWave ] --------------------");
    printf("1. START -> Untuk masuk sesi baru aplikasi WayangWave");
    printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi");
}

void HelpAfterStart() {
    printf("-------------------- [ Menu Help WayangWave ] --------------------");
    printf("1. LIST -> Untuk menampilkan list playlist, list penyanyi, list album, dan list lagu");
    printf("2. PLAY -> Untuk memutar lagu/playlist yang dipilih");
    printf("3. QUEUE -> Untuk menambahkan, menukar, dan menghapus lagu dalam queue");
    printf("4. SONG -> Untuk navigasi lagu dalam queue");
    printf("5. PLAYLIST -> Untuk membuat dan menghapus playlist, menambahkan, menukar, dan menghapus lagu dalam playlist");
    printf("6. STATUS -> Untuk menampilkan lagu yang sedang dimainkan beserta queue song");
    printf("7. SAVE -> Untuk menyimpan state aplikasi WayangWave terbaru");
    printf("8. QUIT -> Untuk keluar dari sesi aplikasi WayangWave");;
}

void InvalidCommand(){
    printf("Command tidak diketahui!");
    printf("Command tidak bisa dieksekusi!");
}