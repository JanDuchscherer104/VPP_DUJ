#include "../include/Bohrung.hpp"
#include <iostream>
#include <QJsonObject>

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
//TODO
/* if inline:
  Undefined symbols for architecture arm64:
  "Bohrung::getDiameter() const", referenced from:
      Fraesung::output(std::__1::basic_ostream<char, std::__1::char_traits<char> >&) const in Fraesung.cpp.o
ld: symbol(s) not found for architecture arm64
clang: error: linker command failed with exit code 1 (use -v to see invocation)*/

void Bohrung::output(std::ostream& os) const {
    os << "Bohrung: ";
    Komponente::output(os);
    os << ", Durchmesser: " << diameter;
}
QJsonObject Bohrung::toJson() const {
    QJsonObject ret;
    ret = Komponente::toJson();
    ret["type"] = "Bohrung";
    ret["diameter"] = diameter;
    return ret;
}
