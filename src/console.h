#include "./ADT/mesin/mesinkata.h"
#include "./ADT/word/word.h"
#include "./ADT/listlinier/listlinier.h"
#include "./ADT/queue/queue.h"

// queue
void QueueSong(Queue *queue);
void QueuePlaylist(Queue *queue);
void QueueSwap(Queue *queue, int id1, int id2);
void QueueRemove(Queue *queue, int id);
void QueueClear(Queue *queue);

// playlist
void createPlaylist(List *playlist);


