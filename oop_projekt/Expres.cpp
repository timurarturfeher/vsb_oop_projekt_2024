#include <iostream>
#include "Expres.h"

Expres::Expres(int cislo, Trasa* trasa)
    : Vlak(cislo, "Expres", trasa) {
}

bool Expres::pridajVagon(Vagon* vagon) {
    // 2.,1.,re�taura�n�
    std::string typVagonu = vagon->getTyp();

    if (typVagonu != "Vag�n druhej triedy" && typVagonu != "Vag�n prvej triedy" && typVagonu != "Re�taura�n� vag�n") {
        std::cout << "Expres m��e ma� iba vag�ny druhej triedy, prvej triedy alebo re�taura�n� vag�n." << std::endl;
        return false;
    }

    // pozri max vag�nov ka�dej triedy
    int pocetVagonovDruhejTriedy = 0;
    int pocetVagonovPrvejTriedy = 0;
    int pocetRestauracnychVagonov = 0;

    for (const auto& v : vagony) {
        if (v->getTyp() == "Vag�n druhej triedy") {
            pocetVagonovDruhejTriedy++;
        }
        else if (v->getTyp() == "Vag�n prvej triedy") {
            pocetVagonovPrvejTriedy++;
        }
        else if (v->getTyp() == "Re�taura�n� vag�n") {
            pocetRestauracnychVagonov++;
        }
    }

    if (typVagonu == "Vag�n druhej triedy" && pocetVagonovDruhejTriedy >= MAX_VAGONY_DRUHEJ_TRIEDY) {
        std::cout << "Expres m��e ma� maxim�lne " << MAX_VAGONY_DRUHEJ_TRIEDY << " vag�nov druhej triedy." << std::endl;
        return false;
    }

    if (typVagonu == "Vag�n prvej triedy" && pocetVagonovPrvejTriedy >= MAX_VAGONY_PRVEJ_TRIEDY) {
        std::cout << "Expres m��e ma� maxim�lne " << MAX_VAGONY_PRVEJ_TRIEDY << " vag�n prvej triedy." << std::endl;
        return false;
    }

    if (typVagonu == "Re�taura�n� vag�n" && pocetRestauracnychVagonov >= MAX_RESTAURACNE_VAGONY) {
        std::cout << "Expres m��e ma� maxim�lne " << MAX_RESTAURACNE_VAGONY << " re�taura�n� vag�n." << std::endl;
        return false;
    }

    // pridaj vag�pn
    vagony.push_back(std::unique_ptr<Vagon>(vagon));
    return true;
}
