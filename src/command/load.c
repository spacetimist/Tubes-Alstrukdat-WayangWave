#include "load.h"

void LOADFILE(ListPenyanyi * LP, char namafile[], Queue *songQue, Stack *riwayatlagu) {
    STARTKALIMATFILE(namafile) ;
    Kalimat NamaPenyanyi;
    Kalimat NamaAlbum;
    Kalimat NamaLagu;

    int jumlah = Line.TabLine[0] - 48;
    printf("\nJumlah Penyanyi: %d\n", jumlah);


    for (int i = 0; i < jumlah; i++){
    ADVSATUKATA();
    int album = Line.TabLine[0] - 48;
    
    ADVKALIMAT();
    
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

      AddAlbum(LP, Line);
      NamaAlbum = NamaAlbumNow(LP);

      printf("Nama Album: %s\n", NamaAlbum.TabLine);
      printf("\n");
      for (int k = 0; k < lagu; k++)
      {
        ADVKALIMAT();

        AddLagu(LP, Line);
        NamaLagu = NamaLaguNow(LP);

        printf("Nama Lagu %d: %s\n", k+1, NamaLagu.TabLine);
    
      }
    }

  }
  ADVKALIMAT() ;
  int jumlahqs = Line.TabLine[0] - 48 ; //banyak lagu ke dalam queue
  printf("\nBanyak record lagu : %d\n", jumlahqs) ;

  for (int i = 0 ; i <jumlahqs ; i++) {
    ADVRecord() ;
    Kalimat NamaPenyanyi = Line ;
    printf("Penyanyi lagu %d : %s\n", i+1, LineToString(Line)) ;
    ADVRecord() ;
    Kalimat NamaAlbum = Line ;
    printf("Nama album %d : %s\n", i+1, LineToString(Line)) ;
    ADVRecord() ;
    printf("Nama lagu %d : %s\n", i+1, LineToString(Line)) ;
    Kalimat NamaLagu = Line ;

    SongDetails save ;
    save.artistName = NamaPenyanyi;
    save.albumName = NamaAlbum;
    save.songName = NamaLagu ;
    enqueue(songQue, save) ;
  }

  ADVKALIMAT() ;
  int jumlahriwayat = Line.TabLine[0] - 48 ;
  printf("\nBanyak jumlah record riwayat : %d\n", jumlahriwayat) ;

  Stack temp ; CreateStack(&temp) ;
  for (int i = 0 ; i< jumlahriwayat; i++) {
    ADVRecord() ;
    Kalimat NamaPenyanyi ; Kalimat NamaAlbum ; 
    SongDetails riwayat ; 
    riwayat.artistName = Line ;
    printf("Penanyi lagu ke-%d : %s\n",i+1, LineToString(Line)) ;
    ADVRecord() ;
    riwayat.albumName = Line ;
    printf("Nama album %d : %s\n",i+1, LineToString(Line)) ;
    ADVRecord() ;
    riwayat.songName = Line ;
    printf("Nama lagu %d : %s\n",i+1, LineToString(Line)) ;
    // disini kurang ngepush ke stack riwayat lagu 
    push(&temp, riwayat) ;
  }
  {
    for (int i = 0 ; i < jumlahriwayat; i++) {
      SongDetails baru ;
      pop(&temp, &baru ) ;
      push(riwayatlagu, baru) ;
    }
  }

  ADVKALIMAT() ;
  int jumlahpl = Line.TabLine[0] - 48 ;
  printf("\njumlah record playlist : %d\n", jumlahpl) ;

  for (int i  = 0 ; i<jumlahpl ; i++) {
    ADVSATUKATA() ;
    int jumlahlagu = Line.TabLine[0] - 48 ;
    ADVKALIMAT() ;
    // kurang fungsi masukin nama playlistnya 
    printf("Nama playlist ke-%d : %s\n", i+1, LineToString(Line) );

    for (int j = 0 ; j<jumlahlagu ; j++) {
        SongDetails infopl ;
        ADVRecord() ;
        infopl.artistName = Line ;
        printf("Penyanyi ke-%d : %s\n", j+1, LineToString(Line)) ;
        ADVRecord() ;
        infopl.albumName = Line;
        printf("Nama album %d : %s\n", j+1, LineToString(Line)) ;
        ADVRecord() ;
        infopl.songName = Line ;
        printf("Nama lagu %d : %s\n", j+1, LineToString(Line)) ;
    }
  }


}   
