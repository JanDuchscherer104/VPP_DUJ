//------------------------------------------------------------------
// 20221028Main.cpp
// Copyright 27.10.2022
// Author: KJR
//------------------------------------------------------------------
#include <iostream>
#include <vector>
#include "uhr.h"

using std::cout;
using std::endl;

int main()
{
  // Aufruf der Klassen-Methode
  // ohne ein Objekt zu erstellen
  cout << Uhr::getSdefault() << endl;


  // Erstellung eine Objektes auf Stack
  // mittels Standard-Konstruktor den der
  // Compiler erstellt, wenn kein anderer
  // Konstruktor vorhanden ist
  Uhr u1;
  u1.displayClock();

  // Konstruktor mit Parametern
  // Vorsicht Aufruf des Sequenzkonstuktors wenn vorhanden
  // Uhr u2{12, 13, 99};

  // Aufruf des Konstruktors mit Parametern
  Uhr u2(12, 13, 99);
  u2.displayClock();

  // Bsp fuer Konvertierung
  // verboten durch explicit
  // Uhr u3 = 2.3;
  // Uhr u3{2.3};
  // Uhr u3{2};
  Uhr u3(2);
  // Uhr u3(2.3);
  u3.displayClock();



  /*
  // Motivation Iterator-Konzept

  double vec[5] = {1.2, 2.3, 3.4, 4.5, 5.6};

  // Durchlaufen aller Elemente mit Pointer
  double* pIt = vec; // begin Position
  double* pEnd = vec + 5; // end Position
  while ( pIt != pEnd) {
    cout << *pIt << endl;
    ++pIt;
  }

  // Durchlaufen mit Iterator
  cout << "Ausgabe mit Iterator" << endl;
  auto it = std::begin(vec);
  while (it != std::end(vec)) {
    cout << *it << endl;
    ++it;
  }

  // Funktioniert auch fuer alle Container der STL
  cout << "Ausgabe von Container vector mit Iterator" << endl;
  std::vector<double> v{1.2, 2.3, 3.4, 4.5, 5.6};
  //auto it2 = v.begin();
  std::vector<double>::iterator it2 = v.begin();
  while (it2 != v.end()) {
    cout << *it2 << endl;
    ++it2;
  }

  // Durchlaufen mit Bereichsbasierter Schleife
  // wird vom Compiler mit Iterator umgesetzt
  cout << "Ausgabe von Container mit Bereichsbasierter Schleife" << endl;
  for(auto e: v){
    cout << e << endl;
  }

  // Addition von 1 zu allen Elementen mittels Referenz
  for(auto& e: v){
    e = e + 1;
  }

  for(auto e: v){
    cout << e << endl;
  }

  */
  return 0;
}
