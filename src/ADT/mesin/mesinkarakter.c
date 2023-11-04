#include <stdio.h>
#include "mesinkarakter.h"

char CC;
boolean EOP;

static FILE *pita;
static int retval;

void START(){
    pita = stdin;
    ADV();
}

void STARTFILE(char *filename){
    pita = fopen(filename, "r");
    ADV();
}

void ADV(){
    retval = fscanf(pita, "%c", &CC);
    EOP = feof(pita);
    if (EOP){
        fclose(pita);
    }
}