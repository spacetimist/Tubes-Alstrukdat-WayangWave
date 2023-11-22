#ifndef __QUEUE_H__
#define __QUEUE_H__

// #include <stdio.h>
// #include <stdlib.h>
#include "../ADT/boolean.h"
// #include "../ADT/mesin/mesinkata.h"
// #include "../ADT/mesin/mesinkarakter.h"
// #include "../ADT/mesin/mesinkalimat.h"
#include "../ADT/map2/map2.h"
#include "../ADT/listlinier/listlinier.h"
// #include "../ADT/list/list.h"
#include "../ADT/queue/queue.h"
// #include "./command/start.h"
// #include "./list.h"
//#include "./command/console.h"
#include "../ADT/SongDetails.h"
#include "../ADT/listDin/listDin.h"


void QueueSong(Queue *songQue, ListPenyanyi LP);
void QueuePlaylist(Queue *songQue);
void QueueSwap(Queue *songQue, int id1, int id2);
void QueueRemove(Queue *songQue, int id);
void QueueClear(Queue *songQue);

#endif