#include <iostream>
#include <string>

#include "Bill.h"

using namespace std;

int main() {
    Bill b;
    b.prenta();
    Bill toyota = Bill(11, "Toyota", "Rauður");
    cout << toyota.toString() << endl;
    toyota.setLitur("Blár");
    toyota.prenta();

    return 0;
}

