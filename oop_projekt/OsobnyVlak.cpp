#include <iostream>
#include "OsobnyVlak.h"

OsobnyVlak::OsobnyVlak(int cislo, Trasa* trasa)
    : Vlak(cislo, "OsobnyVlak", trasa) {
}

bool OsobnyVlak::pridajVagon(Vagon* vagon) {
    // 2.
    if (vagon->getTyp() != "Vag�n druhej triedy") {
        std::cout << "Osobn� vlak m��e ma� iba vag�ny druhej triedy." << std::endl;
        return false;
    }

    // max vag�nov druhej
    int pocetVagonovDruhejTriedy = 0;
    for (const auto& v : vagony) {
        if (v->getTyp() == "Vag�n druhej triedy") {
            pocetVagonovDruhejTriedy++;
        }
    }

    if (pocetVagonovDruhejTriedy >= MAX_VAGONY_DRUHEJ_TRIEDY) {
        std::cout << "Osobn� vlak m��e ma� maxim�lne " << MAX_VAGONY_DRUHEJ_TRIEDY << " vag�nov druhej triedy." << std::endl;
        return false;
    }

    // pushni vagon
    vagony.push_back(std::unique_ptr<Vagon>(vagon));
    return true;
}
