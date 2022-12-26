#ifndef FRAESUNG_H
#define FRAESUNG_H

#include <iostream>

/* Komponente */
class Komponente {
  private:
    double x;
    double y;

  public:
    explicit Komponente(double xPos = 0.0, double yPos = 0.0);
    double getX() const;
    double getY() const;
    virtual void output(std::ostream& os) const;
    virtual ~Komponente() = default;
};

inline std::ostream& operator<<(std::ostream& os, const Komponente& k) {
    k.output(os);
    return os;
}

/* Bohrung */
class Bohrung : public Komponente {
  private:
    double diameter;

  public:
    explicit Bohrung(double x_ = 0.0, double y_ = 0.0, double diam = 6.0);
    double getDiameter() const;
    void output(std::ostream& os) const override;
    ~Bohrung() override = default;
};

/* Fraesung */
class Fraesung : public Bohrung {
  private:
    double length;
    double angle;

  public:
    Fraesung(double x, double y, double diam, double l, double a = 0.0);
    double getLength() const;
    double getAngle() const;
    double getEndX() const;
    double getEndY() const;
    void output(std::ostream& os) const override;
    ~Fraesung() override = default;
};

#endif  // FRAESUNG_H
