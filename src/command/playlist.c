#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"

// ---------------------------------------------- PLAYLIST ------------------------------------------------------------
void createPlaylist(DaftarPlaylist *playlist){
    printf("Masukkan nama playlist yang ingin dibuat : ");
    StartInput();
    Playlist currentPlaylist;
    CreateLinkList(&currentPlaylist);

    //validasi 3 karakter non blank
    while(lengthNoBlanks(LineToString(Input)) < 3){
        printf("Length: %d\n", lengthNoBlanks(LineToString(Input)));
        printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.\n");
        printf("Masukkan nama playlist yang ingin dibuat : ");
        StartInput();
    }

    currentPlaylist.PlaylistName = Input;
    printf("\n");
    printf("Playlist %s berhasil dibuat!\n", currentPlaylist.PlaylistName.TabLine);
    InsVLastDaftarPlaylist(playlist, currentPlaylist);
    ListPlaylist(*playlist);
    printf("Silakan masukan lagu-lagu artis terkini kesayangan Anda!\n\n");
}

void PlaylistAddSong(DaftarPlaylist *daftar, ListPenyanyi LP)
{
    printf("\nDaftar Penyanyi :\n");

    for(int i=0; i<LP.NEff; i++){
        printf("    %d. %s\n", i+1, LP.PenyanyiAlbum[i].NamaPenyanyi.TabLine);
    }

    printf("\nPilih penyanyi untuk melihat album mereka: ");
    StartInput();
    int indexPenyanyi;
    for (int i = 0; i < LP.NEff; i++){
        Kalimat Penyanyi = LP.PenyanyiAlbum[i].NamaPenyanyi;
        if (isKalimatEqual(Input, Penyanyi)){
            indexPenyanyi = i;
            ListAlbum DaftarAlbum = LP.PenyanyiAlbum[i].ListAlbum;
            printf("\nDaftar Album oleh %s :\n", Input.TabLine);
            for(int j=0; j<DaftarAlbum.NEff; j++){
                MapLagu album = DaftarAlbum.AlbumLagu[j];
                printf("    %d. %s\n", j+1, album.NamaAlbum.TabLine);
            }
            break;
        }
        if(!isKalimatEqual(Input, Penyanyi) && i == (LP.NEff)-1){
            printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi.\n\n", Input.TabLine);
            return;
        }
    
    }
    ListAlbum DaftarAlbum = LP.PenyanyiAlbum[indexPenyanyi].ListAlbum;
    printf("\nPilih album untuk melihat lagu yang ada di album: ");
    StartInput();
    int indexAlbum;

    for(int j=0; j<DaftarAlbum.NEff; j++){
        Kalimat album = DaftarAlbum.AlbumLagu[j].NamaAlbum;
        if (isKalimatEqual(Input, album)){
            indexAlbum = j;
            SetLagu DaftarLagu = DaftarAlbum.AlbumLagu[j].IsiLagu; 
            printf("\nDaftar Lagu di");
            printf(" %s :\n", Input.TabLine);
            for(int k=0; k<DaftarLagu.Count;k++){
            Kalimat lagu = DaftarLagu.JudulLagu[k];
                printf("    %d. %s\n", k+1, lagu.TabLine);
            }
            break;
        }
        if(!isKalimatEqual(Input, album) && j == (DaftarAlbum.NEff)-1){
            printf("Album %s tidak ada dalam daftar. Silakan coba lagi.\n\n", Input.TabLine);
            return;
        }
    }

    printf("Masukkan ID Lagu yang dipilih: ");
    StartInput();
    int indexLagu = Input.TabLine[0] - 48 - 1;
    int indexPlaylist;
    if (indexLagu < DaftarAlbum.AlbumLagu[indexAlbum].IsiLagu.Count)
    {
        ListPlaylist(*daftar);
        printf("Masukkan ID Playlist yang dipilih: ");
        StartInput();
        indexPlaylist = Input.TabLine[0] - 48 - 1;
        if(indexPlaylist >= daftar->Neff){
            printf("ID Playlist tidak terdaftar!\n\n");
            return;
        }
        SongDetails X;
        X.songName = DaftarAlbum.AlbumLagu[indexAlbum].IsiLagu.JudulLagu[indexLagu];
        X.albumName = DaftarAlbum.AlbumLagu[indexAlbum].NamaAlbum;
        X.artistName = LP.PenyanyiAlbum[indexPenyanyi].NamaPenyanyi;
        InsVLast(&((*daftar).List[indexPlaylist]), X);
        printf("Lagu dengan judul “%s” pada album %s oleh penyanyi %s berhasil ditambahkan ke dalam playlist %s.\n\n", LineToString(X.songName), LineToString(X.albumName), LineToString(X.artistName), LineToString((*daftar).List[indexPlaylist].PlaylistName));
    }else{
        printf("ID lagu tidak terdaftar! Silakan coba lagi.\n\n");
        return;
    }
    PrintPlaylistSong((*daftar).List[indexPlaylist]);
}

