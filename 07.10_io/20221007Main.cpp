//------------------------------------------------------------------
// 20221007Main.cpp
// Copyright 07.10.2022
// Author: KJR
//------------------------------------------------------------------
#include <iostream>

// C++ Zeienketten
#include <string>

// using namespace std;
using std::cout;
using std::endl;
using std::cin;


int main() {
  constexpr int N = 5;
  constexpr double mws = 1.19;

  double netto[N] = {0.0};
  double brutto[N] = {0.0};

  int n = 0;

  while (n < N) {
    cout << "Eingabe Netto Preis: ";
    cin >> netto[n];
    if (cin.good()) {
      brutto[n] = mws * netto[n];
      ++n; // schneller als n++;
    } else if (cin.eof()){
      break;
    } else if (cin.fail()){
      // Fehlerflag zuruecksetzen
      cin.clear();
      // Muell aus Eingabepuffer auslesen in ein C++ String:
      std::string muell;
      cin >> muell;
      std::cerr << "Fascheingabe: " << muell << endl;
    }
  }

  // Kontrollausgabe
  for(int i = 0; i < N; ++i){
    cout << netto[i] << endl;
  }

  // Hausaufgabe:
  // Erseten Sie die obige einfache Kontrollausgabe
  // durch eine formatierte Ausgabe als Tabelle, so
  // wie es in der Aufgabe auf S. 77 im Skript beschrieben ist

  // int n2 = n++;
  // int n2 = ++n;
  return 0;
}
