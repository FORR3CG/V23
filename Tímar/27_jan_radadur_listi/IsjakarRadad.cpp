// IsjakarRadad.cpp
#include "IsjakarRadad.h"

IsjakarRadad::IsjakarRadad() {
    this->fjoldi = 0;
    this->staerd = 2;
    this->listinn = new Isjaki[this->staerd];
}

IsjakarRadad::IsjakarRadad(IsjakarRadad& hinn) {
    this->fjoldi = hinn.fjoldi;
    this->staerd = hinn.staerd;
    this->listinn = new Isjaki[this->staerd];
    for(int i = 0; i < this->fjoldi; i++) {
        this->listinn[i] = hinn.listinn[i];
    }
    // return *this;
}

void IsjakarRadad::skraIsjaka(Isjaki jaki) {
    if(this->fjoldi < this->staerd) { // það er laust pláss
        for(int i = 0; i < this->staerd; i++) {
            if(this->listinn[i].getId() == -1) { // jakinn sem við setjum inn er stærri en allir hinir
                this->listinn[i] = jaki;
                this->fjoldi++;
                return;
            } else if(jaki < this->listinn[i]) {
                for(int j = this->fjoldi; j > i; j--) {
                    this->listinn[j] = this->listinn[j - 1];
                }
                this->listinn[i] = jaki;
                this->fjoldi++;
                return;
            }
        }
    } else { // það þarf að stækka 
        Isjaki* staerri_listi = new Isjaki[this->staerd * 2];
        for(int i = 0; i < this->staerd; i++) {
            staerri_listi[i] = this->listinn[i];
        }
        delete [] this->listinn;
        this->listinn = staerri_listi;
        this->staerd *= 2;
        this->skraIsjaka(jaki);
    }
}

void IsjakarRadad::skraIsjaka(int id, int staerd, float fjarlaegd) {

}

void IsjakarRadad::eydaIsjaka(int id) {

}

void IsjakarRadad::prentaAllt() {

}

IsjakarRadad& IsjakarRadad::operator=(IsjakarRadad& hinn) {

}

IsjakarRadad::~IsjakarRadad() {

}
