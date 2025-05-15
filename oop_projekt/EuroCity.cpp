#include <iostream>
#include "EuroCity.h"
#include <cstdlib>

EuroCity::EuroCity(int cislo, Trasa* trasa)
    : Expres(cislo, trasa) {
    typVlaku = "EuroCity";  // dedenie override
}

int EuroCity::getOdhadovaneMeskanieDalsiaStanica() const {
    // EuroCity odhad me�kania
    // -2 do 5 min me�kanie
    int odhadovanaZmena = (std::rand() % 8) - 2;
    int odhadovaneMeskanie = meskanie + odhadovanaZmena;

    // nem��e by� z�por
    return std::max(0, odhadovaneMeskanie);
}
