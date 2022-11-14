//------------------------------------------------------------------
// Uhr
// Copyright 28.10.2022
// Author: KJR
//------------------------------------------------------------------
#ifndef UHR_H
#define UHR_H
#include <initializer_list>
#include <iostream>


class Uhr {
 private:
  // Klassenvariable default-Wert fuer Sekunden
  static int SDEFAULT;

  // Attribute
  int stunden;
  int minuten;
  int sekunden;

  // private Hilfsmethode
  void checkAttributes(){
    if (stunden < 0 || stunden >= 24){
      stunden = 0;
    }
    if (minuten < 0 || minuten >= 60){
      minuten = 0;
    }
    if (sekunden < 0 || sekunden >= 60){
      sekunden = SDEFAULT;
    }
  }


 public:
  // Klassen-Methode
  static int getSdefault();

  // Member-Methoden
  void displayClock() const;

  // HAUSAUFGABE:
  // ergaenzen Sie die Klasse um alle im UML-Diagramm
  // aufgefuehrten Methoden, die noch nicht implementiert wurden.
  // tick() soll die Sekunden um 1 hochzaehlen, Tipp dies erfordert
  // in manchen Faellen auch die Werte der Attribute minuten und
  // stunden anzupassen, warum?

  // Konstruktoren
  // Konstruktor mit Parametern
  // Implementierung innerhaln der Klasse
  // deshalb inline
  // ist konvertierend
  // Uhr(int h, int m=0, int s=0)
  // nicht konvertierend durch explicit
  explicit Uhr(int h, int m=0, int s=0)
     // Memeberinitialisierungsliste
      :  stunden{h}, minuten{m}, sekunden{s}
  {
    /*
    // so nicht besser Memeberinitialisierungsliste verwenden
    stunden = h;
    minuten = m;
    sekunden = s;
    */
    checkAttributes();
  }

  // Compiler anfordern den Standard-Konstruktor zu erstellen
  // Uhr() = default;

  // eignenerstellter Standard-Konstruktor als
  // deligierender Konstruktor
  Uhr()
     // Aufruf in der Memeberinitialisierunsliste
      : Uhr(1, 2, 3)
  {
    // so nicht, dies erstellt nur ein
    // tempraeres Uhr-Objekt und initialisiert NICHT this
    // Uhr(1, 2, 3);
  }

  // Sequenzkonstruktor
  Uhr(std::initializer_list<int> list) {
    std::cout << "Sequenzkonstruktor" << std::endl;
    auto it = list.begin();
    if(it != list.end()){
      stunden = *it;
      ++it;
    }
    if(it != list.end()){
      minuten = *it;
      ++it;
    }
    if(it != list.end()){
      sekunden = *it;
      ++it;
    }
    checkAttributes();
  }

  ~Uhr();
};

#endif // UHR_H
