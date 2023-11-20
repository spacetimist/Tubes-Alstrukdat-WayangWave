#include <stdio.h>
#include <stdlib.h>
#include "queuesong.h"

void QueueSong(Queue *songQue, ListPenyanyi LP){
    printf("\nDaftar Penyanyi :\n") ;
    for (int i = 0 ; i < (LP).NEff ; i++) {
        printf("    %d. %s\n", i+1, (LP).PenyanyiAlbum[i].NamaPenyanyi.TabLine);
    }

    printf("\nMasukkan Nama Penyanyi yang Dipilih :\n") ;
    printf(">> ") ;
    StartInput() ;
    int indexPenyanyi, indexAlbum, indexLagu;

    for (int i = 0 ; i< (LP).NEff ; i++) {
        Kalimat Penyanyi = (LP).PenyanyiAlbum[i].NamaPenyanyi ;
        Penyanyi.Length --;

        if (isKalimatEqual(Input, Penyanyi)) {
            indexPenyanyi = i ;
            ListAlbum DaftarAlbum = (LP).PenyanyiAlbum[i].ListAlbum ;
            printf("\nDaftar Album oleh %s :\n", Input.TabLine) ;
            for (int j = 0 ; j<DaftarAlbum.NEff ; j++) {
                MapLagu album = DaftarAlbum.AlbumLagu[j] ;
                printf("    %d. %s\n", j+1, album.NamaAlbum.TabLine) ;
            }
        }
    }
    printf("\nMasukkan Nama Album yang Dipilih :\n") ;
    printf(">> ") ;
    ListAlbum DaftarAlbum = (LP).PenyanyiAlbum[indexPenyanyi].ListAlbum ;
    StartInput() ;
    for (int j = 0; j<DaftarAlbum.NEff ; j++) {
        Kalimat album = DaftarAlbum.AlbumLagu[j].NamaAlbum;
        album.Length--;

        if (isKalimatEqual(Input, album)) {
            indexAlbum = j;
            SetLagu DaftarLagu = DaftarAlbum.AlbumLagu[j].IsiLagu ;
            printf("\nDaftar Lagu Album %s :\n", Input.TabLine) ;
            for (int k = 0 ; k<DaftarLagu.Count; k++) {
                Kalimat judul = DaftarLagu.JudulLagu[k] ;
                printf("    %d. %s\n", k+1, judul.TabLine) ;
            }
        }
    }
    printf("\nMasukkan ID Lagu yang Dipilih :\n") ;
    printf(">> ") ;
    StartInput() ;
    int idSong = Input.TabLine[0] - 48 - 1;
    Kalimat judulLagu = LP.PenyanyiAlbum[indexPenyanyi].ListAlbum.AlbumLagu[indexAlbum].IsiLagu.JudulLagu[idSong];
    judulLagu.Length -- ;
    printf("%s\n", LineToString(judulLagu)) ;

    Kalimat namaPenyanyi = LP.PenyanyiAlbum[indexPenyanyi].NamaPenyanyi ;
    namaPenyanyi.Length -- ;
    printf("%s\n", LineToString(namaPenyanyi)) ;

    Kalimat namaAlbum = LP.PenyanyiAlbum[indexPenyanyi].ListAlbum.AlbumLagu[indexAlbum].NamaAlbum ;
    printf("%s\n", LineToString(namaAlbum)) ;
    namaAlbum.Length -- ;
    SongDetails simpan ;
    SongDetails.songName = judulLagu ;
    // printf("%s\n", LineToString(simpan.songName)) ;
    SongDetails.artistName = namaPenyanyi ;
    // printf("%s\n", LineToString(simpan.artistName)) ;
    SongDetails.albumName = namaAlbum ;
    // printf("%s\n", LineToString(simpan.albumName)) ;
    enqueue(queue, simpan) ;
    displayQueue(*queue) ;

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

    if ((id1 >= 1 && id1 <= IDX_TAIL(*songQue))) {
        if (id2 >= 1 && id2-1 <= IDX_TAIL(*queue) && (id1 != id2)) {

            temp = (*songQue).buffer[id1];
            (*songQue).buffer[id1-1]= (*songQue).buffer[id2-1];
            (*songQue).buffer[id2-1] = temp;

            printf("Lagu %s berhasil ditukar dengan %s", song1, song2); //masih belum dites
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