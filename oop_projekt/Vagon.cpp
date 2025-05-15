#include <iostream>
#include "Vagon.h"

Vagon::Vagon(const std::string& typ) : typ(typ) {}

Vagon::~Vagon() {}

std::string Vagon::getTyp() const {
    return typ;
}
