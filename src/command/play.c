#include "play.h"
#include <stdlib.h>

void PLAYSONG(Queue *songQue, Stack *songHist, Kalimat songName, Kalimat artistName){
    //empty songQue and songHist
    CreateStack(songHist);
    CreateQueue(songQue);
}

void PlaySong(ListPenyanyi * LP, CurrentSong * CS) {
    printf("\nDaftar Penyanyi :\n") ;
    for (int i = 0 ; i < (*LP).NEff ; i++) {
        printf("    %d. %s\n", i+1, (*LP).PenyanyiAlbum[i].NamaPenyanyi.TabLine);
    }

    printf("\nMasukkan Nama Penyanyi yang Dipilih :\n") ;
    printf(">> ") ;
    StartInput() ;
    int indexPenyanyi, indexAlbum, indexLagu;
    for (int i = 0 ; i< (*LP).NEff ; i++) {
        Kalimat Penyanyi = (*LP).PenyanyiAlbum[i].NamaPenyanyi ;
        Penyanyi.Length --;

        if (isKalimatEqual(Input, Penyanyi)) {
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
    printf("Memutar Lagu %s\n" , judulLagu.TabLine) ;

}
void PLAYPLAYLIST();