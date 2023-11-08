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

    char YN[1];
    char input[NMaks]; //mesin kalimat
    ListAlbum DaftarAlbum = Value2(LP, input);

    printf("\nIngin melihat album yang ada? (Y/N): ");
    scanf("%s", YN);
    if(strcmp(YN, "Y")==0){
        printf("\nPilih penyanyi untuk melihat album mereka: ");
        scanf("%[^\n]s", input);
        if(IsMember2(LP, input)){
            printf("\nDaftar Album oleh %s :\n", input);
            for(int i=0; i<DaftarAlbum.NEff; i++){
                printf("    %d. %s\n", i+1, DaftarAlbum.AlbumLagu[i].NamaAlbum.TabLine);
            }
        }
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