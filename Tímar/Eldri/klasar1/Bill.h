// Bill.h
#pragma once

#include <iostream>
#include <string>

class Bill {
    private:
        int id;
        std::string tegund;
        std::string litur;
    public:
        Bill();
        Bill(int id);
        Bill(int id, std::string tegund, std::string litur);
        int getId();
        void setId(int id);
        std::string getTegund();
        void setTegund(std::string tegund);
        std::string getLitur();
        void setLitur(std::string litur);
        void prenta();
        std::string toString();
};