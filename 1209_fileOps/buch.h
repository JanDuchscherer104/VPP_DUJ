//------------------------------------------------------------------
// Buch
// Copyright 02.06.2019
// Author: KJR
//------------------------------------------------------------------
#ifndef BUCH_H
#define BUCH_H
#include <iostream>
#include <string>

class Buch {
  private:
    std::string autor;
    std::string titel;
    size_t jahr;
    size_t bewertung;

  public:
    Buch(std::string&& a, std::string&& t, size_t j, size_t b)
        : autor{a}, titel{t}, jahr{j}, bewertung{b} {}

    std::string getAutor() const { return autor; }
    std::string getTitel() const { return titel; }
    size_t getJahr() const { return jahr; }
    size_t getBewertung() const { return bewertung; }
    void output(std::ostream& os) const {
        os << autor << ", " << titel << ", " << jahr << ", " << bewertung
           << std::endl;
    }
    bool operator()(const Buch& a, const Buch& b) const {
        return getBewertung() > b.getBewertung();
    }
    ~Buch() = default;
};

std::ostream& operator<<(std::ostream& os, const Buch& b) {
    b.output(os);
    return os;
}

#endif  // BUCH_H
