#include <stdio.h>
#include "start.h"
#include "../ADT/mesin/mesinkata.h"
#include "../ADT/mesin/mesinkarakter.h"
#include "../ADT/mesin/mesinkalimat.h"
#include "../ADT/map2/map2.h"


void STARTREAD(ListPenyanyi * LP){
  STARTKALIMATFILE("../save/config.txt");

  Kalimat NamaPenyanyi;
  Kalimat NamaAlbum;
  Kalimat NamaLagu;

  int jumlah = Line.TabLine[0] - 48;
  printf("\nJumlah Penyanyi: %d\n", jumlah);


  for (int i = 0; i < jumlah; i++){
    ADVSATUKATA();
    int album = Line.TabLine[0] - 48;
    
    ADVKALIMAT();
    Line.Length -- ;
    AddPenyanyi(LP, Line);
    NamaPenyanyi = NamaPenyanyiNow(LP);

    printf("\nNama Penyanyi ke-%d: %s\n", i+1, NamaPenyanyi.TabLine);
    printf("\n");
    printf("Jumlah Album: %d\n", album);
    printf("\n");


    for (int j = 0; j < album; j++){
      ADVSATUKATA();
      int lagu = Line.TabLine[0] - 48;

      ADVKALIMAT();
      Line.Length -- ;
      AddAlbum(LP, Line);
      NamaAlbum = NamaAlbumNow(LP);

      printf("Nama Album: %s\n", NamaAlbum.TabLine);
      printf("\n");
      for (int k = 0; k < lagu; k++)
      {
        ADVKALIMAT();
        Line.Length --;
        AddLagu(LP, Line);
        NamaLagu = NamaLaguNow(LP);

        printf("Nama Lagu %d: %s\n", k+1, NamaLagu.TabLine);
    
      }
      printf("\n");
    }

  }
  printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");

}

// int main () {
//   printf(">> ");
//   StartInput() ;
//   ListPenyanyi ls ;
//   CreateListPenyanyi (&ls) ;

//   if (isInputEqual(Input, "START")) {
//     STARTREAD(&ls) ;
//   } else {
//     return 0 ;
//   }
// }