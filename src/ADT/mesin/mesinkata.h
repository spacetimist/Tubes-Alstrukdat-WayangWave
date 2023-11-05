/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkarakter.h"
#include "../word/word.h"

#define BLANK '\n'

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;

/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK ('\n') dan currentChar != EOP */
void IgnoreBlanks();

/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan EOP;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
void STARTWORD(char* file);

/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika EOP, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure UpdateCurrentWord */
void ADVWORD();

/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK ('\n');
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
void UpdateCurrentWord();

/*Melakukan pengisian pita oleh input user
    I.S pita kosong
    F.S pita diisi oleh user dan dilakukan pemrosesan oleh mesin kata
*/
void startInputWord();

/* Mengakuisisi kata  ke- pada sebuah command
    I.S pita tidak kosong
    F.S kata ke- diakuisi dan disimpan ke dalam w
*/
void akuisisiCommandWord(Word *w, Word command, int kataKe);

#endif