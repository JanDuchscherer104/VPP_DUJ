#ifndef WERKSTUECK_HPP
#define WERKSTUECK_HPP

#include "Komponente.hpp"
#include "Iterator.hpp"
#include "DeList.hpp"

class Werkstueck : public Komponente {
  private:
    double height;
    double width;
    bool pathIsOptimized;
    DeList komponenten;

    Iterator getNearest(const IKomponente* pk) const;

  public:
    Werkstueck(double xPos = 0.0, double yPos = 0.0, double h = 1, double w = 1);
    double getHeight() const;
    double getWidth() const;
    void add(IKomponente* k);
    void remove(const IKomponente* k);
    const IKomponente* getChild(int i) const;
    double calcTotalPath() const override;
    double calcPathLength() const;
    void optimizePath();
    void output(std::ostream& os) const override;
    ~Werkstueck() override;
};

#endif //WERKSTUECK_HPP
