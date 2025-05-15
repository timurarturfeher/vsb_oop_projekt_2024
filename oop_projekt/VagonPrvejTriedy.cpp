#include <iostream>
#include "VagonPrvejTriedy.h"

VagonPrvejTriedy::VagonPrvejTriedy(int pocetMiest, bool maKlimatizaciu)
    : Vagon("Vag�n prvej triedy"), pocetMiest(pocetMiest), maKlimatizaciu(maKlimatizaciu) {
}

std::string VagonPrvejTriedy::getPopis() const {
    std::string klimatizacia = maKlimatizaciu ? "s klimatiz�ciou" : "bez klimatiz�cie";
    return "Vag�n prvej triedy s po�tom miest: " + std::to_string(pocetMiest) + " " + klimatizacia;
}

int VagonPrvejTriedy::getPocetMiest() const {
    return pocetMiest;
}

bool VagonPrvejTriedy::getMaKlimatizaciu() const {
    return maKlimatizaciu;
}
