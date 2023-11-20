/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Kreator *** */
void CreateQueue(Queue *q){
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isQueueEmpty(Queue q){
/* Mengirim true jika q kosong: lihat definisi di atas */
    return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
}
boolean isQueueFull(Queue q){
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
    if (IDX_TAIL(q) >= IDX_HEAD(q))
        return IDX_TAIL(q) - IDX_HEAD(q) == CAPACITY - 1;
    else
        return IDX_HEAD(q) - IDX_TAIL(q) == 1;
}
int queueLength(Queue q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    if (isQueueEmpty(q)) 
        return 0;
    else if (IDX_TAIL(q) >= IDX_HEAD(q))
        return IDX_TAIL(q) - IDX_HEAD(q) + 1;
    else
        return IDX_TAIL(q) - IDX_HEAD(q) + CAPACITY + 1;
}
/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, SongDetails val){
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
    if (isQueueEmpty(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else {
        if (IDX_TAIL(*q) == (CAPACITY-1)){
            IDX_TAIL(*q) = 0;
        }
        else {
            IDX_TAIL(*q) += 1;
        }
    }
    TAIL(*q) = val;
}
void dequeue(Queue *q, SongDetails *val){
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q))
    {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else
    {
        if (IDX_HEAD(*q) == CAPACITY - 1)
        {
            IDX_HEAD(*q) = 0;
        }
        else
        {
            IDX_HEAD(*q)
            ++;
        }
    }
}

void displayQueue(Queue q) {
    for (int i = IDX_HEAD(q) ; i<= IDX_TAIL(q) ; i++) {
        printf("{%s, %s, %s}\n", LineToString(q.buffer[i].artistName), LineToString(q.buffer[i].albumName), LineToString(q.buffer[i].songName)) ;
    }
}