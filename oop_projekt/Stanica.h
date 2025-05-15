#ifndef STANICA_H
#define STANICA_H

#include <string>
#include <vector>

class Vlak;

class Stanica {
private:
    std::string nazov;
    int id;
    static int nextId;
    std::vector<Vlak*> aktualneVlaky;

public:
    Stanica(const std::string& nazov);
    ~Stanica();
    std::string getNazov() const;
    int getId() const;
    void pridajVlak(Vlak* vlak);
    void odstranVlak(Vlak* vlak);
    const std::vector<Vlak*>& getAktualneVlaky() const;
    friend std::ostream& operator<<(std::ostream& os, const Stanica& stanica);
};

#endif
