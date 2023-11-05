/* File: mesinkarakter.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "boolean.h"

#define MARK '.'
/* State Mesin */
extern char currentChar;
extern boolean EOP;

/* Pita dimajukan satu karakter.
       I.S. : Karakter pada jendela = currentChar, currentChar != feof
       F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
              Jika  pita kosong EOP akan menyala (true) */
void START(char* file);

/* Pita dimajukan satu karakter.
       I.S. : Karakter pada jendela = currentChar, currentChar != feof
       F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
              Jika  pita kosong EOP akan menyala (true) */
void ADV();

/*
    Mengirimkan currentChar
*/
char GetCC();

/*
    Mengirimkan true jika currentChar = MARK
*/
boolean IsEOP();

/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari sebuah stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita */
void startInput();

#endif