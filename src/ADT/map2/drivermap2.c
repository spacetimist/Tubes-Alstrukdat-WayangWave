#include <stdio.h>
#include "map2.h" // assuming map2.h contains the definitions of your data structures and functions

int main() {
    ListPenyanyi LP;
    CreateListPenyanyi(&LP);

    // Add singers
    AddPenyanyi(&LP, StringtoLine("BLACKPINK"));
    AddPenyanyi(&LP, StringtoLine("New Jeans"));

    // Add albums for BLACKPINK
    AddAlbum(&LP, StringtoLine("BORN PINK"));
    AddAlbum(&LP, StringtoLine("SQUARE ONE"));

    // Add songs for the album "SQUARE ONE"
    AddLagu(&LP, StringtoLine("WHISTLE"));
    AddLagu(&LP, StringtoLine("BOOMBAYAH"));

    // Add songs for the album "BORN PINK"
    AddLagu(&LP, StringtoLine("Pink Venom"));
    AddLagu(&LP, StringtoLine("Shut Down"));

    // Print information
    printf("Current singer: %s\n", NamaPenyanyiNow(&LP));
    printf("Current album: %s\n", NamaAlbumNow(&LP));
    printf("Current song: %s\n", NamaLaguNow(&LP));

    // Check if a singer is a member
    if (IsMemberLP(LP, StringtoLine("Rich Brian"))) {
        printf("Rich Brian is a member.\n");
    } else {
        printf("Rich Brian is not a member.\n");
    }

    // Get the list of albums for a singer
    Kalimat singer = StringtoLine("BLACKPINK");
    ListAlbum albums = ValueLP(LP, singer);

    // Print the list of albums and songs for the singer
    printf("Albums of %s:\n", singer);
    for (int i = 0; i < albums.NEff; i++) {
        printf("  Album: %s\n", albums.AlbumLagu[i].NamaAlbum);
        printf("    Songs:\n");
        for (int j = 0; j < albums.AlbumLagu[i].IsiLagu.Count; j++) {
            printf("      %s\n", albums.AlbumLagu[i].IsiLagu.JudulLagu[j]);
        }
    }

    return 0;
}
