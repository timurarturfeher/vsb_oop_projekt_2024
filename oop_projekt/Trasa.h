#ifndef TRASA_H
#define TRASA_H

#include <vector>
#include <string>
#include "Stanica.h"

class Trasa {
private:
    int id;
    static int nextId;
    std::string nazov;
    std::vector<Stanica*> stanice;
    bool jeMedzinarodna;

public:
    Trasa(const std::string& nazov, bool jeMedzinarodna = false);
    ~Trasa();
    void pridajStanicu(Stanica* stanica);
    int getId() const;
    std::string getNazov() const;
    const std::vector<Stanica*>& getStanice() const;
    bool getJeMedzinarodna() const;
    int getPocetStanic() const;
    Stanica* getStanica(int index) const;
    bool maSaZastavit(const std::string& typVlaku, int indexStanice) const;
};

#endif
