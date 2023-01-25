#pragma once

#include <iostream>
#include <string>

#include "Tolva.h"

class Tolvur {
    private:
        Tolva* tolvurnar;
        int staerd;
        int finnaLaustPlass();
    public:
        Tolvur();
        Tolvur(int staerd);
        Tolvur(Tolvur& hinn); // copy constructor
        Tolvur& operator=(Tolvur& hinn); // assignment operator
        void skraTolvu(Tolva t);
        void skraTolvu(int id, std::string cpu, int ram, int hdd);
        bool eydaTolvu(int id);
        void prentaTolvu(int id);
        void prentaAllt();
        ~Tolvur();
};