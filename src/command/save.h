#ifndef __SAVE_H__
#define __SAVE_H__

#include <stdio.h>
#include <stdlib.h>
#include "../ADT/boolean.h"
#include "../ADT/mesin/mesinkalimat.h"
#include "../ADT/map2/map2.h"
#include "../ADT/queue/queue.h"
#include "../ADT/stack/stack.h"
#include "../ADT/listDin/listDin.h"
// #include "../ADT/listlinier/listlinier.h"
#include "../ADT/SongDetails.h"
#include "queuesong.h"


static FILE * save ;


void SAVEFILE(ListPenyanyi * LP, char namafile[] ,Queue *songQue, Stack *riwayatlagu, SongDetails *currentSong, DaftarPlaylist *daftar);

#endif