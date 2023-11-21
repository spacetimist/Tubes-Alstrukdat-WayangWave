#include "save.h"

void SAVEFILE(ListPenyanyi * LP, char namafile[] ,Queue *songQue) {
    save = fopen(namafile, "w") ;

    fprintf(save, "%d\n", (*LP).NEff ) ;
    for (int i = 0 ; i < (*LP).NEff; i++) {
        fprintf(save, "%d %s\n", (*LP).PenyanyiAlbum[i].ListAlbum.NEff , (*LP).PenyanyiAlbum[i].NamaPenyanyi.TabLine) ;
    
        for (int j = 0 ; j < (*LP).PenyanyiAlbum[i].ListAlbum.NEff; j++) {
            fprintf(save, "%d %s\n", (*LP).PenyanyiAlbum[i].ListAlbum.AlbumLagu[j].IsiLagu.Count, (*LP).PenyanyiAlbum[i].ListAlbum.AlbumLagu[j].NamaAlbum.TabLine) ;

            for (int k = 0 ; k < (*LP).PenyanyiAlbum[i].ListAlbum.AlbumLagu[j].IsiLagu.Count; k++)  {      
                fprintf(save, "%s\n", (*LP).PenyanyiAlbum[i].ListAlbum.AlbumLagu[j].IsiLagu.JudulLagu[k].TabLine) ;
            }   
        }

    }
    fclose(save) ;
}