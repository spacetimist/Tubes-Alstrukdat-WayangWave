#include "queue.h"
#include "../mesin/mesinkalimat.h"

int main () {
    Queue queuesong;
    CreateQueue (&queuesong) ;
    SongDetails tes;
    tes.songName = StringtoLine("Pink Venom") ;
    tes.albumName = StringtoLine ("BORN PINK") ;
    tes.artistName = StringtoLine ("BLACK PINK") ;
    SongDetails tes2;
    tes2.songName = StringtoLine("Arabella") ;
    tes2.albumName = StringtoLine ("AM") ;
    tes2.artistName = StringtoLine ("Arctic Monkeys") ;
    enqueue(&queuesong, tes) ;
    enqueue(&queuesong, tes2) ;
    displayQueue(queuesong) ;

}