#include <iostream>
#include <string>
#include <cstdlib> // <stdlib.h> fyrir mac
#include <ctime>

#include "Dyragardur.h"

using namespace std;

int main() {
    srand(time(0));
    string nofn[] = {"Snati", "Grettir", "Fluffy", "Kekkur", "Pjakkur", "Lassý", "Vaskur", "Lotta", "Lína", "Leó", "Brandur"};
    int nafnafjoldi = 11;
    Dyragardur dg;
    for(int i = 0; i < 5; i++) {
        dg.skraHund(rand() % 20, nofn[rand() % 11], rand() % 10);
        dg.skraKott(rand() % 20, nofn[rand() % 11], "Jón");
    }
    dg.prentaAllt();
    cout << "------------------------------------\n";
    dg.prentaHunda();
    cout << "------------------------------------\n";
    dg.prentaKetti();
    return 0;
}