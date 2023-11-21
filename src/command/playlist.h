#include "../ADT/mesin/mesinkata.h"
#include "../ADT/mesin/mesinkarakter.h"
#include "../ADT/mesin/mesinkalimat.h"
#include "../ADT/map2/map2.h"
#include "../ADT/listlinier/playlistADT.h"
#include "../ADT/listlinier/listlinier.h"
#include "../ADT/boolean.h"
#include "../ADT/listDin/listDin.h"
#include "list.h"

// primitif
void PrintPlaylistSong (Playlist L);

void InsVLastDaftarPlaylist(DaftarPlaylist *daftar, Playlist value);

// fungsi utama
void createPlaylist(DaftarPlaylist *daftar);

void PlaylistAddSong(DaftarPlaylist *daftar, ListPenyanyi LP);

void PlaylistAddAlbum(DaftarPlaylist *daftar, ListPenyanyi LP);

void PlaylistSwap(DaftarPlaylist *daftar, int id, int x, int y);

void PlaylistRemove(DaftarPlaylist *daftar, int id, int n);

void PlaylistDelete(DaftarPlaylist *daftar);
