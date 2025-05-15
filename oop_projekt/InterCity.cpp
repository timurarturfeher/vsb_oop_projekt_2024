#include <iostream>
#include "InterCity.h"

InterCity::InterCity(int cislo, Trasa* trasa)
    : Expres(cislo, trasa) {
    typVlaku = "InterCity";  // dedenie override
}
