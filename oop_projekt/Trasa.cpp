#include <iostream>
#include "Trasa.h"

int Trasa::nextId = 1;

Trasa::Trasa(const std::string& nazov, bool jeMedzinarodna)
    : id(nextId++), nazov(nazov), jeMedzinarodna(jeMedzinarodna) {
}

Trasa::~Trasa() {}

void Trasa::pridajStanicu(Stanica* stanica) {
    stanice.push_back(stanica);
}

int Trasa::getId() const {
    return id;
}

std::string Trasa::getNazov() const {
    return nazov;
}

const std::vector<Stanica*>& Trasa::getStanice() const {
    return stanice;
}

bool Trasa::getJeMedzinarodna() const {
    return jeMedzinarodna;
}

int Trasa::getPocetStanic() const {
    return static_cast<int>(stanice.size());
}

Stanica* Trasa::getStanica(int index) const {
    if (index >= 0 && index < stanice.size()) {
        return stanice[index];
    }
    return nullptr;
}

bool Trasa::maSaZastavit(const std::string& typVlaku, int indexStanice) const {
    // prva posledna - stop
    if (indexStanice == 0 || indexStanice == stanice.size() - 1) {
        return true;
    }

    // stopy pre vlaky
    if (!jeMedzinarodna) {
        if (typVlaku == "OsobnyVlak") {
            return true; // všetky
        }
        else if (typVlaku == "Rychlik") {
            return indexStanice % 3 == 0; // ob 3
        }
        else if (typVlaku == "Expres") {
            return indexStanice % 6 == 0; // ob 6
        }
    }
    else {
        if (typVlaku == "InterCity") {
            return indexStanice % 4 == 0; // ob 4
        }
        else if (typVlaku == "EuroCity") {
            return indexStanice % 6 == 0; // ob 6
        }
        else if (typVlaku == "railjet" || typVlaku == "SuperCity") {
            return false; // 1. + n-1
        }
    }

    return false;
}
