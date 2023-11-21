// #include <stdio.h>
// #include "listDin.h"

// DaftarPlaylist MakeDaftarPlaylist(){
//     DaftarPlaylist arr;
//     arr.List = (Playlist *)malloc(initial_cap*sizeof(Playlist));
//     arr.capacity = initial_cap;
//     arr.Neff = 0;

//     return arr;
// }

// boolean IsDaftarPlaylistEmpty(DaftarPlaylist L) {
//     return L.Neff == 0 ; 
// }

// void DeallocateDaftarPlaylist(DaftarPlaylist *L){
//     free((*L).List);
//     L->capacity = 0;
//     L->Neff = 0;
// }

// void InsertAtListDin(DaftarPlaylist *L, Playlist el, IdxType i){
//     IdxType j;
//     for(j = L->Neff; j > i; j--){
//         L->List[j] = L->List[j-1];
//     }
//     L->List[i] = el;
//     L->Neff++;
// }

// void DeleteAtListDin(DaftarPlaylist *L, IdxType i){
//     IdxType j;
//     for(j=i; j<L->Neff-1; j++){
//         L->List[j] = L->List[j+1];
//     }
//     L->Neff--;
// }

// // int Length(DaftarPlaylist L) {
// //     int count = 0, i = 0 ;
// //     while (L.List[i] != Mark && count <= MaxEl) {
// //         count++ ;
// //         i++ ;
// //     }
// //     return i;
// // }

// // IdxType FirstIdx(DaftarPlaylist L) {
// //     return 0 ;
// // }

// // IdxType LastIdx(DaftarPlaylist L) {
// //     return Length(L) - 1 ;
// // }

// // boolean IsIdxValid (DaftarPlaylist L, IdxType i) {
// //     return (i >= FirstIdx(L) && i <= MaxEl - 1) ;
// // }

// // boolean IsIdxEff (DaftarPlaylist L, IdxType i) {
// //     return (i >= FirstIdx(L) && i <= LastIdx(L)) ;
// // }

// // boolean SearchDaftarPlaylist(DaftarPlaylist L, Playlist X) {
// //     int i = 0;
// //     boolean found = false;
// //     while (found == false && i <= L.Neff - 1) {
// //         if (L.List[i] == X) {
// //             found = true;
// //         }
// //         else {
// //             i++;
// //         }
// //     }
// //     return found;
// // }

// // void InsertFirstDaftarPlaylist(DaftarPlaylist *L, Playlist X) {
// //     int i;
// //     for (i=LastIdx(*L);i>=0;i--) {
// //         (*L).List[i+1] = (*L).List[i];
// //     }
// //     (*L).A[FirstIdx(*L)] = X;
// // } 

// // void InsertAtDaftarPlaylist(DaftarPlaylist *L, Playlist X, IdxType i) {
// //     int j;
// //     for (j = LastIdx(*L); j >= i; j--) {
// //         (*L).List[j+1] = (*L).List[j];
// //     }
// //     (*L).List[i] = X;
// // } 

// // void InsertLastDaftarPlaylist(DaftarPlaylist *L, Playlist X) {
// //     if (IsDaftarPlaylistEmpty(*L)) {
// //         (*L).List[0] = X;
// //     }
// //     else {
// //         (*L).List[LastIdx(*L) + 1] = X;
// //     }
// // }

// // void DeleteFirstDaftarPlaylist(DaftarPlaylist *L) {
// //     int i;
// //     for (i = 0; i <= LastIdx(*L); i++) {
// //         (*L).List[i] = (*L).List[i+1];
// //     }
// // } 

// // void DeleteAtDaftarPlaylist(DaftarPlaylist *L, IdxType i) {
// //     int j;
// //     for(j = i; j <= LastIdx(*L); j++) {
// //         (*L).List[j] = (*L).List[j+1];
// //     }
// // }

// // void DeleteLastDaftarPlaylist(DaftarPlaylist *L) {
// //     (*L).List[LastIdx(*L)] = Mark ;
// // }

// // DaftarPlaylist ConcatDaftarPlaylist(DaftarPlaylist L1, DaftarPlaylist L2) {
// //     DaftarPlaylist L3;
// //     L3 = MakeDaftarPlaylist() ;
// //     int i;
// //     for (i=0;i<Length(L1);i++) {
// //         InsertLastDaftarPlaylist(&L3, L1.List[i]);
// //     }
// //     for (i=0;i<Length(L2);i++) {
// //         InsertLastDaftarPlaylist(&L3, L2.List[i]);
// //     }
// //     return L3;
// // } 

