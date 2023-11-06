#include <stdio.h>
#include "start.h"
#include "../ADT/mesin/mesinkata.h"
#include "../ADT/mesin/mesinkarakter.h"
#include "../ADT/mesin/mesinkalimat.h"
#include "../ADT/map2/map2.h"


void STARTREAD(ListPenyanyi * LP){
  STARTKALIMATFILE("config.txt");

  Kalimat NamaPenyanyi;
  Kalimat NamaAlbum;
  Kalimat NamaLagu;

  int loop = CLine.TabLine[0] - 48;
  printf("\nJumlah Penyanyi: %d\n", loop);


  for (int i = 0; i < loop; i++){
    ADVSATUKATA();
    int album = CLine.TabLine[0] - 48;
    
    ADVKALIMAT();
    
    AddPenyanyi(LP, CLine);
    NamaPenyanyi = NamaPenyanyiNow(LP);

    printf("\nNama Penyanyi ke-%d: %s\n", i+1, NamaPenyanyi.TabLine);
    printf("\n");
    printf("Jumlah Album: %d\n", album);
    printf("\n");


    for (int j = 0; j < album; j++){
      ADVSATUKATA();
      int lagu = CLine.TabLine[0] - 48;

      ADVKALIMAT();

      AddAlbum(LP, CLine);
      NamaAlbum = NamaAlbumNow(LP);

      printf("Nama Album: %s\n", NamaAlbum.TabLine);
      printf("\n");
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

int main () {
  printf(">>");
  STARTWORD() ;
  ListPenyanyi ls ;
  CreateListPenyanyi (&ls) ;

  if (IsKataEqual(currentWord, "START")) {
    STARTREAD(&ls) ;
  } else {
    return 0 ;
  }
}