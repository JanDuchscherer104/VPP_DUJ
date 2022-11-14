#ifndef UHR_HPP
#define UHR_HPP
#include <iostream>

class Uhr {
   private:
    int h;
    int m;
    int s;

    static unsigned int obj_id;

    void checkAttributes();

   public:
    Uhr(int h, int m, int s) : h{h}, m{m}, s{s} { ++obj_id; }
    Uhr() Uhr(0, 0, 0) {}
    void tick();
    void displayClock() const;
    ~Uhr() {
        displayClock();
        std::cout << "del " << obj_id << std::endl;
        --obj_id;
    }
};

#endif  // UHR_HPP