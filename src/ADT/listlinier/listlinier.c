#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isLinkListEmpty (List L){
	return First(L) == Nul; 
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void createEmptyLinkList (List *L){
	First(*L) = Nul;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
adr Alokasi (infotype X){
	adr P;
	P = (ElmtList *)malloc(sizeof(ElmtList));
	if (P != Nul) {
		Info(P) = X;
		Next(P) = Nul;
		return P;
	} else {
		return Nul;
	}
}
/* Mengirimkan adr hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka adr tidak Nul, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nul */
/* Jika alokasi gagal, mengirimkan Nul */
void Dealokasi (adr *P){
	free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian adr P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
adr Search (List L, infotype X){
	adr P = First(L);
	boolean found = false;

	while (P != Nul && !found){
		if (Info(P) == X){
			found = true;
		} else{
			P = Next(P); 
		}
	}
	if (found){
		return P;
	} else {
		return Nul;
	}
}
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan adr elemen tersebut. */
/* Jika tidak ada, mengirimkan Nul */

/****************** PRIMITIF BERDASARKAN NulAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
	adr P = Alokasi(X);

	if (P != Nul){
		Next(P) = First(*L);
		First(*L) = P;
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan Nulai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
	adr P = Alokasi(X);

	if (P != Nul){
		InsertLast(L, P);
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNulai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
	adr P;
	DelFirst(L, &P);

	*X = Info(P);
	Dealokasi(&P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: Nulai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
	adr P;
	
	DelLast(L, &P);
	*X = Info(P);
	Dealokasi(&P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: Nulai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, adr P){
	Next(P) = First(*L);
	First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-adr P sebagai elemen pertama */
void InsertAfter (List *L, adr P, adr Prec){
	Next(P) = Next(Prec);
	Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, adr P){

	if (isLinkListEmpty(*L)){
		InsertFirst(L, P);
	} else {
		adr last = First(*L);
		while (Next(last) != Nul){
			last = Next(last);
		}
		InsertAfter(L, P, last);
	}
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, adr *P){
	*P = First(*L);
	First(*L) = Next(*P);
	Next(*P) = Nul;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, infotype X){
	adr P = Search(*L, X);

	if (P != Nul){
		if (P == First(*L)){
			DelFirst(L, &P);
		}
		else {
			adr prec = First(*L);
			while (Next(prec) != P){
				prec = Next(prec);
			}
			DelAfter(L, &P, prec);
		}
	}
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beradr P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, adr *P){
	adr last = First(*L);
	adr prec = Nul;

	while (Next(last) != Nul){
		prec = last;
		last = Next(last);
	}

	*P = last;
	if (prec == Nul){
		First(*L) = Nul; 
	} else {
		Next(prec) = Nul;
	}
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, adr *Pdel, adr Prec){
	*Pdel = Next(Prec);
	if (Next(Prec) != Nul){
		Next(Prec) = Next(Next(Prec));
		Next(*Pdel) = Nul;
	}
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
// void PrintInfo (List L){
// 	adr P = First(L);

// 	if (isLinkListEmpty(L)){
// 		printf("[]");
// 	} else {
// 		printf("[%d", Info(P));
// 		while (Next(P) != Nul){
// 			P = Next(P);
// 			printf(",%d", Info(P));
// 		}
// 		printf("]");
// 	}
// }
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berNulai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmt (List L){
	int banyak = 0;

	adr P = First(L);

	while (P != Nul) {
		P = Next(P);
		banyak++;
	}
	return banyak;
}


/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L){
	adr P = First(*L);
	adr A = P;
	adr B = Next(P);
	
	while (B != Nul) {
		A = B;
		B = Next(B);
		InsertFirst(L, A);
		Next(P) = B;
	}
}
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

void Konkat1 (List *L1, List *L2, List *L3){
	createEmptyLinkList(L3);
	adr lastL1 = First(*L1);

	if (isLinkListEmpty(*L1)){
		First(*L3) = First(*L2);
	} else {
		First(*L3) = First(*L1);
		while (Next(lastL1) != Nul){
			lastL1 = Next(lastL1);
		}
		Next(lastL1) = First(*L2);
	}
	createEmptyLinkList(L1);
	createEmptyLinkList(L2);
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan 	L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
void setElmt(List *L, int idx, infotype val){
    int ctr = 0;
	adr p = First(*L);

    while (ctr < idx){
        p = Next(p);
    	ctr++;
	}
    Info(p) = val;
}

infotype getElmt(List L, int idx){
    int ctr = 0;
    adr p = First(L);

    while (ctr < idx){
        p = Next(p);
        ctr++;
    }
    return Info(p);
}

void bubbleSort(List *L){
	// Membesar
	infotype temp;
	for (int i = 0; i < NbElmt(*L)-1; ++i)
    {
        for (int j = 0; j < NbElmt(*L) - i - 1; ++j)
        {
            if (getElmt(*L, j) > getElmt(*L, j+1)){
                temp = getElmt(*L, j);
                setElmt(L, j, getElmt(*L, j+1));
                setElmt(L, j+1, temp);
            }
        }
    }
}