#ifndef __QUIT_H__
#define __QUIT_H__

#include "../ADT/boolean.h"
#include <stdio.h>
// #include "../ADT/mesin/mesinkata.h"
// #include "../ADT/mesin/mesinkarakter.h"
#include "../ADT/mesin/mesinkalimat.h"
#include "../command/save.h"

void quit(ListPenyanyi * LP, char namafile [] ,Queue *songQue, Stack *riwayatlagu, SongDetails *currentSong, DaftarPlaylist *dp);

#endif