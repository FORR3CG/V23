#include <iostream>
#include <string>

using namespace std;

class Dyr {
    protected:
        int aldur;
        string nafn;
    public:
        Dyr() {
            this->aldur = -1;
            this->nafn = "";
        }
        Dyr(int aldur, string nafn) {
            this->aldur = aldur;
            this->nafn = nafn;
        }
        int getAldur() { return this->aldur; }
        void setAldur(int aldur) { this->aldur = aldur;} 
        string getNafn() { return this->nafn; }
        void setNafn(string nafn) { this->nafn = nafn; }
        string toString() { 
            return "aldur: " + to_string(this->aldur) + ", nafn: " + this->nafn;
        }
        void prenta() {
            cout << "Dýr, nafn: " << this->nafn << ", aldur: " 
                 << this->aldur << endl;
        }
        ~Dyr() { }
};

class Hundur : public Dyr { // aðgangsstýring segir til um aðgengi public
    private:                // falla og breyta í klasanum sem erfir
        int einkunn;
    public:
        Hundur() {
            this->einkunn = -1;
        }
        Hundur(int einkunn, int aldur, string nafn) : Dyr(aldur, nafn) {
            this->einkunn = einkunn;
        }
        int getEinkunn() { return this->einkunn; }
        void setEinkunn(int einkunn) { this->einkunn = einkunn; }
        void prenta() {
            cout << "Hundur, nafn: " << this->nafn << ", aldur: " << this->aldur
                 << ", einkunn: " << this->einkunn << endl;
        }
};

class Kottur : public Dyr {
    private:
        string eigandi;
    public:
        Kottur() { this->eigandi = ""; }
        Kottur(string eigandi, int aldur, string nafn) : Dyr(aldur, nafn) {
            this->eigandi = eigandi;
        }
        string getEigandi() { return this->eigandi; }
        void setEigandi(string eigandi) { this->eigandi = eigandi; }
        void prenta() {
            cout << "Köttur, nafn: " << this->nafn << ", aldur: " << this->aldur
                 << ", eigandi: " << this->eigandi << endl;
        }
};

int main() {
    Hundur snati;
    snati.prenta();
    Kottur grettir;
    grettir.prenta();
    Dyr d;
    d.prenta();
    return 0;
}