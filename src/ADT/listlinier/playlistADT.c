#include "../listDin/listDin.h"
//#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

addressNode Alokasi (SongDetails X){
	addressNode P;
	P = (SongNode *)malloc(sizeof(SongNode));
	if (P != Nul) {
		P->song = X;
		P->Next = Nul;
		return P;
	} else {
		return Nul;
	}
}

void InsVSongPlaylistLast (Playlist *L, SongDetails X){
	addressNode P = Alokasi(X);

	if (P != Nul){
		if (isLinkListEmpty(*L)){
		Next(P) = First(*L);
	    First(*L) = P;
	    } else {
            addressNode last = First(*L);
            while (Next(last) != Nul){
                last = Next(last);
            }
            Next(P) = Next(last);
	        Next(last) = P;
        }
	}
}

// void setElmtLinkList(Playlist *L, int idx, SongDetails val){
//     int ctr = 0;
// 	adr p = First(*L);

//     while (ctr < idx){
//         p = Next(p);
//     	ctr++;
// 	}
//     Info(p) = val;
// }