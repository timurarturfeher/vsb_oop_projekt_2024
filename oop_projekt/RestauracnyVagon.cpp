#include <iostream>
#include "RestauracnyVagon.h"

RestauracnyVagon::RestauracnyVagon(int pocetStolov, bool maBar)
    : Vagon("Re�taura�n� vag�n"), pocetStolov(pocetStolov), maBar(maBar) {
}

std::string RestauracnyVagon::getPopis() const {
    std::string bar = maBar ? "s barom" : "bez baru";
    return "Re�taura�n� vag�n s po�tom stolov: " + std::to_string(pocetStolov) + " " + bar;
}

int RestauracnyVagon::getPocetStolov() const {
    return pocetStolov;
}

bool RestauracnyVagon::getMaBar() const {
    return maBar;
}
