#include "Vlak.h"
#include <algorithm>
#include <iostream>

std::vector<int> Vlak::obsadeneCisla;

Vlak::Vlak(int cislo, const std::string& typVlaku, Trasa* trasa)
    : cislo(cislo), typVlaku(typVlaku), trasa(trasa), aktualnaPoloha(0),
    meskanie(0), jeZruseny(false) {

    // aby ��slo sa nepou�ilo znova
    if (jeObsadeneCislo(cislo)) {
        throw std::invalid_argument("��slo vlaku " + std::to_string(cislo) + " je u� obsaden�.");
    }

    // lockne ��slo
    obsadeneCisla.push_back(cislo);

    // za�ne trasu pre vlak
    if (trasa && trasa->getPocetStanic() > 0) {
        Stanica* prvaStanica = trasa->getStanica(0);
        if (prvaStanica) {
            prvaStanica->pridajVlak(this);
        }
    }
}

Vlak::~Vlak() {
    // ��slo pushne von
    uvolniCislo(cislo);

    // vlak sa ma�e zos stanice
    Stanica* aktualnaStanica = getAktualnaStanica();
    if (aktualnaStanica) {
        aktualnaStanica->odstranVlak(this);
    }
}

int Vlak::getCislo() const {
    return cislo;
}

std::string Vlak::getTypVlaku() const {
    return typVlaku;
}

Trasa* Vlak::getTrasa() const {
    return trasa;
}

int Vlak::getAktualnaPoloha() const {
    return aktualnaPoloha;
}

int Vlak::getMeskanie() const {
    return meskanie;
}

void Vlak::setMeskanie(int noveMeskanie) {
    meskanie = noveMeskanie;

    // ak 30m, tak von
    if (meskanie > 30 && !jeZruseny) {
        zrusVlak();
    }
}

bool Vlak::getJeZruseny() const {
    return jeZruseny;
}

void Vlak::zrusVlak() {
    jeZruseny = true;
    std::cout << "Vlak �. " << cislo << " typu " << typVlaku << " bol zru�en� kv�li me�kaniu " << meskanie << " min�t." << std::endl;
}

void Vlak::posunNaDalsiuStanicu() {
    if (jeZruseny) {
        std::cout << "Vlak �. " << cislo << " je zru�en� a nem��e sa pohybova�." << std::endl;
        return;
    }

    if (!trasa) {
        std::cout << "Vlak �. " << cislo << " nem� pridelen� trasu." << std::endl;
        return;
    }

    // da��ia stanica - push zos predch�dzaj�cej
    Stanica* aktualnaStanica = getAktualnaStanica();
    if (aktualnaStanica) {
        aktualnaStanica->odstranVlak(this);
    }

	// dal�ia stanica   
    aktualnaPoloha++;

    // koniec sk��ka
    if (aktualnaPoloha >= trasa->getPocetStanic()) {
        std::cout << "Vlak �. " << cislo << " dorazil do cie�ovej stanice." << std::endl;
        aktualnaPoloha = trasa->getPocetStanic() - 1;  // zostane na kone�nej
    }
    else {
        // ide na nov� stanicu
        Stanica* novaStanica = getAktualnaStanica();
        if (novaStanica) {
            novaStanica->pridajVlak(this);
        }
    }
}

bool Vlak::maSaZastavitNaAktualnejStanici() const {
    if (!trasa) return false;
    return trasa->maSaZastavit(typVlaku, aktualnaPoloha);
}

Stanica* Vlak::getAktualnaStanica() const {
    if (!trasa) return nullptr;
    return trasa->getStanica(aktualnaPoloha);
}

const std::vector<std::unique_ptr<Vagon>>& Vlak::getVagony() const {
    return vagony;
}

int Vlak::getOdhadovaneMeskanieDalsiaStanica() const {
    // Base implementation returns the current delay
    // Higher tier trains will override this method
    return meskanie;
}

bool Vlak::jeObsadeneCislo(int cislo) {
    return std::find(obsadeneCisla.begin(), obsadeneCisla.end(), cislo) != obsadeneCisla.end();
}

void Vlak::uvolniCislo(int cislo) {
    obsadeneCisla.erase(std::remove(obsadeneCisla.begin(), obsadeneCisla.end(), cislo), obsadeneCisla.end());
}

std::ostream& operator<<(std::ostream& os, const Vlak& vlak) {
    os << vlak.typVlaku << " �. " << vlak.cislo;
    if (vlak.jeZruseny) {
        os << " (ZRU�EN�)";
    }
    else {
        os << " na trase " << vlak.trasa->getNazov();
        Stanica* stanica = vlak.getAktualnaStanica();
        if (stanica) {
            os << ", aktu�lne na stanici: " << stanica->getNazov();
        }
        os << ", me�kanie: " << vlak.meskanie << " min�t";
    }
    return os;
}
