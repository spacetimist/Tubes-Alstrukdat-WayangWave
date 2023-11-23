#include "song.h"

void songNext(Queue *songQue, Stack *songHist, SongDetails *currentSong){
    //check if songQue is empty
    if (isQueueEmpty(*songQue)){
        printf("No song in queue\n");
        printf("Memutar kembali “%s”", LineToString(currentSong->songName));
        printf(" oleh %s\n", LineToString(currentSong->artistName));
    } else {
        //check if songHist is full
        if (isStackFull(*songHist)){
            //shift stack to left once
            int i;
            for (i=1; i<CAPACITY; i++){
                songHist->buffer[i-1] = songHist->buffer[i];
            }
            songHist->idxTop--;
        }
        //push current song to history
        push(songHist, *currentSong);
        //pop song from queue
        dequeue(songQue, currentSong);
        //print current song
        printf("Memutar lagu selanjutnya \n");
        printf("Memutar “%s”",LineToString(currentSong->songName));
        printf(" oleh %s\n",LineToString(currentSong->artistName));
    }
}

void songPrev(Queue *songQue, Stack *songHist, SongDetails *currentSong){
    //check if songHist is empty
    if (isStackEmpty(*songHist)){
        printf("No song in history\n");
        printf("Memutar kembali “%s”",LineToString(currentSong->songName));
        printf(" oleh %s\n",LineToString(currentSong->artistName));
    } else {
        //check if songQue is full
        if (isQueueFull(*songQue)){
            //pop tail from songQue
            IDX_TAIL(*songQue)--;
        }
        //push current song to queue head
        if (IDX_HEAD(*songQue)>0){
            IDX_HEAD(*songQue)--;
        } else if (IDX_HEAD(*songQue)==0){
            IDX_HEAD(*songQue) = CAPACITY-1;  
        }
        HEAD(*songQue) = *currentSong;
        //pop song from history
        pop(songHist, currentSong);
        //print current song
        printf("Memutar lagu sebelumnya \n");
        printf("Memutar “%s”", LineToString(currentSong->songName));
        printf(" oleh %s\n",LineToString(currentSong->artistName));
    }
}