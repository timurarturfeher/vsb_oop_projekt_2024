#include "Stanica.h"
#include "Vlak.h"
#include <algorithm>
#include <iostream>

int Stanica::nextId = 1;

Stanica::Stanica(const std::string& nazov) : nazov(nazov), id(nextId++) {}

Stanica::~Stanica() {}

std::string Stanica::getNazov() const {
    return nazov;
}

int Stanica::getId() const {
    return id;
}

void Stanica::pridajVlak(Vlak* vlak) {
    aktualneVlaky.push_back(vlak);
}

void Stanica::odstranVlak(Vlak* vlak) {
    aktualneVlaky.erase(std::remove(aktualneVlaky.begin(), aktualneVlaky.end(), vlak), aktualneVlaky.end());
}

const std::vector<Vlak*>& Stanica::getAktualneVlaky() const {
    return aktualneVlaky;
}

std::ostream& operator<<(std::ostream& os, const Stanica& stanica) {
    os << "Stanica " << stanica.nazov << " (ID: " << stanica.id << ")";
    return os;
}
