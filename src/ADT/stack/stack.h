#ifndef STACK_H
#define STACK_H
#include "../boolean.h"
#include "../mesin/mesinkalimat.h"
#include "../SongDetails.h"

#define IDX_UNDEF -1
#define Capacity 10

typedef struct {
    SongDetails buffer[Capacity];
    int idxTop;
} Stack;

#define IDX_TOP(s) (s).idxTop
#define TOP(s) (s).buffer[(s).idxTop]

/*** Konstruktor/Kreator ***/
void CreateStack(Stack *s);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Stack s yang kosong berkapasitas Capacity */
/* jadi indeksnya antara 0..Capacity-1 */
/* Ciri stack kosong: idxTop bernilai IDX_UNDEF */

/********** Predikat Untuk test keadaan KOLEKSI **********/
boolean isStackEmpty(Stack s);
/* Mengirim true jika Stack kosong: lihat definisi di atas */

boolean isStackFull(Stack s);
/* Mengirim true jika Stack penuh */

int stackLength(Stack s);
/* Mengirim ukuran Stack s saat ini */

/*********** Menambahkan sebuah elemen ke Stack **********/
void push(Stack *s, SongDetails val);
/* Menambahkan val sebagai elemen Stack s.
I.S. s mungkin kosong, tidak penuh
F.S. val menjadi TOP yang baru, TOP bertambah 1 */
/*********** Menghapus sebuah elemen Stack **********/
void pop(Stack *s, SongDetails *val);
/* Menghapus X dari Stack S.
I.S. S tidak mungkin kosong
F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif