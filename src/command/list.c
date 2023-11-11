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
        if(IsMemberLP(LP, Input)){
            ListAlbum DaftarAlbum = ValueLP(LP, Input);
            for(int i=0; i<DaftarAlbum.NEff; i++){
                MapLagu album = DaftarAlbum.AlbumLagu[i];
                printf("    %d. %s\n", i+1, album.NamaAlbum.TabLine);
            }
        }
    }else if(isInputEqual(Input, "N")){
        return;
    }else{
        printf("Input tidak valid.");
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