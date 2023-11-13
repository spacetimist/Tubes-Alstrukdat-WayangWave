#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"

// ---------------------------------------------- PLAYLIST ------------------------------------------------------------
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

    Word namaplaylist;
    // = currentWord
    // printWord(namaplaylist)
    // playlist bisa dibuat
    printf("\n");
    printf("Playlist %s berhasil dibuat!\n", wordToString(namaplaylist));
    InsVFirst(playlist, wordToString(namaplaylist));
    
    printf("Silakan masukan lagu-lagu artis terkini kesayangan Anda!\n");
}

void playlistAdd(List *singer){

    // output daftar penyanyi (list)
    printf("Daftar Penyanyi :\n");
    for (int i = 0; i < Length(singer); i++) {
        printf("    %d. %s\n", i+1, Get(*singer, i));
    }

    printf("Masukkan Nama Penyanyi yang dipilih : ");
    startInputWord();
}
//     // kalau nama penyanyi benar
//     // menampilkan daftar album
//     printf("Daftar Album oleh %s : \n", wordToString(namapenyanyi));
//     for (int i = 0; i <= lengthlist; i++) {
//         printf("    %d. %s", i, (list).buffer[i]);
//     }
//     printf("\n\n");

//     // kalau nama penyanyi salah
//     printf("Penyanyi ... tidak ada dalam daftar. Silakan coba lagi.");

//     printf("Masukkan Judul Album yang dipilih : %s", wordToString(judulalbum));
//     startInputWord();
//     // kalau judul album benar
//     // menampilkan daftar lagu
//     printf("Daftar Lagu Album %s oleh %s : \n", wordToString(namapenyanyi), wordToString(judulalbum));
//     for (int i = 0; i <= lengthlist; i++) {
//         printf("    %d. %s", i, (list).buffer[i]);
//     }
//     printf("\n\n");

//     // kalau salah judul
//     printf("Album ... tidak ada dalam daftar. Silakan coba lagi.\n");

//     if () {
//         printf("Masukkan ID Lagu yang dipilih : ");
//         startInputWord();

//         /* kalo salah input */
//         printf("ID Lagu ... tidak ada dalam daftar. Silakan coba lagi.");

//         printf("\n\n");

//         printf("Daftar Playlist Pengguna : \n");
//         for (int i = 0; i <= lengthlist; i++) {
//             printf("    %d. %s", i, (list).buffer[i]);

//         }

//         printf("\n\n");

//         printf("Masukkan ID PLaylist yang dipilih : ");
//         startInputWord();

//         // kalo benar
//         printf("Lagu dengan judul “%s” pada album %s oleh penyanyi %s berhasil ditambahkan ke dalam playlist %s.")
//         /* kalo salah input */
//         printf("ID Playlist ... tidak ada dalam daftar. Silakan coba lagi.");

//     }
//     else if () {
//         printf("Daftar Playlist Pengguna : \n");
//         for (int i = 0; i <= lengthlist; i++) {
//             printf("    %d. %s", i, (list).buffer[i]);

//         }

//         printf("\n\n");

//         printf("Masukkan ID PLaylist yang dipilih : ");
//         startInputWord();

//         // kalo benar
//         printf("Album dengan judul “%s” berhasil ditambahkan ke dalam pada playlist pengguna “%s”");
//         /* kalo salah input */
//         printf("ID Playlist ... tidak ada dalam daftar. Silakan coba lagi.");
//     }
// } 

// void playlistSwap(a, b, c){ 
//     //a = playlist
//     //b = urutan awal
//     //c = urutan akhir

//     printf("Berhasil menukar lagu dengan nama “...” dengan “...” di playlist “...”");
//     //kalo ga ada ID playlistnya
//     printf("Tidak ada playlist dengan playlist ID ...");
//     //kalo ga ada urutan lagunya
//     printf("Tidak ada lagu dengan urutan ... di playlist “...”");
// }

// void playlistRemove(a, b){
//     // a = playlist
//     // b = urutan lagu
//     printf("Lagu ... oleh ... telah dihapus dari playlist ...!");
//     //kalo ga ada ID playlistnya
//     printf("Tidak ada playlist dengan ID ....");
//     //kalo ga ada urutannya di playlist
//     printf("Tidak ada lagu dengan urutan ... di playlist ... !");
// }

// void playlistDelete() {
//     printf("Daftar Playlist Pengguna :\n");
//     for (int i = 0; i <= lengthlist; i++) {
//         printf("    %d. %s", i, (list).buffer[i]);
//     }

//     printf("Masukkan ID Playlist yang dipilih : ");

//     //kalo ga ada ID Playlist nya di daftar
//     printf("Tidak ada playlist dengan ID 11 dalam daftar playlist pengguna. Silakan coba lagi.");
// }
