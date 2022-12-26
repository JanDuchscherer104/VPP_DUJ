//
// Created by Jan Duchscherer on 18.11.22.
//

#include <iostream>
#include <complex>
#include <stdexcept>

class IZweipol {
  public:
    virtual std::complex<double> impedanz(double w) const = 0;
    virtual ~IZweipol() = default;
};

class R : public IZweipol {
  private:
    double r;
  public:
    explicit R(double r) : r{r} {}
    std::complex<double> impedanz(double) const override {
        //return static_cast<std::complex<double>>(r);
        return {r, 0.0};
    }
};

class L : public IZweipol {
  private:
    double l;
  public:
    explicit L(double l) : l{l} {}
    std::complex<double> impedanz(double w) const override {
        return {0, w * l};
    }
};

class C : public IZweipol {
  private:
    double c;
  public:
    explicit C(double c) : c{c} {}
    std::complex<double> impedanz(double w) const override {
        return {0, -1 / (w * c)};
    }
};

class Schaltung : public IZweipol {
  private:
    IZweipol* elemente[2];

    static void checkIdx(size_t idx) {
        if (idx > 1) {
            throw std::out_of_range("Given index out of range!");
        }
    }
  protected:
    void checkChild() const {
        if (!elemente[0] || !elemente[1]) {
            throw "ERROR: elemente[idx] is nullptr!";
        }
    }

  public:
    Schaltung(IZweipol* s1, IZweipol* s2)
        : elemente{s1, s2} {}

    void add(IZweipol* e, size_t idx) {
        checkIdx(idx);
        if (!elemente[idx]) {
            elemente[idx] = e;
        } else {
            throw "ERROR: elemente[idx] is not empty!";
        }

    }
    void remove(size_t idx) {
        if (idx < 2) {
            elemente[idx] = nullptr;
        } else {
            throw std::out_of_range("Given index out of range!");
        }
    }
    IZweipol* getChild(size_t idx) const {
        checkIdx(idx);
        return elemente[idx];
    }
};

class SerSchaltung : public Schaltung {
  public:
    explicit SerSchaltung(IZweipol* s1, IZweipol* s2) : Schaltung(s1, s2) {}
    std::complex<double> impedanz(double w) const override {
        checkChild();
        return getChild(0)->impedanz(w) + getChild(1)->impedanz(w);
    }
};

class ParSchaltung : public Schaltung {
  public:
    explicit ParSchaltung(IZweipol* s1, IZweipol* s2) : Schaltung(s1, s2) {}
    std::complex<double> impedanz(double w) const override {
        checkChild();
        std::complex<double> one {1, 0};
        return one / (one / getChild(0)->impedanz(w) + one / getChild(1)->impedanz(w));
    }
};

int main() {
    R r1{50};
    R r2{300};
    R r3{20};
    L l1{1};
    L l2{1.5};
    C c1{10e-6};
    double w = 300;
    SerSchaltung s1{&r3, &l2};
    SerSchaltung s2{&r2, &c1};
    SerSchaltung s3{&r1, &l1};
    ParSchaltung p1{&s1, &s2};
    SerSchaltung s4{&s3, &p1};
    std::cout << "impedanz of s4: " << s4.impedanz(w) << std::endl;
    return 0;
}
