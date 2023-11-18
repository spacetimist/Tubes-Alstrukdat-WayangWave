#include <stdio.h>
#include <stdlib.h>
#include "queuesong.h"

void QueueSong(Queue *queue, ListPenyanyi LP) {

    // output daftar penyanyi (list)
    printf("Daftar Penyanyi :\n");
    StartInput();
    int indexPenyanyi;

    // output daftar penyanyi
    for (int i = 0; i < LP.NEff; i++){
        Kalimat Penyanyi = LP.PenyanyiAlbum[i].NamaPenyanyi;
        Penyanyi.Length--;

        if (isKalimatEqual(Input, Penyanyi)){
            indexPenyanyi = i;
            ListAlbum DaftarAlbum = LP.PenyanyiAlbum[i].ListAlbum;
            printf("\nDaftar Album oleh %s :\n", Input.TabLine);
            for(int j=0; j<DaftarAlbum.NEff; j++){
                MapLagu album = DaftarAlbum.AlbumLagu[j];
                printf("    %d. %s\n", j+1, album.NamaAlbum.TabLine);
            }
        }

    // input nama album yang dipilih
    ListAlbum DaftarAlbum = LP.PenyanyiAlbum[indexPenyanyi].ListAlbum;
    printf("Masukkan Nama Album yang dipilih : ");
    StartInput();

    for(int j=0; j<DaftarAlbum.NEff; j++){
        Kalimat album = DaftarAlbum.AlbumLagu[j].NamaAlbum;
        album.Length--;
        // printf("%d\n",album.Length);
        // printf("%d\n",Input.Length);
        if (isKalimatEqual(Input, album)){
            SetLagu DaftarLagu = DaftarAlbum.AlbumLagu[j].IsiLagu; 
            printf("\nDaftar Lagu Album %s oleh, NamaAlbum");
            printf(" %s :\n", Input.TabLine);
            for(int k=0; k<DaftarLagu.Count;k++){
            Kalimat lagu = DaftarLagu.JudulLagu[k];
                printf("    %d. %s\n", k+1, lagu.TabLine);
            }
        }
    }

    // input ID lagu
    printf("Masukkan ID Lagu yang dipilih: ");
    StartInput();
    int idLagu = Input.TabLine[0] - 48 - 1;

    // output kalau berhasil menambahkan lagu
    printf("Berhasil menambahkann lagu");
    printf("%s");
    printf("oleh");
    printf("%s", Penyanyi.TabLine);
    printf("ke queue.");
}

void QueuePlaylist(Queue *queue) {
    
    // input ID playlist
    printf("Masukkan ID Playlist: ");
    StartInput();
    int idPlaylist = Input.TabLine[0] - 48 - 1;

    printf("Berhasil menambahkan playlist %s ke queue.", Playlist);
}

void QueueSwap(Queue *queue, int id1, int id2)
{

}

void QueueRemove(Queue *queue, int id) {

}

void QueueClear(Queue *queue) {
    
    IDX_HEAD(*queue) = IDX_UNDEF;
    IDX_TAIL(*queue) = IDX_UNDEF;

    printf("Queue berhasil dikosongkan.");
}