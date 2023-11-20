/* Berisi definisi dan semua primitif pemrosesan DaftarPlaylist integer */
/* Penempatan elemen selalu rapat kiri */
#include "../mesin/mesinkata.h"
#include "../mesin/mesinkarakter.h"
#include "../mesin/mesinkalimat.h"
#include "../SongDetails.h"
#include "../map2/map2.h"
#include "../boolean.h"

#ifndef ADTDaftarPlaylist1
#define ADTDaftarPlaylist1

/* Kamus Umum */
#define MaxEl 100
#define Mark -9999  /* Nilai tak terdefinisi */
#define InvalidIdx -1  /* Indeks tak terdefinisi */

/* Definisi elemen dan koleksi objek */
#define IdxType int
#define initial_cap 100
typedef struct tsongNode *addressNode;
typedef struct tsongNode{
    SongDetails song;
    addressNode Next;
}SongNode;

typedef struct {
    addressNode First;
    Kalimat PlaylistName;
}Playlist;

typedef struct{
    Playlist *List;
    int capacity;
    int Neff;
}DaftarPlaylist;

/* Indeks yang digunakan seberapa banyak memori itu terisi */
/* Jika L adalah DaftarPlaylist, cara deklarasi dan akses: */
/* Deklarasi: L : DaftarPlaylist */
/* Maka cara akses:
 * L.A untuk mengakses seluruh nilai elemen DaftarPlaylist
 * L.A[i] untuk mengakses elemen ke-i */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create DaftarPlaylist kosong */
DaftarPlaylist MakeDaftarPlaylist();
/* I.S. sembarang */
/* F.S. Terbentuk DaftarPlaylist L kosong dengan kapasitas MaxEl */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test DaftarPlaylist kosong *** */
boolean IsDaftarPlaylistEmpty(DaftarPlaylist L);
/* Mengirimkan true jika DaftarPlaylist L kosong, mengirimkan false jika tidak */

/* *** Menghasilkan sebuah elemen *** */
Playlist Get(DaftarPlaylist L, IdxType i);
/* Prekondisi : DaftarPlaylist tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen DaftarPlaylist yang ke-i */

/* *** Selektor SET : Mengubah nilai DaftarPlaylist dan elemen DaftarPlaylist *** */
void Set(DaftarPlaylist *L, IdxType i, Playlist v);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length(DaftarPlaylist L);
/* Mengirimkan banyaknya elemen efektif DaftarPlaylist */
/* Mengirimkan nol jika DaftarPlaylist kosong */

/* *** Selektor INDEKS *** */
IdxType FirstIdx(DaftarPlaylist L);
/* Prekondisi : DaftarPlaylist L tidak kosong */
/* Mengirimkan indeks elemen pertama */

IdxType LastIdx(DaftarPlaylist L);
/* Prekondisi : DaftarPlaylist L tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (DaftarPlaylist L, IdxType i);
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran DaftarPlaylist */
/* yaitu antara indeks yang terdefinisi untuk container*/

boolean IsIdxEff (DaftarPlaylist L, IdxType i);
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk DaftarPlaylist */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

/* ********** Operasi-operasi ********** */
boolean SearchDaftarPlaylist(DaftarPlaylist L, Playlist X);
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam DaftarPlaylist */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

void InsertFirstDaftarPlaylist(DaftarPlaylist *L, Playlist X);
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */

void InsertAtDaftarPlaylist(DaftarPlaylist *L, Playlist X, IdxType i);
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */

void InsertLastDaftarPlaylist(DaftarPlaylist *L, Playlist X);
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */

void DeleteFirstDaftarPlaylist(DaftarPlaylist *L);
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */

void DeleteAtDaftarPlaylist(DaftarPlaylist *L, IdxType i);
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */

// void DeleteLastDaftarPlaylist(DaftarPlaylist *L);
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */

// DaftarPlaylist ConcatDaftarPlaylist(DaftarPlaylist L1, DaftarPlaylist L2);
/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah DaftarPlaylist yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */
#endif