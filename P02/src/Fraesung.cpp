#include "../include/Fraesung.hpp"

#include <cmath>
#include <iostream>

/* Definitions of methods for class Fraesung */
Fraesung::Fraesung(double x, double y, double diam, double l, double a)
    : Bohrung{x, y, diam}, length{l}, angle{a} {
    if (l <= 0) {
        length = 0;
    }
}

/**
 * @brief Alternative constructor that constructs a Fraesung from a given starting point and endpoint
 */
Fraesung::Fraesung(double xB, double yB, double diam, double xE, double yE, double)
    : Bohrung{xB, yB, diam} {
    length = std::sqrt(std::pow(xE - xB, 2) +
        std::pow(yE - yB, 2));
    angle = std::atan((yE - yB) / (xE - xB));
    if (xB > xE) { // quadrant II or III
        angle += M_PI;
    } else if (yB > yE) { // quadrant IV
        angle += 2 * M_PI;
    }
}

inline double Fraesung::getLength() const {
    return length;
}

inline double Fraesung::getAngle() const {
    return angle;
}

double Fraesung::getEndX() const {
    return getX() + length * std::cos(angle);
}

double Fraesung::getEndY() const {
    return getY() + length * std::sin(angle);
}

inline double Fraesung::calcTotalPath() const {
    return 2 * length;
}

void Fraesung::output(std::ostream& os) const {
    os << "Fraesung mit Start: ";
    Bohrung::Komponente::output(os);  //TODO or Komponente::output?
    os << " und Endpunkt: (" << getEndX() << ", " << getEndY() << "), "
       << "Durchmesser: " << Bohrung::getDiameter();
}
