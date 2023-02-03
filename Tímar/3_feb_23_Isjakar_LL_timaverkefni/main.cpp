#include <iostream>
#include <string>

using namespace std;

#include "IsjakarRadad.h"

int main() {
    IsjakarRadad ir;
    

    Isjaki eyddur = ir.eydaIsjaka(23);
    if(eyddur.getId() == -1) {
        cout << "Fann ekki ísjaka með id 23!!\n";
    }

}