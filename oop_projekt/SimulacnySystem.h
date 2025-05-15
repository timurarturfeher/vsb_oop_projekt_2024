#ifndef SIMULACNY_SYSTEM_H
#define SIMULACNY_SYSTEM_H

#include <vector>
#include <memory>
#include "Vlak.h"
#include "OsobnyVlak.h"
#include "Rychlik.h"
#include "Expres.h"
#include "InterCity.h"
#include "EuroCity.h"
#include "Railjet.h"
#include "SuperCity.h"
#include "Trasa.h"
#include "Stanica.h"

class SimulacnySystem {
private:
    std::vector<std::unique_ptr<Stanica>> stanice;
    std::vector<std::unique_ptr<Trasa>> trasy;
    std::vector<std::unique_ptr<Vlak>> vlaky;

    void vytvorStanice();
    void vytvorTrasy();
    void vytvorVlaky();

public:
    SimulacnySystem();
    ~SimulacnySystem();
    void spustiSimulaciu(int pocetKrokov);
    void zobrazStavVlakov() const;
    void zobrazStaniceAVlaky() const;
    Vlak* najdiVlak(int cisloVlaku) const;
    void pridajVlak(Vlak* vlak);
    bool zrusVlak(int cisloVlaku);
    bool nastavMeskanie(int cisloVlaku, int meskanie);
    bool posunVlakNaDalsiuStanicu(int cisloVlaku);
    bool pridajVagonVlaku(int cisloVlaku, Vagon* vagon);
};

#endif
