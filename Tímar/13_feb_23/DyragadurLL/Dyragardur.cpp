#include "Dyragardur.h"

Dyragardur::Dyragardur() {
    this->head = nullptr;
}

void Dyragardur::skraDyr(Dyr* dyrid) { // push
    DyraNode* nytt_dyr = new DyraNode(dyrid);
    if(!this->head) {
        this->head = nytt_dyr;
    } else {
        nytt_dyr->next = this->head;
        this->head = nytt_dyr;
    }
}

void Dyragardur::skodaNaesta() { // peek
    if(this->head) {
        this->head->dyrid->prenta();
    }
}

void Dyragardur::takaNaesta() { // pop
    if(this->head) {
        DyraNode* new_head = this->head->next;
        // delete this->head->dyrid; // gerum frekar destructor í Node
        delete this->head;
        this->head = new_head;
    }
}

void Dyragardur::skraHund(int aldur, std::string nafn, int einkunn) {
    this->skraDyr(new Hundur(einkunn, aldur, nafn));
}

void Dyragardur::skraKott(int aldur, std::string nafn, std::string eigandi) {
    this->skraDyr(new Kottur(eigandi, aldur, nafn));
}

bool Dyragardur::eydaDyri(std::string nafn) {

}

void Dyragardur::skodaDyr(std::string nafn) {

}

void Dyragardur::prentaAllt() {
    DyraNode* current = this->head;
    while(current) {
        current->dyrid->prenta();
        current = current->next;
    }
}

void Dyragardur::prentaDyraTegund(std::string tegund) {
    DyraNode* current = this->head;
    while(current) {
        if(current->dyrid->getType() == tegund) {
            current->dyrid->prenta();
        }
        current = current->next;
    }
}

void Dyragardur::prentaHunda() {
    this->prentaDyraTegund("hundur");
}

void Dyragardur::prentaKetti() {
    this->prentaDyraTegund("köttur");
}

Dyragardur::~Dyragardur() {
    while(this->head) {
        DyraNode* new_head = this->head->next;
        delete this->head;
        this->head = new_head;
    }
}
