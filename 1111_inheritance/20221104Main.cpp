//------------------------------------------------------------------
// 20221104Main.cpp
// Copyright 04.11.2022
// Author: KJR
//------------------------------------------------------------------
#include <iostream>
#include "punkt3d.h"

using std::cout;
using std::endl;

int main() {

  // Objekt auf Stack bis auf mit new angelegter Heap-Speicher
  // fuer die Koordinaten
  Punkt3D p1{1, 2, 3};
  cout << p1 << endl;

  // R-Wert Version wird auch hier nicht verwendet
  // da Objekt nicht konstant
  cout << "y-Komponente: " << p1[1] << endl;

  // L-Wert
  p1[2] = 99;
  cout << p1 << endl;

  // Verwendung der R-Wert Version fuer const Objekt
  const Punkt3D cp2{2};
  cout << "y-Komponente: " << cp2[1] << endl;

  // Objekt auf Heap
  Punkt3D* pp = new Punkt3D{42};
  cout << *pp << endl;
  delete pp;
  pp = nullptr;

  // Konvertierender Konstruktor
  Punkt3D p2 = 4711;
  cout << p2 << endl;

  // Notwendigkeit den Copy-Konstruktor selber zu
  // implementieren
  // Punkt3D p3{p2};
  Punkt3D p3 = p2;  // Aufruf des Copy-Konstruktors
  cout << p3 << endl;

  p3 = p2;  // Aufruf des Copy-Zuweisungsoperators
  p3[1] = 99;
  cout << "p2 = " << p2 << endl;
  cout << "p3 = " << p3 << endl;

  // Insitu Addition
  p3 += p2;
  cout << "p3 = " << p3 << endl;

  // Arithmetik mit gemischten Typen
  // (Punkt3D und int/double) ist aufgrund der
  // Existenz des konvertierenden Konstruktors
  // moeglich
  Punkt3D p4 = p1 + 1;
  cout << "p4 = " << p4 << endl;

  // Postfix Inkrement
  Punkt3D i = 3;
  Punkt3D j = i++;
  cout << "j = " << j << endl;
  cout << "i = " << i << endl;

  // Praefix Inkrement
  j = ++i;
  cout << "j = " << j << endl;
  cout << "i = " << i << endl;

  // Move-Konstruktor
  // ueber std::move() kann man dem Compiler mitteilen,
  // das ein Objekt verschiebbar ist, im wesentlichen
  // ist es in unserem Fall der Cast
  // (Punkt3D&&)(p2 + 2);
  // bzw in C++ Syntax der Cast
  // static_cast<Punkt3D&&>(p2 + 2);
  // dies verhindert dann allerdings die copy elison
  // Optimierung des Compilers, der sonst implizit
  // direkt im Objekt p5 das temporaere Objekt erstellt
  Punkt3D p5 = std::move(p2 + 2);
  cout << p5 << endl;

  // Move Zuweisung
  p5 = p2 + 4;
  cout << p5 << endl;

  return 0;
}
