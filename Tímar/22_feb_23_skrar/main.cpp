#include <iostream>
#include <string>

#include <fstream> // filestream

using namespace std;

int main() {
    int j = 10, k = 20;
    string texti = "abc";

    ofstream skrifa("gogn.txt", fstream::app);
    if(!skrifa) {
        cout << "Gat ekki opnað skrá!!\n";
    } else {
        skrifa << texti << " " << j << " " << k << endl;
    }
    skrifa.close();

    ifstream lesa("gogn.txt");

    if(!lesa) {
        cout << "Gat ekki opnað skrá!!\n";
    } else {
        while(lesa >> texti >> j >> k) {
            cout << texti << "-" << j << "-" << k << endl;
        }
    }
    lesa.close();
    return 0;
}