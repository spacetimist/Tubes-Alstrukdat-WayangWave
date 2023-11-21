#include "mesinkalimat.h"
#include <stdio.h>

int main () {
    StartCommand() ;
    if (isInputEqual(Input, "LOAD")) {
        ADVCommand() ;
        printf("%s\n", Input.TabLine) ;
        printf("%d\n", Input.Length) ;
        Kalimat nama ;
        nama = Directory(Input) ;
        printf("%s\n", nama.TabLine) ;
        printf("%d\n", nama.Length) ;
    }
}