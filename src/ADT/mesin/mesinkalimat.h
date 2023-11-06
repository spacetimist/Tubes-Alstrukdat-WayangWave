#ifndef __MESIN_KALIMAT_H__
#define __MESIN_KALIMAT_H__

#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"

#define NMaks 400
#define NEWLINE '\n'
#define MARK2 '\0'

typedef struct {
  char TabLine[NMaks+1];
  int Length;
} Kalimat;

/* State Mesin Kalimat */
extern boolean EndKalimat;
extern Kalimat Line;

void IgnoreNewline();

void Ignoreblanks();

void SalinKalimat();

void SalinSatuKata();

void STARTKALIMATFILE(char filename[]);

void ADVKALIMAT();

void ADVSATUKATA();

void copyKalimat (Kalimat k1, Kalimat *k2);

void ResetKalimat();


#endif
