#ifndef RESTAURACNY_VAGON_H
#define RESTAURACNY_VAGON_H

#include "Vagon.h"

class RestauracnyVagon : public Vagon {
private:
    int pocetStolov;
    bool maBar;

public:
    RestauracnyVagon(int pocetStolov = 15, bool maBar = true);
    std::string getPopis() const override;
    int getPocetStolov() const;
    bool getMaBar() const;
};

#endif
