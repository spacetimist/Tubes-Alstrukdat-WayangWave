#include <stdio.h>
#include <stdlib.h>

#include "./ADT/queue/queue.h"

void QueueSong(Queue *queue) {

    // yang dimasukkin parameter itu album secara keseluruhan
    char penyanyi[100], album[100], lagu[100];

    // output daftar penyanyi (list)
    printf("Daftar Penyanyi :\n");
   
    // input nama penyanyi pakai mesin kata
    STARTWORD();

    while (!isEndWord()) {

    }

    printf("Masukkan Nama Penyanyi: ");


    // output daftar album (set)
    printf("Daftar Album oleh %s :\n", penyanyi);
    // output isi set daftar album

    // input nama album yang dipilih
    printf("Masukkan Nama Album yang dipilih : ");
    // input pakai mesin kata

    // output daftar lagu album (set)
    printf("Daftar Lagu Album %s oleh %s :\n", album, penyanyi);
    // output isi set daftar lagu album

    // input ID lagu
    printf("Masukkan ID Lagu yang dipilih: ");
    // input pakai mesin kata

    // output kalau berhasil menambahkan lagu
    printf("Berhasil menambahkann lagu");
    printf("%s", lagu);
    printf("oleh");
    printf("%s", penyanyi);
    printf("ke queue.");
}

void QueuePlaylist() {

    char playlist[100];
    
    // input masukkan ID playlist
    printf("Masukkan ID Playlist: ");
    // input pakai mesin kata

    printf("Berhasil menambahkan playlist %s ke queue.", playlist);
}

void QueueSwap() {

}

void QueueRemove(int id) {

    
}

void QueueClear(Queue *queue) {
    
    IDX_HEAD(*queue) = IDX_UNDEF;
    IDX_TAIL(*queue) = IDX_UNDEF;

    printf("Queue berhasil dikosongkan.");
}
