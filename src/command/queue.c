#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void QueueSong(Queue *queue, ListPenyanyi *ls) {

    // output daftar penyanyi (list)
    printf("Daftar Penyanyi :\n");
    for (int i = 0; i < Length(ls); i++) {
        printf("    %d. %s\n", i+1, Get(*ls, i));
    }
   
    // input nama penyanyi pakai mesin kata
    printf("Masukkan Nama Penyanyi: ");
    StartInput();

    // output daftar album (set)
    printf("Daftar Album oleh %s :\n");
    // output isi set daftar album

    // input nama album yang dipilih
    printf("Masukkan Nama Album yang dipilih : ");
    // input pakai mesin kata

    // output daftar lagu album (set)
    printf("Daftar Lagu Album %s oleh %s :\n");
    // output isi set daftar lagu album

    // input ID lagu
    printf("Masukkan ID Lagu yang dipilih: ");
    // input pakai mesin kata

    // output kalau berhasil menambahkan lagu
    printf("Berhasil menambahkann lagu");
    printf("%s");
    printf("oleh");
    printf("%s");
    printf("ke queue.");
}

void QueuePlaylist(Queue *queue) {

    char playlist[00];
    
    // input masukkan ID playlist
    printf("Masukkan ID Playlist: ");
    // input pakai mesin kata

    printf("Berhasil menambahkan playlist %s ke queue.", playlist);
}

void QueueSwap(Queue *queue, int id1, int id2) {
    if (isEmpty(*queue)) printf("Queue kosong!");
    else if ((id1 < 0 || id1 >= CAPACITY) && (id2 < 0 || id2 >= CAPACITY)) printf("Lagu dengan urutan ke %d dan ke %d tidak terdapat dalam queue!", id1, id2);
    else if (id1 < 0 || id1 >= CAPACITY) printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!", id1);
    else if (id2 < 0 || id2 >= CAPACITY) printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!", id1);
    else {

        int idx1 = (IDX_HEAD(*queue) + id1) % CAPACITY;
        int idx2 = (IDX_HEAD(*queue) + id2) % CAPACITY;

        ElType song1 = (*queue).buffer[idx1];
        (*queue).buffer[idx1] = (*queue).buffer[idx2];
        (*queue).buffer[idx2] = song1; 
        ElType song2 = (*queue).buffer[idx1];

        printf("Lagu '%s' berhasil ditukar dengan '%s'", song1, song2);
    }
}

void QueueRemove(Queue *queue, int id) {
    if (isEmpty(*queue)) return;
    else if (id < 0 || id >= length(*queue)) printf("Lagu dengan urutan ke %d tidak ada.");
    else {

        int idToRemove = (IDX_HEAD(*queue) + id) % CAPACITY;
        ElType songToRemove = (*queue).buffer[idToRemove];

        for (int i = idToRemove; i < length(*queue) - 1; i++) {
            (*queue).buffer[i] = (*queue).buffer[i + 1];
        }

        (*queue).idxTail = ((*queue).idxTail - 1 + CAPACITY) & CAPACITY;

        printf("Lagu '%s' oleh '%s' telah dihapus dari queue!", songToRemove);
    }
}

void QueueClear(Queue *queue) {
    
    IDX_HEAD(*queue) = IDX_UNDEF;
    IDX_TAIL(*queue) = IDX_UNDEF;

    printf("Queue berhasil dikosongkan.");
}