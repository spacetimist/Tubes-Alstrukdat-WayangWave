#include <stdio.h>
#include "./mesin/mesinkata.h"
#include "./mesin/mesinkarakter.h"
#include "./mesin/mesinkata.h"
#include "./map2/map2.h"
#include "start.h"

void STARTREAD(ListPenyanyi * LP){
  STARTKALIMATFILE("config.txt");

  Kalimat NamaPenyanyi;
  Kalimat NamaAlbum;
  Kalimat NamaLagu;

  int loop = CLine.TabLine[0] - 48;
  printf("\nJumlah Penyanyi: %d\n", loop);


  for (int i = 0; i < loop; i++){
    ADVSATUKATA();
    // printf("Kalimat %d: %s\n", 1, CLine.TabLine);
    int album = CLine.TabLine[0] - 48;
    
    ADVKALIMAT();
    
    AddPenyanyi(LP, CLine);
    NamaPenyanyi = NamaPenyanyiNow(LP);

    printf("\nNama Penyanyi ke-%d: %s\n", i+1, NamaPenyanyi.TabLine);
    printf("--------------------------------------\n");
    printf("Jumlah Album: %d\n", album);
    printf("--------------------------------------\n");


    for (int j = 0; j < album; j++){
      ADVSATUKATA();
      int lagu = CLine.TabLine[0] - 48;

      ADVKALIMAT();

      AddAlbum(LP, CLine);
      NamaAlbum = NamaAlbumNow(LP);

      printf("Nama Album: %s\n", NamaAlbum.TabLine);
      printf("--------------------------------------\n");
      for (int k = 0; k < lagu; k++)
      {
        ADVKALIMAT();

        AddLagu(LP, CLine);
        NamaLagu = NamaLaguNow(LP);

        printf("Nama Lagu %d: %s\n", k+1, NamaLagu.TabLine);
    
      }
      printf("\n");
    }

  }

}

