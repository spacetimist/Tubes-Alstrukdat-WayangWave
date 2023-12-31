#include "load.h"

void LOADFILE(ListPenyanyi * LP, char namafile[], Queue *songQue, Stack *riwayatlagu, SongDetails *currentsong, DaftarPlaylist *daftar) {
    STARTKALIMATFILE(namafile) ;
    Kalimat NamaPenyanyi;
    Kalimat NamaAlbum;
    Kalimat NamaLagu;

    int jumlah = Line.TabLine[0] - 48;
 //   printf("\nJumlah Penyanyi: %d\n", jumlah);

    if (jumlah > 0 ) {
    printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n") ;
    for (int i = 0; i < jumlah; i++){
    ADVSATUKATA();
    int album = Line.TabLine[0] - 48;
    
    ADVKALIMAT();
    
    AddPenyanyi(LP, Line);
    NamaPenyanyi = NamaPenyanyiNow(LP);

 //   printf("\nNama Penyanyi ke-%d: %s\n", i+1, NamaPenyanyi.TabLine);
   // printf("\n");
   // printf("Jumlah Album: %d\n", album);
   // printf("\n");


    for (int j = 0; j < album; j++){
      ADVSATUKATA();
      int lagu = Line.TabLine[0] - 48;

      ADVKALIMAT();

      AddAlbum(LP, Line);
      NamaAlbum = NamaAlbumNow(LP);

     // printf("Nama Album: %s\n", NamaAlbum.TabLine);
     // printf("\n");
      for (int k = 0; k < lagu; k++)
      {
        ADVKALIMAT();

        AddLagu(LP, Line);
        NamaLagu = NamaLaguNow(LP);

       // printf("Nama Lagu %d: %s\n", k+1, NamaLagu.TabLine);
    
      }
    }

  }
  ADVKALIMAT() ;
  (*currentsong).artistName = Line;
  ADVRecord() ;
  (*currentsong).albumName = Line;
  ADVRecord() ;
  (*currentsong).songName = Line ;
 // printf("Current song : %s-%s-%s\n", LineToString((*currentsong).artistName), LineToString((*currentsong).albumName), LineToString((*currentsong).songName));

  ADVKALIMAT() ;
  int jumlahqs = Line.TabLine[0] - 48 ; //banyak lagu ke dalam queue
 // printf("\nBanyak record lagu : %d\n", jumlahqs) ;

  for (int i = 0 ; i <jumlahqs ; i++) {
    ADVRecord() ;
    Kalimat NamaPenyanyi = Line ;
  //  printf("Penyanyi lagu %d : %s\n", i+1, LineToString(Line)) ;
    ADVRecord() ;
   Kalimat NamaAlbum = Line ;
 //   printf("Nama album %d : %s\n", i+1, LineToString(Line)) ;
    ADVRecord() ;
   // printf("Nama lagu %d : %s\n", i+1, LineToString(Line)) ;
    Kalimat NamaLagu = Line ;

    SongDetails save ;
    save.artistName = NamaPenyanyi;
    save.albumName = NamaAlbum;
    save.songName = NamaLagu ;
    enqueue(songQue, save) ;
  }

  ADVKALIMAT() ;
  int jumlahriwayat = Line.TabLine[0] - 48 ;
 // printf("\nBanyak jumlah record riwayat : %d\n", jumlahriwayat) ;

  Stack temp ; CreateStack(&temp) ;
  for (int i = 0 ; i< jumlahriwayat; i++) {
    ADVRecord() ;
    Kalimat NamaPenyanyi ; Kalimat NamaAlbum ; 
    SongDetails riwayat ; 
    riwayat.artistName = Line ;
   // printf("Penanyi lagu ke-%d : %s\n",i+1, LineToString(Line)) ;
    ADVRecord() ;
    riwayat.albumName = Line ;
   // printf("Nama album %d : %s\n",i+1, LineToString(Line)) ;
    ADVRecord() ;
    riwayat.songName = Line ;
   // printf("Nama lagu %d : %s\n",i+1, LineToString(Line)) ;
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
 // printf("\njumlah record playlist : %d\n", jumlahpl) ;
  (*daftar).Neff = jumlahpl ;
  for (int i  = 0 ; i<jumlahpl ; i++) {
    ADVSATUKATA() ;
    int jumlahlagu = Line.TabLine[0] - 48 ;
    ADVKALIMAT() ;
    Kalimat namapl = Line;
    (*daftar).List[i].PlaylistName = namapl;
    // kurang fungsi masukin nama playlistnya 
 //   printf("Nama playlist ke-%d : %s\n", i+1, LineToString(Line) );
    for (int j = 0 ; j <jumlahlagu ; j++) {
      SongDetails temp ;
      ADVRecord() ;
      temp.artistName = Line ;
      ADVRecord() ;
      temp.albumName = Line ;
      ADVRecord() ;
      temp.songName = Line ;
      InsVLast(&(daftar->List[i]), temp) ;
    }
 //   PrintPlaylistSong((*daftar).List[i]) ;
  }
  } else {
    printf("Save file tidak ditemukan. WayangWave gagal dijalankan.\n") ;
  }

}   
