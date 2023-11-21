#include "SongDetails.h"

void createSongDetails(SongDetails *song){
    song->songName.Length = 0;
    song->artistName.Length = 0;
    song->albumName.Length = 0;
}

boolean isSongDetailsEmpty(SongDetails song){
    return (song.songName.Length == 0 &&
    song.artistName.Length == 0 &&
    song.albumName.Length == 0);
}