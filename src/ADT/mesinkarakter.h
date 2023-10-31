/* File: mesinkarakter.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "boolean.h"

/* State Mesin */
extern char CC;
extern boolean EOP;

void STARTFILE();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.*/

void START();
//	 Pita disiapkan untuk dibaca.
//   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
//   Pita baca diambil dari stdin.

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari currentChar yang lama,
          CC mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */


#endif