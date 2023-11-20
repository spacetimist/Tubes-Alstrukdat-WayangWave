#include <stdio.h>
#include <stdlib.h>
#include "console.h"

void banner(){
    printf("\n");
    printf("                              W E L C O M E  T O                               \n");
    printf(" __      __                                     __      __                     \n");
    printf("/  \\    /  \\_____  ___.__._____    ____    ____/  \\    /  \\_____ ___  __ ____  \n");
    printf("\\   \\/\\/   /\\__  \\<   |  |\\__  \\  /    \\  / ___\\   \\/\\/   /\\__  \\\\  \\/ // __ \\ \n");
    printf(" \\        /  / __ \\\\___  | / __ \\|   |  \\/ /_/  >        /  / __ \\\\   /\\  ___/ \n");
    printf("  \\__/\\  /  (____  / ____|(____  /___|  /\\___  / \\__/\\  /  (____  /\\_/  \\___  >\n");
    printf("       \\/        \\/\\/          \\/     \\//_____/       \\/        \\/          \\/ \n");
    printf("\n");
/*                               
 tar jadinya ky gini
 __      __                                     __      __                     
/  \    /  \_____  ___.__._____    ____    ____/  \    /  \_____ ___  __ ____  
\   \/\/   /\__  \<   |  |\__  \  /    \  / ___\   \/\/   /\__  \\  \/ // __ \ 
 \        /  / __ \\___  | / __ \|   |  \/ /_/  >        /  / __ \\   /\  ___/ 
  \__/\  /  (____  / ____|(____  /___|  /\___  / \__/\  /  (____  /\_/  \___  >
       \/        \/\/          \/     \//_____/       \/        \/          \/                          

*/    

}

void InvalidCommand(){
    printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
}

int main() {
    banner();
    ListPenyanyi ls ;
    DaftarPlaylist dp;
    CreateListPenyanyi (&ls) ;
    createDaftarPlaylist (&dp);
    boolean valid = true;
    Queue songQue;
    CreateQueue(&songQue);
    Stack songHist;
    CreateStack(&songHist);
    SongDetails currentSong;
    //createSongDetails(&currentSong);

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
        }else {
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
                //
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
            }
            else {
                printf("Command tidak diketahui!\n") ;
            }
        }
        else if(isInputEqual(Input, "PLAYLIST ADD SONG")) {
            PlaylistAddSong(&dp, ls) ;
        }else if(isInputEqual(Input, "PLAYLIST ADD ALBUM")) {
            PlaylistAddAlbum(&dp, ls) ;
        }else if (isInputEqual(Input, "PLAYLIST CREATE")){
            createPlaylist(&dp);    
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
        else{
            InvalidCommand();
        }
    }

    return 0;
}
