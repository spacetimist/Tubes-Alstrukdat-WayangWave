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
extern Kalimat Input; /* Untuk mengecek input(command)*/

void IgnoreSemiColon() ;
void IgnoreNewline();
void Ignoreblanks();

void SalinKalimat();
void SalinSatuKata();
void SalinRecordLoad() ;
void SalinInput() ;

void STARTKALIMATFILE(char NamaFile[]);
void StartInput () ;

void ADVKALIMAT();
void ADVSATUKATA();
void ADVRecord() ;
void ADVCommand() ;

void copyKalimat (Kalimat k1, Kalimat *k2);

boolean isKalimatEqual(Kalimat K1, Kalimat K2);
boolean isInputEqual (Kalimat Input, char * kata) ;


void ResetKalimat();
void ResetIn() ;

int length(char * S) ;


#endif