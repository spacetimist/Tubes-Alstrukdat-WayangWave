#include <stdio.h>
#include "mesinkalimat.h"

boolean EndKalimat;
Kalimat Line;
Kalimat Input;

void IgnoreSemiColon() 
{
    while (CC == ';') {
        ADV() ;
    }
}

void Ignoreblanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (CC == BLANK)
    {
        ADV();
    }
}

void IgnoreNewline()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (CC == NEWLINE)
    {
        ADV();
    }
}

void SalinKalimat() {
    ResetKalimat(); 
    int i = 0;
    while ((CC != MARK) && (CC != NEWLINE) && (CC != EOF))
    {
        Line.TabLine[i] = CC;

        i+= 1;
        ADV();
    }
    Line.Length = i;
}

void SalinSatuKata() {
    ResetKalimat();  
    int i = 0 ;
    while ((CC != BLANK) && (CC != MARK))
    {
        Line.TabLine[i] = CC;
        i += 1;
        ADV();
    }
    Line.Length = i;
}

void SalinRecordLoad() {
    ResetKalimat() ;
    int x = 0 ;
    while ((CC != ';') && (CC != NEWLINE)) {
        Line.TabLine[x] = CC ;
        x ++ ;
        ADV();
    }
    Line.Length = x ;
}

void SalinInput() {
    ResetIn() ;
    int x = 0 ;
    while ((CC != NEWLINE) && (CC != MARK) && (CC != EOF)) {
        Input.TabLine[x] = CC ;
        x++ ;
        ADV() ;
    }
    Input.Length = x ;
}

void STARTKALIMATFILE(char NamaFile[]) {
    STARTFILE(NamaFile);
    IgnoreNewline();
    if (CC == MARK2) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinKalimat();
    }
}

void StartInput() {
    START() ;
    if (CC == ';') {
        EndKalimat = true ;
    } else {EndKalimat = false ;  SalinInput() ;}
}

void ADVKALIMAT(){
    IgnoreNewline();
    Ignoreblanks();
    if (CC == MARK2) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinKalimat();
    }
}

void ADVSATUKATA() {
    Ignoreblanks();
    IgnoreNewline();
    if (CC == BLANK) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinSatuKata();
    }
}

void ADVRecord() {
    Ignoreblanks() ; IgnoreNewline() ; IgnoreSemiColon();
    if (CC == ';' || CC == '\n') {
        EndKalimat = true ;
    } else {
        EndKalimat = false ;
        SalinRecordLoad() ;
    }
}

void copyKalimat (Kalimat k1, Kalimat *k2){
    (*k2).Length=k1.Length;
    for (int i=0;i<=k1.Length;i++){
        k2->TabLine[i] = k1.TabLine[i];
    }
}


boolean isKalimatEqual(Kalimat K1, Kalimat K2) // belum dites
{   
    boolean equal = true;
    if (K1.Length == K2.Length)
    {
        int i = 0;
        while (i < K1.Length && equal)
        {
            if (K1.TabLine[i] != K2.TabLine[i])
            {
                equal = false;
            }
            else
            {
                i++;
            }
        }
        return equal;
    }
    else
    {
        return false;
    }
}

boolean isInputEqual(Kalimat Input, char * kata) {
    boolean eq = true ;
    if (Input.Length == length(kata) ) {
        int i = 0 ;
        while (eq && i < Input.Length) {
            if (Input.TabLine[i] != kata[i]) {
                eq = false ;
            } else { i++ ;}
        } return eq;
    } else {
        return false ;
    }
}


int length (char * S) {
    int i = 0 ;
    while (S[i] != '\0') {
        i++ ;
    } return i ;
}

void ResetIn() {
    for (int x = 0 ; x < sizeof(Input.TabLine) ; x++) {
        Input.TabLine[x] = '\0' ;
        Input.Length = 0 ;
    }
}

void ResetKalimat() {
    for (int i = 0; i < sizeof(Line.TabLine); i++) {
        Line.TabLine[i] = '\0';
        Line.Length = 0;
    }
}


