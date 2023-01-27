// IsjakarRadad.h
#pragma once

#include "Isjaki.h"

class IsjakarRadad {
    private:
        int fjoldi;
        int staerd;
        Isjaki* listinn;
    public:
        IsjakarRadad();
        IsjakarRadad(IsjakarRadad& hinn);
        void skraIsjaka(Isjaki jaki);
        void skraIsjaka(int id, int staerd, float fjarlaegd);
        void eydaIsjaka(int id);
        void prentaAllt();
        IsjakarRadad& operator=(IsjakarRadad& hinn);
        ~IsjakarRadad();
};
