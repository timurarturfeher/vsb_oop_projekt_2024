#include <iostream>
#include "Railjet.h"
#include <cstdlib>

Railjet::Railjet(int cislo, Trasa* trasa)
    : Vlak(cislo, "railjet", trasa) {
}

bool Railjet::pridajVagon(Vagon* vagon) {
	// 2.,1.,reštauraènı, business
    std::string typVagonu = vagon->getTyp();

    if (typVagonu != "Vagón druhej triedy" &&
        typVagonu != "Vagón prvej triedy" &&
        typVagonu != "Reštauraènı vagón" &&
        typVagonu != "Vagón business triedy") {
        std::cout << "Railjet môe ma iba vagóny druhej triedy, prvej triedy, reštauraènı vagón, alebo vagóny business triedy." << std::endl;
        return false;
    }

    // check max
    int pocetVagonovDruhejTriedy = 0;
    int pocetVagonovPrvejTriedy = 0;
    int pocetRestauracnychVagonov = 0;
    int pocetVagonovBusinessTriedy = 0;

    for (const auto& v : vagony) {
        if (v->getTyp() == "Vagón druhej triedy") {
            pocetVagonovDruhejTriedy++;
        }
        else if (v->getTyp() == "Vagón prvej triedy") {
            pocetVagonovPrvejTriedy++;
        }
        else if (v->getTyp() == "Reštauraènı vagón") {
            pocetRestauracnychVagonov++;
        }
        else if (v->getTyp() == "Vagón business triedy") {
            pocetVagonovBusinessTriedy++;
        }
    }

    if (typVagonu == "Vagón druhej triedy" && pocetVagonovDruhejTriedy >= MAX_VAGONY_DRUHEJ_TRIEDY) {
        std::cout << "Railjet môe ma maximálne " << MAX_VAGONY_DRUHEJ_TRIEDY << " vagónov druhej triedy." << std::endl;
        return false;
    }

    if (typVagonu == "Vagón prvej triedy" && pocetVagonovPrvejTriedy >= MAX_VAGONY_PRVEJ_TRIEDY) {
        std::cout << "Railjet môe ma maximálne " << MAX_VAGONY_PRVEJ_TRIEDY << " vagón prvej triedy." << std::endl;
        return false;
    }

    if (typVagonu == "Reštauraènı vagón" && pocetRestauracnychVagonov >= MAX_RESTAURACNE_VAGONY) {
        std::cout << "Railjet môe ma maximálne " << MAX_RESTAURACNE_VAGONY << " reštauraènı vagón." << std::endl;
        return false;
    }

    if (typVagonu == "Vagón business triedy" && pocetVagonovBusinessTriedy >= MAX_VAGONY_BUSINESS_TRIEDY) {
        std::cout << "Railjet môe ma maximálne " << MAX_VAGONY_BUSINESS_TRIEDY << " vagóny business triedy." << std::endl;
        return false;
    }

    // pusni vagon
    vagony.push_back(std::unique_ptr<Vagon>(vagon));
    return true;
}

int Railjet::getOdhadovaneMeskanieDalsiaStanica() const {
	// Railjet -1,0,1 min meškanie
    int odhadovanaZmena = (std::rand() % 2) - (std::rand() % 2);
    int odhadovaneMeskanie = meskanie + odhadovanaZmena;

    // nemôe ma zápor
    return std::max(0, odhadovaneMeskanie);
}
