#ifndef VAGON_H
#define VAGON_H

#include <string>

class Vagon {
protected:
    std::string typ;

public:
    Vagon(const std::string& typ);
    virtual ~Vagon();
    virtual std::string getPopis() const = 0;
    std::string getTyp() const;
};

#endif
