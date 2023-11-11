#include <stdio.h>
#include "start.h"
#include "string.h"
#include "../ADT/mesin/mesinkata.h"
#include "../ADT/mesin/mesinkarakter.h"
#include "../ADT/mesin/mesinkalimat.h"
#include "../ADT/map2/map2.h"

//MASIH ERROR YANG LIST LAGU

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
        int indexPenyanyi;
        for (int i = 0; i < LP.NEff; i++){
            Kalimat Penyanyi = LP.PenyanyiAlbum[i].NamaPenyanyi;
            Penyanyi.Length -= 2;
            if (isKalimatEqual(Input, Penyanyi)){
                indexPenyanyi = i;
                ListAlbum DaftarAlbum = LP.PenyanyiAlbum[i].ListAlbum;
                printf("\nDaftar Album oleh %s :\n", Input.TabLine);
                for(int j=0; j<DaftarAlbum.NEff; j++){
                    MapLagu album = DaftarAlbum.AlbumLagu[j];
                    printf("    %d. %s\n", j+1, album.NamaAlbum.TabLine);
                }
		    }
        }
        printf("\nIngin melihat lagu yang ada? (Y/N): ");
        StartInput();
        if(isInputEqual(Input, "Y")){
            ListAlbum DaftarAlbum = LP.PenyanyiAlbum[indexPenyanyi].ListAlbum;
            printf("\nPilih album untuk melihat lagu yang ada di album: ");
            StartInput();

            for(int j=0; j<DaftarAlbum.NEff; j++){
                Kalimat album = DaftarAlbum.AlbumLagu[j].NamaAlbum;
                album.Length -= 2;
                // printf("%d\n",album.Length);
                // printf("%d\n",Input.Length);
                if (isKalimatEqual(Input, album)){
                    SetLagu DaftarLagu = DaftarAlbum.AlbumLagu[j].IsiLagu; 
                    printf("\nDaftar Lagu di");
                    printf(" %s :\n", Input.TabLine);
                    for(int k=0; k<DaftarLagu.Count;k++){
                    Kalimat lagu = DaftarLagu.JudulLagu[k];
                        printf("    %d. %s\n", k+1, lagu.TabLine);
                    }
                }
            }
        }else{
            return;
        }
    }else if(isInputEqual(Input, "N")){
        return;
    }else{
        printf("Input tidak valid.\n");
    } 
}

int main(){
    ListPenyanyi ls ;
    CreateListPenyanyi (&ls) ;
    printf(">> ");
    StartInput() ;   /* pakai ini untuk nerima inputnya.*/
    if (isInputEqual(Input, "START")) {
        STARTREAD(&ls) ;
        ListDefault(ls);
    } else {
        printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
    }
}