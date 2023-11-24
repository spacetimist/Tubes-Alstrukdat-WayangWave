#include <stdio.h>
#include "start.h"
#include "string.h"
#include "list.h"

void ListDefault(ListPenyanyi LP){
    int indexPenyanyi, indexAlbum;

    printf("\nDaftar Penyanyi :\n");

    for(int i=0; i<LP.NEff; i++){
        printf("    %d. %s\n", i+1, LP.PenyanyiAlbum[i].NamaPenyanyi.TabLine);
    }

    printf("\nIngin melihat album yang ada? (Y/N): ");
    StartInput();
    if(isInputEqual(Input, "Y")){
        printf("\nPilih penyanyi untuk melihat album mereka: ");
        StartInput();
        int i = 0 ; boolean found = false ;
        while (i< LP.NEff && (found == false)) {
            Kalimat Penyanyi = LP.PenyanyiAlbum[i].NamaPenyanyi;
            if (isKalimatEqual(Input, Penyanyi)) {
                found = true ;
                indexPenyanyi = i ;
            } else {i++ ;}}
            if (found == true) {
                ListAlbum DaftarAlbum = LP.PenyanyiAlbum[indexPenyanyi].ListAlbum;
                printf("\nDaftar Album oleh %s :\n", Input.TabLine);
                for (int j=0 ; j< DaftarAlbum.NEff; j++) {
                    MapLagu album = DaftarAlbum.AlbumLagu[j] ;
                    printf("    %d. %s\n",j+1, album.NamaAlbum.TabLine );
                }
            }
            else if (found == false) {
                printf("\nArtis tidak dikenali. Silahkan coba lagi!\n\n");
                return;
            }
        
        // for (int i = 0; i < LP.NEff; i++){
        //     Kalimat Penyanyi = LP.PenyanyiAlbum[i].NamaPenyanyi;
        //     // printf("%d\n",Penyanyi.Length);
        //     // printf("%d\n",Input.Length);
        //     if (isKalimatEqual(Input, Penyanyi)){
        //         indexPenyanyi = i;
        //         ListAlbum DaftarAlbum = LP.PenyanyiAlbum[indexPenyanyi].ListAlbum;
        //         printf("\nDaftar Album oleh %s :\n", Input.TabLine);
        //         for(int j=0; j<DaftarAlbum.NEff; j++){
        //             MapLagu album = DaftarAlbum.AlbumLagu[j];
        //             printf("    %d. %s\n", j+1, album.NamaAlbum.TabLine);
        //         }
		//     }
        //     else if(!isKalimatEqual(Input, Penyanyi) && i+1 == LP.NEff) {
        //         printf("\nArtis tidak dikenali. Silahkan coba lagi!\n\n");
        //         return;
        //     }
        // }
        // printf("%d\n", indexPenyanyi);
        printf("\nIngin melihat lagu yang ada? (Y/N): ");
        StartInput();
        if(isInputEqual(Input, "Y")){
            ListAlbum DaftarAlbum = LP.PenyanyiAlbum[indexPenyanyi].ListAlbum;
            printf("\nPilih album untuk melihat lagu yang ada di album: ");
            StartInput();
            boolean cek = false; int j = 0;
            while (j<DaftarAlbum.NEff && (cek==false)) {
                Kalimat album = DaftarAlbum.AlbumLagu[j].NamaAlbum;
                if (isKalimatEqual(Input, album)) {
                    cek = true ;
                    indexAlbum = j;
                } else {j++;}
            }
            if (cek == true) {
                SetLagu DaftarLagu = DaftarAlbum.AlbumLagu[indexAlbum].IsiLagu ;
                printf("\nDaftar Lagu di %s :\n", Input.TabLine) ;
                for (int k=0; k< DaftarLagu.Count; k++) {
                    Kalimat lagu = DaftarLagu.JudulLagu[k];
                    printf("    %d. %s\n", k+1, lagu.TabLine);
                }
            }
            else if (cek == false) {
                printf("\nAlbum tidak dikenali. Silahkan coba lagi!\n\n");
                return;
            }

            // for(int j=0; j<DaftarAlbum.NEff; j++){
            //     Kalimat album = DaftarAlbum.AlbumLagu[j].NamaAlbum;
            //     // printf("%d\n",album.Length);
            //     // printf("%d\n",Input.Length);
            //     indexAlbum = j;
            //     if (isKalimatEqual(Input, album)){
            //         SetLagu DaftarLagu = DaftarAlbum.AlbumLagu[j].IsiLagu; 
            //         printf("\nDaftar Lagu di");
            //         printf(" %s :\n", Input.TabLine);
            //         for(int k=0; k<DaftarLagu.Count;k++){
            //         Kalimat lagu = DaftarLagu.JudulLagu[k];
            //             printf("    %d. %s\n", k+1, lagu.TabLine);
            //         }
            //     }else if(!isKalimatEqual(Input, album) && j+1 == DaftarAlbum.NEff) {
            //         printf("\nArtis tidak dikenali. Silahkan coba lagi!\n\n");
            //         return;
            //     }
            // }
            // printf("\n");
        }
    }else if(isInputEqual(Input, "N")){
        return;
    }else{
        printf("Input tidak valid.\n");
    } 
}

void ListPlaylist(DaftarPlaylist DP){
    printf("\nDaftar Playlist yang kamu miliki:\n");
    if(!IsDaftarPlaylistEmpty(DP)){
        for(int i=0; i<DP.Neff; i++){
            printf("    %d. %s\n", i+1, DP.List[i].PlaylistName.TabLine);
        }
    }else{
        printf("\nKamu tidak memiliki playlist.\n");
    }   
}

// int main(){
//     ListPenyanyi ls ;
//     CreateListPenyanyi (&ls) ;
//     printf(">> ");
//     StartInput() ;   /* pakai ini untuk nerima inputnya.*/
//     if (isInputEqual(Input, "START")) {
//         STARTREAD(&ls) ;
//         ListDefault(ls);
//     } else {
//         printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
//     }
// }