#include <iostream>
#include <string>
#include <cstdlib> // <stdlib.h>
#include <ctime>

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
        virtual void prenta() {
            cout << "Dýr, nafn: " << this->nafn << ", aldur: " 
                 << this->aldur << endl;
        }
        virtual ~Dyr() {}
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

class Dyragardur {
    private:
        Dyr** listinn;
        int staerd;
        int finnaLausanIndex() {
            for(int i = 0; i < this->staerd; i++) {
                if(this->listinn[i] == nullptr) {
                    return i;
                }
            }
            return -1;
        }
    public:
        Dyragardur() {
            this->staerd = 100010;
            this->listinn = new Dyr*[this->staerd]();
        }
        void skraHund(string nafn, int aldur, int einkunn) {
            // hverju skilar þetta: new Hundur(einkunn, aldur, nafn)
            this->skraDyr(new Hundur(einkunn, aldur, nafn));
        }
        void skraKott(string nafn, int aldur, string eigandi) {
            this->skraDyr(new Kottur(eigandi, aldur, nafn));
        }
        void skraDyr(string nafn, int aldur) {
            this->skraDyr(new Dyr(aldur, nafn));
        }
        void skraDyr(Dyr* nytt_dyr) {
            int idx = finnaLausanIndex();
            if(idx != -1) {
                this->listinn[idx] = nytt_dyr;
            } else {
                Dyr** temp = new Dyr*[this->staerd * 2]();
                for(int i = 0; i < this->staerd; i++) {
                    temp[i] = this->listinn[i];
                }
                delete [] this->listinn;
                this->listinn = temp;
                this->listinn[this->staerd] = nytt_dyr;
                this->staerd *= 2;
            }
        }

        void eydaDyri(string nafn) {
            for(int i = 0; i < this->staerd; i++) {
                if(this->listinn[i] && this->listinn[i]->getNafn() == nafn) {
                    delete this->listinn[i];
                    this->listinn[i] = nullptr;
                    return;
                }
            }
        }

        void breytaAldri(string nafn, int nyr_aldur) {
            for(int i = 0; i < this->staerd; i++) {
                if(this->listinn[i] && this->listinn[i]->getNafn() == nafn) {
                    this->listinn[i]->setAldur(nyr_aldur);
                    return;
                }
            }
        }

        void prentaEittDyr(string nafn) {
            for(int i = 0; i < this->staerd; i++) {
                if(this->listinn[i] && this->listinn[i]->getNafn() == nafn) {
                    this->listinn[i]->prenta();
                    return;
                }
            }
        }

        void prentaAllt() {
            for(int i = 0; i < this->staerd; i++) {
                if(this->listinn[i]) {
                    this->listinn[i]->prenta();
                }
            }
        }

        ~Dyragardur() {
            for(int i = 0; i < this->staerd; i++) {
                if(this->listinn[i]) // if(this->listinn[i] != nullptr)
                    delete this->listinn[i];
            }
            delete [] this->listinn;
        }
};


int main() {
    srand(time(0));
    string nofn[] = {"Snati", "Grettir", "Fluffy", "Kekkur", "Pjakkur", "Lassý", "Vaskur", "Lotta", "Lína", "Leó", "Brandur"};
    int nafnafjoldi = 11;
    Dyragardur dg;
    dg.skraHund("Snati", 5, 5);
    for(int i = 0; i < 5000; i++) {
        dg.skraHund(nofn[rand() % nafnafjoldi], rand() % 15, rand() % 10);
        dg.skraKott(nofn[rand() % nafnafjoldi], rand() % 15, "Jón");
    }
    cout << "Búið!!\n";
    return 0;
}