#include <stdio.h>
#include <stdlib.h>
#include "listDin.h" 

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateDaftarPlaylist(DaftarPlaylist *l, int capacity){
    /* I.S. l sembarang, capacity > 0 */
    /* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    capacity(*l) = capacity;
    BUFFER(*l) = (Playlist *)malloc(capacity * sizeof(Playlist));
    NEFF(*l) = 0;

}


void dealocateList(DaftarPlaylist *l){
    /* I.S. l terdefinisi; */
    /* F.S. (l) dikembalikan ke system, capacity(l)=0; NEFF(l)=0 */
    NEFF(*l) = 0;
    capacity(*l) = 0;
    free(BUFFER(*l));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(DaftarPlaylist l){
    /* Mengirimkan banyaknya elemen efektif list */
    /* Mengirimkan nol jika list l kosong */
    /* *** Daya tampung container *** */
    return NEFF(l);
}


/* *** Selektor INDEKS *** */
IdxType getFirstIdx(DaftarPlaylist l){
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l pertama */
    return IDX_MIN;
}

IdxType getLastIdx(DaftarPlaylist l){
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l terakhir */
    return(IdxType)(listLength(l)-1);
}


/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(DaftarPlaylist l, IdxType i){
    /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
    /* yaitu antara indeks yang terdefinisi utk container*/
    return (i>=getFirstIdx(l)) && (i< capacity(l));
}

boolean isIdxEff(DaftarPlaylist l, IdxType i){
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
    /* yaitu antara 0..NEFF(l) */
    return (i>=getFirstIdx(l)) && (i<=NEFF(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isDaftarPlaylistEmpty(DaftarPlaylist l){
    /* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
    /* *** Test list penuh *** */
    return(listLength(l) == 0);
}

boolean isFull(DaftarPlaylist l){
    /* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    return(listLength(l) == capacity(l));
}

/* ********** OPERASI LAIN ********** */
void copyList(DaftarPlaylist lIn, DaftarPlaylist *lOut){
    /* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
    /* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
    /* Proses : Menyalin isi lIn ke lOut */
    int i;
    CreateListDin(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    for(i = 0; i < NEFF(lIn); i++){
       ELMT(*lOut,i) = ELMT(lIn,i);
    }   
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(DaftarPlaylist *l, Playlist val){
    /* Proses: Menambahkan val sebagai elemen terakhir list */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen terakhir l yang baru */
    ELMT(*l,NEFF(*l)) = val;
    NEFF(*l) += 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(DaftarPlaylist *l, Playlist *val){
    /* Proses : Menghapus elemen terakhir list */
    /* I.S. List tidak kosong */
    /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
    /*      Banyaknya elemen list berkurang satu */
    /*      List l mungkin menjadi kosong */
    *val = ELMT(*l,NEFF(*l)-1);
    NEFF(*l) -= 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(DaftarPlaylist *l, int num){
    /* Proses : Menambahkan capacity l sebanyak num */
    /* I.S. List sudah terdefinisi */
    /* F.S. Ukuran list bertambah sebanyak num */
    DaftarPlaylist ltemp;
    int i;
    CreateDaftarPlaylist(&ltemp, capacity(*l) + num);
    for(i = 0; i < NEFF(*l); i++){
       ELMT(ltemp,i) = ELMT(*l,i);
    }
    NEFF(ltemp) = NEFF(*l);
    dealocateList(l);
    copyList(ltemp,l);
}


void shrinkList(DaftarPlaylist *l, int num){
    /* Proses : Mengurangi capacity sebanyak num */
    /* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
    /* F.S. Ukuran list berkurang sebanyak num. */
    DaftarPlaylist ltemp;
    int i;
    CreateDaftarPlaylist(&ltemp, capacity(*l) - num);
    for(i = 0; i < NEFF(*l); i++){
       ELMT(ltemp,i) = ELMT(*l,i);
    }
    NEFF(ltemp) = NEFF(*l);
    dealocateList(l);
    copyList(ltemp,l);
}

void compressList(DaftarPlaylist *l){
    /* Proses : Mengubah capacity sehingga capacity = nEff */
    /* I.S. List tidak kosong */
    /* F.S. Ukuran capacity = nEff */
    DaftarPlaylist ltemp;
    int i;
    CreateDaftarPlaylist(&ltemp, NEFF(*l));
    for(i = 0; i < NEFF(*l); i++){
       ELMT(ltemp,i) = ELMT(*l,i);
    }
    NEFF(ltemp) = NEFF(*l);
    dealocateList(l);
    copyList(ltemp,l);
}