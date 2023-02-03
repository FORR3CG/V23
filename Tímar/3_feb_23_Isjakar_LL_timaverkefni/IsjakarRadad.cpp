#include "IsjakarRadad.h"

IsjakarRadad::IsjakarRadad() {
    this->head = nullptr;
}

void IsjakarRadad::skraIsjaka(Isjaki k) {
    IsjakaNode* ny_gogn = new IsjakaNode(k);
    if(!this->head) { // listinn er tómur
        this->head = ny_gogn;
    } else { // listinn er ekki tómur
        if(this->head->jaki > k) { // nýi jakinn á að koma fremst
            ny_gogn->next = this->head;
            this->head = ny_gogn;
        } else { // nýi jakinn að að koma einhversstaðar annarsstaðar
            IsjakaNode* current = this->head;
            IsjakaNode* prev = this->head;
            while(current && current->jaki <= k) {
                prev = current;
                current = current->next;
            }
            if(current) { // nýi jakinn á að ekki að koma aftast
                ny_gogn->next = current;
                prev->next = ny_gogn;
            } else { // nýi jakinn á að koma afstast
                prev->next = ny_gogn;
            }
        }
    }
}

void IsjakarRadad::skraIsjaka(int id, int staerd, float fjarlaegd) {
    this->skraIsjaka(Isjaki(id, staerd, fjarlaegd));
}

bool IsjakarRadad::eydaIsjaka(int id) {
    
}

void IsjakarRadad::breytaFjarlaegd(int id, float fjarlaegd) {

}

void IsjakarRadad::prentaEinnIsjaka(int id) {

}

void IsjakarRadad::prentaAllt() {

}

IsjakarRadad::~IsjakarRadad() {

}
