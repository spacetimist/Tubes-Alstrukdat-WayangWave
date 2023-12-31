#ifndef MAPLIST_H
#define MAPLIST_H
#include <stdio.h>
#include "../mesin/mesinkalimat.h"
#include "../boolean.h"



#define Nil 0
#define AlbumMax 100
#define Undefined -999


typedef int idAlbum;
typedef int address;


typedef struct
{   
  Kalimat JudulLagu[25];
  int Count;
} SetLagu;


typedef struct {
	Kalimat NamaAlbum;
	SetLagu IsiLagu; 
} MapLagu;


typedef struct
{
	MapLagu AlbumLagu[10];
	int NEff;
} ListAlbum;


typedef struct {
	Kalimat NamaPenyanyi;
	ListAlbum ListAlbum; 
} MapAlbum;


typedef struct {
	MapAlbum PenyanyiAlbum[20];
	int NEff;
} ListPenyanyi;

boolean IsMemberLP(ListPenyanyi LP, Kalimat NP);

ListAlbum ValueLP(ListPenyanyi LP, Kalimat NP);

void CreateListPenyanyi(ListPenyanyi * LP);

void AddPenyanyi(ListPenyanyi * LP, Kalimat NamaPenyanyi);

Kalimat NamaPenyanyiNow(ListPenyanyi * LP);

void AddAlbum(ListPenyanyi * LP, Kalimat NamaAlbum);

Kalimat NamaAlbumNow(ListPenyanyi * LP);

void AddLagu(ListPenyanyi * LP, Kalimat NamaLagu);

Kalimat NamaLaguNow(ListPenyanyi * LP);


#endif