/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#ifndef listlinier_H
#define listlinier_H

#include "../boolean.h"
#include "../SongDetails.h"

#define Nil NULL

// typedef int infotype;
// typedef struct tElmtlist *address;
// typedef struct tElmtlist { 
// 	infotype info;
// 	address next;
// } ElmtList;
typedef struct tsongNode *addressNode;
typedef struct tsongNode{
    SongDetails song;
    addressNode Next;
}SongNode;

// typedef struct {
// 	address First;
// } List;
typedef struct {
    addressNode First;
    Kalimat PlaylistName;
}Playlist;

/* Definisi Playlist : */
/* PlayList kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir Playlist : jika addressnya Last, maka Next(Last)=Nil */
#define Info(P) (P)->song
#define Next(P) (P)->Next
#define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST Playlist KOSONG ******************/
boolean IsEmpty (Playlist L);
/* Mengirim true jika Playlist kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (Playlist *L);
/* I.S. sembarang             */
/* F.S. Terbentuk Playlist kosong */

/****************** Manajemen Memori ******************/
addressNode Alokasi (SongDetails X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (addressNode *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (Playlist *L, SongDetails X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (Playlist *L, SongDetails X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen Playlist di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (Playlist *L, SongDetails *X);
/* I.S. Playlist L tidak kosong  */
/* F.S. Elemen pertama Playlist dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (Playlist *L, SongDetails *X);
/* I.S. Playlist tidak kosong */
/* F.S. Elemen terakhir Playlist dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (Playlist *L, addressNode P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (Playlist *L, addressNode P, addressNode Prec);
/* I.S. Prec pastilah elemen Playlist dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (Playlist *L, addressNode P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (Playlist *L, addressNode *P);
/* I.S. Playlist tidak kosong */
/* F.S. P adalah alamat elemen pertama Playlist sebelum penghapusan */
/*      Elemen Playlist berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DelLast (Playlist *L, addressNode *P);
/* I.S. Playlist tidak kosong */
/* F.S. P adalah alamat elemen terakhir Playlist sebelum penghapusan  */
/*      Elemen Playlist berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (Playlist *L, addressNode *Pdel, addressNode Prec);
/* I.S. Playlist tidak kosong. Prec adalah anggota Playlist  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen Playlist yang dihapus  */

/****************** PROSES SEMUA ELEMEN Playlist ******************/
int NbElmt (Playlist L);
/* Mengirimkan banyaknya elemen Playlist; mengirimkan 0 jika Playlist kosong */

#endif