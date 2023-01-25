#include <iostream>
#include <string>

#include "Tolva.h"
#include "Tolvur.h"

using namespace std;

int main() {
    Tolvur t;
    t.skraTolvu(1, "Intel", 16, 500);
    t.skraTolvu(2, "Intel", 16, 500);
    t.skraTolvu(3, "Intel", 16, 500);

    Tolvur t2 = t;
    Tolvur t3;
    t2.skraTolvu(99, "AMD", 16, 1000);
    t3 = t2 = t;
    int a = 10, b = 20, c = 30;
    a = b = c;
    cout << "T listinn\n";
    t.prentaAllt();
    cout << "T2 listinn\n";
    t2.prentaAllt();

    return 0;
}