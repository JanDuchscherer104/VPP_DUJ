//------------------------------------------------------------------
// punkt3d.h
// Copyright 04.11.2022
// Author: KJR
//------------------------------------------------------------------
#ifndef PUNKT3D_H
#define PUNKT3D_H
#include <iostream>

// vordefinierte Exceptions
#include <stdexcept>

// Bemerkung
// Nur der Einfachheit halber werden hier viele
// Methoden inline innerhalb der Klassen-Definition
// definiert, sauberer und um Compile-Zeit zu sparen
// ist es in der Klassen-Definition
// nur den Prototypen anzugeben und die Implementierung
// in der zugehoerigen cpp-Datei vorzunehmen.
class Punkt3D {
 private:
  static const size_t DIM;
  double* koord;

 public:
  Punkt3D(double x, double y, double z)
      : koord{new double[DIM]{x, y, z}}
  {}

  // konvertierender Konstruktor
  // da kein explicit orangestellt
  Punkt3D(double wert)
      : koord{new double[DIM]{wert, wert, wert}}
  {}

  void output(std::ostream& os) const {
    os << "(" << koord[0] << ", "
       << koord[1] << ", "
       << koord[2] << ")";
  }

  // Indizierungs-Operator
  // L-Wert
  double& operator[](size_t i) {
    if (i < DIM) {
      return koord[i];
    } else {
      throw std::out_of_range("ERROR: ungueltiger index");
    }
  }

  // Indizierungs-Operator
  // R-Wert
  const double& operator[](size_t i) const {
    // Ausgabe nur um zu demonstrieren dass diese Version nur
    // fuer const-Objekte verwendet wird
    std::cout << "R-Wert" << std::endl;
    if (i < DIM) {
      return koord[i];
    } else {
      throw std::out_of_range("ERROR: ungueltiger index");
    }
  }

  // Insitu Addition
  Punkt3D& operator+=(const Punkt3D& a){
    for(size_t i = 0; i < DIM; ++i){
      koord[i] += a.koord[i];
    }
    return *this;
  }

  // Inkrement Operator
  // Praefix-Form
  Punkt3D& operator++() {
    for(size_t i = 0; i < DIM; ++i){
      ++koord[i];
    }
    return *this;
  }

  // Postfix-Form
  // fuer das Ueberladen ist der dummy Parameter
  // notwendig so dass sich die Signaturen unterscheiden
  // die Warnung unused Parameter laesst sich nicht
  // vermeiden.
  Punkt3D operator++(int dummy) {
    // Ausgabe nur um zu demonstrieren, dass das
    // C++ Laufzeitsystem ihn mit dem Aktualparameter 0
    // aufruft
    std::cout << "dummy = " << dummy << std::endl;
    // Es wird immer ein temporaeres Objekt benoetigt
    // deshalb ist die Postfix-Form in der Ausfuehrung
    // immer langsamer als die Praefix-Form
    Punkt3D erg{*this};
    ++*this;
    return erg;
  }

  // Big Three
  // Copy-Konstruktor
  Punkt3D(const Punkt3D& rhs)
      : koord{new double[DIM]{rhs.koord[0], rhs.koord[1], rhs.koord[2]}}
      // da in der Klasse auch der Indizierungs-Operator ueberladen wurde
      // kann alternativ auch dieser verwendet werden
      // : koord{new double[DIM]{rhs[0], rhs[1], rhs[2]}}
  {}

  // Copy-Zuweisungs-Operator
  Punkt3D& operator=(const Punkt3D& rhs) {
    // Test auf Selbstzweisung
    if (this != &rhs) {
      delete [] koord;
      koord = new double[DIM]{rhs.koord[0], rhs.koord[1], rhs.koord[2]};
      // da in der Klasse auch der Indizierungs-Operator ueberladen wurde
      // kann alternativ auch dieser verwendet werden
      // koord = new double[DIM]{rhs[0], rhs[1], rhs[2]};
    }
    return *this;
  }

  // Destruktor
  ~Punkt3D();

  // Ergaenzung der Big Three zu den Big Five
  // Move-Konstruktor
  Punkt3D(Punkt3D&& rhs)
      : koord{rhs.koord}
 {
    std::cout << "Move Konstruktor" << std::endl;
    rhs.koord = nullptr;
  }

  // Move-Zuweisungs-Operator
  Punkt3D& operator=(Punkt3D&& rhs) {
    std::cout << "Move Zuweisungs-Operator" << std::endl;
    if (this != &rhs) {
      delete [] koord;
      koord = rhs.koord;
      rhs.koord = nullptr;
    }
    return *this;
  }

};

// Ueberladen des Ausgabe-Operators als freie Funktion
// Um die One-Definition-Rule nicht zu verletzen hat man die
// beiden Moeglichkeiten:
// 1) nur Deklaration durch Angabe des Prototypen in der
//    Header-Datei, Implementierung in der cpp-Datei
// std::ostream& operator<<(std::ostream& os, const Punkt3D& p);

// 2) oder der Trick mit dem Schluesselwort inline
inline std::ostream& operator<<(std::ostream& os, const Punkt3D& p) {
  p.output(os);
  return os;
}

// binaere Addition als freie Funktion
inline Punkt3D operator+(const Punkt3D& a, const Punkt3D& b){
  Punkt3D erg{a};
  erg += b;
  return erg;
}

#endif // PUNKT3D_H
