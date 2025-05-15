#include <iostream>
#include "SuperCity.h"
#include <cstdlib>
#include <algorithm>

SuperCity::SuperCity(int cislo, Trasa* trasa)
    : Expres(cislo, trasa) {
    typVlaku = "SuperCity";  // dedenie override
}

int SuperCity::getOdhadovaneMeskanieDalsiaStanica() const {
    // SuperCity odhad me�kania
    // presnej�� -1,1
    int odhadovanaZmena = (std::rand() % 3) - 1;
    int odhadovaneMeskanie = meskanie + odhadovanaZmena;

    // nem��e �s� do z�poru
    return std::max(0, odhadovaneMeskanie);
}

void SuperCity::posunNaDalsiuStanicu() {
    // prechod na dal�iu stanicu - men� me�kanie
    if (!jeZruseny && meskanie > 0) {
        // 1-3 min odr�ta
        int znizenie = 1 + (std::rand() % 3);
        meskanie = std::max(0, meskanie - znizenie);
    }

    // syst�m posunu
    Vlak::posunNaDalsiuStanicu();
}
