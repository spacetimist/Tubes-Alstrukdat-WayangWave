// /* Berisi definisi dan semua primitif pemrosesan DaftarPlaylist integer */
// /* Penempatan elemen selalu rapat kiri */
// #include "../mesin/mesinkata.h"
// #include "../mesin/mesinkarakter.h"
// #include "../mesin/mesinkalimat.h"
// #include "../SongDetails.h"
// #include "../map2/map2.h"
// #include "../boolean.h"

// #ifndef ADTDaftarPlaylist1
// #define ADTDaftarPlaylist1
// #define Nul NULL


// /* Kamus Umum */
// #define MaxEl 100
// #define Mark -9999  /* Nilai tak terdefinisi */
// #define InvalidIdx -1  /* Indeks tak terdefinisi */

// /* Definisi elemen dan koleksi objek */
// #define IdxType int
// #define initial_cap 100
// typedef struct tsongNode *addressNode;
// typedef struct tsongNode{
//     SongDetails song;
//     addressNode Next;
// }SongNode;

// typedef struct {
//     addressNode First;
//     Kalimat PlaylistName;
// }Playlist;

// typedef struct{
//     Playlist *List;
//     int capacity;
//     int Neff;
// }DaftarPlaylist;

// #define Info(P) (P)->song
// #define Next(P) (P)->Next
// #define First(L) ((L).First)

// /* Indeks yang digunakan seberapa banyak memori itu terisi */
// /* Jika L adalah DaftarPlaylist, cara deklarasi dan akses: */
// /* Deklarasi: L : DaftarPlaylist */
// /* Maka cara akses:
//  * L.A untuk mengakses seluruh nilai elemen DaftarPlaylist
//  * L.A[i] untuk mengakses elemen ke-i */

// /* ********** KONSTRUKTOR ********** */
// /* Konstruktor: create DaftarPlaylist kosong */
// DaftarPlaylist MakeDaftarPlaylist();
// /* I.S. sembarang */
// /* F.S. Terbentuk DaftarPlaylist L kosong dengan kapasitas MaxEl */

// /* ********** TEST KOSONG/PENUH ********** */
// /* *** Test DaftarPlaylist kosong *** */
// boolean IsDaftarPlaylistEmpty(DaftarPlaylist L);
// /* Mengirimkan true jika DaftarPlaylist L kosong, mengirimkan false jika tidak */

// /**
//  * Destruktor
//  * I.S. ArrayDin terdefinisi
//  * F.S. array->A terdealokasi
//  */
// void DeallocateDaftarPlaylist(DaftarPlaylist *L);

// /* ********** SELEKTOR ********** */
// /* *** Banyaknya elemen *** */

// /**
//  * Fungsi untuk menambahkan elemen baru di index ke-i
//  * Prekondisi: array terdefinisi, i di antara 0..Length(array).
//  */
// void InsertAtListDin(DaftarPlaylist *L, Playlist el, IdxType i);

// /**
//  * Fungsi untuk menghapus elemen di index ke-i ArrayDin
//  * Prekondisi: array terdefinisi, i di antara 0..Length(array).
//  */
// void DeleteAtListDin(DaftarPlaylist *L, IdxType i);

// #endif

/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#ifndef LISTDIN_H
#define LISTDIN_H

#include "../boolean.h"
#include "../listlinier/listlinier.h"

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
// typedef int ElType; /* type elemen list */
typedef int IdxType;
// typedef struct
// {
//     ElType *buffer; /* memori tempat penyimpan elemen (container) */
//     int nEff;       /* >=0, banyaknya elemen efektif */
//     int capacity;   /* ukuran elemen */
// } ListDin;
typedef struct{
    Playlist *List;
    int capacity;
    int Neff;
}DaftarPlaylist;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListDin, cara deklarasi dan akses: */
/* Deklarasi : l : ListDin */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacity */

/* ********** SELEKTOR ********** */
#define NEFF(l) (l).Neff
#define BUFFER(l) (l).List
#define ELMT(l, i) (l).List[i]
#define capacity(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateDaftarPlaylist(DaftarPlaylist *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateList(DaftarPlaylist *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, capacity(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(DaftarPlaylist l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(DaftarPlaylist l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(DaftarPlaylist l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(DaftarPlaylist l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(DaftarPlaylist l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsDaftarPlaylistEmpty(DaftarPlaylist l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean IsDaftarPlaylistFull(DaftarPlaylist l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** OPERASI LAIN ********** */
void copyList(DaftarPlaylist lIn, DaftarPlaylist *lOut);
    /* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
    /* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
    /* Proses : Menyalin isi lIn ke lOut */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void ListDininsertLast(DaftarPlaylist *l, Playlist val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void ListDindeleteLast(DaftarPlaylist *l, Playlist *val);
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(DaftarPlaylist *l, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(DaftarPlaylist *l, int num);
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressList(DaftarPlaylist *l);
/* Proses : Mengubah capacity sehingga capacity = nEff */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacity = nEff */

#endif