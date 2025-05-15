#include <iostream>
#include "VagonBusinessTriedy.h"

VagonBusinessTriedy::VagonBusinessTriedy(int pocetMiest, bool maPripojenieLAN, bool maWifi)
    : Vagon("Vag�n business triedy"), pocetMiest(pocetMiest), maPripojenieLAN(maPripojenieLAN), maWifi(maWifi) {
}

std::string VagonBusinessTriedy::getPopis() const {
    std::string lan = maPripojenieLAN ? "s LAN pripojen�m" : "bez LAN pripojenia";
    std::string wifi = maWifi ? "s WiFi" : "bez WiFi";
    return "Vag�n business triedy s po�tom miest: " + std::to_string(pocetMiest) + " " + lan + " " + wifi;
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
