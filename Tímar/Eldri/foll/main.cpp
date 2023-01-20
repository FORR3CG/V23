#include <iostream>
#include <string>

using namespace std;

void prentaNafn(string);
int leggjaSaman(int, int);
int leggjaSaman(int, int, int);
float leggjaSaman(float, float);
double leggjaSaman(double, double);

int haekkaUmEinn(int a) {
    return a + 1;
}

void haekkaUmEinn(int& a, int& b) {
    a++;
    b++;
}

int main() {
    int k = 10;
    cout << &k << endl;
    cout << haekkaUmEinn(k) << endl;
    cout << k << endl;
    int a = 10, b = 20;
    haekkaUmEinn(a, b);
    cout << "a: " << a << ", b: " << b << endl; 
    return 0;
}

void prentaNafn(string nafn) {
    if(nafn == "Geir") 
        return;
    cout << "Halló " << nafn << endl;

/*     if(nafn != "Geir")
        cout << "Halló " << nafn << endl; */
}

int leggjaSaman(int a, int b) {
    return a + b;
}

int leggjaSaman(int a, int b, int c) {
    return a + b + c;
}

float leggjaSaman(float a, float b) {
    return a + b;
}

double leggjaSaman(double a, double b) {
    return a + b;
}
