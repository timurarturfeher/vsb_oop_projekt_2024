#ifndef RAILJET_H
#define RAILJET_H

#include "Vlak.h"
#include "VagonDruhejTriedy.h"
#include "VagonPrvejTriedy.h"
#include "RestauracnyVagon.h"
#include "VagonBusinessTriedy.h"

class Railjet : public Vlak {
private:
    static const int MAX_VAGONY_DRUHEJ_TRIEDY = 7;
    static const int MAX_VAGONY_PRVEJ_TRIEDY = 1;
    static const int MAX_RESTAURACNE_VAGONY = 1;
    static const int MAX_VAGONY_BUSINESS_TRIEDY = 2;

public:
    Railjet(int cislo, Trasa* trasa);
    bool pridajVagon(Vagon* vagon) override;
    int getOdhadovaneMeskanieDalsiaStanica() const override;
};

#endif
