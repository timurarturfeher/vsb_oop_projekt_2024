#include <iostream>
#include "SuperCity.h"
#include <cstdlib>
#include <algorithm>

SuperCity::SuperCity(int cislo, Trasa* trasa)
    : Expres(cislo, trasa) {
    typVlaku = "SuperCity";  // dedenie override
}

int SuperCity::getOdhadovaneMeskanieDalsiaStanica() const {
    // SuperCity odhad meškania
    // presnejší -1,1
    int odhadovanaZmena = (std::rand() % 3) - 1;
    int odhadovaneMeskanie = meskanie + odhadovanaZmena;

    // nemôže ís do záporu
    return std::max(0, odhadovaneMeskanie);
}

void SuperCity::posunNaDalsiuStanicu() {
    // prechod na dal¾iu stanicu - mení meškanie
    if (!jeZruseny && meskanie > 0) {
        // 1-3 min odráta
        int znizenie = 1 + (std::rand() % 3);
        meskanie = std::max(0, meskanie - znizenie);
    }

    // systém posunu
    Vlak::posunNaDalsiuStanicu();
}
