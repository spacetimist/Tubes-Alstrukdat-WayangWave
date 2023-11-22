#include <stdio.h>
#include "status.h"

void status(Queue q, SongDetails currentSong, Playlist currentPlaylist){
    if(!IsLinkListEmpty(currentPlaylist)){
        printf("\nCurrent Playlist: %s\n", currentPlaylist.PlaylistName.TabLine);
    }
    printf("\nNow Playing:\n");
    if(isSongDetailsEmpty(currentSong)){
        printf("No songs have been played yet. Please search for a song to begin playback.\n");
    }else{
        printf("%s -", LineToString(currentSong.artistName));
        printf(" %s -", LineToString(currentSong.songName));
        printf(" %s\n", LineToString(currentSong.albumName));
    }
    printf("\nQueue:\n");
    if(isQueueEmpty(q)){
        printf("Your queue is empty.\n\n");
    }else{
        int index = 1;
        for (int i = IDX_HEAD(q) ; i<= IDX_TAIL(q) ; i++) {
            printf("    %d. %s - %s - %s\n", index, LineToString(q.buffer[i].artistName), LineToString(q.buffer[i].songName), LineToString(q.buffer[i].albumName));
            index++;
        }
        printf("\n");
    }
}