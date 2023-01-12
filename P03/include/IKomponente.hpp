#ifndef IKOMPONENTE_HPP
#define IKOMPONENTE_HPP

#include <iostream>

class QJsonObject;

/* Komponente */
class IKomponente {
  public:
    // explicit IKomponente() = delete; //TODO
    virtual double calcTotalPath() const = 0;
    virtual double getXAbsolute() const = 0;
    virtual double getYAbsolute() const = 0;
    virtual double getX() const = 0;
    virtual double getY() const = 0;
    virtual double distance(const IKomponente* k) const = 0; // read-only ptr, not a const ptr
    virtual const IKomponente* getParent() const = 0;
    virtual void setParent(const IKomponente* p) = 0;
    virtual void output(std::ostream& os) const = 0;
    virtual QJsonObject toJson() const = 0;
    virtual ~IKomponente() = default;
};

inline std::ostream& operator<<(std::ostream& os, const IKomponente& k) { //TODO static inline?
    k.output(os);
    return os;
}

#endif // IKOMPONENTE_HPP
