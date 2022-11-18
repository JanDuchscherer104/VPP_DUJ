#ifndef KOMPONENTEN_LIST_H
#define KOMPONENTEN_LIST_H

#include <iostream>

#include "fraesung.hpp"

/* KomponentenElement */
struct KomponentenElement {
  Komponente* k;
  KomponentenElement* before;
  KomponentenElement* next;

  explicit KomponentenElement(Komponente* k = nullptr);
};

/* KomponentenList */
class KomponentenList {
  private:
    size_t m_counter{0};
    KomponentenElement* m_first{nullptr};
    KomponentenElement* m_head{nullptr};
    static bool s_verbose;

    KomponentenElement* getElement(size_t pos) const;

  public:
    KomponentenList() = default;
    size_t size() const; //inline causes error
    Komponente const* at(size_t pos) const;
    int erase(size_t pos);
    void push_back(Komponente* k);
    KomponentenElement* begin() const;
    KomponentenElement* end() const;
    void output(std::ostream& os) const;
    ~KomponentenList();
};

inline std::ostream& operator<<(std::ostream& os, const KomponentenList& kl) {
    kl.output(os);
    return os;
}

#endif  // KOMPONENTEN_LIST_H
