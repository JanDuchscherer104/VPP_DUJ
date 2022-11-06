#include <iostream>
#include <iomanip>

int main(void) {
    constexpr int N = 5;
    constexpr float mws = 1.19;

    double netto[5] = {0.0};
    double brutto[5] = {0.0};
    int n = 0;
    float sum = 0;

    while (n < 5) {
        std::cout << "Enter net price: ";
        std::cin >> netto[n];
        if (std::cin.good()) {
            brutto[n] = netto[n] * mws;
            sum += brutto[n];
            ++n;
        }
        else if (std::cin.eof()) {
            break;
        }
        else if (std::cin.fail()) {
            std::cin.clear();
            std::string muell;
            std::cin >> muell;
            std::cerr << "Fascheingabe: " << muell << std::endl;
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < N; ++i) {
        std::cout << std::left << std::setw(4) << i << "|";
        std::cout << std::right << std::setw(8) << std::fixed << std::setprecision(2) << netto[i];
        std::cout << "  |  " << brutto[i] << std::endl;
    }
    std::cout << "SUM | " << std::setw(17) << sum << std::endl;
    return 0;
}