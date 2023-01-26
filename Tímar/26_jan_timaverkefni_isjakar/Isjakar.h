// Isjakar.h
#pragma once

#include "Isjaki.h"

class Isjakar {
    private:
        Isjaki* listinn;
        int staerd;
        int finnaLaustPlass();
    public:
        Isjakar();
        Isjakar(Isjakar& hinn);
        void skraIsjaka(Isjaki k);
        void skraIsjaka(int id, int staerd, float fjarlaegd);
        void eydaIsjaka(int id);
        void breytaFjarlaegd(int id, int fjarlaegd);
        void prentaEinnIsjaka(int id);
        void prentaAllt();
        Isjakar& operator=(Isjakar& hinn);
        ~Isjakar();
};