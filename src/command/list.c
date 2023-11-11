#include <stdio.h>
#include "start.h"
#include "string.h"
#include "../ADT/mesin/mesinkata.h"
#include "../ADT/mesin/mesinkarakter.h"
#include "../ADT/mesin/mesinkalimat.h"
#include "../ADT/map2/map2.h"

//MASIH ERROR SETENGAH

void ListDefault(ListPenyanyi LP){
    printf("\nDaftar Penyanyi :\n");

    for(int i=0; i<LP.NEff; i++){
        printf("    %d. %s\n", i+1, LP.PenyanyiAlbum[i].NamaPenyanyi.TabLine);
    }

    printf("\nIngin melihat album yang ada? (Y/N): ");
    StartInput();
    if(isInputEqual(Input, "Y")){
        printf("\nPilih penyanyi untuk melihat album mereka: ");
        StartInput();
        for (int i = 0; i < LP.NEff; i++){
            char *albumNow = LP.PenyanyiAlbum[i].NamaPenyanyi.TabLine;
            if (isInputEqual(Input, albumNow)){
                ListAlbum DaftarAlbum = LP.PenyanyiAlbum[i].ListAlbum;
                for(int j=0; j<DaftarAlbum.NEff; j++){
                    MapLagu album = DaftarAlbum.AlbumLagu[j];
                    printf("    %d. %s\n", j+1, album.NamaAlbum.TabLine);
                }
		    }
        }
    }else if(isInputEqual(Input, "N")){
        return;
    }else{
        printf("Input tidak valid.\n");
    } 
}

// int main(){
//     printf(">> ");
//     STARTWORD() ;
//     ListPenyanyi ls ;
//     CreateListPenyanyi (&ls) ;
//     if (IsKataEqual(currentWord, "LIST")) {
//         STARTREAD(&ls);
//         ListDefault(ls);
//     } else {
//         return 0 ;
//     }
// }