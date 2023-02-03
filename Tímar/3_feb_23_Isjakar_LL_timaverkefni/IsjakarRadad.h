#pragma once

#include "Isjaki.h" // ?? þarf ekki
#include "IsjakaNode.h"

class IsjakarRadad {
    private:
        IsjakaNode* head;
    public:
        IsjakarRadad();
        void skraIsjaka(Isjaki k);
        void skraIsjaka(int id, int staerd, float fjarlaegd);
        bool eydaIsjaka(int id);
        void breytaFjarlaegd(int id, float fjarlaegd);
        void prentaEinnIsjaka(int id);
        void prentaAllt();
        ~IsjakarRadad();
};