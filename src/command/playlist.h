// #include "../ADT/mesin/mesinkata.h"
// #include "../ADT/mesin/mesinkarakter.h"
#include "../ADT/mesin/mesinkalimat.h"
#include "../ADT/map2/map2.h"
#include "../ADT/listlinier/listlinier.h"
<<<<<<< HEAD
#include "boolean.h"
=======
// #include "../ADT/queue/queue.h"
// #include "../ADT/set/set.h"
// #include "../command/start.h"
#include "../ADT/boolean.h"
>>>>>>> 06c8d9e179eb099ddad6d13e8f4401bb4e38fe34

#define initial_cap 100
typedef struct tsongNode *addressNode;
typedef struct {
    Kalimat songName;
    Kalimat artistName;
    Kalimat albumName;
} SongDetails;
typedef struct tsongNode{
    SongDetails song;
    addressNode Next;
}SongNode;

typedef struct {
    addressNode First;
    Kalimat PlaylistName;
}Playlist;

typedef struct{
    Playlist *List;
    int capacity;
    int Neff;
}DaftarPlaylist;
/*menggunakan list dinamis
I.S capacity = initial_cap */

void createDaftarPlaylist(DaftarPlaylist *daftar);

// daftar
void createPlaylist(DaftarPlaylist *daftar);


void InsVLastDaftarPlaylist(DaftarPlaylist *daftar, Playlist value);

void PlaylistAdd(DaftarPlaylist *daftar, ListPenyanyi LP);

// void playlistAdd(List *singer);

// void playlistSwap(a, b, c);

// void playlistRemove(a, b);

// void playlistDelete();