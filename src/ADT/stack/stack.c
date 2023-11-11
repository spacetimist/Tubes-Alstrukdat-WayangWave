#include <stdio.h>
#include "stack.h"

void CreateStack(Stack *s) {
/* ... */
/* KAMUS LOKAL */
/* ALGORITMA */
    IDX_TOP(*s) = IDX_UNDEF;
}
int length(Stack s) {
/* ... */
/* KAMUS LOKAL */
/* ALGORITMA */
    return (IDX_TOP(s) + 1);
}

boolean isEmpty(Stack s) {
/* ... */
/* KAMUS LOKAL */
/* ALGORITMA */
    return (IDX_TOP(s) == IDX_UNDEF);
}
boolean isFull(Stack s) {
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