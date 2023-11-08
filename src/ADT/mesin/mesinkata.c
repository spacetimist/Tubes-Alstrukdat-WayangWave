#include "mesinkata.h"
#include <stdio.h>


/* State Mesin Word */
boolean EndWord;
Word currentWord;

void IgnoreBlanks(){
    while (CC == BLANK){
        ADV();
    }
}

void STARTWORD(){
    START();
    IgnoreBlanks();
    if (CC == MARK){
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD(){
    IgnoreBlanks();
    if(CC == MARK){
        EndWord = true;
    } else{
        CopyWord();
        IgnoreBlanks();
    }
}


void CopyWord(){
    currentWord.Length = 0;
    while (CC != MARK && CC != BLANK && CC != '\n'){
        if (currentWord.Length < NMax){
            currentWord.TabWord[currentWord.Length] = CC;
            currentWord.Length++;
        }
        ADV();
    }
}

void printWord(){
    for (int i = 0; i < currentWord.Length; i++)
    {
        printf("%c", currentWord.TabWord[i]);
    }
    printf("\n");
}

void WordToString (Word w, char *S){
    for (int i = 0; i < w.Length; i++)
    {
        S[i] = w.TabWord[i];
    }
    for (int i = w.Length; i < length(S); i++) 
    {
        if (S[i] != '\0') {
            S[i] = '\0';
        }
    }
}

boolean IsKataEqual(Word w1, char * S2){
    boolean equal = true;
    int i = 0;
    
    if (w1.Length == length(S2)){
        while (i < length(S2) && equal){
            if (w1.TabWord[i] != S2[i])
            {
                equal = false;
            }
            else
            {
                i++;
            }
        }
    }
    else{
        equal = false;
    }

    return equal;
}



void resetWord()
{
    currentWord.Length = 0;
}