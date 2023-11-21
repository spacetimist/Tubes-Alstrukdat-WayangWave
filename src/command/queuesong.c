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
  //      Penyanyi.Length --;

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
   //     album.Length--;

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
 //   judulLagu.Length -- ;
    // printf("%s\n", LineToString(judulLagu)) ;

    Kalimat namaPenyanyi = LP.PenyanyiAlbum[indexPenyanyi].NamaPenyanyi ;
 //   namaPenyanyi.Length -- ;
    // printf("%s\n", LineToString(namaPenyanyi)) ;

    Kalimat namaAlbum = LP.PenyanyiAlbum[indexPenyanyi].ListAlbum.AlbumLagu[indexAlbum].NamaAlbum ;
    // printf("%s\n", LineToString(namaAlbum)) ;
 //   namaAlbum.Length -- ;
    SongDetails simpan ;
    simpan.songName= judulLagu ;
    // printf("%s\n", LineToString(simpan.songName)) ;
    simpan.artistName = namaPenyanyi ;
    // printf("%s\n", LineToString(simpan.artistName)) ;
    simpan.albumName = namaAlbum ;
    // printf("%s\n", LineToString(simpan.albumName)) ;
    enqueue(songQue, simpan) ;
    printf("Berhasil menambahkan lagu %s oleh %s ke queue\n", LineToString(judulLagu), LineToString(namaPenyanyi)) ;
    displayQueue(*songQue) ;

}

// void QueuePlaylist(Queue *songQue, DaftarPlaylist DP) {
    
//     // // input ID playlist
//     // printf("Masukkan ID Playlist: ");
//     // StartInput();
//     // int idPlaylist = Input.TabLine[0] - 48 - 1;

//     // List playlist = DP.(*Playlist);
//     // if (!IsListEmpty(playlist)) {
//     //     for (int i = 0; i < DP.NEff; i++) {
//     //         if (i == idPlaylist) {
//     //             printf("Berhasil menambahkan playlist %s ke queue.", playlist.PlaylistName.TabLine);
//     //             for (int j = 0; j < DP.NEff; j++) {
//     //                 enqueue(songQue, playlist.PlaylistName.TabLine);
//     //             }
//     //         }
//     //     }
//     // }
// }

void QueueSwap(Queue *songQue, int id1, int id2)
{
    // song1 = (*songQue).buffer[id1];
    // song2 = (*songQue).buffer[id2];

    if ((id1 >= 1 && id1 <= IDX_TAIL(*songQue))) {
        if (id2 >= 1 && id2-1 <= IDX_TAIL(*songQue) && (id1 != id2)) {
            SongDetails temp ;
            temp = (*songQue).buffer[id1-1];
            (*songQue).buffer[id1-1]= (*songQue).buffer[id2-1];
            (*songQue).buffer[id2-1] = temp;

            printf("Lagu %s berhasil ditukar dengan %s\n", LineToString((*songQue).buffer[id1-1].songName), LineToString((*songQue).buffer[id2-1].songName));
            displayQueue(*songQue) ;
        }
        else printf("Lagu dengan urutan ke %d dan ke %d tidak terdapat dalam queue!\n", id1, id2) ;
    }
    else printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!", id1) ;
}

void QueueRemove(Queue *songQue, int id) {
    if (!isQueueEmpty(*songQue)) {
        if (id <= 0 || id > IDX_TAIL(*songQue) - IDX_HEAD(*songQue) + 1) {
            printf("Lagu dengan urutan ke %d tidak ada\n", id);
        }
        else if (IDX_TAIL(*songQue) - IDX_HEAD(*songQue) == 0) {
            IDX_HEAD(*songQue) = IDX_UNDEF;
            IDX_TAIL(*songQue) = IDX_UNDEF;
            printf("Lagu %s oleh %s telah dihapus dari queue\n", LineToString((*songQue).buffer[id-1].songName), LineToString((*songQue).buffer[id-1].artistName));
            displayQueue(*songQue);
        }
        else {
            for (int i = id -1; i< IDX_TAIL(*songQue) ; i++) {
                (*songQue).buffer[i] = (*songQue).buffer[i+1];
            }
            IDX_TAIL(*songQue) -- ;
            printf("Lagu %s oleh %s telah dihapus dari queue\n", LineToString((*songQue).buffer[id-1].songName), LineToString((*songQue).buffer[id-1].artistName));
            displayQueue(*songQue) ;
        }
    }
    else printf("Queue kosong.\n");
}

void QueueClear(Queue *songQue) {
    
    IDX_HEAD(*songQue) = IDX_UNDEF;
    IDX_TAIL(*songQue) = IDX_UNDEF;

    printf("Queue berhasil dikosongkan.\n");
}