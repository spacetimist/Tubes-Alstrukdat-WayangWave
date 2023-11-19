#include <stdio.h>
#include "stack.h"

void CreateStack(Stack *s) {
/* ... */
/* KAMUS LOKAL */
/* ALGORITMA */
    IDX_TOP(*s) = IDX_UNDEF;
}
int stackLength(Stack s) {
/* ... */
/* KAMUS LOKAL */
/* ALGORITMA */
    return (IDX_TOP(s) + 1);
}

boolean isStackEmpty(Stack s) {
/* ... */
/* KAMUS LOKAL */
/* ALGORITMA */
    return (IDX_TOP(s) == IDX_UNDEF);
}
boolean isStackFull(Stack s) {
/* ... */
/* KAMUS LOKAL */
/* ALGORITMA */
    return (IDX_TOP(s) == CAPACITY-1);
}

void push(Stack *s, ElType val) {
/* ... */
/* KAMUS LOKAL */
/* ALGORITMA */
    IDX_TOP(*s)++;
    TOP(*s) = val;
}
void pop(Stack *s, ElType *val) {
/* ... */
/* KAMUS LOKAL */
/* ALGORITMA */
    *val = TOP(*s);
    IDX_TOP(*s)--;
}