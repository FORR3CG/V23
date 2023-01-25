#include "Tolvur.h"

Tolvur::Tolvur() {
    this->staerd = 5;
    this->tolvurnar = new Tolva[this->staerd];
}

Tolvur::Tolvur(int staerd) {
    this->staerd = staerd;
    this->tolvurnar = new Tolva[this->staerd];
}

int Tolvur::finnaLaustPlass() {
    for(int i = 0; this->staerd; i++) {
        if(this->tolvurnar[i].getId() == -1) {
            return i;
        }
    }
    return -1;
}

void Tolvur::skraTolvu(Tolva t) {
    int idx = this->finnaLaustPlass();
    if(idx != -1) {
        this->tolvurnar[idx] = t;
    } else {
        Tolva* temp = new Tolva[this->staerd + 5];
        for(int i = 0; i < this->staerd; i++) {
            temp[i] = this->tolvurnar[i];
        }
        delete [] this->tolvurnar;
        this->tolvurnar = temp;
        this->tolvurnar[this->staerd] = t;
        this->staerd += 5;
    }
}

void Tolvur::skraTolvu(int id, std::string cpu, int ram, int hdd) {
    Tolva ny_tolva(id, cpu, ram, hdd);
    this->skraTolvu(ny_tolva);
    // this->skraTolvu(Tolva(id, cpu, ram, hdd));
}

bool Tolvur::eydaTolvu(int id) {
    for(int i = 0; i < this->staerd; i++) {
        if(this->tolvurnar[i].getId() == id) {
            this->tolvurnar[i] = Tolva();
            return true;
        }
    }
    return false;
}

void Tolvur::prentaTolvu(int id) {
    for(int i = 0; i < this->staerd; i++) {
        if(this->tolvurnar[i].getId() == id) {
            this->tolvurnar[i].prenta();
        }
    }    
}

void Tolvur::prentaAllt() {
    for(int i = 0; i < this->staerd; i++) {
        if(this->tolvurnar[i].getId() != -1)
            this->tolvurnar[i].prenta();
    }
}

Tolvur::~Tolvur() {
    delete [] this->tolvurnar;
}

Tolvur::Tolvur(Tolvur& hinn) {
    this->staerd = hinn.staerd;
    this->tolvurnar = new Tolva[this->staerd];
    for(int i = 0; i < this->staerd; i++) {
        this->tolvurnar[i] = hinn.tolvurnar[i];
    }
}

Tolvur& Tolvur::operator=(Tolvur& hinn) {
    this->staerd = hinn.staerd;
    this->tolvurnar = new Tolva[this->staerd];
    for(int i = 0; i < this->staerd; i++) {
        this->tolvurnar[i] = hinn.tolvurnar[i];
    }
    return *this;
}
