#ifndef __START_H__
#define __START_H__

#include "../ADT/boolean.h"
#include <stdio.h>
#include "../ADT/mesin/mesinkata.h"
#include "../ADT/mesin/mesinkarakter.h"
#include "../ADT/mesin/mesinkalimat.h"
#include "../ADT/map2/map2.h"

void STARTREAD(ListPenyanyi * LP);

#endif

// gcc ../ADT/mesin/mesinkata.h ../ADT/mesin/mesinkalimat.h ../ADT/mesin/mesinkarakter.h ../ADT/map2/map2.h ../ADT/mesin/mesinkata.c ../ADT/mesin/mesinkalimat.c ../ADT/mesin/mesinkarakter.c ../ADT/map2/map2.c start.h start.c -o tes