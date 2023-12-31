#include <stdio.h>
#include <stdlib.h>
#include "console.h"

int main() {
    banner();
    ListPenyanyi ls ;
    CreateListPenyanyi (&ls) ;    
    DaftarPlaylist dp;
    CreateDaftarPlaylist (&dp, 50); //kapasitasnya 50 playlist
    boolean valid = true;
    Queue songQue;
    CreateQueue(&songQue);
    Stack songHist;
    CreateStack(&songHist);
    SongDetails currentSong;
    createSongDetails(&currentSong);
    Playlist currentPlaylist;
    CreateLinkList(&currentPlaylist);
    Kalimat namafile;
    namafile.Length = 0;

    while(valid){
        printf(">> ");
        StartCommand() ;   /* pakai ini untuk nerima inputnya.*/
        if (isInputEqual(Input, "START")) {
            STARTREAD(&ls) ;
            valid = false;
        }else if (isInputEqual(Input, "HELP")) {
            printf("\n====================[ Menu Help WayangWave ]====================\n");
            printf("1. START -> Untuk masuk sesi baru aplikasi WayangWave\n");
            printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
        } else if (isInputEqual(Input, "LOAD")) {
            ADVCommand() ;
            namafile = Directory(Input) ;
            LOADFILE(&ls, LineToString(namafile), &songQue, &songHist, &currentSong, &dp);
            if(ls.NEff <= 0){
                valid = true;
            }
            else valid = false;
        }
        else {
            InvalidCommand();
        }
    }

    valid = true;
    while(valid){
        printf(">> ");
        StartCommand() ; 
        if (isInputEqual(Input, "LIST")) {
            ADVCommand() ; //ini untuk baca kata ke-duanya
            if (isInputEqual(Input, "DEFAULT")) {
                ListDefault(ls) ;
            } else if (isInputEqual(Input, "PLAYLIST")) {
                ListPlaylist(dp) ;
            }
        }else if(isInputEqual(Input, "PLAY")) {
            ADVCommand() ;
            if (isInputEqual(Input, "SONG")) {  
                PlaySong(&songQue,  &songHist,  &ls,  &currentSong);
            }
            else if (isInputEqual(Input, "PLAYLIST")) {
                PLAYPLAYLIST(&songQue, &songHist, dp, &currentSong, &currentPlaylist);
            }
        }
        else if(isInputEqual(Input, "SONG")) {
            ADVCommand() ;
            if (isInputEqual(Input, "NEXT")) {  
                songNext(&songQue,  &songHist,  &currentSong);
            }
            else if (isInputEqual(Input, "PREV")) {
                songPrev(&songQue,  &songHist,  &currentSong);
            }
        }
        else if (isInputEqual(Input, "QUEUE")) {
            ADVCommand() ; 
            if (isInputEqual(Input, "SONG")) {
                QueueSong(&songQue, ls) ;
            } else if (isInputEqual(Input, "CLEAR")) {
                QueueClear(&songQue) ;
            } else if (isInputEqual(Input, "SWAP")) {
                ADVCommand() ;
                int id1 = Input.TabLine[0] - 48 ;
                ADVCommand() ;
                int id2 = Input.TabLine[0] - 48 ;
                QueueSwap(&songQue, id1, id2) ;
            } else if (isInputEqual(Input, "REMOVE")) {
                ADVCommand() ;
                int id = Input.TabLine[0] - 48 ;
                QueueRemove(&songQue, id) ;
            } else if (isInputEqual(Input, "PLAYLIST")) {
                QueuePlaylist(&songQue, dp) ;
            }
            else {
                printf("Command tidak diketahui!\n") ;
            }
        }
        else if(isInputEqual(Input, "PLAYLIST")) {
            ADVCommand() ; 
            if (isInputEqual(Input, "CREATE")) {
                createPlaylist(&dp);
            } else if (isInputEqual(Input, "ADD")) {
                ADVCommand();
                if(isInputEqual(Input, "SONG")){
                    PlaylistAddSong(&dp, ls);
                }else if(isInputEqual(Input, "ALBUM")){
                    PlaylistAddAlbum(&dp, ls);
                }
            } else if (isInputEqual(Input, "SWAP")) {
                ADVCommand() ;
                int idp = Input.TabLine[0] - 48 ;
                ADVCommand() ;
                int id1 = Input.TabLine[0] - 48 ;
                ADVCommand() ;
                int id2 = Input.TabLine[0] - 48 ;
                PlaylistSwap(&dp, idp, id1, id2);
            } else if (isInputEqual(Input, "REMOVE")) {
                ADVCommand() ;
                int id = Input.TabLine[0] - 48 ;
                ADVCommand() ;
                int n = Input.TabLine[0] - 48 ;
                PlaylistRemove(&dp, id, n);
            }else if (isInputEqual(Input, "DELETE")){
                PlaylistDelete(&dp);
            }
            else if (isInputEqual(Input, "CREATE")){
                createPlaylist(&dp);    
            } 
        }  
        else if (isInputEqual(Input, "STATUS")) {
            status(songQue, currentSong, currentPlaylist);
        }
        else if (isInputEqual(Input, "HELP")) {
            printf("\n====================[ Menu Help WayangWave ]====================\n");
            printf("1. LIST -> Untuk menampilkan list playlist, list penyanyi, list album, dan list lagu\n");
            printf("2. PLAY -> Untuk memutar lagu/playlist yang dipilih\n");
            printf("3. QUEUE -> Untuk menambahkan, menukar, dan menghapus lagu dalam queue\n");
            printf("4. SONG -> Untuk navigasi lagu dalam queue\n");
            printf("5. PLAYLIST -> Untuk membuat dan menghapus playlist, menambahkan, menukar, dan menghapus lagu dalam playlist\n");
            printf("6. STATUS -> Untuk menampilkan lagu yang sedang dimainkan beserta queue song\n");
            printf("7. SAVE -> Untuk menyimpan state aplikasi WayangWave terbaru\n");
            printf("8. QUIT -> Untuk keluar dari sesi aplikasi WayangWave\n");
        }
        else if (isInputEqual(Input, "SAVE")) {
            ADVCommand() ; Kalimat namasave ;
            namasave = Directory(Input) ;
            SAVEFILE(&ls, LineToString(namasave), &songQue, &songHist, &currentSong, &dp);
        }
        else if (isInputEqual(Input, "QUIT")) {
            quit(&ls,LineToString(namafile) ,&songQue, &songHist, &currentSong, &dp) ;
        }
        else if (isInputEqual(Input, "ENHANCE")) {
            enhance(dp, ls);
        }
        else{
            InvalidCommand();
        }
    }

    return 0;
}

