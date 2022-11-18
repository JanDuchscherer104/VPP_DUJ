//
// Created by Jan Duchscherer on 18.11.22.
//

#include <iostream>
#include <complex>

class IZweipol {
  public:
    virtual std::complex<double> impedanz(double w) const = 0;
    virtual ~IZweipol() = default;
};

class R : public IZweipol {
  private:
    double r;
  public:
    explicit R(double r): r{r} {}
    std::complex<double> impedanz(double) const override{
        //return static_cast<std::complex<double>>(r);
        std::complex<double>(r, 0.0);
    }
};

class L: public IZweipol {
  private:
    double l;
  public:
    explicit L(double l): l{l} {}
    std::complex<double> impedanz(double w) const override{
        return std::complex<double>(0, w * l);
    }
};

class C: public IZweipol {
  private:
    double c;
  public:
    explicit C(double c): c{c} {}
    std::complex<double> impedanz(double w) const override{
        return std::complex<double>(0, -1 / (w * c));
    }
};

class Schaltung {
  private:
    IZweipol* elemente[2];
  public:
    void add()

};


int main() {
    R r0{10};
    return 0;
}
