#ifndef BOHRUNG_HP
#define BOHRUNG_HP

#include "Komponente.hpp"

/* Bohrung */
class Bohrung : public Komponente {
  private:
    double diameter;

  public:
    explicit Bohrung(double x_ = 0.0, double y_ = 0.0, double diam = 6.0);
    double getDiameter() const;
    void output(std::ostream& os) const override;
    QJsonObject toJson() const override;
    ~Bohrung() override = default;
};

#endif //BOHRUNG_HP
