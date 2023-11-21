#include <stdio.h>
#include <stdlib.h>
#include "listDin.h"

int main(){
    DaftarPlaylist l;
    CreateDaftarPlaylist(&l, 10);
    Playlist p;
    ListDininsertLast(&l, p);
    printf("%d\n", capacity(l));
    printf("%d\n", NEFF(l));
    printf("%d\n", listLength(l));
    printf("%d\n", IsDaftarPlaylistEmpty(l));
    printf("%d\n", IsDaftarPlaylistFull(l));
    printf("%d\n", isIdxValid(l, 0));
    printf("%d\n", isIdxEff(l, 0));
    printf("%d\n", getFirstIdx(l));
    printf("%d\n", getLastIdx(l));
    DaftarPlaylist l2;
    CreateDaftarPlaylist(&l2, 10);
    copyList(l, &l2);
    printf("%d\n", NEFF(l2));
    ListDindeleteLast(&l, &p);
    printf("%d\n", NEFF(l));
    expandList(&l, 10);
    printf("%d\n", capacity(l));
    shrinkList(&l, 5);
    printf("%d\n", capacity(l));
    compressList(&l);
    printf("%d\n", capacity(l));
    dealocateList(&l);
    return 0;
}