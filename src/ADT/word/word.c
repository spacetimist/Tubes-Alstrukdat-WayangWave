#include "word.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Word CreateWord()
{
    Word w;

    w.Length = 0;
}

int wordToInt(Word w)
{
    int val = 0;
    boolean negatif = false;
    int i;
    for (i = 0; i < w.Length; i++)
    {
        if (i == 0 && w.TabWord[0] == '-')
        {
            negatif = true;
        }
        else
        {
            val = val * 10 + (w.TabWord[i] - 48);
        }
    }

    if (negatif)
    {
        val = val * -1;
    }

    return val;
}

void printWord(Word w)
{
    int i;
    for (i = 0; i < w.Length; i++)
    {
        printf("%c", w.TabWord[i]);
    }
}

Word stringToWord(char* s)
{
    Word w;
    w.Length = 0 ;
    int i;
	while (s[i] != '\0')
	{
		w.TabWord[i] = s[i];
		w.Length++;
		i++;
	}
    return w;
}

void CopyWord(Word *w1, Word w2)
{
    for (int i = 0; i < w2.Length; i++)
    {
        (*w1).TabWord[i] = w2.TabWord[i];
    }
    (*w1).Length = w2.Length;
}

boolean stringEQWord(Word w, char* c)
{
    boolean eq = false;
    if (w.Length == strlen(c))
    {
        eq = true;
        int i = 0;
        while (i < w.Length && eq)
        {
            if (w.TabWord[i] != c[i])
            {
                eq = false;
            }
            else
            {
                i++;
            }
        }
    }

    return eq;
}

boolean IsEQWord(Word w1, Word w2)
{
    boolean eq = false;
    if (w1.Length == w2.Length)
    {
        eq = true;
        int i = 0;
        while (i < w1.Length && eq)
        {
            if (w1.TabWord[i] != w2.TabWord[i])
            {
                eq = false;
            }
            else
            {
                i++;
            }
        }
    }

    return eq;
}

char* wordToString(Word w)
{
    int i = 0;

    char* ret = malloc((w.Length - i + 2) * sizeof(char));
    char* p = ret;

    while (i < w.Length)
    {
        *p++ = w.TabWord[i];
        i++;
    }
    *p = '\0';

    return ret;
}

Word ambilKataKe(Word w, int kataKe)
{
    Word w2;
    int i = 0, counter = 0, length = 0;
    boolean stop;

    while (counter != kataKe - 1 && i < w.Length)
    {
        stop = false;
        if (w.TabWord[i] == ' ')
        {
            counter++;
            while (i < w.Length && !stop)
            {
                i++;
                if (w.TabWord[i] != ' ')
                {
                    stop = true;
                }
            }
        }
        else
        {
            i++;
        }

        if (i == w.Length)
        {
            counter++;
        }
    }

    stop = false;
    while (!stop && i < w.Length)
    {
        if (w.TabWord[i] == ' ')
        {
            stop = true;
        }
        else
        {
            w2.TabWord[length] = w.TabWord[i];
            i++;
            length++;
        }
    }
    w2.Length = length;

    return w2;
}

Word intToWord(int i)
{
    Word w;
    int len = 0;
    int num = i;
    do
    {
        num /= 10;
        len += 1;
    } while (num != 0);

    w.Length = len;
    for (int j = len - 1; j >= 0; j--)
    {
        w.TabWord[j] = i % 10 + 48;
        i /= 10;
    }

    return w;
}

Word lowerWord(Word w)
{
    Word w1 = CreateWord();
    for (int i = 0; i < w.Length; i++)
    {
        if (w.TabWord[i] >= 'A' && w.TabWord[i] <= 'Z')
        {
            w1.TabWord[i] = 'a' + (w.TabWord[i] - 'A');
        }
        else
        {
            w1.TabWord[i] = w.TabWord[i];
        }
    }
    w1.Length = w.Length;
    return w1;
}

Word upperWord(Word w)
{
    Word w1 = CreateWord();
    for (int i = 0; i < w.Length; i++)
    {
        if (w.TabWord[i] >= 'a' && w.TabWord[i] <= 'z')
        {
            w1.TabWord[i] = 'A' + (w.TabWord[i] - 'a');
        }
        else
        {
            w1.TabWord[i] = w.TabWord[i];
        }
    }
    w1.Length = w.Length;
    return w1;
}

boolean isWordInt(Word w)
{
    boolean cek = true;
    int i = 0;
    while (cek && i < w.Length)
    {
        if (w.TabWord[i] - 48 >= 0 && w.TabWord[i] - 48 <= 9)
        {
            i++;
        }
        else
        {
            cek = false;
        }
    }
    return cek;
}