#include <iostream>

using namespace std;

int main() {
    int fylki[] = {1,2,3,4,5};
    double dfylki[] = {1.1, 2.2, 3.3};
    double* dfp = dfylki;
    int* pf = fylki;
    int* bp = pf;
    cout << *pf << endl;
    *pf = 99; // fylki[0] = 99;
    cout << *pf << endl;
    pf++;
    cout << *pf << endl;
    pf++;
    cout << *pf << endl;
    pf = bp;
    cout << "For lykkjan: " << endl;
    for(int i = 0; i < 5; i++) {
        cout << *pf << endl;
        pf++;
    }

    return 0;
}