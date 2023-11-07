#include <stdio.h>
#include <stdlib.h>
#include "console.h"

int main() {

    // create list daftar penyanyi
    List singer;
    MakeList(&singer);
    
    // create queue
    Queue queue;
    CreateQueue(&queue);

    // create list playlist
    List playlist;
    createPlaylist(&playlist);
    
    return 0;
}
