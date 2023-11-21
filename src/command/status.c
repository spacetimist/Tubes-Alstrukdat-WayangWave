#include <stdio.h>
#include "status.h"

void status(Queue q, SongDetails currentSong){
    printf("\nNow Playing:\n");
    if(isStackEmpty(hist)){
        printf("No songs have been played yet. Please search for a song to begin playback.\n\n");
    }else{
        printf("%s - %s - %s\n\n", currentSong.artistName.TabLine, currentSong.songName.TabLine, currentSong.albumName.TabLine);
    }
    printf("Queue:\n");
    if(isQueueEmpty(q)){
        printf("Your queue is empty.\n\n");
    }else{
        for (int i = IDX_HEAD(q) ; i<= IDX_TAIL(q) ; i++) {
            printf("    %d. %s - %s - %s\n", LineToString(q.buffer[i].artistName), LineToString(q.buffer[i].songName), LineToString(q.buffer[i].albumName));
        }
        printf("\n");
    }
}