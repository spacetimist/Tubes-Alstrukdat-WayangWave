#include "../ADT/mesin/mesinkata.h"
#include "../ADT/mesin/mesinkarakter.h"
#include "../ADT/mesin/mesinkalimat.h"
#include "../ADT/map2/map2.h"
#include "../ADT/word/word.h"
#include "../ADT/listlinier/listlinier.h"
#include "../ADT/queue/queue.h"
#include "../ADT/set/set.h"
#include "../command/start.h"
#include "boolean.h"

#define initial_cap 100
typedef struct {
    Kalimat songName;
    Kalimat artistName;
    Kalimat albumName;
} ElType;
typedef struct {
    ElType song;
    address Next;
}SongNode;

typedef struct {
    address First;
    Kalimat PlaylistName;
}List;

typedef struct{
    List *Playlist;
    int capacity;
    int Neff;
}DaftarPlaylist;
/*menggunakan list dinamis
I.S capacity = initial_cap */

// playlist
void createPlaylist(List *playlist);

void playlistAdd(List *singer);

void playlistSwap(a, b, c);

void playlistRemove(a, b);

void playlistDelete();