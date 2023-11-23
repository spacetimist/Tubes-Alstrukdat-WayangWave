#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"

void enchance(DaftarPlaylist DP, ListPenyanyi LP);
/*I.S. DP dan LP terdefinisi
F.S. Playlist berisi lagu yang di enhance apabila di add oleh user.*/

boolean isSongExist(Playlist P, SongDetails S);
// Mengembalikan true jika lagu S ada di playlist P

void insertRandomtoPlaylist(Playlist *P, SongDetails S, addressNode *prec);
// Menambahkan lagu S ke playlist P

void getRandomSong(ListPenyanyi LP, SongDetails *S);
// Mengembalikan lagu random dari list penyanyi LP