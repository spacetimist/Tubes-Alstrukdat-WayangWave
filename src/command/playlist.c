#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"

// ---------------------------------------------- PLAYLIST ------------------------------------------------------------
void createPlaylist(DaftarPlaylist *playlist){
    // playlist belum bisa dibuat
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
    printf("Silakan masukan lagu-lagu artis terkini kesayangan Anda!\n");
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
        // Penyanyi.Length--;  (ini kayaknya gaperlu lagi, soalnya udah dikurangin di fungsi start)
        // printf("%d\n",Penyanyi.Length);
        // printf("%d\n",Input.Length);
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
    ListAlbum DaftarAlbum = LP.PenyanyiAlbum[indexPenyanyi].ListAlbum;
    printf("\nPilih album untuk melihat lagu yang ada di album: ");
    StartInput();
    int indexAlbum;

    for(int j=0; j<DaftarAlbum.NEff; j++){
        Kalimat album = DaftarAlbum.AlbumLagu[j].NamaAlbum;
    //    album.Length--;
        // printf("%d\n",album.Length);
        // printf("%d\n",Input.Length);
        if (isKalimatEqual(Input, album)){
            indexAlbum = j;
            SetLagu DaftarLagu = DaftarAlbum.AlbumLagu[j].IsiLagu; 
            printf("\nDaftar Lagu di");
            printf(" %s :\n", Input.TabLine);
            for(int k=0; k<DaftarLagu.Count;k++){
            Kalimat lagu = DaftarLagu.JudulLagu[k];
                printf("    %d. %s\n", k+1, lagu.TabLine);
            }
        }
    }

    printf("Masukkan ID Lagu yang dipilih: ");
    StartInput();
    int indexLagu = Input.TabLine[0] - 48 - 1;
    if (indexLagu < DaftarAlbum.AlbumLagu[indexAlbum].IsiLagu.Count)
    {
        ListPlaylist(*daftar);
        printf("Masukkan ID Playlist yang dipilih: ");
        StartInput();
        int indexPlaylist = Input.TabLine[0] - 48 - 1;
        if (indexPlaylist < daftar->Neff)
        {
            SongDetails X;
            X.songName = DaftarAlbum.AlbumLagu[indexAlbum].IsiLagu.JudulLagu[indexLagu];
            X.albumName = DaftarAlbum.AlbumLagu[indexAlbum].NamaAlbum;
            X.artistName = LP.PenyanyiAlbum[indexPenyanyi].NamaPenyanyi;
            InsVLast(&((*daftar).List[indexPlaylist]), X);
            PrintPlaylistSong((*daftar).List[indexPlaylist]);
        }
    }
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
  //      Penyanyi.Length--;
        // printf("%d\n",Penyanyi.Length);
        // printf("%d\n",Input.Length);
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
    ListAlbum DaftarAlbum = LP.PenyanyiAlbum[indexPenyanyi].ListAlbum;
    printf("\nMasukkan nama album yang dipilih: ");
    StartInput();
    int indexAlbum;
    for(int j=0; j<DaftarAlbum.NEff; j++){
        Kalimat album = DaftarAlbum.AlbumLagu[j].NamaAlbum;
    //    album.Length--;
        // printf("%d\n",album.Length);
        // printf("%d\n",Input.Length);
        if (isKalimatEqual(Input, album)){
            indexAlbum = j;
            SetLagu DaftarLagu = DaftarAlbum.AlbumLagu[j].IsiLagu; 
            ListPlaylist(*daftar);
            printf("Masukkan ID Playlist yang dipilih: ");
            StartInput();
            int indexPlaylist = Input.TabLine[0] - 48 - 1;
            if (indexPlaylist < daftar->Neff)
            {
                SongDetails X;
                X.albumName = DaftarAlbum.AlbumLagu[indexAlbum].NamaAlbum;
                X.artistName = LP.PenyanyiAlbum[indexPenyanyi].NamaPenyanyi;
                for(int k=0; k<DaftarLagu.Count;k++){
                    X.songName = DaftarAlbum.AlbumLagu[indexAlbum].IsiLagu.JudulLagu[k];    
                    InsVLast(&((*daftar).List[indexPlaylist]), X);
                }
                PrintPlaylistSong((*daftar).List[indexPlaylist]);
            }
        }
    }
}

void PlaylistSwap(DaftarPlaylist *daftar, int id, int x, int y){
    addressNode P = First(daftar->List[id-1]);
    int h1 = 0;
    while (P != NULL)
    {
        h1++;
        if(h1 == x){
            break;
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
        } 
        Q = Next(Q);
    }

    SongDetails temp = Info(P);
    Info(P) = Info(Q);
    Info(Q) = temp;
    PrintPlaylistSong(((*daftar).List[id-1]));
}    

void PlaylistRemove(DaftarPlaylist *daftar, int id, int n)
{
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
    PrintPlaylistSong(((*daftar).List[id-1]));
}

void PlaylistDelete(DaftarPlaylist *daftar)
{
    printf("Masukkan ID Playlist yang dipilih: ");
    StartInput();
    int id = Input.TabLine[0] - 48 - 1;
    int j;
    for (j = id; j < daftar -> Neff; j++) {
        daftar -> List[j] = daftar -> List [j+1];
    }
    daftar -> Neff -= 1;    
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
		while (P != Nul){
			printf("%s\n", LineToString(Info(P).songName));
			P = Next(P);
		}
	}
}