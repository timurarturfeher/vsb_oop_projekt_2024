#ifndef VAGON_BUSINESS_TRIEDY_H
#define VAGON_BUSINESS_TRIEDY_H

#include "Vagon.h"

class VagonBusinessTriedy : public Vagon {
private:
    int pocetMiest;
    bool maPripojenieLAN;
    bool maWifi;

public:
    VagonBusinessTriedy(int pocetMiest = 40, bool maPripojenieLAN = true, bool maWifi = true);
    std::string getPopis() const override;
    int getPocetMiest() const;
    bool getMaPripojenieLAN() const;
    bool getMaWifi() const;
};

#endif
