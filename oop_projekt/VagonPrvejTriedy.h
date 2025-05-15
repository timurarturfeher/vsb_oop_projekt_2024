#ifndef VAGON_PRVEJ_TRIEDY_H
#define VAGON_PRVEJ_TRIEDY_H

#include "Vagon.h"

class VagonPrvejTriedy : public Vagon {
private:
    int pocetMiest;
    bool maKlimatizaciu;

public:
    VagonPrvejTriedy(int pocetMiest = 60, bool maKlimatizaciu = true);
    std::string getPopis() const override;
    int getPocetMiest() const;
    bool getMaKlimatizaciu() const;
};

#endif
