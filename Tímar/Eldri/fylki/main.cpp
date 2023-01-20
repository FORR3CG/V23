#include <iostream>

using namespace std;

void prentaFylki(int fylkid[], int staerd) {
    cout << "stærð í falli: " << sizeof(fylkid) << endl;
    for(int i = 0; i < staerd; i++) {
        cout << fylkid[i] << endl;
    }
}

void fall() {
    fall();
}


int main() {
    int fylki[] = {1,2,3,4,5};
    prentaFylki(fylki, 5);
    cout << "Fylkið: " << fylki << endl;
    cout << "1. stakið: " << &fylki[0] << endl;
    int annadFylki[5] = {0};
    annadFylki[20] = 99;
    cout << "af10: " << annadFylki[20] << endl;
    int staerd = sizeof(fylki)/sizeof(fylki[0]);
    cout << "Fjöldi: " << staerd << endl;
    for(int i = 0; i < staerd; i++)
        cout << fylki[i] << ":" << &fylki[i] << endl;

    return 0;
}