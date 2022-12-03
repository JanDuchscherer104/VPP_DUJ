#include "../include/Komponente.hpp"
#include <iostream>
#include <complex>

/* Definitions of methods for class Komponente */
Komponente::Komponente(double xPos, double yPos)
    : x{xPos}, y{yPos}, parent{nullptr} {}

inline double Komponente::calcTotalPath() const {
    return 0.0;
}

inline double Komponente::getX() const {
    return x;
}

inline double Komponente::getY() const {
    return y;
}

double Komponente::getXAbsolute() const {
    double tempX = getX();
    const IKomponente* curParent{parent};
    while (curParent) {
        tempX += curParent->getX();
        curParent = curParent->getParent();
    }
    return tempX;
}

double Komponente::getYAbsolute() const {
    double tempY = getY();
    const IKomponente* curParent{parent};
    while (curParent) {
        tempY += curParent->getY();
        curParent = curParent->getParent();
    }
    return tempY;
}

double Komponente::distance(const IKomponente* k) const {
    return std::norm(std::complex<double>(getXAbsolute() - k->getXAbsolute(),
                                          getYAbsolute() - k->getYAbsolute()));
}

inline const IKomponente* Komponente::getParent() const {
    return parent;
}
inline void Komponente::setParent(const IKomponente* p) {
    parent = p;
}

void Komponente::output(std::ostream& os) const {
    os << "(" << x << ", " << y << ")";
}
