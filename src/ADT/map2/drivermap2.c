#include <stdio.h>
#include "map2.h"

int main() {
    ListPenyanyi LP;
    CreateListPenyanyi(&LP);

    // Add penyanyi
    AddPenyanyi(&LP, StringtoLine("BLACKPINK"));
    AddPenyanyi(&LP, StringtoLine("New Jeans"));

    // Add albums untuk BLACKPINK
    AddAlbum(&LP, StringtoLine("BORN PINK"));
    AddAlbum(&LP, StringtoLine("SQUARE ONE"));

    // Add lagu untuk album "SQUARE ONE"
    AddLagu(&LP, StringtoLine("WHISTLE"));
    AddLagu(&LP, StringtoLine("BOOMBAYAH"));

    // Add lagu untuk album "BORN PINK"
    AddLagu(&LP, StringtoLine("Pink Venom"));
    AddLagu(&LP, StringtoLine("Shut Down"));

    // Print informasi
    printf("Current singer: %s\n", NamaPenyanyiNow(&LP));
    printf("Current album: %s\n", NamaAlbumNow(&LP));
    printf("Current song: %s\n", NamaLaguNow(&LP));

    // Apakah penyanyi adalah member
    if (IsMemberLP(LP, StringtoLine("Rich Brian"))) {
        printf("Rich Brian is a member.\n");
    } else {
        printf("Rich Brian is not a member.\n");
    }

    // list albums dari penyanyi
    Kalimat singer = StringtoLine("BLACKPINK");
    ListAlbum albums = ValueLP(LP, singer);

    // Print list album dan lagu dari penyanyi
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
