#include <iostream>
#include "VagonPrvejTriedy.h"

VagonPrvejTriedy::VagonPrvejTriedy(int pocetMiest, bool maKlimatizaciu)
    : Vagon("Vagón prvej triedy"), pocetMiest(pocetMiest), maKlimatizaciu(maKlimatizaciu) {
}

std::string VagonPrvejTriedy::getPopis() const {
    std::string klimatizacia = maKlimatizaciu ? "s klimatizáciou" : "bez klimatizácie";
    return "Vagón prvej triedy s poètom miest: " + std::to_string(pocetMiest) + " " + klimatizacia;
}

int VagonPrvejTriedy::getPocetMiest() const {
    return pocetMiest;
}

bool VagonPrvejTriedy::getMaKlimatizaciu() const {
    return maKlimatizaciu;
}
