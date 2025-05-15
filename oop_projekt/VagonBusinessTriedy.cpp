#include <iostream>
#include "VagonBusinessTriedy.h"

VagonBusinessTriedy::VagonBusinessTriedy(int pocetMiest, bool maPripojenieLAN, bool maWifi)
    : Vagon("Vagón business triedy"), pocetMiest(pocetMiest), maPripojenieLAN(maPripojenieLAN), maWifi(maWifi) {
}

std::string VagonBusinessTriedy::getPopis() const {
    std::string lan = maPripojenieLAN ? "s LAN pripojením" : "bez LAN pripojenia";
    std::string wifi = maWifi ? "s WiFi" : "bez WiFi";
    return "Vagón business triedy s poètom miest: " + std::to_string(pocetMiest) + " " + lan + " " + wifi;
}

int VagonBusinessTriedy::getPocetMiest() const {
    return pocetMiest;
}

bool VagonBusinessTriedy::getMaPripojenieLAN() const {
    return maPripojenieLAN;
}

bool VagonBusinessTriedy::getMaWifi() const {
    return maWifi;
}
