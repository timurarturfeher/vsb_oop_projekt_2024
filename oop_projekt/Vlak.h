#ifndef VLAK_H
#define VLAK_H

#include <string>
#include <vector>
#include <memory>

#include "Vagon.h"
#include "Trasa.h"
#include "Stanica.h"

class Vlak {
protected:
    int cislo;
    static std::vector<int> obsadeneCisla;
    std::string typVlaku;
    Trasa* trasa;
    int aktualnaPoloha;
    int meskanie;
    bool jeZruseny;
    std::vector<std::unique_ptr<Vagon>> vagony;

public:
    Vlak(int cislo, const std::string& typVlaku, Trasa* trasa);
    virtual ~Vlak();
    int getCislo() const;
    virtual std::string getTypVlaku() const;
    Trasa* getTrasa() const;
    int getAktualnaPoloha() const;
    int getMeskanie() const;
    virtual void setMeskanie(int noveMeskanie);
    bool getJeZruseny() const;
    void zrusVlak();
    virtual void posunNaDalsiuStanicu();
    bool maSaZastavitNaAktualnejStanici() const;
    Stanica* getAktualnaStanica() const;
    const std::vector<std::unique_ptr<Vagon>>& getVagony() const;
    virtual bool pridajVagon(Vagon* vagon) = 0;
    virtual int getOdhadovaneMeskanieDalsiaStanica() const;
    static bool jeObsadeneCislo(int cislo);
    static void uvolniCislo(int cislo);
    friend std::ostream& operator<<(std::ostream& os, const Vlak& vlak);
};

#endif
