#include "../include/Komponente.hpp"
#include <iostream>
#include <cmath>
#include <QJsonObject>

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
    double ret = 0;
    if (k) {
        ret = std::sqrt(std::pow(getXAbsolute() - k->getXAbsolute(), 2) +
            std::pow(getYAbsolute() - k->getYAbsolute(), 2));
    }
    return ret;
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

QJsonObject Komponente::toJson() const {
    QJsonObject ret;
    ret["type"] = "Komponente";
    ret["x"] = getX();
    ret["y"] = getY();
    ret["hasParent"] = (bool)(getParent() != nullptr);
    return ret;
}
