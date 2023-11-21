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
#define Nul NULL


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

#define Info(P) (P)->song
#define Next(P) (P)->Next
#define First(L) ((L).First)

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

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateDaftarPlaylist(DaftarPlaylist *L);

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAtListDin(DaftarPlaylist *L, Playlist el, IdxType i);

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAtListDin(DaftarPlaylist *L, IdxType i);

#endif