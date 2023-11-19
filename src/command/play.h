#ifndef __SONG_H__
#define __SONG_H__  

#include "../ADT/boolean.h"
#include "../ADT/queue/queue.h"
#include "../ADT/stack/stack.h"
#include "../ADT/mesin/mesinkalimat.h"
#include "../ADT/map2/map2.h"
#include "./playlist.h"

void PlaySong(Queue *songQue, Stack *songHist, ListPenyanyi * LP, Kalimat *songName, Kalimat *artistName);
/*mengosongkan isi songQue dan songHist. lalu menambahkan song ke songHist
I.S. : songQue dan songHist terdefinisi sembarang.
F.S. : songQue kosong, songHist berisi song*/

void PLAYPLAYLIST(Queue *songQue, Stack *songHist, DaftarPlaylist DP);
/*mengosongkan isi songQue dan songHist. lalu songHist akan berisi playlist(inverted)
I.S. : songQue dan songHist terdefinisi sembarang.
F.S. : songQue kosong, songHist berisi playlist(inverted)*/

#endif