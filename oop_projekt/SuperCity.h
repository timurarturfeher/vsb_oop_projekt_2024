#ifndef SUPER_CITY_H
#define SUPER_CITY_H

#include "Expres.h"

class SuperCity : public Expres {
public:
    SuperCity(int cislo, Trasa* trasa);
    int getOdhadovaneMeskanieDalsiaStanica() const override;
    void posunNaDalsiuStanicu() override;
};

#endif
