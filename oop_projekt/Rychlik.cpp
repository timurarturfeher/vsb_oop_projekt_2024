#include <iostream>
#include "Rychlik.h"

Rychlik::Rychlik(int cislo, Trasa* trasa)
    : Vlak(cislo, "Rychlik", trasa) {
}

bool Rychlik::pridajVagon(Vagon* vagon) {
    // 2.,1.
    std::string typVagonu = vagon->getTyp();

    if (typVagonu != "Vagón druhej triedy" && typVagonu != "Vagón prvej triedy") {
        std::cout << "Rýchlik môže ma iba vagóny prvej alebo druhej triedy." << std::endl;
        return false;
    }

    // max vagóny tried
    int pocetVagonovDruhejTriedy = 0;
    int pocetVagonovPrvejTriedy = 0;

    for (const auto& v : vagony) {
        if (v->getTyp() == "Vagón druhej triedy") {
            pocetVagonovDruhejTriedy++;
        }
        else if (v->getTyp() == "Vagón prvej triedy") {
            pocetVagonovPrvejTriedy++;
        }
    }

    if (typVagonu == "Vagón druhej triedy" && pocetVagonovDruhejTriedy >= MAX_VAGONY_DRUHEJ_TRIEDY) {
        std::cout << "Rýchlik môže ma maximálne " << MAX_VAGONY_DRUHEJ_TRIEDY << " vagónov druhej triedy." << std::endl;
        return false;
    }

    if (typVagonu == "Vagón prvej triedy" && pocetVagonovPrvejTriedy >= MAX_VAGONY_PRVEJ_TRIEDY) {
        std::cout << "Rýchlik môže ma maximálne " << MAX_VAGONY_PRVEJ_TRIEDY << " vagón prvej triedy." << std::endl;
        return false;
    }

    // pushni vagón
    vagony.push_back(std::unique_ptr<Vagon>(vagon));
    return true;
}
