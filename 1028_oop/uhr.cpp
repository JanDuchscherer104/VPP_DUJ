//------------------------------------------------------------------
// Uhr
// Copyright 28.10.2022
// Author: KJR
//------------------------------------------------------------------
#include <iostream>
#include <iomanip>

#include "uhr.h"

// Definition der Klassenvariablen ausserhalb der
// Klassendefinition in der cpp-Datei
int Uhr::SDEFAULT = 42;

// Definition der Klassen-Methode
int Uhr::getSdefault() {
  return SDEFAULT;
}

void Uhr::displayClock() const{
    std::cout << std::setw(2) << this->stunden << ":"
              << std::setw(2) << minuten << ":"
              << std::setw(2) << sekunden << std::endl;
}

// Destruktor mit leerer Implementierung
Uhr::~Uhr()
{

}
