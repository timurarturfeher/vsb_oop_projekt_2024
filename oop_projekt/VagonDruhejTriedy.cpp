#include <iostream>
#include "VagonDruhejTriedy.h"

VagonDruhejTriedy::VagonDruhejTriedy(int pocetMiest)
    : Vagon("Vagón druhej triedy"), pocetMiest(pocetMiest) {
}

std::string VagonDruhejTriedy::getPopis() const {
    return "Vagón druhej triedy s poètom miest: " + std::to_string(pocetMiest);
}

int VagonDruhejTriedy::getPocetMiest() const {
    return pocetMiest;
}
