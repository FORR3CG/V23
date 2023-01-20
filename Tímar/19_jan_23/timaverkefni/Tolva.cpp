#include "Tolva.h"

Tolva::Tolva() {
    this->id = -1;
    this->cpu = "";
    this->ram = -1;
    this->hdd = -1;
}

Tolva::Tolva(int id, std::string cpu, int ram, int hdd) {
    this->id = id;
    this->cpu = cpu;
    this->ram = ram;
    this->hdd = hdd;
}

int Tolva::getId() {
    return this->id;
}

void Tolva::setId(int id) {
    this->id = id;
}

std::string Tolva::getCPU() {
    return this->cpu;
}

void Tolva::setCPU(std::string cpu) {
    this->cpu = cpu;
}

int Tolva::getRam() {
    return this->ram;
}

void Tolva::setRam(int ram) {
    this->ram = ram;
}

int Tolva::getHdd() {
    return this->hdd;
}

void Tolva::setHdd(int hdd) {
    this->hdd = hdd;
}

void Tolva::prenta() {
    std::cout << this->toString() << std::endl;
}

std::string Tolva::toString() {
    return "Id: " + std::to_string(this->id) + ", cpu: " + this->cpu +
           ", ram: " + std::to_string(this->ram) + "GB, hdd: " + 
           std::to_string(this->hdd) + "GB.";
}
