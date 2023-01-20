#pragma once

#include <iostream>
#include <string>

class Tolva {
    private:
        int id;
        std::string cpu;
        int ram;
        int hdd;
    public:
        Tolva();
        Tolva(int id, std::string cpu, int ram, int hdd);
        int getId();
        void setId(int id);
        std::string getCPU();
        void setCPU(std::string cpu);
        int getRam();
        void setRam(int ram);
        int getHdd();
        void setHdd(int hdd);
        void prenta();
        std::string toString();
};