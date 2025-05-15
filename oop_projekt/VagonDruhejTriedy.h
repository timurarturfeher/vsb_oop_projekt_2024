#ifndef VAGON_DRUHEJ_TRIEDY_H
#define VAGON_DRUHEJ_TRIEDY_H

#include "Vagon.h"

class VagonDruhejTriedy : public Vagon {
private:
    int pocetMiest;

public:
    VagonDruhejTriedy(int pocetMiest = 80);
    std::string getPopis() const override;
    int getPocetMiest() const;
};

#endif
