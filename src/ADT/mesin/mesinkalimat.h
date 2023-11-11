<<<<<<< HEAD
#ifndef __MESIN_KALIMAT_H__
#define __MESIN_KALIMAT_H__

#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"

#define NMaks 400
#define NEWLINE '\n'
#define MARK2 '\0'

typedef struct {
  char TabLine[NMaks+1];
  int Length;
} Kalimat;

/* State Mesin Kalimat */
extern boolean EndKalimat;
extern Kalimat Line;
extern Kalimat Input; /* Untuk mengecek input(command)*/

void IgnoreSemiColon();
/*mengabaikan satu atau beberapa ";"
I.S. : CC sembarang
F.S. : CC != ";" atau CC = MARK*/
void IgnoreNewline();
/*mengabaikan satu atau beberapa "\n"
I.S. : CC sembarang
F.S. : CC != "\n" atau CC = MARK*/
void Ignoreblanks();
/*mengabaikan satu atau beberapa BLANK
I.S. : CC sembarang
F.S. : CC != BLANK atau CC = MARK*/

void SalinKalimat();
/*mengosongkan kalimat dan mengisi kalimat yang baru
I.S. : Kalimat sembarang, bisa kosong.
F.S. : Kalimat berisi kalimat yang baru, CC = MARK/NEWLINE/EOF */
void SalinSatuKata();
/*mengosongkan kalimat dan mengisi kalimat dengan satu kata
I.S. : Kalimat sembarang, bisa kosong.
F.S. : Kalimat berisi satu kata yang baru, CC = BLANK/MARK */
void SalinRecordLoad() ;
/*mengosongkan kalimat dan mengisi kalimat yang baru
I.S. : Kalimat sembarang, bisa kosong
F.S. : Kalimat berisi 1 line command, CC = ";"/NEWLINE*/
void SalinInput() ;
/*mengosongkan Input lalu membaca dan menyalin pita karakter
I.S. : Input sembarang
F.S. : Input berisi kalimat/kata, CC = NEWLINE/MARK/EOF*/

void STARTKALIMATFILE(char NamaFile[]);
/*membaca file lalu manyalin kalimat pertama
I.S. : pita sembarang, Kalimat sembarang
F.S. : pita terdefinisi, Kalimat berisi kalimat pertama*/
void StartInput () ;
/*meminta input pita karakter lalu menyalin pita kedalam kalimat hingga NEWLINE/MARK/EOF
I.S. : Kalimat sembarang
F.S. : Kalimat berisi yang di input hingga menemukan NEWLINE/MARK/EOF*/
boolean isInputEqual(Kalimat Input, char *kata);
void ADVKALIMAT();
/*melanjutkan ke kalimat selanjutnya*/
void ADVSATUKATA();
/*melanjutkan ke kata selanjutnya*/
void ADVRecord() ;
/*melanjutkan ke command selanjutnya*/
void ADVCommand() ;
/*???*/

void copyKalimat (Kalimat k1, Kalimat *k2);
/*menyalin isi kalimat k1 ke k2
I.S. : k1 dan k2 terdefinisi, k2 sembarang.
F.S. : k2 berisi kalimat k1*/

boolean isKalimatEqual(Kalimat K1, Kalimat K2);
/*mengembalikan true jika K1 = K2
I.S. : K1 dan K2 terdefinisi

boolean isInputEqual (Kalimat Input, char * kata) ;
/*mengembalikan true jika Input = kata (Kalimat == array of char)
I.S. : Input dan kata terdefinisi*/


void ResetKalimat();
/*mengosongkan Kalimat
I.S. : input sembarang
F.S. : line.Length = 0, setiap Line.Tabline[idx] = '\0'*/
void ResetIn();
/*mengosongkan input.
I.S : input sembarang
F.S : Input.Length = 0 dan setiap Input.Tabline[idx] = '\0'*/

int length(char * S) ;
/*mengembalikan panjang array of char
I.S. : S terdefinisi*/


