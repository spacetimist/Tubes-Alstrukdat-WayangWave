#include "save.h"

void SAVEFILE(ListPenyanyi * LP, char namafile[] ,Queue *songQue, Stack *riwayatlagu, SongDetails *currentSong, DaftarPlaylist *daftar) {
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
    fprintf(save, "%s;%s;%s\n", LineToString((*currentSong).artistName), LineToString((*currentSong).albumName), LineToString((*currentSong).songName));
    fprintf(save, "%d\n", queueLength(*songQue)) ;
    for (int i = 0 ; i < queueLength(*songQue); i++) {
        fprintf(save, "%s;%s;%s\n", LineToString((*songQue).buffer[i].artistName), LineToString((*songQue).buffer[i].albumName), LineToString((*songQue).buffer[i].songName));
    }
    fprintf(save, "%d\n", stackLength(*riwayatlagu)) ;
    for (int i = stackLength(*riwayatlagu)-1 ; i>= 0 ; i--) {
        fprintf(save, "%s;%s;%s\n", LineToString((*riwayatlagu).buffer[i].artistName), LineToString((*riwayatlagu).buffer[i].albumName), LineToString((*riwayatlagu).buffer[i].songName));
    }

    fprintf(save, "%d\n", (*daftar).Neff) ;
    for (int i= 0 ; i< (*daftar).Neff; i++) {
        fprintf(save,"%d ", NbElmt(daftar->List[i])) ;
        fprintf(save, "%s\n", (*daftar).List[i].PlaylistName.TabLine) ;
        addressNode P = daftar->List[i].First;
        while(P!=NULL) {
            fprintf(save, "%s;%s;%s\n", LineToString(P->song.artistName), LineToString(P->song.albumName), LineToString(P->song.songName ));
            P = Next(P);
        }
    }
    fclose(save) ;
}