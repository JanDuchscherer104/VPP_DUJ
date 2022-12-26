#ifndef IKOMPONENTENELEMENT_HPP
#define IKOMPONENTENELEMENT_HPP

//#include "IKomponente.hpp"

class IKomponente;

struct IKomponentenElement {
  IKomponente* k;
  IKomponentenElement* before;
  IKomponentenElement* next;

  explicit IKomponentenElement(IKomponente* k = nullptr)
      : k{k}, before{nullptr}, next{nullptr} {}
};

#endif //IKOMPONENTENELEMENT_HPP
