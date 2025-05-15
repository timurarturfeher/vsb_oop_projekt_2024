#ifndef EURO_CITY_H
#define EURO_CITY_H

#include "Expres.h"

class EuroCity : public Expres {
public:
    EuroCity(int cislo, Trasa* trasa);
    int getOdhadovaneMeskanieDalsiaStanica() const override;
};

#endif
