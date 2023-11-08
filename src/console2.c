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
    }

    return 0;
}
