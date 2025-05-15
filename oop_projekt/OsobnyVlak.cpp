#include <iostream>
#include "OsobnyVlak.h"

OsobnyVlak::OsobnyVlak(int cislo, Trasa* trasa)
    : Vlak(cislo, "OsobnyVlak", trasa) {
}

bool OsobnyVlak::pridajVagon(Vagon* vagon) {
    // 2.
    if (vagon->getTyp() != "Vagón druhej triedy") {
        std::cout << "Osobný vlak môže ma iba vagóny druhej triedy." << std::endl;
        return false;
    }

    // max vagónov druhej
    int pocetVagonovDruhejTriedy = 0;
    for (const auto& v : vagony) {
        if (v->getTyp() == "Vagón druhej triedy") {
            pocetVagonovDruhejTriedy++;
        }
    }

    if (pocetVagonovDruhejTriedy >= MAX_VAGONY_DRUHEJ_TRIEDY) {
        std::cout << "Osobný vlak môže ma maximálne " << MAX_VAGONY_DRUHEJ_TRIEDY << " vagónov druhej triedy." << std::endl;
        return false;
    }

    // pushni vagon
    vagony.push_back(std::unique_ptr<Vagon>(vagon));
    return true;
}
