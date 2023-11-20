#ifndef __SONG_H__
#define __SONG_H__  

#include "../ADT/boolean.h"
#include "../ADT/queue/queue.h"
#include "../ADT/stack/stack.h"
#include "../ADT/mesin/mesinkalimat.h"
#include "../ADT/map2/map2.h"
#include "../ADT/listDin/listDin.h"
#include "list.h"

void PlaySong(Queue *songQue, Stack *songHist, ListPenyanyi *LP, SongDetails *currentSong);
/*mengosongkan isi songQue dan songHist. lalu menambahkan song ke songHist
I.S. : songQue dan songHist terdefinisi sembarang.
F.S. : songQue kosong, songHist berisi song, currentSong berisi song yang di play*/

void PLAYPLAYLIST(Queue *songQue, Stack *songHist, DaftarPlaylist DP, SongDetails *currentSong);
/*mengosongkan isi songQue dan songHist. lalu songHist akan berisi playlist(inverted)
I.S. : songQue dan songHist terdefinisi sembarang.
F.S. : songQue kosong, songHist berisi playlist(inverted), currentSong berisi song pertama pada playlist*/

#endif