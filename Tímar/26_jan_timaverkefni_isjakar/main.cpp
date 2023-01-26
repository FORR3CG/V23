// main.cpp

#include <iostream>
#include "Isjakar.h"

using namespace std;

int main() {
    Isjakar listi;
    listi.skraIsjaka(10,200,300);
    Isjaki i1 = Isjaki(20, 30, 40);
    Isjaki i2 = Isjaki(20, 30, 40);
    if(i1 == i2) cout << "eins\n";
    return 0;
}