void PlaylistAddAlbum(DaftarPlaylist *daftar, ListPenyanyi LP)
{
    printf("\nDaftar Penyanyi :\n");

    for(int i=0; i<LP.NEff; i++){
        printf("    %d. %s\n", i+1, LP.PenyanyiAlbum[i].NamaPenyanyi.TabLine);
    }
    int indexPenyanyi;
    printf("\nPilih penyanyi untuk melihat album mereka: ");
    StartInput();
    for (int i = 0; i < LP.NEff; i++){
        Kalimat Penyanyi = LP.PenyanyiAlbum[i].NamaPenyanyi;
        if (isKalimatEqual(Input, Penyanyi)){
            indexPenyanyi = i;
            ListAlbum DaftarAlbum = LP.PenyanyiAlbum[i].ListAlbum;
            printf("\nDaftar Album oleh %s :\n", Input.TabLine);
            for(int j=0; j<DaftarAlbum.NEff; j++){
                MapLagu album = DaftarAlbum.AlbumLagu[j];
                printf("    %d. %s\n", j+1, album.NamaAlbum.TabLine);
            }
            break;
        }
        if(!isKalimatEqual(Input, Penyanyi) && i == (LP.NEff)-1){
            printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi.\n\n", Input.TabLine);
            return;
        }
    
    }
    ListAlbum DaftarAlbum = LP.PenyanyiAlbum[indexPenyanyi].ListAlbum;
    printf("\nMasukkan nama album yang dipilih: ");
    StartInput();
    int indexAlbum, indexPlaylist;
    for(int j=0; j<DaftarAlbum.NEff; j++){
        Kalimat album = DaftarAlbum.AlbumLagu[j].NamaAlbum;
        if (isKalimatEqual(Input, album)){
            indexAlbum = j;
            SetLagu DaftarLagu = DaftarAlbum.AlbumLagu[j].IsiLagu; 
            ListPlaylist(*daftar);
            printf("Masukkan ID Playlist yang dipilih: ");
            StartInput();
            indexPlaylist = Input.TabLine[0] - 48 - 1;
            if(indexPlaylist >= daftar->Neff){
            printf("ID Playlist tidak terdaftar!\n\n");
            return;
            }else
            {
                SongDetails X;
                X.albumName = DaftarAlbum.AlbumLagu[indexAlbum].NamaAlbum;
                X.artistName = LP.PenyanyiAlbum[indexPenyanyi].NamaPenyanyi;
                for(int k=0; k<DaftarLagu.Count;k++){
                    X.songName = DaftarAlbum.AlbumLagu[indexAlbum].IsiLagu.JudulLagu[k];    
                    InsVLast(&((*daftar).List[indexPlaylist]), X);
                }
                printf("Album dengan judul “%s” berhasil ditambahkan ke dalam pada playlist pengguna “%s”.\n\n", LineToString(X.albumName), LineToString((*daftar).List[indexPlaylist].PlaylistName));
            }
            break;
        }
        if(!isKalimatEqual(Input, album) && j == (DaftarAlbum.NEff)-1){
            printf("Album %s tidak ada dalam daftar. Silakan coba lagi.\n\n", Input.TabLine);
            return;
        }
    }
    PrintPlaylistSong((*daftar).List[indexPlaylist]);
}

