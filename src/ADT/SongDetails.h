#ifndef __SONGDETAILS_h__
#define __SONGDETAILS_h__

#include "./mesin/mesinkalimat.h"
#include "boolean.h"
#include <stdlib.h>

typedef struct {
    Kalimat songName;
    Kalimat artistName;
    Kalimat albumName;
} SongDetails;

void createSongDetails(SongDetails *song);
/*I.S. sembarang
F.S. kalimat.length semuanya 0*/

#endif