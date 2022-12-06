#ifndef FRAESUNG_HPP
#define FRAESUNG_HPP

#include "Bohrung.hpp"
#include <iostream>

/* Fraesung */
class Fraesung : public Bohrung {
  private:
    double length;
    double angle;

  public:
    Fraesung(double x, double y, double diam, double l, double a = 0.0);
    Fraesung(double xB, double yB, double diam, double xE, double yE, double dummy);
    double getLength() const;
    double getAngle() const;
    double getEndX() const;
    double getEndY() const;
    double calcTotalPath() const override;
    void output(std::ostream& os) const override;
    ~Fraesung() override = default;
};

#endif  // FRAESUNG_HPP
