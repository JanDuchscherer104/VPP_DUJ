//------------------------------------------------------------------
// 20221021Main.cpp
// Copyright 20.10.2022
// Author: KJR
//------------------------------------------------------------------

// in C: #include<math.h>
#include <cmath>

#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;

double func(double x){
  return std::sqrt(x) / (1 + 2* x);
}

double trapez( double (*f)(double), double a, double b, int n){

  double h = (b-a) / n;
  double erg = 0;
  for (int i = 1; i < n; ++i){
    erg += f(a + i*h);
  }
  erg = h/2 * (f(a) + f(b) + 2*erg);
  return erg;
}

void printDreieck(int** p, int h) {
  for(int i = 0; i < h; ++i){
    for(int j = 0; j < i + 1; ++j){
      cout << std::setw(4) << p[i][j];
    }
    cout << endl;
  }
}

// HAUSAUFGABE: Funktion erstellen,
// die das Pascal-Dreieck mittels
// C-Funktionen malloc() und free()
// erstellt und ausdruckt (hierzu kann
// wieder die Funktion printDreieck()
// aufgerufen werden

void pascalDreieckMitNew(int h){
  int** p = new int*[h];

  for(int i = 0; i < h; ++i){
    p[i] = new int[i+1];
    for(int j = 0; j < i + 1; ++j){
      if (j == 0 || j == i) {
        p[i][j] = 1;

      } else {
        p[i][j] = p[i-1][j-1] + p[i-1][j];
      }
      //cout << p[i][j] << "  ";
    }
  }
  printDreieck(p, h);

  // Heap-Speicher frei geben
  for(int i = 0; i < h; ++i){
    delete [] p[i];
    p[i] = nullptr;
  }

  delete [] p;
  p = nullptr;
}

// Funktionspointer als neuen Typ definieren
using TfunPtr = double (*)(double);

int main() {

  double a = 1, b = 2;
  int n = 500;
  cout << "Integral 1 = "
       << trapez(std::sin, a, b, n)
       << endl;

  cout << "Integral 2 = "
       << trapez(func, a, b, n)
       << endl;

  // Verwendung einiger komplexerer Typen:
  // Feld mit Funktionspointern fuer die Integranden
  TfunPtr af[4] = {std::sin, func, std::cos, std::atan};
  cout << "Welche Funktionsnummer soll integriert werden: ";
  int nummer;
  cin >> nummer;
  cout << "Integral "
      << nummer
      << " = "
      << trapez(af[nummer], a, b, n)
      << endl;

  // Pointer auf das obige Feld von Funktionspointern
  // HAUSAUFGABE: Welchen Typ haette paf wenn die
  // runden Klammern weggelassen werden
  // TfunPtr *paf[4];
  TfunPtr (*paf)[4] = &af;
  cout << "Integral "
       << nummer
       << " = "
       << trapez((*paf)[nummer], a, b, n)
       << endl;

  // Auf dem Heap angelegtes Feld von Funktionspointern
  TfunPtr* pfp = new TfunPtr[4]{std::sin, func, std::cos, std::atan};
  cout << "Integral "
       << nummer
       << " = "
       << trapez(pfp[nummer], a, b, n)
       << endl;

  delete [] pfp;
  pfp = nullptr;

  //pascalDreieckMitNew(5);

  /*
  // Matrix mit Spaltenanzahl, die zur
  // Compile-Zeit bekannt sein muss
  constexpr int N = 3;
  int m;
  cout << "Eingabe Anzahl Zeilen: ";
  cin >> m;

  double (*mat)[N] = new double[m][N];
  int k = 1;
  for( int i = 0; i < m; ++i){
    for(int j = 0; j < N; ++j){
      mat[i][j] = k++;
    }
  }
  for( int i = 0; i < m; ++i){
    for( int j = 0; j < N; ++j){
      cout << std::setw(12) << std::setprecision(2)
           // << mat[i][j]; // Alternative fuer mat[i][j]?
           << *(*(mat + i)+j);
    }
    cout << endl;
  }
  delete[] mat; mat = nullptr;
  */

  /*
  // Anlegen von Heap-Speicher in C++
  // und Demonstration von Heob
  int* ip = new int{42};
  double* dp = new double{1.3e-2};
  cout << *ip << ", " << *dp << endl;
  delete ip;
  ip = nullptr;
  delete dp;
  dp = nullptr;
  */
  return 0;
}
