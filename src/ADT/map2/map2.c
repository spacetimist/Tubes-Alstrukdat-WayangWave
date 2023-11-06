#include <stdio.h>
#include "boolean.h"
#include "map2.h"

/* *** Konstruktor/Kreator *** */
void CreateListPenyanyi(ListPenyanyi * LP)
{
	LP->NEff = 0;
	int idxPenyanyi = LP->NEff;
	LP->PenyanyiAlbum[idxPenyanyi].ListAlbum.NEff = 0;
	int idxAlbum = LP->PenyanyiAlbum[idxPenyanyi].ListAlbum.NEff;
	LP->PenyanyiAlbum[idxPenyanyi].ListAlbum.AlbumLagu[idxAlbum].IsiLagu.Count = 0;
}

void AddPenyanyi(ListPenyanyi * LP, Kalimat NamaPenyanyi)
{	
	int idxPenyanyi = LP->NEff;
	LP->PenyanyiAlbum[idxPenyanyi].NamaPenyanyi = NamaPenyanyi; 
	LP->NEff ++ ; 
}

Kalimat NamaPenyanyiNow(ListPenyanyi * LP)
{	
	int idxPenyanyi = LP->NEff - 1;
	return LP->PenyanyiAlbum[idxPenyanyi].NamaPenyanyi;
}

void AddAlbum(ListPenyanyi * LP, Kalimat NamaAlbum)
{
	int idxPenyanyi = LP->NEff - 1; 
	int idxAlbum = LP->PenyanyiAlbum[idxPenyanyi].ListAlbum.NEff; 
	LP->PenyanyiAlbum[idxPenyanyi].ListAlbum.AlbumLagu[idxAlbum].NamaAlbum = NamaAlbum; 
	LP->PenyanyiAlbum[idxPenyanyi].ListAlbum.NEff ++ ; 
}

Kalimat NamaAlbumNow(ListPenyanyi * LP)
{
	int idxPenyanyi = LP->NEff - 1;
	int idxAlbum = LP->PenyanyiAlbum[idxPenyanyi].ListAlbum.NEff - 1;
	return LP->PenyanyiAlbum[idxPenyanyi].ListAlbum.AlbumLagu[idxAlbum].NamaAlbum;
}

void AddLagu(ListPenyanyi * LP, Kalimat NamaLagu)
{
	int indeksPenyanyi = LP->NEff - 1;
	int indeksAlbum = LP->PenyanyiAlbum[indeksPenyanyi].ListAlbum.NEff - 1;
	int indekSLagu = LP->PenyanyiAlbum[indeksPenyanyi].ListAlbum.AlbumLagu[indeksAlbum].IsiLagu.Count;
	LP->PenyanyiAlbum[indeksPenyanyi].ListAlbum.AlbumLagu[indeksAlbum].IsiLagu.JudulLagu[indekSLagu] = NamaLagu;
	LP->PenyanyiAlbum[indeksPenyanyi].ListAlbum.AlbumLagu[indeksAlbum].IsiLagu.Count ++ ;
}

Kalimat NamaLaguNow(ListPenyanyi * LP)
{
	int indeksPenyanyi = LP->NEff - 1;
	int indeksAlbum = LP->PenyanyiAlbum[indeksPenyanyi].ListAlbum.NEff - 1;
	int indekSLagu = LP->PenyanyiAlbum[indeksPenyanyi].ListAlbum.AlbumLagu[indeksAlbum].IsiLagu.Count - 1;

	return LP->PenyanyiAlbum[indeksPenyanyi].ListAlbum.AlbumLagu[indeksAlbum].IsiLagu.JudulLagu[indekSLagu];
}

