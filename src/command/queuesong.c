#include <stdio.h>
#include <stdlib.h>
#include "queuesong.h"

void QueueSong(Queue *queue, ListPenyanyi *LP) {

    // output daftar penyanyi (list)
    printf("Daftar Penyanyi :\n");
    for (int i = 0; i < LP.NEff; i++) {
        printf("    %d. %s\n", i+1, Get(LP, i));
    }
   
    // input nama penyanyi pakai mesin kata
    printf("Masukkan Nama Penyanyi: ");
    StartInput();

    printf("\nPilih penyanyi untuk melihat album mereka: ");
    StartInput();
    int indexPenyanyi;
    for (int i = 0; i < LP.NEff; i++){
        Kalimat Penyanyi = LP.PenyanyiAlbum[i].NamaPenyanyi;
        Penyanyi.Length--;
        // printf("%d\n",Penyanyi.Length);
        // printf("%d\n",Input.Length);
        if (isKalimatEqual(Input, Penyanyi)){
            indexPenyanyi = i;
            ListAlbum DaftarAlbum = LP.PenyanyiAlbum[i].ListAlbum;
            printf("\nDaftar Album oleh %s :\n", Input.TabLine);
            for(int j=0; j<DaftarAlbum.NEff; j++){
                MapLagu album = DaftarAlbum.AlbumLagu[j];
                printf("    %d. %s\n", j+1, album.NamaAlbum.TabLine);
            }
        }

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
    
    // input masukkan ID playlist
    printf("Masukkan ID Playlist: ");
    // input pakai mesin kata

    printf("Berhasil menambahkan playlist %s ke queue.", playlist);
}

void QueueSwap(Queue *queue, int id1, int id2)
{

}

void QueuePlaylist(Queue *queue) {
}

void QueueRemove(Queue *queue, int id) {
}

void QueueClear(Queue *queue) {
    
    IDX_HEAD(*queue) = IDX_UNDEF;
    IDX_TAIL(*queue) = IDX_UNDEF;

    printf("Queue berhasil dikosongkan.");
}