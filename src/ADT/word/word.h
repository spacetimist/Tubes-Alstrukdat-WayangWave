#ifndef __WORD_H__
#define __WORD_H__

#define NMax 100

#include "./boolean.h"

typedef struct
{
    char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
    int Length;
} Word;

/* Membuat sebuah word kosong. Ciri word kosong: w.Length = 0 */
Word CreateWord();

/*
 I.S word terdefinisi
 F.S dirubah ke integer dan dimasukkan ke dalan integer
*/
int wordToInt(Word w);

/*
 I.S word terdefinisi
 F.S menampilkan word
*/
void printWord(Word w);

/* Mengkonversi string menjadi word */
Word stringToWord(char* string);

/*
 Proses: Menyalin isi w2 ke w1
 I.S. w1 sembarang
 F.S. TabWord w1 berisi elemen elemen yang sama dengan TabWord w2;
      w1.Length = w2.Length */
void CopyWord(Word *w1, Word w2);

/*Mengembalikan Nilai true jika string dengan tabword bernilai sama*/
boolean stringEQWord(Word w, char* c);

/*Mengembalikan Nilai true jika w1 dengan w2 bernilai sama*/
boolean IsEQWord(Word w1, Word w2);

/* Mengkonversi tipe Word menjadi tipe string */
char* wordToString(Word w);

/* Mereturn kata ke- pada w */
Word ambilKataKe(Word w, int kataKe);

/* Mereturn integer ke word untuk bilangan positid*/
Word intToWord(int i);

/* Mereturn word dengan setiap karakter bersifat lowercase */
Word lowerWord(Word w);

/* Mereturn word dengan setiap karakter bersifat uppercase */
Word upperWord(Word w);

/* Mereturn false jika bukan semua elemen tabword integer, true jika semua integer*/
boolean isWordInt(Word w);

#endif