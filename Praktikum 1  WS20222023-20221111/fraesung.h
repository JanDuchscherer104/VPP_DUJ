#ifndef FRAESUNG_H
#define FRAESUNG_H

#include <iostream>

/* Komponente */
class Komponente {
   private:
    double x;
    double y;

   public:
    Komponente(double xPos = 0.0, double yPos = 0.0) : x{xPos}, y{yPos} {}
    double getX() const;
    double getY() const;
    virtual void output(std::ostream& os) const;
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
    Bohrung(double x_ = 0.0, double y_ = 0.0, double diam = 6.0)
        : Komponente{x_, y_}, diameter{diam} {}
    double getDiameter() const;
    virtual void output(std::ostream& os) const;
};

/* Fraesung */
class Fraesung : public Bohrung {
   private:
    double length;
    double angle;

   public:
    Fraesung(double x, double y, double diam, double l, double a = 0.0)
        : Bohrung{x, y, diam}, length{l}, angle{a} {}
    double getAngle() const;
    double getEndX() const;
    double getEndY() const;
    void output(std::ostream& os) const override;
};

#endif  // FRAESUNG_H