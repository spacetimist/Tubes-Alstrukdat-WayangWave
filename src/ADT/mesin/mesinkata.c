#include "mesinkata.h"
#include <stdio.h>
#include <stdlib.h>

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    while (currentChar == BLANK && !IsEOP())
    {
        ADV();
    }
}

void STARTWORD(char* file)
{
    START(file);
    IgnoreBlanks();
    if (IsEOP())
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        ADVWORD();
    }
}

void ADVWORD()
{
    if (IsEOP())
    {
        EndWord = true;
    }
    else
    {
        UpdateCurrentWord();
        IgnoreBlanks();
    }
}

void UpdateCurrentWord()
{
    int i = 0;
    while ((currentChar != BLANK) && i < NMax && !IsEOP())
    {
        currentWord.TabWord[i] = currentChar;
        ADV();

        i += 1;
    }
    currentWord.Length = i;
}

void startInputWord()
{
    startInput();
    IgnoreBlanks();
    if (IsEOP())
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        UpdateCurrentWord();
    }
}

void akuisisiCommandWord(Word *w, Word command, int kataKe)
{
    int i = 0, counter = 0, length = 0;
    boolean stop;

    while (counter != kataKe - 1 && i < command.Length)
    {
        stop = false;
        if (command.TabWord[i] == ' ')
        {
            counter++;
            while (i < command.Length && !stop)
            {
                i++;
                if (command.TabWord[i] != ' ')
                {
                    stop = true;
                }
            }
        }
        else
        {
            i++;
        }

        if (i == command.Length)
        {
            counter++;
        }
    }

    stop = false;
    while (!stop && i < command.Length)
    {
        if (command.TabWord[i] == ' ')
        {
            stop = true;
        }
        else
        {
            w->TabWord[length] = command.TabWord[i];
            i++;
            length++;
        }
    }
    w->Length = length;
}