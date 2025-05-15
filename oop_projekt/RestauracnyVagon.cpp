#include <iostream>
#include "RestauracnyVagon.h"

RestauracnyVagon::RestauracnyVagon(int pocetStolov, bool maBar)
    : Vagon("Reštauraèný vagón"), pocetStolov(pocetStolov), maBar(maBar) {
}

std::string RestauracnyVagon::getPopis() const {
    std::string bar = maBar ? "s barom" : "bez baru";
    return "Reštauraèný vagón s poètom stolov: " + std::to_string(pocetStolov) + " " + bar;
}

int RestauracnyVagon::getPocetStolov() const {
    return pocetStolov;
}

bool RestauracnyVagon::getMaBar() const {
    return maBar;
}
