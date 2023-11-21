#include "quit.h"
#include <stdio.h>
#include <stdlib.h>

void quit(){
    printf("Apakah kamu ingin menyimpan data sesi sekarang? (Y/N) ");
    StartInput();
    if(isInputEqual(Input, "Y")){
        save();
    }else if(isInputEqual(Input, "N")){
        printf("Kamu keluar dari WayangWave.\nDadah ^_^/\n\n");
        exit(0);
    }
}