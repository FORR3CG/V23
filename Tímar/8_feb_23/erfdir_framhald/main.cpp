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
            this->staerd = 2;
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
                Dyr** temp = new Dyr*[this->staerd + 2]();
                for(int i = 0; i < this->staerd; i++) {
                    temp[i] = this->listinn[i];
                }
                delete [] this->listinn;
                this->listinn = temp;
                this->listinn[this->staerd] = nytt_dyr;
                this->staerd += 2;
            }
        }
        ~Dyragardur() {
            for(int i = 0; i < this->staerd; i++) {
                delete this->listinn[i];
            }
            delete [] this->listinn;
        }
};


int main() {
    Dyragardur dg;
    Dyr** f2 = new Dyr*[5]();
    for(int i = 0; i < 5; i++) {
        cout << f2[i] << endl;
    }
    
    //Dyr fylkid[3];
    Dyr** fylkid = new Dyr*[3];
    fylkid[0] = new Hundur(); //snati;
    fylkid[1] = new Kottur();
    fylkid[2] = new Dyr();
    
    for(int i = 0; i < 3; i++) {
        fylkid[i]->prenta();
    }

    for(int i = 0; i < 3; i++) {
        delete fylkid[i];
    }
    delete [] fylkid;

    return 0;
}