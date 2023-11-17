#ifndef __SONG_H__
#define __SONG_H__  

#include "./boolean.h"
#include "../ADT/queue/queue.h"
#include "../ADT/stack/stack.h"
#include "../ADT/mesin/mesinkalimat.h"

void PLAYSONG(Queue *songQue, Stack *songHist, Kalimat songName, Kalimat artistName);
/*mengosongkan isi songQue dan songHist. lalu menambahkan song ke songHist
I.S. : songQue dan songHist terdefinisi sembarang.
F.S. : songQue kosong, songHist berisi song*/

void PLAYPLAYLIST(Queue *songQue, Stack *songHist, playlist/*type unknown*/);
/*mengosongkan isi songQue dan songHist. lalu songHist akan berisi playlist(inverted)
I.S. : songQue dan songHist terdefinisi sembarang.
F.S. : songQue kosong, songHist berisi playlist(inverted)*/

#endif