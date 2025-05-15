#include <iostream>
#include "Expres.h"

Expres::Expres(int cislo, Trasa* trasa)
    : Vlak(cislo, "Expres", trasa) {
}

bool Expres::pridajVagon(Vagon* vagon) {
    // 2.,1.,reštauraèný
    std::string typVagonu = vagon->getTyp();

    if (typVagonu != "Vagón druhej triedy" && typVagonu != "Vagón prvej triedy" && typVagonu != "Reštauraèný vagón") {
        std::cout << "Expres môže ma iba vagóny druhej triedy, prvej triedy alebo reštauraèný vagón." << std::endl;
        return false;
    }

    // pozri max vagónov každej triedy
    int pocetVagonovDruhejTriedy = 0;
    int pocetVagonovPrvejTriedy = 0;
    int pocetRestauracnychVagonov = 0;

    for (const auto& v : vagony) {
        if (v->getTyp() == "Vagón druhej triedy") {
            pocetVagonovDruhejTriedy++;
        }
        else if (v->getTyp() == "Vagón prvej triedy") {
            pocetVagonovPrvejTriedy++;
        }
        else if (v->getTyp() == "Reštauraèný vagón") {
            pocetRestauracnychVagonov++;
        }
    }

    if (typVagonu == "Vagón druhej triedy" && pocetVagonovDruhejTriedy >= MAX_VAGONY_DRUHEJ_TRIEDY) {
        std::cout << "Expres môže ma maximálne " << MAX_VAGONY_DRUHEJ_TRIEDY << " vagónov druhej triedy." << std::endl;
        return false;
    }

    if (typVagonu == "Vagón prvej triedy" && pocetVagonovPrvejTriedy >= MAX_VAGONY_PRVEJ_TRIEDY) {
        std::cout << "Expres môže ma maximálne " << MAX_VAGONY_PRVEJ_TRIEDY << " vagón prvej triedy." << std::endl;
        return false;
    }

    if (typVagonu == "Reštauraèný vagón" && pocetRestauracnychVagonov >= MAX_RESTAURACNE_VAGONY) {
        std::cout << "Expres môže ma maximálne " << MAX_RESTAURACNE_VAGONY << " reštauraèný vagón." << std::endl;
        return false;
    }

    // pridaj vagópn
    vagony.push_back(std::unique_ptr<Vagon>(vagon));
    return true;
}
