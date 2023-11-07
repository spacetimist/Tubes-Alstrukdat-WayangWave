#include <stdio.h>
#include "start.h"
#include "stdlib.h"
#include "../ADT/mesin/mesinkata.h"
#include "../ADT/mesin/mesinkarakter.h"
#include "../ADT/mesin/mesinkalimat.h"
#include "../ADT/map2/map2.h"

//MASIH ERROR

void ListDefault(ListPenyanyi *LP){
    printf("\nDaftar Penyanyi :\n");

    for(int i=0; i<LP->NEff; i++){
        printf("    %d. %s\n", i+1, LP->PenyanyiAlbum[i].NamaPenyanyi.TabLine);
    }

    char YN[1];
    char input[NMaks]; //mesin kalimat
    ListAlbum DaftarAlbum = Value2(*LP, input);

    printf("\nIngin melihat album yang ada? (Y/N): ");
    scanf("%s", YN);
    if(YN == "Y"){
        printf("\nPilih penyanyi untuk melihat album mereka: ");
        scanf("%[^\n]s", input);;
        if(IsMember2(*LP, input)){
            printf("\nDaftar Album oleh %s : :\n", input);
            for(int i=0; i<DaftarAlbum.NEff; i++){
                printf("    %d. %s\n", i+1, DaftarAlbum.AlbumLagu[i].NamaAlbum.TabLine);
            }
        }
    }
}