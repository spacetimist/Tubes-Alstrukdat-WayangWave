#include "play.h"
#include <stdlib.h>

void PlaySong(Queue *songQue, Stack *songHist, ListPenyanyi *LP, SongDetails *currentSong) {
    //print daftar penyanyi
    printf("\nDaftar Penyanyi :\n") ;
    for (int i = 0 ; i < (*LP).NEff ; i++) {
        printf("    %d. %s\n", i+1, (*LP).PenyanyiAlbum[i].NamaPenyanyi.TabLine);
    }
    //milih penyanyi
    printf("\nMasukkan Nama Penyanyi yang Dipilih :\n") ;
    printf(">> ") ;
    StartInput() ;
    int indexPenyanyi, indexAlbum, indexLagu;
    for (int i = 0 ; i< (*LP).NEff ; i++) {
        Kalimat Penyanyi = (*LP).PenyanyiAlbum[i].NamaPenyanyi ;
        Penyanyi.Length --;

        if (isKalimatEqual(Input, Penyanyi)) {
            copyKalimat(Input, &currentSong.artistName ) //&currentSong or currentSong not sure
            indexPenyanyi = i ;
            ListAlbum DaftarAlbum = (*LP).PenyanyiAlbum[i].ListAlbum ;
            printf("\nDaftar Album oleh %s :\n", Input.TabLine) ;
            for (int j = 0 ; j<DaftarAlbum.NEff ; j++) {
                MapLagu album = DaftarAlbum.AlbumLagu[j] ;
                printf("    %d. %s\n", j+1, album.NamaAlbum.TabLine) ;
            }
        }
    }
    printf("\nMasukkan Nama Album yang Dipilih :\n") ;
    printf(">> ") ;
    ListAlbum DaftarAlbum = (*LP).PenyanyiAlbum[indexPenyanyi].ListAlbum ;
    StartInput() ;
    for (int j = 0; j<DaftarAlbum.NEff ; j++) {
        Kalimat album = DaftarAlbum.AlbumLagu[j].NamaAlbum;
        album.Length--;

        if (isKalimatEqual(Input, album)) {
            copyKalimat(Input, &currentSong.albumName) //&currentSong or currentSong not sure
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
    Kalimat judulLagu = LP->PenyanyiAlbum[indexPenyanyi].ListAlbum.AlbumLagu[indexAlbum].IsiLagu.JudulLagu[idSong];
    judulLagu.Length -- ;
    Kalimat namaPenyanyi = LP->PenyanyiAlbum[indexPenyanyi].NamaPenyanyi ;
    printf("Nama Penyanyi: %s\n", namaPenyanyi.TabLine);
    printf("Memutar Lagu %s\n" , judulLagu.TabLine);
    copyKalimat(judulLagu, &currentSong.songName ) //&currentSong or currentSong not sure

    //empty songQue and songHist
    CreateStack(songHist);
    CreateQueue(songQue);
}

void PLAYPLAYLIST(Queue *songQue, Stack *songHist, DaftarPlaylist DP, SongDetails *currentSong){
    //print daftar playlist

    //milih playlist
    printf("\nMasukkan Nama Penyanyi yang Dipilih :\n") ;
    printf(">> ") ;
    StartInput() ;
}