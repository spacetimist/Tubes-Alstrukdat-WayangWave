#include <stdio.h>
#include <stdlib.h>
#include "load.h"
#include "start.h"
// Ini file cuma untuk ngetes load nya aja
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
//   createDaftarPlaylist (&dp);
    boolean valid = true;
    Queue songQue;
    CreateQueue(&songQue);
    Stack songHist;
    CreateStack(&songHist);
    SongDetails currentSong;
  //  createSongDetails(&currentSong);
    while (valid) {
        printf(">> ");
        StartCommand() ;
        if (isInputEqual(Input, "LOAD")) {
            ADVCommand() ;
       //     printf("%s\n", LineToString(Input)) ;
            Kalimat nama ;
            nama = Directory(Input) ;
            printf("%s\n", nama.TabLine) ;
            LOADFILE(&ls, LineToString (nama), &songQue) ;
            valid = false ;
    }    else if (isInputEqual(Input, "START")) {
            STARTREAD(&ls) ; valid = false ;
        }  else {
            printf("Tidak ada file dengan nama tersebut !\n") ;
        }  
    }
    valid = true ;
    while (valid) {
        printf(">> ") ;
        StartCommand() ;
        if (isInputEqual(Input, "QUIT")) {
            valid = false ;
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
    }
}
