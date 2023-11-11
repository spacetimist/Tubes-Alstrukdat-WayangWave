/* File: mesinkarakter.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_
#include "../boolean.h"

#define MARK ';'

/* State Mesin */
extern char CC;
extern boolean EOP;

void START();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Mengambil parameter nama file yang hendak dibaca */

void STARTFILE(char filename[]);
/* Mesin membaca dari sebuah file */

void ADV();
/* Pita dimajukan satu karakter */

void ADVFILE();

#endif