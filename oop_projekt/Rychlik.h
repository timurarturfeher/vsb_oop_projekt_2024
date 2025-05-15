#ifndef RYCHLIK_H
#define RYCHLIK_H

#include "Vlak.h"
#include "VagonDruhejTriedy.h"
#include "VagonPrvejTriedy.h"

class Rychlik : public Vlak {
private:
    static const int MAX_VAGONY_DRUHEJ_TRIEDY = 7;
    static const int MAX_VAGONY_PRVEJ_TRIEDY = 1;

public:
    Rychlik(int cislo, Trasa* trasa);
    bool pridajVagon(Vagon* vagon) override;
};

#endif
