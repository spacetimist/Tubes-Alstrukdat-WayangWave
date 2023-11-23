#include "./ADT/mesin/mesinkata.h"
#include "./ADT/mesin/mesinkarakter.h"
#include "./ADT/mesin/mesinkalimat.h"
#include "./ADT/map2/map2.h"
#include "./ADT/queue/queue.h"
#include "./ADT/stack/stack.h"
#include "./ADT/listlinier/listlinier.h"
#include "./command/start.h"
#include "./command/list.h"
#include "./command/queuesong.h"
#include "./ADT/SongDetails.h"
#include "./ADT/listDin/listDin.h"
#include "./command/play.h"
#include "./command/quit.h"
#include "./command/song.h"
#include "./command/status.h"
#include "./command/load.h"
#include "./command/enhance.h"
//#include "./command/playlist.h"

void banner();

void InvalidCommand();


// gcc ../src/ADT/mesin/mesinkata.c ../src/ADT/mesin/mesinkalimat.c ../src/ADT/mesin/mesinkarakter.c ../src/ADT/map2/map2.c ../src/ADT/queue/queue.c ../src/ADT/stack/stack.c ../src/ADT/listlinier/listlinier.c ../src/ADT/listDin/listDin.c ../src/command/start.c ../src/command/list.c ../src/command/playlist.c ../src/console.c ../src/command/queuesong.c -o cekk