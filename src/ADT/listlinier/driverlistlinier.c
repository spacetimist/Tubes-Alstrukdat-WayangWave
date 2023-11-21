#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

int main(){
    Playlist l;
    CreateLinkList(&l);
    addressNode p;
    SongDetails song;
    p = Alokasi(song);
    InsertFirst(&l, p);
    printf("%d\n", IsLinkListEmpty(l));
    printf("%d\n", NbElmt(l));
    Dealokasi(&p);
    return 0;
}