#include <stdio.h>
#include <stdlib.h>
#include "console.h"

// void QueueSong(Queue *queue) {

//     char penyanyi[00], album[00], lagu[00];

//     // output daftar penyanyi (list)
//     printf("Daftar Penyanyi :\n");
   

//     // input nama penyanyi pakai mesin kata
//     startInputWord();

//     while (!isEndWord()) {

//     }

//     printf("Masukkan Nama Penyanyi: ");


//     // output daftar album (set)
//     printf("Daftar Album oleh %s :\n", penyanyi);
//     // output isi set daftar album

//     // input nama album yang dipilih
//     printf("Masukkan Nama Album yang dipilih : ");
//     // input pakai mesin kata

//     // output daftar lagu album (set)
//     printf("Daftar Lagu Album %s oleh %s :\n", album, penyanyi);
//     // output isi set daftar lagu album

//     // input ID lagu
//     printf("Masukkan ID Lagu yang dipilih: ");
//     // input pakai mesin kata

//     // output kalau berhasil menambahkan lagu
//     printf("Berhasil menambahkann lagu");
//     printf("%s", lagu);
//     printf("oleh");
//     printf("%s", penyanyi);
//     printf("ke queue.");
// }

// void QueuePlaylist(Queue *queue) {

//     char playlist[00];
    
//     // input masukkan ID playlist
//     printf("Masukkan ID Playlist: ");
//     // input pakai mesin kata

//     printf("Berhasil menambahkan playlist %s ke queue.", playlist);
// }

// void QueueSwap(Queue *queue, int id, int id2) {

// }

// void QueueRemove(Queue *queue, int id) {

    
// }

// void QueueClear(Queue *queue) {
    
//     IDX_HEAD(*queue) = IDX_UNDEF;
//     IDX_TAIL(*queue) = IDX_UNDEF;

//     printf("Queue berhasil dikosongkan.");
// }


void createPlaylist(List *playlist){
    printf(">> PLAYLIST CREATE;\n\n");
    
    // playlist belum bisa dibuat
    boolean sesuai = false;

    while (sesuai){
        int count = 0;
        printf("Masukkan nama playlist yang ingin dibuat : ");
        startInputWord();
        // menghitung banyak karakter
        for (int i = 0; i < EOP; i++){
            count++;
        }
        if (count < 3) {
            printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.");
            continue;
        }
        else sesuai = true;
    }

    Word namaplaylist = currentWord;
    // printWord(namaplaylist);
    // playlist bisa dibuat
    printf("\n");
    printf("Playlist %s berhasil dibuat!\n", wordToString(namaplaylist));
    InsVFirst(playlist, wordToString(namaplaylist));
    
    printf("Silakan masukan lagu-lagu artis terkini kesayangan Anda!\n");
}

void playlistAdd(){
    printf("Daftar Penyanyi :\n");
    for (int i = 0; i <= lengthlist; i++) {
        printf("    %d. %s", i, (list).buffer[i]);
    }

    printf("Masukkan Nama Penyanyi yang dipilih : ");
    startInputWord();
    printf("\n\n");
    

/* kalo salah input */
    printf("Penyanyi ... tidak ada dalam daftar. Silakan coba lagi.")
} 


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
    printf("8. QUIT -> Untuk keluar dari sesi aplikasi WayangWave");
}

void invalidComment(){
    printf("Command tidak diketahui!");
    printf("Command tidak bisa dieksekusi!");
}