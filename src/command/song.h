#include <stdio.h>
#include <stdlib.h>
#include "../ADT/boolean.h"
#include "../ADT/SongDetails.h"
#include "../ADT/queue/queue.h"
#include "../ADT/stack/stack.h"
#include "../ADT/mesin/mesinkalimat.h"

void songNext(Queue *songQue, Stack *songHist, SongDetails *currentSong);
// I.S. songQue, songHist, currentSong terdefinisi
// F.S. currentSong berisi lagu selanjutnya dari songQue, songHist berisi currentSong.
//jika songQue kosong, currentSong tetap.
//jika songHist penuh, elemen bottom stack dihapus 1.

void songPrev(Queue *songQue, Stack *songHist, SongDetails *currentSong);
// I.S. songQue, songHist, currentSong terdefinisi
// F.S. currentSong berisi lagu sebelumnya dari songHist, currentSong dimasukan ke songQue.
//jika kosong, currentSong tetap.
//jika songQue penuh, elemen tail queue dihapus 1.