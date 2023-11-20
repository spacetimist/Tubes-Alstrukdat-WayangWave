/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi adr dengan pointer */
/* infotype adalah integer */

#ifndef listlinier_H
#define listlinier_H

#include "../boolean.h"

#define Nul NULL

typedef char* infotype;
typedef struct tElmtlist *adr;
typedef struct tElmtlist { 
	infotype info; // judul lagu
	adr next;
} ElmtList;
typedef struct {
	adr First;
} List;

/* Definisi list : */
/* List kosong : First(L) = Nul */
/* Setiap elemen dengan adr P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika adrnya Last, maka Next(Last)=Nul */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void createEmptyLinkList (List *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
adr Alokasi (infotype X);
/* Mengirimkan adr hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka adr tidak Nul, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nul */
/* Jika alokasi gagal, mengirimkan Nul */
void Dealokasi (adr *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian adr P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
adr Search (List L, infotype X);
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan adr elemen tersebut. */
/* Jika tidak ada, mengirimkan Nul */

/****************** PRIMITIF BERDASARKAN NulAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan Nulai X jika alokasi berhasil */
void InsVLast (List *L, infotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNulai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: Nulai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: Nulai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, adr P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-adr P sebagai elemen pertama */
void InsertAfter (List *L, adr P, adr Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, adr P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, adr *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, infotype X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beradr P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, adr *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, adr *Pdel, adr Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berNulai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmt (List L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L);
/* Mengirimkan Nulai info(P) yang maksimum */
adr AdrMax (List L);
/* Mengirimkan adr P, dengan info(P) yang berNulai maksimum */
infotype Min (List L);
/* Mengirimkan Nulai info(P) yang minimum */
adr AdrMin (List L);
/* Mengirimkan adr P, dengan info(P) yang berNulai minimum */
float Average (List L);
/* Mengirimkan Nulai rata-rata info(P) */

/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L);
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

void Konkat1 (List *L1, List *L2, List *L3);
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
void setElmt(List *L, int idx, infotype val);
infotype getElmt(List L, int idx);
void bubbleSort(List *L);

#endif