#endif
=======
#ifndef __MESIN_KALIMAT_H__
#define __MESIN_KALIMAT_H__

#include "./boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"

#define NMaks 400
#define NEWLINE '\n'
#define MARK2 '\0'

typedef struct {
  char TabLine[NMaks+1];
  int Length;
} Kalimat;

/* State Mesin Kalimat */
extern boolean EndKalimat;
extern Kalimat Line;
extern Kalimat Input; /* Untuk mengecek input(command)*/

void IgnoreSemiColon();
/*mengabaikan satu atau beberapa ";"
I.S. : CC sembarang
F.S. : CC != ";" atau CC = MARK*/
void IgnoreNewline();
/*mengabaikan satu atau beberapa "\n"
I.S. : CC sembarang
F.S. : CC != "\n" atau CC = MARK*/
void Ignoreblanks();
/*mengabaikan satu atau beberapa BLANK
I.S. : CC sembarang
F.S. : CC != BLANK atau CC = MARK*/

void SalinKalimat();
/*mengosongkan kalimat dan mengisi kalimat yang baru
I.S. : Kalimat sembarang, bisa kosong.
F.S. : Kalimat berisi kalimat yang baru, CC = MARK/NEWLINE/EOF */
void SalinSatuKata();
/*mengosongkan kalimat dan mengisi kalimat dengan satu kata
I.S. : Kalimat sembarang, bisa kosong.
F.S. : Kalimat berisi satu kata yang baru, CC = BLANK/MARK */
void SalinRecordLoad() ;
/*mengosongkan kalimat dan mengisi kalimat yang baru
I.S. : Kalimat sembarang, bisa kosong
F.S. : Kalimat berisi 1 line command, CC = ";"/NEWLINE*/
void SalinInput() ;
/*mengosongkan Input lalu membaca dan menyalin pita karakter
I.S. : Input sembarang
F.S. : Input berisi kalimat/kata, CC = NEWLINE/MARK/EOF*/

void STARTKALIMATFILE(char NamaFile[]);
/*membaca file lalu manyalin kalimat pertama
I.S. : pita sembarang, Kalimat sembarang
F.S. : pita terdefinisi, Kalimat berisi kalimat pertama*/
void StartInput () ;
/*meminta input pita karakter lalu menyalin pita kedalam kalimat hingga NEWLINE/MARK/EOF
I.S. : Kalimat sembarang
F.S. : Kalimat berisi yang di input hingga menemukan NEWLINE/MARK/EOF*/

void ADVKALIMAT();
/*melanjutkan ke kalimat selanjutnya*/
void ADVSATUKATA();
/*melanjutkan ke kata selanjutnya*/
void ADVRecord() ;
/*melanjutkan ke command selanjutnya*/
void ADVCommand() ;
/*???*/

void copyKalimat (Kalimat k1, Kalimat *k2);
/*menyalin isi kalimat k1 ke k2
I.S. : k1 dan k2 terdefinisi, k2 sembarang.
F.S. : k2 berisi kalimat k1*/

boolean isKalimatEqual(Kalimat K1, Kalimat K2);
/*mengembalikan true jika K1 = K2
I.S. : K1 dan K2 terdefinisi

boolean isInputEqual (Kalimat Input, char * kata) ;
/*mengembalikan true jika Input = kata (Kalimat == array of char)
I.S. : Input dan kata terdefinisi*/


void ResetKalimat();
/*mengosongkan Kalimat
I.S. : input sembarang
F.S. : line.Length = 0, setiap Line.Tabline[idx] = '\0'*/
void ResetIn();
/*mengosongkan input.
I.S : input sembarang
F.S : Input.Length = 0 dan setiap Input.Tabline[idx] = '\0'*/

int length(char * S) ;
/*mengembalikan panjang array of char
I.S. : S terdefinisi*/


#endif
>>>>>>> refs/remotes/origin/main
