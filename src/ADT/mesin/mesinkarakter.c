#include "mesinkarakter.h"
#include <stdio.h>
#include <stdlib.h>

char CC;
boolean EOP;

static FILE * pita;
static int retval;

void START() {
    pita = stdin;
    ADV();
}

void STARTFILE(char filename[]) {
    pita = fopen(filename, "r");
    if (pita != NULL) {
        ADVFILE();
    } else {

    }
}

void ADV() {
    retval = fscanf(pita,"%c",&CC);
}

void ADVFILE() {
    retval = fscanf(pita,"%c",&CC);
    if (feof(pita)) {
       fclose(pita);
    }
}