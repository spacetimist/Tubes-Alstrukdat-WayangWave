#include "quit.h"
#include <stdio.h>
#include <stdlib.h>

void quit(ListPenyanyi * LP, char namafile[] ,Queue *songQue, Stack *riwayatlagu, SongDetails *currentSong, DaftarPlaylist *daftar){
    printf("Apakah kamu ingin menyimpan data sesi sekarang? (Y/N) ");
    StartInput();
    if(isInputEqual(Input, "Y")){
        if (namafile.Length == 0){
            printf("Masukkan nama file: ");
            StartInput();
            namafile = Directory(Input) ;
        }
        SAVEFILE(LP, namafile, songQue, riwayatlagu, currentSong, daftar);
    }else if(isInputEqual(Input, "N")){
        printf("Kamu keluar dari WayangWave.\nDadah ^_^/\n\n");
    }
    exit(0);
}