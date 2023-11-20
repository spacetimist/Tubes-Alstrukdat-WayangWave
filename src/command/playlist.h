#include "../ADT/mesin/mesinkata.h"
#include "../ADT/mesin/mesinkarakter.h"
#include "../ADT/mesin/mesinkalimat.h"
#include "../ADT/map2/map2.h"
#include "../ADT/listlinier/listlinier.h"
#include "../ADT/boolean.h"
#include "../ADT/listDin/listDin.h"

// typedef struct{
//     Playlist *List;
//     int capacity;
//     int Neff;
// }DaftarPlaylist;
/*menggunakan list dinamis
I.S capacity = initial_cap */

void createDaftarPlaylist(DaftarPlaylist *daftar);

// daftar
void createPlaylist(DaftarPlaylist *daftar);

void InsVLastDaftarPlaylist(DaftarPlaylist *daftar, Playlist value);

void PlaylistAddSong(DaftarPlaylist *daftar, ListPenyanyi LP);

void PlaylistAddAlbum(DaftarPlaylist *daftar, ListPenyanyi LP);

void PrintPlaylistSong (Playlist L);

boolean isLinkListEmpty (Playlist L);

// void playlistAdd(List *singer);

// void playlistSwap(a, b, c);

// void playlistRemove(a, b);

// void playlistDelete();