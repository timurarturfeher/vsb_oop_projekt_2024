#ifndef EXPRES_H
#define EXPRES_H

#include "Vlak.h"
#include "VagonDruhejTriedy.h"
#include "VagonPrvejTriedy.h"
#include "RestauracnyVagon.h"

class Expres : public Vlak {
protected:
    static const int MAX_VAGONY_DRUHEJ_TRIEDY = 6;
    static const int MAX_VAGONY_PRVEJ_TRIEDY = 1;
    static const int MAX_RESTAURACNE_VAGONY = 1;

public:
    Expres(int cislo, Trasa* trasa);
    bool pridajVagon(Vagon* vagon) override;
};

#endif
