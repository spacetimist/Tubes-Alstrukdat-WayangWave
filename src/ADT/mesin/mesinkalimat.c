#include <stdio.h>
#include "mesinkalimat.h"

boolean EndKalimat;
Kalimat Line;

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
    while ((CC != NEWLINE) && (CC != EOF) && (CC != MARK))
    {
        Line.TabLine[i] = CC;
        i+= 1;
        ADV();
    }
    Line.Length = i;
}

void SalinSatuKata() {
    ResetKalimat(); 
    int i = 0;
    while ((CC != BLANK) && (CC != MARK))
    {
        Line.TabLine[i] = CC;
        i += 1;
        ADV();
    }
    Line.Length = i;
}

void STARTKALIMATFILE(char filename[]) {
    STARTFILE(filename);
    IgnoreNewline();
    if (CC == MARK2) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinKalimat();
    }
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

void copyKalimat (Kalimat k1, Kalimat *k2){
    k2->Length=k1.Length;
    for (int i=0;i<=k1.Length;i++){
        k2->TabLine[i] = k1.TabLine[i];
    }
}

void ResetKalimat() {
    for (int i = 0; i < sizeof(Line.TabLine); i++) {
        Line.TabLine[i] = '\0';
        Line.Length = 0;
    }
}


