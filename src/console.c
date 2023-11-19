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
 tar jadinya ky gini_
 _      __                                     __      __                     
/  \    /  \_____  ___.__._____    ____    ____/  \    /  \_____ ___  __ ____  
\   \/\/   /\__  \<   |  |\__  \  /    \  / ___\   \/\/   /\__  \\  \/ // __ \ 
 \        /  / __ \\___  | / __ \|   |  \/ /_/  >        /  / __ \\   /\  ___/ 
  \__/\  /  (____  / ____|(____  /___|  /\___  / \__/\  /  (____  /\_/  \___  >
       \/        \/\/          \/     \//_____/       \/        \/          \/                          

*/    

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

    while(valid){
        printf(">> ");
        StartInput() ;   /* pakai ini untuk nerima inputnya.*/
        if (isInputEqual(Input, "START")) {
            STARTREAD(&ls) ;
            valid = false;
        }else if (isInputEqual(Input, "HELP")) {
            printf("\n====================[ Menu Help WayangWave ]====================\n");
            printf("1. START -> Untuk masuk sesi baru aplikasi WayangWave\n");
            printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
        }else {
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
        }
    }

    valid = true;
    while(valid){
        printf(">> ");
        StartInput() ; 
        if (isInputEqual(Input, "LIST DEFAULT")) {
            ListDefault(ls) ;
        }
        else if (isInputEqual(Input, "PLAY SONG")){
            
        }else if (isInputEqual(Input, "PLAYLIST CREATE")){
            createPlaylist(&dp);
        }
        else if (isInputEqual(Input, "HELP")) {
            printf("====================[ Menu Help WayangWave ]====================");
            printf("1. LIST -> Untuk menampilkan list playlist, list penyanyi, list album, dan list lagu");
            printf("2. PLAY -> Untuk memutar lagu/playlist yang dipilih");
            printf("3. QUEUE -> Untuk menambahkan, menukar, dan menghapus lagu dalam queue");
            printf("4. SONG -> Untuk navigasi lagu dalam queue");
            printf("5. PLAYLIST -> Untuk membuat dan menghapus playlist, menambahkan, menukar, dan menghapus lagu dalam playlist");
            printf("6. STATUS -> Untuk menampilkan lagu yang sedang dimainkan beserta queue song");
            printf("7. SAVE -> Untuk menyimpan state aplikasi WayangWave terbaru");
            printf("8. QUIT -> Untuk keluar dari sesi aplikasi WayangWave");;
        }
        else{
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
        }
    }

    return 0;
}
