#include "enhance.h"

boolean isSongExist(Playlist P, SongDetails S){
    addressNode Pn = P.First;
    while (Pn != Nil){
        if (isKalimatEqual(Pn->song.songName, S.songName) && isKalimatEqual(Pn->song.artistName, S.artistName)){
            return true;
        }
        Pn = Pn->Next;
    }
    return false;
}

void getRandomSong(ListPenyanyi LP, SongDetails *S){
    //get random penyanyi
    int randomPenyanyi = rand() % LP.NEff;
    //get penyanyi
    MapAlbum penyanyi = LP.PenyanyiAlbum[randomPenyanyi];
    //get random album
    int randomAlbum = rand() % penyanyi.ListAlbum.NEff;
    //get album
    MapLagu album = penyanyi.ListAlbum.AlbumLagu[randomAlbum];
    //get random lagu
    int randomLagu = rand() % album.IsiLagu.Count;
    //get lagu
    Kalimat songtitle = album.IsiLagu.JudulLagu[randomLagu];
    //get song
    (*S).albumName = album.NamaAlbum;
    (*S).artistName = penyanyi.NamaPenyanyi;
    (*S).songName = songtitle;
}

void insertRandomtoPlaylist(Playlist *P, SongDetails S, addressNode *prec){
    int random = rand() % NbElmt(*P);
    addressNode Pn = P->First;
    int i = 0;
    while (i <= random){
        *prec = Pn;
        Pn = Pn->Next;
        i++;
    }
    addressNode Pnew = Alokasi(S);
    InsertAfter(P, Pnew, *prec);
}

void enhance(DaftarPlaylist DP, ListPenyanyi LP){
    //check if daftar playlist empty
    if (IsDaftarPlaylistEmpty(DP)) {
        printf("\nDaftar Playlist Kosong. harap membuat playlist terlebih dahulu\n") ;
        return ;
    }
    //print daftar playlist
    ListPlaylist(DP) ;
    //milih playlist
    printf("\nMasukkan ID Playlist :\n") ;
    printf(">> ") ;
    StartInput() ;
    //turn kalimat to int
    int indexPlaylist = Input.TabLine[0] - 48 - 1;
    //check if indexPlaylist valid
    if (indexPlaylist < 0 || indexPlaylist >= DP.Neff) {
        printf("\nPlaylist tidak ditemukan\n") ;
        return ;
    }
    //get playlist
    Playlist playlist = DP.List[indexPlaylist];

    //check if playlist empty
    if(IsLinkListEmpty(playlist)){
        printf("\nPlaylist Kosong. harap menambahkan lagu terlebih dahulu\n") ;
        return ;
    }

    //insert song to playlist
    int i;
    int limit;
    int count;
    int precCount = 0;
    addressNode Prec[100];
    SongDetails song;
    int n = (NbElmt(playlist)/3);
    for (i = 0; i<n; i++){
        //get random song
        getRandomSong(LP, &song);
        //check if song exist in playlist
        limit = 50;
        count = 0;
        while (isSongExist(playlist, song) && count < limit) {
            getRandomSong(LP, &song);
            count++;
        }
        //if song found, insert to playlist
        if (count < limit){
            insertRandomtoPlaylist(&playlist, song, &Prec[precCount]);
            precCount++;
        }
        //if not, break
        else if (count >= limit||precCount>=100){
            break;
        }
    }

    //check if input successfull
    if (precCount == 0){
        printf("\nTidak ada lagu yang dapat ditambahkan ke playlist\n");
        return;
    }

    //print song in playlist
    PrintPlaylistSong(playlist);
    
    //add or remove song
    addressNode temp;
    for(i=0; i<precCount; i++){
        //print message
        printf("\nTambahkan lagu %s oleh %s ? (Y/N)\n", LineToString(Prec[i]->Next->song.songName), LineToString(Prec[i]->Next->song.artistName));
        printf(">> ") ;
        StartInput() ;
        //check if user input Y
        if (isInputEqual(Input, "Y")){
            //print message
            printf("\nLagu berhasil ditambahkan ke playlist\n");
        }
        //check if user input N
        else if (isInputEqual(Input, "N")){
            //remove song
            DelAfter(&playlist, &temp, Prec[i]);
            //print message
            printf("\nLagu berhasil dihapus dari playlist\n");
        }
    }

    //print song in playlist
    PrintPlaylistSong(playlist);
}




    // //get random song
    // SongDetails song;
    // int limit;
    // int count;
    // while(true){
    //     getRandomSong(LP, &song);
    //     //check if song exist in playlist
    //     limit = 50;
    //     count = 0;
    //     while (isSongExist(playlist, song) || count < limit) {
    //         getRandomSong(LP, &song);
    //         count++;
    //     }
    //     //check if song found
    //     if (count < limit){
    //         //print message
    //         printf("Tambahkan lagu %s oleh %s ? (Y/N)\n", LineToString(song.songName), LineToString(song.artistName));
    //         printf(">> ") ;
    //         StartInput() ;
    //         //check if user input Y
    //         if (isInputEqual(Input, "Y")){
    //             //insert song to playlist
    //             insertRandomtoPlaylist(&playlist, song);
    //             //print song in playlist
    //             PrintPlaylistSong(playlist);
    //             //print message
    //             printf("\nLagu berhasil ditambahkan ke playlist\n");
    //         }
    //         printf("\nLakukan Enhance Kembali? (Y/N)\n");
    //         printf(">> ") ;
    //         StartInput() ;
    //         //check if user input N
    //         if (isInputEqual(Input, "N")){
    //             return;
    //         }
    //     } else {
    //         printf("\nTidak ada lagu yang dapat ditambahkan ke playlist\n");
    //         return;
    //     }
    // }

