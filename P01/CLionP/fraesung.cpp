#include "fraesung.hpp"

#include <cmath>
#include <iostream>

/* Definitions of methods for class Komponente */
Komponente::Komponente(double xPos, double yPos)
    : x{xPos}, y{yPos} {}

double Komponente::getX() const {
    return x;
}

double Komponente::getY() const {
    return y;
}

void Komponente::output(std::ostream& os) const {
    os << "(" << x << ", " << y << ")";  // formatting??
}

/* Definitions of methods for class Bohrung */
Bohrung::Bohrung(double x_, double y_, double diam)
    : Komponente{x_, y_}, diameter{diam} {
    if (diam <= 0) {
        diameter = 6.0;
    }
}

double Bohrung::getDiameter() const {
    return diameter;
}

void Bohrung::output(std::ostream& os) const {
    // os << "Bohrung: " << static_cast<const Komponente&>(*this)
    //    << ", Durchmesser: " << diameter;
    os << "Bohrung: ";
    Komponente::output(os);
    os << ", Durchmesser: " << diameter;
}

/* Definitions of methods for class Fraesung */
Fraesung::Fraesung(double x, double y, double diam, double l, double a)
    : Bohrung{x, y, diam}, length{l}, angle{a} {
    if (l <= 0) {
        length = 0;
    }
}

double Fraesung::getLength() const {
    return length;
}

double Fraesung::getAngle() const {
    return angle;
}

double Fraesung::getEndX() const {
    return getX() + length * std::cos(angle);
}

double Fraesung::getEndY() const {
    return getY() + length * std::sin(angle);
}

void Fraesung::output(std::ostream& os) const {
    os << "Fraesung mit Start: ";
    Komponente::output(os);  // or Bohrung::Komponente::
    os << " und Endpunkt: (" << getEndX() << ", " << getEndY() << "), "
       << "Durchmesser: " << getDiameter();
}
