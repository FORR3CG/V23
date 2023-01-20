#include <iostream>
#include <string>

using namespace std;

struct Gogn2 {
    // public:
};

class Gogn {
    // private:
    int tala;
    string texti;

    public:
    Gogn() {
        this->tala = 0;
        this->texti = "";
    }

    Gogn(int tala, string texti) {
        this->tala = tala;
        this->texti = texti;
    }

    void setTala(int tala) {
        this->tala = tala;
    }

    int getTala() {
        return this->tala;
    }

    void setTexti(string texti) {
        this->texti = texti;
    }

    string getTexti() {
        return this->texti;
    }

    void prenta() {
        cout << "Talan: " << this->tala << ", textinn: " << this->texti << endl;
    }
};

int main() {
    Gogn g;
    Gogn f(10,"abc");
    Gogn h = Gogn(20,"xyz");
    // g.tala = 10;
    g.setTala(10);
    // g.texti = "ABC";
    g.setTexti("ABC");
    g.prenta();
    f.prenta();
    h.prenta();

    return 0;
}