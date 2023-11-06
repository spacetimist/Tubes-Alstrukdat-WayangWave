#ifndef MAPSETLIST_H
#define MAPSETLIST_H
#include <stdio.h>
#include "../mesin/mesinkalimat.h"
#include "boolean.h"

/* MODUL MapAlbum
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define Nil 0
#define AlbumMax 100
#define Undefined -999

// typedef int bool;
typedef int idAlbum;
typedef int address;

// 5
typedef struct
{   
  Kalimat JudulLagu[20];
  address Count;
} SetLagu;

// 4
typedef struct {
	Kalimat NamaAlbum;
	SetLagu IsiLagu; // set Lagu dari suatu album
} MapLagu;

// 3
typedef struct
{
	MapLagu AlbumLagu[10];
	int NEff;
} ListAlbum;

// 2
typedef struct {
	Kalimat NamaPenyanyi;
	ListAlbum ListAlbum; // array of ListAlbum yang dimiliki penyanyi
} MapAlbum;

// 1
typedef struct {
	MapAlbum PenyanyiAlbum[20];
	int NEff;
} ListPenyanyi;



void CreateListPenyanyi(ListPenyanyi * LP);

void AddPenyanyi(ListPenyanyi * LP, Kalimat NamaPenyanyi);


Kalimat NamaPenyanyiNow(ListPenyanyi * LP);


void AddAlbum(ListPenyanyi * LP, Kalimat NamaAlbum);


Kalimat NamaAlbumNow(ListPenyanyi * LP);

void AddLagu(ListPenyanyi * LP, Kalimat NamaLagu);

Kalimat NamaLaguNow(ListPenyanyi * LP);


#endif