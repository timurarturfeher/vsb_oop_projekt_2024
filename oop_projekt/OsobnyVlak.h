#ifndef OSOBNY_VLAK_H
#define OSOBNY_VLAK_H

#include "Vlak.h"
#include "VagonDruhejTriedy.h"

class OsobnyVlak : public Vlak {
private:
    static const int MAX_VAGONY_DRUHEJ_TRIEDY = 3;

public:
    OsobnyVlak(int cislo, Trasa* trasa);
    bool pridajVagon(Vagon* vagon) override;
};

#endif
