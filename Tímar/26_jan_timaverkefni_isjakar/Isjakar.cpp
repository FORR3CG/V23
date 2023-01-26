// Isjakar.cpp
#include "Isjakar.h"

Isjakar::Isjakar() {
    this->staerd = 5;
    this->listinn = new Isjaki[this->staerd];
}

Isjakar::Isjakar(Isjakar& hinn) {
    this->staerd = hinn.staerd;
    this->listinn = new Isjaki[this->staerd];
    for(int i = 0; i < this->staerd; i++) {
        this->listinn[i] = hinn.listinn[i];
    }
}

int Isjakar::finnaLaustPlass() {
    for(int i = 0; i < this->staerd; i++) {
        if(this->listinn[i].getId() == -1) {
            return i;
        }
    }
    return -1;
}

void Isjakar::skraIsjaka(Isjaki k) {
    int idx = finnaLaustPlass();
    if(idx != -1) {
        this->listinn[idx] = k;
    } else {
        Isjaki* temp = new Isjaki[this->staerd + 10];
        for(int i = 0; i < this->staerd; i++) {
            temp[i] = this->listinn[i];
        }
        delete [] this->listinn;
        this->listinn = temp;
        this->listinn[this->staerd] = k;
        this->staerd += 10;
    }
}

void Isjakar::skraIsjaka(int id, int staerd, float fjarlaegd) {
    this->skraIsjaka(Isjaki(id, staerd, fjarlaegd));
}

void Isjakar::eydaIsjaka(int id) {
    for(int i = 0; i < this->staerd; i++) {
        if(this->listinn[i].getId() == id) {
            this->listinn[i] = Isjaki();
            // this->listinn[i].setId(-1);
        }
    }
}

void Isjakar::breytaFjarlaegd(int id, int fjarlaegd) {
    for(int i = 0; i < this->staerd; i++) {
        if(this->listinn[i].getId() == id) {
            this->listinn[i].setFjarlaegd(fjarlaegd);
        }
    }
}

void Isjakar::prentaEinnIsjaka(int id) {
    for(int i = 0; i < this->staerd; i++) {
        if(this->listinn[i].getId() == id) {
            this->listinn[i].prenta();
        }
    }
}

void Isjakar::prentaAllt() {
    for(int i = 0; i < this->staerd; i++) {
        if(this->listinn[i].getId() != -1)
            this->listinn[i].prenta();
    }
}

Isjakar& Isjakar::operator=(Isjakar& hinn) {
    this->staerd = hinn.staerd;
    this->listinn = new Isjaki[this->staerd];
    for(int i = 0; i < this->staerd; i++) {
        this->listinn[i] = hinn.listinn[i];
    }
    return *this;
}

Isjakar::~Isjakar() {
    delete [] this->listinn;
}
