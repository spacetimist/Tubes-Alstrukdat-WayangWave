#include <stdio.h>
#include "status.h"

void status(Queue q, Stack hist){
    printf("\nNow Playing:\n");
    if(isStackEmpty(hist)){
        printf("No songs have been played yet. Please search for a song to begin playback.\n\n");
    }else{

    }
    printf("Queue:\n");
    if(isQueueEmpty(q)){
        printf("Your queue is empty.\n\n");
    }else{
        
    }
}