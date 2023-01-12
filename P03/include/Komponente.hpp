#ifndef KOMPONENTE_HPP
#define KOMPONENTE_HPP

#include "IKomponente.hpp"

class QJsonObject;

/* Komponente */
class Komponente : public IKomponente {
  private:
    double x;
    double y;
    const IKomponente* parent;

  public:
    explicit Komponente(double xPos = 0.0, double yPos = 0.0);
    double calcTotalPath() const override;
    double getX() const override;
    double getY() const override;
    double getXAbsolute() const override;
    double getYAbsolute() const override;
    double distance(const IKomponente* k) const override;
    const IKomponente* getParent() const override;
    void setParent(const IKomponente* p) override;
    void output(std::ostream& os) const override;
    QJsonObject toJson() const override;
    ~Komponente() override = default;
};

#endif //KOMPONENTE_HPP
