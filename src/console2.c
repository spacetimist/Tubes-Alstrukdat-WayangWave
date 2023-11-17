#include <stdio.h>
#include <stdlib.h>
#include "console2.h"

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
    CreateListPenyanyi (&ls) ;
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
        } else {
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
            
        }
        else{
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
        }
    }

    return 0;
}
