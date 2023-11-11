#include "./ADT/mesin/mesinkata.h"
#include "./ADT/mesin/mesinkarakter.h"
#include "./ADT/mesin/mesinkalimat.h"
#include "./ADT/map2/map2.h"
#include "./ADT/word/word.h"
#include "./ADT/listlinier/listlinier.h"
#include "./ADT/queue/queue.h"
#include "./ADT/set/set.h"
#include "./command/start.h"

// queue
void QueueSong(Queue *queue, List *singer);
void QueuePlaylist(Queue *queue);
void QueueSwap(Queue *queue, int id1, int id2);
void QueueRemove(Queue *queue, int id);
void QueueClear(Queue *queue);

// playlist
void createPlaylist(List *playlist);

// help
void HelpBeforeStart();
void HelpAfterStart();

//invalid comment
void invalidComment();
