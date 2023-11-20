#include <stdio.h>
#include "listDin.h"

// DaftarPlaylist MakeDaftarPlaylist() {
//     DaftarPlaylist L ;
//     int i ;
//     for (i=0; i < L.capacity; i++) {
//         L.List[i] = Mark ;
//     }
//     return L ;
// } 

boolean IsDaftarPlaylistEmpty(DaftarPlaylist L) {
    return L.Neff == 0 ; 
}

// Playlist Get(DaftarPlaylist L, IdxType i) {
//     return L.List[i] ;
// }

// void Set(DaftarPlaylist *L, IdxType i, Playlist v) {
//     (*L).List[i] = v ;
// } 

// int Length(DaftarPlaylist L) {
//     int count = 0, i = 0 ;
//     while (L.List[i] != Mark && count <= MaxEl) {
//         count++ ;
//         i++ ;
//     }
//     return i;
// }

// IdxType FirstIdx(DaftarPlaylist L) {
//     return 0 ;
// }

// IdxType LastIdx(DaftarPlaylist L) {
//     return Length(L) - 1 ;
// }

// boolean IsIdxValid (DaftarPlaylist L, IdxType i) {
//     return (i >= FirstIdx(L) && i <= MaxEl - 1) ;
// }

// boolean IsIdxEff (DaftarPlaylist L, IdxType i) {
//     return (i >= FirstIdx(L) && i <= LastIdx(L)) ;
// }

// boolean SearchDaftarPlaylist(DaftarPlaylist L, Playlist X) {
//     int i = 0;
//     boolean found = false;
//     while (found == false && i <= L.Neff - 1) {
//         if (L.List[i] == X) {
//             found = true;
//         }
//         else {
//             i++;
//         }
//     }
//     return found;
// }

// void InsertFirstDaftarPlaylist(DaftarPlaylist *L, Playlist X) {
//     int i;
//     for (i=LastIdx(*L);i>=0;i--) {
//         (*L).List[i+1] = (*L).List[i];
//     }
//     (*L).A[FirstIdx(*L)] = X;
// } 

// void InsertAtDaftarPlaylist(DaftarPlaylist *L, Playlist X, IdxType i) {
//     int j;
//     for (j = LastIdx(*L); j >= i; j--) {
//         (*L).List[j+1] = (*L).List[j];
//     }
//     (*L).List[i] = X;
// } 

// void InsertLastDaftarPlaylist(DaftarPlaylist *L, Playlist X) {
//     if (IsDaftarPlaylistEmpty(*L)) {
//         (*L).List[0] = X;
//     }
//     else {
//         (*L).List[LastIdx(*L) + 1] = X;
//     }
// }

// void DeleteFirstDaftarPlaylist(DaftarPlaylist *L) {
//     int i;
//     for (i = 0; i <= LastIdx(*L); i++) {
//         (*L).List[i] = (*L).List[i+1];
//     }
// } 

// void DeleteAtDaftarPlaylist(DaftarPlaylist *L, IdxType i) {
//     int j;
//     for(j = i; j <= LastIdx(*L); j++) {
//         (*L).List[j] = (*L).List[j+1];
//     }
// }

// void DeleteLastDaftarPlaylist(DaftarPlaylist *L) {
//     (*L).List[LastIdx(*L)] = Mark ;
// }

// DaftarPlaylist ConcatDaftarPlaylist(DaftarPlaylist L1, DaftarPlaylist L2) {
//     DaftarPlaylist L3;
//     L3 = MakeDaftarPlaylist() ;
//     int i;
//     for (i=0;i<Length(L1);i++) {
//         InsertLastDaftarPlaylist(&L3, L1.List[i]);
//     }
//     for (i=0;i<Length(L2);i++) {
//         InsertLastDaftarPlaylist(&L3, L2.List[i]);
//     }
//     return L3;
// } 