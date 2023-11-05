#include <stdio.h>
#include "hashmap.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(HashMap *M)
/* I.S. Sembarang */
/* F.S. Membuat sebuah HashMap M kosong berkapasitas MaxEl */
/* Ciri HashMap kosong : count bernilai Nil dengan seluruh isi map Undefined */
{
    (*M).Count = Nil;

    for (int i = 0; i < MaxEl; i++)
    {
        (*M).Elements[i].Key = Undefined;
        (*M).Elements[i].Value = Undefined;
    }
}

/* *** Index Penyimpanan dengan modulo *** */
address Hash(keytype K)
/* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxEl */
{
    return K % MaxEl;
}

/* ********** Operator Dasar HashMap ********* */
valuetype Value(HashMap M, keytype k)
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */
{
    address index = Hash(k);

    if (M.Elements[index].Key == k) return M.Elements[index].Value;
    else
    {
        address i = index + 1;

        while (M.Elements[i].Key != Undefined && M.Elements[i].Key != k && i != index)
        {
            i += 1;
            if (i == MaxEl) i = 0;
        }
        
        if (M.Elements[i].Key == k) return M.Elements[i].Value;
        else return Undefined;
    }
}

void Insert(HashMap *M, keytype k, valuetype v)
/* Menambahkan Elmt sebagai elemen HashMap M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan 
        index yang digunakan untuk menyimpan v adalah hash dari k
        gunakan open addressing linear probing dengan interval 1 jika index sudah terisi    */
{
    address index = Hash(k);

    if ((*M).Count == Nil)
    {
        (*M).Elements[index].Key = k;
        (*M).Elements[index].Value = v;
        (*M).Count = 1;
    } else
    {
        if ((*M).Elements[index].Key == Undefined)
        {
            (*M).Elements[index].Key = k;
            (*M).Elements[index].Value = v;
            (*M).Count += 1;
        } else if ((*M).Elements[index].Key == k) (*M).Elements[index].Value = v;
        else
        {
            address i = index + 1;

            while ((*M).Elements[i].Key != Undefined)
            {
                i += 1;
                if (i == MaxEl) i = 0;
            }
            
            (*M).Elements[i].Key = k;
            (*M).Elements[i].Value = v;
            (*M).Count += 1;
        }
    }
}