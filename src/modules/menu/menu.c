#include <stdio.h>
#include "menu.h"
// #include "../modules/makanan/makanan.c"
// #include "../modules/peta/peta.c"
// #include "../modules/time/time.c"
// #include "../modules/boolean.h"
// #include "../modules/simulator/simulator.c"
// #include "../modules/string/string.c"

boolean isExit(Word w) {
    Word temp;
    createWord("EXIT", 4);
    return (isWordEqual(w, temp));
}

boolean isStart(Word w) {
    Word temp;
    createWord("START", 5);
    return (isWordEqual(w, temp));
}

boolean isBuy(Word w) {
    Word temp;
    createWord("BUY", 3);
    return (isWordEqual(w, temp));
}

boolean isChop(Word w) {
    Word temp;
    createWord("CHOP", 4);
    return (isWordEqual(w, temp));
}

boolean isFry(Word w) {
    Word temp;
    createWord("FRY", 3);
    return (isWordEqual(w, temp));
}

boolean isBoil(Word w) {
    Word temp;
    createWord("BOIL", 4);
    return (isWordEqual(w, temp));
}

boolean isMix(Word w) {
    Word temp;
    createWord("MIX", 3);
    return (isWordEqual(w, temp));
}

void Splash(String name) {
    printf("  ;)( ;\n");
    printf(" :----:     o8Oo./\n");
    printf("C|====| ._o8o8o8Oo_.\n");
    printf(" |    |  \\========/\n");
    printf(" `----'   `------'\n");
    printf("\n");
    printf("Welcome to BNMO, ");
    printString(name);
    printf("!\n");
}

void Initiate(Simulator *s, Peta *p, ListStatik *catalog) {
    char* petaFileName = "src/data/map.txt";
    char* makananFileName = "src/data/makanan.txt";
    String name;

    readPeta(petaFileName, p);
    printf("\n");

    printf("Enter your name: ");
    startString();
    assignString(currentString, &name);
    printf("\n");

    // while (currentString.Length == 0) {
    //     printf("Nama tidak boleh kosong!\n\n");
    //     printf("Enter your name: ");
    //     startString();
    //     assignString(currentString, &name);
    // }


    CreateSimulation(s, name, Absis(Locate(*p, 'S')), Ordinat(Locate(*p, 'S')));

    Splash(name);

    CreateListStatik(catalog);
    readMakanan(makananFileName, *p, catalog);
    printf("Catalog = ");
    printListMakanan(*catalog);
    printf("\n");
}

void inputCommand(Word *cmd) {
    printf("Enter command : ");
    STARTWORD();
    assignWord(currentWord, cmd);
    printf("\n");
}

