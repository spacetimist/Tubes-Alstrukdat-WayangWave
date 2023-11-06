#include <stdio.h>
#include "boolean.h"
#include "map2.h"

/* *** Konstruktor/Kreator *** */
void CreateListPenyanyi(ListPenyanyi * LP)
{
	(*LP).NEff = 0;
	int indeksPenyanyi = (*LP).NEff;
	(*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.NEff = 0;
	int indeksAlbum = (*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.NEff;
	(*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.AlbumLagu[indeksAlbum].IsiLagu.Count = 0;
}

void AddPenyanyi(ListPenyanyi * LP, Kalimat NamaPenyanyi)
{	
	int indeksPenyanyi = (*LP).NEff;
	(*LP).PenyanyiAlbum[indeksPenyanyi].NamaPenyanyi = NamaPenyanyi; 
	(*LP).NEff += 1; 
}

Kalimat NamaPenyanyiNow(ListPenyanyi * LP)
{	
	int indeksPenyanyi = (*LP).NEff - 1;
	return (*LP).PenyanyiAlbum[indeksPenyanyi].NamaPenyanyi;
}

void AddAlbum(ListPenyanyi * LP, Kalimat NamaAlbum)
{
	int indeksPenyanyi = (*LP).NEff - 1; 
	int indeksAlbum = (*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.NEff; 
	(*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.AlbumLagu[indeksAlbum].NamaAlbum = NamaAlbum; 
	(*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.NEff += 1; 
}

Kalimat NamaAlbumNow(ListPenyanyi * LP)
{
	int indeksPenyanyi = (*LP).NEff - 1;
	int indeksAlbum = (*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.NEff - 1;
	return (*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.AlbumLagu[indeksAlbum].NamaAlbum;
}

void AddLagu(ListPenyanyi * LP, Kalimat NamaLagu)
{
	int indeksPenyanyi = (*LP).NEff - 1;
	int indeksAlbum = (*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.NEff - 1;
	int indekSLagu = (*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.AlbumLagu[indeksAlbum].IsiLagu.Count;
	(*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.AlbumLagu[indeksAlbum].IsiLagu.JudulLagu[indekSLagu] = NamaLagu;
	(*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.AlbumLagu[indeksAlbum].IsiLagu.Count += 1;
}

Kalimat NamaLaguNow(ListPenyanyi * LP)
{
	int indeksPenyanyi = (*LP).NEff - 1;
	int indeksAlbum = (*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.NEff - 1;
	int indekSLagu = (*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.AlbumLagu[indeksAlbum].IsiLagu.Count - 1;

	return (*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbum.AlbumLagu[indeksAlbum].IsiLagu.JudulLagu[indekSLagu];
}

