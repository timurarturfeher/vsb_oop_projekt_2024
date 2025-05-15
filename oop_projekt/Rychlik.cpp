#include <iostream>
#include "Rychlik.h"

Rychlik::Rychlik(int cislo, Trasa* trasa)
    : Vlak(cislo, "Rychlik", trasa) {
}

bool Rychlik::pridajVagon(Vagon* vagon) {
    // 2.,1.
    std::string typVagonu = vagon->getTyp();

    if (typVagonu != "Vag�n druhej triedy" && typVagonu != "Vag�n prvej triedy") {
        std::cout << "R�chlik m��e ma� iba vag�ny prvej alebo druhej triedy." << std::endl;
        return false;
    }

    // max vag�ny tried
    int pocetVagonovDruhejTriedy = 0;
    int pocetVagonovPrvejTriedy = 0;

    for (const auto& v : vagony) {
        if (v->getTyp() == "Vag�n druhej triedy") {
            pocetVagonovDruhejTriedy++;
        }
        else if (v->getTyp() == "Vag�n prvej triedy") {
            pocetVagonovPrvejTriedy++;
        }
    }

    if (typVagonu == "Vag�n druhej triedy" && pocetVagonovDruhejTriedy >= MAX_VAGONY_DRUHEJ_TRIEDY) {
        std::cout << "R�chlik m��e ma� maxim�lne " << MAX_VAGONY_DRUHEJ_TRIEDY << " vag�nov druhej triedy." << std::endl;
        return false;
    }

    if (typVagonu == "Vag�n prvej triedy" && pocetVagonovPrvejTriedy >= MAX_VAGONY_PRVEJ_TRIEDY) {
        std::cout << "R�chlik m��e ma� maxim�lne " << MAX_VAGONY_PRVEJ_TRIEDY << " vag�n prvej triedy." << std::endl;
        return false;
    }

    // pushni vag�n
    vagony.push_back(std::unique_ptr<Vagon>(vagon));
    return true;
}
