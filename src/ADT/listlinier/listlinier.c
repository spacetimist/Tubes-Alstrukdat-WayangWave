#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

boolean IsLinkListEmpty (Playlist L){
/* Mengirim true jika list kosong */
    return (First(L) == Nul);
}

void CreateLinkList (Playlist *L){
    First(*L) = Nul;
}

addressNode Alokasi (SongDetails X){
    //alocate node(ElmtList), put address in P
    // address P = (address) malloc (sizeof(ElmtList));
    addressNode P = (SongNode*) malloc (sizeof(SongNode));
    //check if allocation success
    if (P != Nul){
        //if success, put X in info(P)
        Info(P).songName = X.songName;
        Info(P).albumName = X.albumName;
        Info(P).artistName = X.artistName;
        Next(P) = Nul;
    }
    //return address of P
    return P;
}

void Dealokasi (addressNode *P){
    //free to deallocate memory
    free(*P);
}

void InsVFirst (Playlist *L, SongDetails X){
    //alocate X, put address in P
    addressNode P = Alokasi(X);
    //check if allocation success
    if (P != Nul){
        InsertFirst(L, P);
    }
}

void InsVLast (Playlist *L, SongDetails X){
    //alocate X, put address in P
    addressNode P = Alokasi(X);
    //check if allocation success
    if (P != Nul){
        InsertLast(L, P);
    }
}

void DelVFirst (Playlist *L, SongDetails *X){
    //can use DelFirst() but will cause 1 extra step
    //declare temp to store address
    addressNode temp = First(*L);
    //check if list is empty
    if (temp != Nul){
        //if not empty, put info(temp) in X
        *X = Info(temp);
        //connect First(L) to Next(temp)
        First(*L) = Next(temp);
        //deallocate memory
        Dealokasi(&temp);
    }
}

void DelVLast (Playlist *L, SongDetails *X){
    //declare P to store last node's address
    addressNode P;
    //disconnect last node from list and put address in P
    DelLast(L, &P);
    //put last node's info() in X
    *X = Info(P);
    //deallocate last node's memory
    Dealokasi(&P);
    
}

void InsertFirst (Playlist *L, addressNode P){
    //connect Next(P) to first node
    Next(P) = First(*L);
    //connect First(L) to P
    First(*L) = P;
}

void InsertAfter (Playlist *L, addressNode P, addressNode Prec){
    //connect Next(P) to Next(Prec)
    Next(P) = Next(Prec);
    //connect Next(Prec) to P
    Next(Prec) = P;
}

void InsertLast(Playlist *L, addressNode P){
    //declare temp to store address
    addressNode temp = First(*L);
    //check if list is empty
    if (temp == Nul){
        //if empty, connect First(L) to P
        First(*L) = P;
        //Next(P) already Nul, refer to Alokasi()
    } else {
        //if not empty, transverse to find last node
        while (Next(temp) != Nul){
            temp = Next(temp);
        }
        //connect Next(temp) to P
        Next(temp) = P;
    }
}

void DelFirst (Playlist *L, addressNode *P){
    //assign first node's address to P
    *P = First(*L);
    //connect First(L) to 2nd node
    First(*L) = Next(*P);
    //disconnect P from list
    Next(*P) = Nul;
}

void DelLast (Playlist *L, addressNode *P){
    //declare temp to store address
    addressNode temp = First(*L);
    //check if list is empty
    if (temp != Nul){
        //if not empty, transverse to find 2nd last node
        while (Next(Next(temp)) != Nul){
            temp = Next(temp);
        }
        //assign last node's address to P
        *P = Next(temp);
        //connect Next(temp) to Nul
        Next(temp) = Next(*P);
    }
}

void DelAfter (Playlist *L, addressNode *Pdel, addressNode Prec){
    //assign next node's address to Pdel
    *Pdel = Next(Prec);
    //connect Next(Prec) to Next(Pdel)
    Next(Prec) = Next(*Pdel);
    //disconnect Pdel from list
    Next(*Pdel) = Nul;
}

int NbElmt (Playlist L){
    //declare temp to store address
    addressNode temp = First(L);
    //declare counter
    int count = 0;
    //transverse to count nodes
    while (temp != Nul){
        count++;
        temp = Next(temp);
    }
    return count;
}

// addressNode SearchPlaylist(Playlist L, SongDetails X)
// /* Mencari apakah ada elemen Playlist dengan Info(P)= X */
// /* Jika ada, mengirimkan addressNode elemen tersebut. */
// /* Jika tidak ada, mengirimkan Nil */
// {
//     addressNode P;
//     boolean bFound = false;

//     if (!IsLinkListEmpty(L))
//     {
//         P = First(L);
//         while (!bFound && P != Nil)
//         {
//             if (X == Info(P))
//             {
//                 bFound = true;
//             }
//             else
//             {
//                 P = Next(P);
//             }
//         }

//         if (bFound)
//         {
//             return P;
//         }
//         else
//         {
//             return Nil;
//         }
//     }
//     else
//     {
//         return Nil;
//     }
// }