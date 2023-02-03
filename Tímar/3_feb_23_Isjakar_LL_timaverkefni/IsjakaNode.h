#pragma once

#include "Isjaki.h"

struct IsjakaNode {
    Isjaki jaki;
    IsjakaNode* next;

    IsjakaNode(Isjaki jaki) {
        this->jaki = jaki;
        this->next = nullptr;
    }
};

/*
Isjaki.h
Isjaki.cpp
IsjakaNode.h
IsjakarRadad.h
IsjakarRadad.cpp
*/