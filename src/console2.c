#include <stdio.h>
#include <stdlib.h>
#include "console2.h"

// baru bisa yang START
int main() {
    ListPenyanyi ls ;
    CreateListPenyanyi (&ls) ;
    boolean valid = true;

    while(valid){
        printf(">> ");
        STARTWORD() ;   
        if (IsKataEqual(currentWord, "START")) {
            STARTREAD(&ls) ;
            valid = false;
        } else {
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
        }
    }
    valid = true;
    while(valid){
        printf(">> ");
        STARTWORD() ; 
        if (IsKataEqual(currentWord, "LIST DEFAULT")) {
            ListDefault(ls) ;

        }
    }

    return 0;
}
