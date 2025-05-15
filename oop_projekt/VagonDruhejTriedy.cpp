#include <iostream>
#include "VagonDruhejTriedy.h"

VagonDruhejTriedy::VagonDruhejTriedy(int pocetMiest)
    : Vagon("Vag�n druhej triedy"), pocetMiest(pocetMiest) {
}

std::string VagonDruhejTriedy::getPopis() const {
    return "Vag�n druhej triedy s po�tom miest: " + std::to_string(pocetMiest);
}

int VagonDruhejTriedy::getPocetMiest() const {
    return pocetMiest;
}
