#include <iostream>
#include "EuroCity.h"
#include <cstdlib>

EuroCity::EuroCity(int cislo, Trasa* trasa)
    : Expres(cislo, trasa) {
    typVlaku = "EuroCity";  // dedenie override
}

int EuroCity::getOdhadovaneMeskanieDalsiaStanica() const {
    // EuroCity odhad meökania
    // -2 do 5 min meökanie
    int odhadovanaZmena = (std::rand() % 8) - 2;
    int odhadovaneMeskanie = meskanie + odhadovanaZmena;

    // nemÙûe byù z·por
    return std::max(0, odhadovaneMeskanie);
}
