#include <iostream>

using namespace std;

int main() {

    int fylki[][2][2] = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};

    int* pf = fylki[0][0];
    cout << pf << endl;
    cout << &fylki[0][0][0] << endl;
    cout << endl;
    cout << sizeof(fylki) << endl; // 32
    cout << sizeof(fylki[0]) << endl; // 16
    cout << sizeof(fylki[0][0]) << endl; // 8
    cout << sizeof(fylki[0][0][0]) << endl; // 4
    int fjoldiStaka = sizeof(fylki) / sizeof(fylki[0][0][0]);
    for(int i = 0; i < fjoldiStaka; i++) {
        cout << *pf << endl;
        pf++;
    }

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                cout << fylki[i][j][k] << ": " << &fylki[i][j][k] << endl;
            }
        }
    }


    /*int fjoldiStakaIYtraFylki = sizeof(fylki) / sizeof(fylki[0]);
    int fjoldiStakaIInnraFylki = sizeof(fylki[0]) / sizeof(fylki[0][0]);

    for(int i = 0; i < fjoldiStakaIYtraFylki; i++) {
        for(int j = 0; j < fjoldiStakaIInnraFylki; j++) {
            //fylki[i][j] = i + 20;
            cout << fylki[i][j] << endl;
        }
    }*/

    return 0;
}