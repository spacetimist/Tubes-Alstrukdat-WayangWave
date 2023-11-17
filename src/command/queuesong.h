#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include "../ADT/boolean.h"
#include "../ADT/mesin/mesinkata.h"
#include "../ADT/mesin/mesinkarakter.h"
#include "../ADT/mesin/mesinkalimat.h"
#include "../ADT/map2/map2.h"
#include "../ADT/word/word.h"
#include "../ADT/listlinier/listlinier.h"
#include "../ADT/list/list.h"
#include "../ADT/queue/queue.h"
#include "../ADT/set/set.h"
#include "../command/start.h"
#include "../command/list.h"


void QueueSong(Queue *queue, ListPenyanyi LP);
void QueuePlaylist(Queue *queue);
void QueueSwap(Queue *queue, int id1, int id2);
void QueueRemove(Queue *queue, int id);
void QueueClear(Queue *queue);

#endif