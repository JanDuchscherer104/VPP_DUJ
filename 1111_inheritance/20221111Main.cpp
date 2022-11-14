//------------------------------------------------------------------
// 20221111Main.cpp
// Copyright 10.11.2022
// Author: KJR
//------------------------------------------------------------------
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

class Lebewesen {
   private:
    int alter;

   public:
    Lebewesen(int a) : alter{a} {}

    int getAlter() const {
        return alter;
    }

    // Da die Klasse Lebewesen als Basisklasse
    // sehr allgemein ist, kann man die folgenden
    // Methden nicht sinnvoll implementieren.
    // In C++ kann man z. B. durch
    // virtual void gibLaut() const = 0;
    // sie als rein virtuelle Methoden deklarieren, die
    // nicht implementiert werden muessen

    // Ohne virtual findet statische Bindung statt:
    // z.B.:
    // void gibLaut() const { ..... }
    // arbeitet man mit Basis-Klassen Poinern oder Referenzen
    // werden dann nicht die Methoden der Unterklassen aufgerufen
    // wenn der Pointer oder die Referenz auf ein Objekt vom Typ der
    // Unterklasse verweist, deshalb werden alle ueberschriebenen Methoden
    // als virtual deklariert

    // Virtuelle Methoden:
    virtual void gibLaut() const {
        cout << "hust hust" << endl;
    }

    virtual double getLebensAlter() const {
        return alter;
    }

    virtual void output(std::ostream& os) const {
        os << "Alter: " << alter << endl;
    }

    // Bei einer Basisklasse sollte auch der Desktruktor
    // als virtual deklariert werden, damit bei der Verwendeung
    // von Basisklassen-Pointern/Referenzen der zum Objekt passende
    // Destruktor aufgerufen wird
    virtual ~Lebewesen() {}
};

class Hund : public Lebewesen {
   private:
    double gewicht;

   public:
    Hund(int a, double g) : Lebewesen{a}, gewicht{g} {
    }

    // Beim Ueberschreiben muss die Signatur genau uebereinstimmen
    // durch das Schluesselwort override kann man den Compiler auffordern
    // dies zu ueberpruefen
    void gibLaut() const override {
        cout << "wau wau" << endl;
    }

    double getLebensAlter() const override {
        return getAlter() * 5.5;
    }

    void output(std::ostream& os) const override {
        os << "Hund:" << endl;
        Lebewesen::output(os);
        os << "Gewicht: " << gewicht << endl;
    }
    ~Hund() {}
};

class Wellensittich : public Lebewesen {
   private:
    char geschlecht;

   public:
    Wellensittich(int a, char g) : Lebewesen{a}, geschlecht{g} {}

    void gibLaut() const override {
        cout << "piep piep" << endl;
    }

    double getLebensAlter() const override {
        return getAlter() * 12.9;
    }
    void output(std::ostream& os) const override {
        os << "Wellensittich:" << endl;
        Lebewesen::output(os);
        os << "Geschlecht: " << geschlecht << endl;
    }
    ~Wellensittich() {}

    // Methode die es nicht in der Basis-Klasse gibt,
    // sie kann deshalb nicht ueber einen Basisklassen-Pointer/Referenz
    // aufgerufen werden, vielmehr ist ein Down-Cast erforderlich, siehe main()
    void pick() const {
        cout << "pick pick" << endl;
    }
};

// Ueberladen des Ausgabe-Operators
std::ostream& operator<<(std::ostream& os, const Lebewesen& le) {
    le.output(os);
    return os;
}

int main() {
    Hund struppi{2, 12.8};
    Wellensittich hansi{1, 'm'};
    Hund rex{7, 33.4};

    cout << struppi << endl;
    // Statische Bindung
    struppi.gibLaut();

    // Liskovsches Ersetzungsprinzip:
    // Basisklassen-Pointer/Referenz kann auf alle
    // Objekte vom Typ einer Unterklasse verweisen
    Lebewesen& le = hansi;
    // dynamische Bindung
    le.gibLaut();

    // Zum Aufruf der Methode pick() ist ein
    // Down-cast erforderlich
    dynamic_cast<Wellensittich&>(le).pick();

    // Down-cast scheitert, da die Basisklassen-Referenz
    // nun auf ein Hund-Objekt verweist, es wird eine bad_cast
    // exception ausgeworfen
    // Lebewesen& rle = rex;
    // dynamic_cast<Wellensittich&>(rle).pick();

    // Dynamische Bindung mit Basisklassen-Pointer
    Lebewesen* ple = &struppi;
    ple->gibLaut();  // (*ple).gibLaut();

    ple = &hansi;

    // mit ple kann pick() nicht aufgerufen werden
    // ple->pick();
    // Es wird ein Down-Cast benoetigt
    Wellensittich* pw = dynamic_cast<Wellensittich*>(ple);
    pw->pick();

    // Down-Cast ist nicht immer moeglich
    // Hier zeigt der Basisklassen-Pointer auf ein Hund-Objekt
    // ein Down-Cast nach Wellensittich* scheitert
    ple = &rex;
    pw = dynamic_cast<Wellensittich*>(ple);
    // Ergebnis ist ein nullprt
    if (pw == nullptr) {
        cout << "kein Wellensittich" << endl;
    }

    // Polymorphie
    // Verschiedenartige Objekte werden gleichartig
    // behandelt, aber trotzdem automatisch die genau zum
    // jeweiligen Objekt passende Aktion ausgefuehrt
    // Alle Tiere in einem STL-Vektor speichern
    std::vector<Lebewesen*> meinZoo;
    meinZoo.push_back(&struppi);
    meinZoo.push_back(&hansi);
    meinZoo.push_back(&rex);

    // Alle Tiere geben laut:
    for (auto l : meinZoo) {
        l->gibLaut();
    }

    // Nur fuer die Hund-Objekte das Lebens-Alter ausgeben
    // durchlaufen mit Iterator
    /*
    for(auto it = meinZoo.begin(); it != meinZoo.end(); ++it){

    }
    */
    /*auto it = meinZoo.begin();
    while(it != meinZoo.end()){
      // Ausgabe des Objektes
      cout << **it << endl;
      Hund* ph = dynamic_cast<Hund*>(*it);
      if (ph != nullptr){
        cout << "Lebensalter: " << ph->getLebensAlter() << endl;
      }
      ++it;
    }*/
    for (auto it : meinZoo) {
        // Ausgabe des Objektes
        cout << *it << endl;
        Hund* ph = dynamic_cast<Hund*>(it);
        if (ph != nullptr) {
            cout << "Lebensalter: " << ph->getLebensAlter() << endl;
        }
    }
    return 0;
}