void PlaylistSwap(DaftarPlaylist *daftar, int id, int x, int y){
    if(id > daftar->Neff){
        printf("Tidak ada playlist dengan playlist ID %d.\n\n", id);
        return;
    }
    addressNode P = First(daftar->List[id-1]);
    int h1 = 0;
    while (P != NULL)
    {
        h1++;
        if(h1 == x){
            break;
        }else if(Next(P) == NULL && h1 != x){
            printf("Tidak ada lagu dengan urutan %d di playlist “%s”.\n\n", x, LineToString(daftar->List[id-1].PlaylistName));
            return;
        } 
        P = Next(P);
    }

    addressNode Q = First(daftar->List[id-1]);
    int h2 = 0;
    while (Q != NULL)
    {
        h2++;
        if(h2 == y){
            break;
        }else if(Next(Q) == NULL && h2 != y){
            printf("Tidak ada lagu dengan urutan %d di playlist “%s”.\n\n", y, LineToString(daftar->List[id-1].PlaylistName));
            return;
        } 
        Q = Next(Q);
    }

    SongDetails temp = Info(P);
    Info(P) = Info(Q);
    Info(Q) = temp;
    printf("Berhasil menukar lagu dengan nama “%s” dengan “%s” di playlist “%s”.\n\n", LineToString(Info(Q).songName), LineToString(Info(P).songName), LineToString(daftar->List[id-1].PlaylistName));
    PrintPlaylistSong((*daftar).List[id]);
}    

void PlaylistRemove(DaftarPlaylist *daftar, int id, int n)
{
    if(id > daftar->Neff){
        printf("Tidak ada playlist dengan playlist ID %d.\n\n", id);
        return;
    }
    int count;

    // Mencari address x
    count = 0;
    addressNode addressNPrev = ((*daftar).List[id-1]).First;
    if (n != 1)
    {
        while (count < n - 2)
        {
            count++;
            addressNPrev = (((*daftar).List[id-1]).First)->Next;
        }

        addressNPrev->Next = (addressNPrev->Next)->Next;
    }
    else
    {
        ((*daftar).List[id-1]).First = (((*daftar).List[id-1]).First)->Next;
    }
    Playlist playlist = (*daftar).List[id];
    printf("Lagu dengan urutan %d telah dihapus dari playlist “%s”!\n\n", n, LineToString(playlist.PlaylistName));
    PrintPlaylistSong((*daftar).List[id]);
}

void PlaylistDelete(DaftarPlaylist *daftar)
{
    printf("Masukkan ID Playlist yang dipilih: ");
    StartInput();
    int id = Input.TabLine[0] - 48 - 1;
    if(id >= daftar->Neff){
        printf("Tidak ada playlist dengan playlist ID %d.\n\n", id+1);
        return;
    }
    Kalimat playlistName = (*daftar).List[id].PlaylistName;
    int j;
    for (j = id; j < daftar -> Neff; j++) {
        daftar -> List[j] = daftar -> List [j+1];
    }
    daftar -> Neff -= 1;  
    printf("Playlist dengan judul “%s” berhasil dihapus.\n\n", LineToString(playlistName)); 
    PrintPlaylistSong((*daftar).List[id]);
}

void InsVLastDaftarPlaylist(DaftarPlaylist *daftar, Playlist value)
{
    int idx = daftar->Neff;
    if (idx == daftar->capacity)
    {
        (*daftar).List = (Playlist*) malloc (2 * idx * sizeof(Playlist));
    }
    (*daftar).List[idx] = value;
    (*daftar).Neff += 1;
}

void PrintPlaylistSong (Playlist L){

	if (IsLinkListEmpty(L)){
		printf("Playlist kosong.\n");
	} else {
	    addressNode P = First(L);
        printf("%s:\n", L.PlaylistName.TabLine);
		while (P != Nul){
			printf("%s\n", LineToString(Info(P).songName));
			P = Next(P);
		}
	}
    printf("\n");
}