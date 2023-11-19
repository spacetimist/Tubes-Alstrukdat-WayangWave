#include <stdio.h>
#include <stdlib.h>
#include "queuesong.h"

void QueueSong(Queue *songQue, ListPenyanyi LP) {

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

    enqueue(*songQue, idLagu);

    // output kalau berhasil menambahkan lagu
    printf("Berhasil menambahkann lagu %s oleh %s ke queue.", HEAD(*songQue), Penyanyi.TabLine);
}

void QueuePlaylist(Queue *songQue) {
    
    // input ID playlist
    printf("Masukkan ID Playlist: ");
    StartInput();
    int idPlaylist = Input.TabLine[0] - 48 - 1;

    printf("Berhasil menambahkan playlist %s ke queue.", Playlist);
}

void QueueSwap(Queue *songQue, int id1, int id2)
{
    song1 = (*songQue).buffer[id1];
    song2 = (*songQue).buffer[id2];

    if ((id1 >= 0 && id1 <= queueLength(songQue))) {
        if (id2 >= 0 && id2 <= queueLength(songQue)) {

            temp = (*songQue).buffer[id1];
            (*songQue).buffer[id1] = (*songQue).buffer[id2];
            (*songQue).buffer[id2] = temp;

            printf("Lagu %s berhasil ditukar dengan %s", song1, song2);
        }
        else printf("Lagu dengan urutan ke %d dan ke %d tidak terdapat dalam queue!", id1, id2);
    }
    else printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!", id1)
}

void QueueRemove(Queue *songQue, int id, Kalimat Penyanyi) {
    int removedValue = (*songQue).buffer[IDX_HEAD(*songQue) + id];

    if (!isEmpty(songQue)) {
        if (id <= 0 || id > IDX_TAIL(*songQue) - IDX_HEAD(*songQue) + 1)  {
            printf("Lagu dengan urutan ke %d tidak ada", id);
        }
        else {
            for (int i = 0; i < queueLength(songQue); i++) {
                (*songQue).buffer[IDX_HEAD(*songQue) + i] = (*songQue).buffer[IDX_HEAD(*songQue) + i + 1];
            }
            IDX_HEAD(*songQue)--;

            if (IDX_HEAD(*songQue) == IDX_TAIL(*songQue)) {
                IDX_HEAD(*songQue) = IDX_UNDEF;
                IDX_TAIL(*songQue) = IDX_UNDEF;
            }

            printf("Lagu %s oleh %s telah dihapus dari queue", removedValue, Penyanyi.TabLine)
        }
    }
    else printf("Queue kosong.")
}

void QueueClear(Queue *songQue) {
    
    IDX_HEAD(*songQue) = IDX_UNDEF;
    IDX_TAIL(*songQue) = IDX_UNDEF;

    printf("Queue berhasil dikosongkan.");
}