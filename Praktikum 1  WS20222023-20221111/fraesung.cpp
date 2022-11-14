#include "fraesung.h"

#include <cmath>
#include <iostream>

/* Definitions of methods for class Komponente */
inline double Komponente::getX() const {
    return x;
}
inline double Komponente::getY() const {
    return y;
}
void Komponente::output(std::ostream& os) const {
    os << "(" << x << "," << y << ")";  // formatting??
}

/* Definitions of methods for class Bohrung */
inline double Bohrung::getDiameter() const {
    return diameter;
}

void Bohrung::output(std::ostream& os) const {
    // os << "Bohrung: " << static_cast<const Komponente&>(*this)
    //    << ", Duchmesser: " << diameter;
    os << "Bohrung: ";
    Komponente::output(os);
    os << ", Duchmesser: " << diameter;
}

/* Definitions of methods for class Fraesung */
inline double Fraesung::getAngle() const {
    return angle;
}
inline double Fraesung::getEndX() const {
    return getX() + length * std::cos(angle);
}
inline double Fraesung::getEndY() const {
    return getY() + length * std::sin(angle);
}
void Fraesung::output(std::ostream& os) const {
    os << "Fraesung mit Start: ";
    Komponente::output(os);  // or Bohrung::Komponente::
    os << " und Endpunkt: (" << getEndX() << ", " << getEndY() << "), "
       << "Durchmesser: " << getDiameter();
}