#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"

// ---------------------------------------------- PLAYLIST ------------------------------------------------------------
void createPlaylist(DaftarPlaylist *playlist){
    // playlist belum bisa dibuat
    printf("Masukkan nama playlist yang ingin dibuat : ");
    StartInput();
    Playlist currentPlaylist;
    currentPlaylist.PlaylistName = Input;
        // menghitung banyak karakter
        // for (int i = 0; i < EOP; i++){
        //     count++;
        // }
        // if (count < 3) {
        //     printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.");
        //     sesuai = true;
        // }
        // else sesuai = false;

    // = currentWord
    // printWord(namaplaylist)
    // playlist bisa dibuat
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
   //     Penyanyi.Length--;  (ini kayaknya gaperlu lagi, soalnya udah dikurangin di fungsi start)
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
        printf("Masukkan ID Playlist yang dipilih: ");
        ListPlaylist(*daftar);
        printf("Masukkan ID Playlist yang dipilih: ");
        StartInput();
        int indexPlaylist = Input.TabLine[0] - 48 - 1;
        if (indexPlaylist < daftar->Neff)
        {
            Playlist currentPlaylist = (*daftar).List[indexPlaylist - 1];
            addressNode currentSongAddress = currentPlaylist.First;
            (*currentSongAddress).song.songName = DaftarAlbum.AlbumLagu[indexAlbum].IsiLagu.JudulLagu[indexLagu];
            (*currentSongAddress).song.albumName = DaftarAlbum.AlbumLagu[indexAlbum].NamaAlbum;
            (*currentSongAddress).song.artistName = LP.PenyanyiAlbum[indexPenyanyi].NamaPenyanyi;

            (*daftar).List[indexPlaylist] = currentPlaylist;
            PrintPlaylistSong(currentPlaylist);
        }
    }
}

void PlaylistAddAlbum(DaftarPlaylist *daftar, ListPenyanyi LP)
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
    
}

void PlaylistSwap(DaftarPlaylist *daftar, int id, int x, int y)
{
    Playlist currentPlaylist = (*daftar).List[id-1];
    int count;

    // Mencari address x
    count = 0;
    addressNode addressX = currentPlaylist.First;
    while (count < x - 1)
    {
        count++;
        addressX = (currentPlaylist.First)->Next;
    }

    // Mencari address y
    count = 0;
    addressNode addressY = currentPlaylist.First;
    while (count < x - 1)
    {
        count++;
        addressY = (currentPlaylist.First)->Next;
    }

    SongDetails temp = addressX->song;
    addressX->song = addressY->song;
    addressY->song = temp;

    (*daftar).List[id-1] = currentPlaylist;
}

void PlaylistRemove(DaftarPlaylist *daftar, int id, int n)
{
    Playlist currentPlaylist = (*daftar).List[id-1];
    int count;

    // Mencari address x
    count = 0;
    addressNode addressNPrev = currentPlaylist.First;
    if (n != 1)
    {
        while (count < n - 2)
        {
            count++;
            addressNPrev = (currentPlaylist.First)->Next;
        }

        addressNPrev->Next = (addressNPrev->Next)->Next;
    }
    else
    {
        currentPlaylist.First = (currentPlaylist.First)->Next;
    }
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

void createDaftarPlaylist(DaftarPlaylist *daftar)
{
    (*daftar).List = (Playlist*) malloc (10 * sizeof(Playlist));
    (*daftar).capacity = 10;
    (*daftar).Neff = 0;
}

boolean isLinkListEmpty (Playlist L){
	return L.First == Nul; 
}

void PrintPlaylistSong (Playlist L){
	addressNode P = L.First;

	if (isLinkListEmpty(L)){
		printf("Playlist kosong.");
	} else {
		while (P->Next != Nul){
			P = P->Next;
			printf("%s\n", P->song.songName.TabLine);
		}
	}
}