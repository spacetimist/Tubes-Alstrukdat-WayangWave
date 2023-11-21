#include "stack.h"
#include <stdio.h>
#include "../mesin/mesinkalimat.h"

int main() {
    Stack temp1 ; CreateStack(&temp1) ;
    SongDetails a; SongDetails b; 
    a.artistName = StringtoLine("BLACKPINK");
    a.albumName = StringtoLine("BORN PINK") ;
    a.songName = StringtoLine("Pink Venom") ;

    b.artistName = StringtoLine("Arctic Monkeys") ;
    b.albumName = StringtoLine("AM");
    b.songName = StringtoLine("Arabella") ;

    push(&temp1, a) ;
    push(&temp1, b) ;

    printf("%s-%s-%s\n", LineToString(TOP(temp1).artistName), LineToString(TOP(temp1).albumName),LineToString(TOP(temp1).songName)) ;
    SongDetails hapus;
    pop(&temp1, &hapus ) ;
    printf("%s-%s-%s\n", LineToString(TOP(temp1).artistName), LineToString(TOP(temp1).albumName),LineToString(TOP(temp1).songName)) ;

}