#include <iostream>
#include <string>

#include "Bill.h"

using namespace std;

int main() {
    Bill b;
    b.prenta();
    Bill toyota = Bill(11, "Toyota", "Rauður");
    Bill bmw = Bill(12, "BMW", "Grænn");
    cout << toyota.toString() << endl;
    toyota.setLitur("Blár");
    toyota.prenta();

    //if(toyota.erEins(bmw))

    if(toyota > bmw) {
        cout << "Toyotan er stærri en BMW-inn" << endl;
    } else {
        cout << "Toyotan er minni eða sama sem en BMW-inn" << endl;

    }

    if(toyota == bmw) {
        cout << "Toyotan er eins og BMW-inn" << endl;
    } else {
        cout << "Toyotan er ekki eins og BMW-inn" << endl;
    }

    cout << bmw << " " << toyota << " Geir " << endl;

    return 0;
}

