#include "start.h"

void START(Arr *arrgame, StackW *history)
{
    MakeEmpty(arrgame);
    CreateEmptyStackV2(history);
    STARTWORD("../data/config.txt");

    int i;
    int lenOfArr = currentWord.TabWord[0] - 48;

    ADVWORD();
    int temp = 0;
    for (i = 0; i < lenOfArr; i++)
    {
        // printf("%s\n", currentWord.TabWord);
        SetEl(arrgame, i, currentWord);
        ADVWORD();
    }
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}
/*
int main()
{
    Arr arrgame;
    STARTGAME(&arrgame);
    TulisIsi(arrgame);
}
*/