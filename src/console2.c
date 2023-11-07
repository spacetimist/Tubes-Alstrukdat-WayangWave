#include <stdio.h>
#include <stdlib.h>
#include "console2.h"

int main() {
    printf(">> ");
    STARTWORD() ;
    ListPenyanyi ls ;
    CreateListPenyanyi (&ls) ;
    boolean valid = false;

    if (IsKataEqual(currentWord, "START")) {
        STARTREAD(&ls) ;
        valid = true;
        while(valid){
            printf(">> ");
            STARTWORD() ;
            if (IsKataEqual(currentWord, "LIST DEFAULT")){
                ListDefault(&ls);
            }
        }
    } else {
        valid = false;
        return 0 ;
    }
    
    return 0;
}
