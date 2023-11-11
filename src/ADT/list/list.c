#include <stdio.h>
#include "boolean.h"
#include "list.h"

List MakeList() {
    List L ;
    int i ;
    for (i=0; i < MaxEl; i++) {
        L.A[i] = Mark ;
    }
    return L ;
} 

boolean IsEmpty(List L) {
    return L.A[0] == Mark ; 
}

ElType Get(List L, IdxType i) {
    return L.A[i] ;
}

void Set(List *L, IdxType i, ElType v) {
    (*L).A[i] = v ;
} 

int Length(List L) {
    int count = 0, i = 0 ;
    while (L.A[i] != Mark && count <= MaxEl) {
        count++ ;
        i++ ;
    }
    return i;
}

IdxType FirstIdx(List L) {
    return 0 ;
}

IdxType LastIdx(List L) {
    return Length(L) - 1 ;
}

boolean IsIdxValid (List L, IdxType i) {
    return (i >= FirstIdx(L) && i <= MaxEl - 1) ;
}

boolean IsIdxEff (List L, IdxType i) {
    return (i >= FirstIdx(L) && i <= LastIdx(L)) ;
}

boolean Search(List L, ElType X) {
    int i = 0;
    boolean found = false;
    while (found == false && i <= Length(L) - 1) {
        if (L.A[i] == X) {
            found = true;
        }
        else {
            i++;
        }
    }
    return found;
}

void InsertFirst(List *L, ElType X) {
    int i;
    for (i=LastIdx(*L);i>=0;i--) {
        (*L).A[i+1] = (*L).A[i];
    }
    (*L).A[FirstIdx(*L)] = X;
} 

void InsertAt(List *L, ElType X, IdxType i) {
    int j;
    for (j = LastIdx(*L); j >= i; j--) {
        (*L).A[j+1] = (*L).A[j];
    }
    (*L).A[i] = X;
} 

void InsertLast(List *L, ElType X) {
    if (IsEmpty(*L)) {
        (*L).A[0] = X;
    }
    else {
        (*L).A[LastIdx(*L) + 1] = X;
    }
}

void DeleteFirst(List *L) {
    int i;
    for (i = 0; i <= LastIdx(*L); i++) {
        (*L).A[i] = (*L).A[i+1];
    }
} 

void DeleteAt(List *L, IdxType i) {
    int j;
    for(j = i; j <= LastIdx(*L); j++) {
        (*L).A[j] = (*L).A[j+1];
    }
}

void DeleteLast(List *L) {
    (*L).A[LastIdx(*L)] = Mark ;
}

List Concat(List L1, List L2) {
    List L3;
    L3 = MakeList() ;
    int i;
    for (i=0;i<Length(L1);i++) {
        InsertLast(&L3, L1.A[i]);
    }
    for (i=0;i<Length(L2);i++) {
        InsertLast(&L3, L2.A[i]);
    }
    return L3;
} 