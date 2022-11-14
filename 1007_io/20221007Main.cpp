//------------------------------------------------------------------
// 20221007Main.cpp
// Copyright 07.10.2022
// Author: KJR
//------------------------------------------------------------------
#include <iomanip>
#include <iostream>

// C++ Zeienketten
#include <string>

int main() {
    constexpr int N = 5;
    constexpr double mws = 1.19;

    double netto[N] = {0.0};
    double brutto[N] = {0.0};
    double sum;

    int n = 0;

    while (n < N) {
        std::cout << "Eingabe Netto Preis: ";
        std::cin >> netto[n];
        if (std::cin.good()) {
            brutto[n] = mws * netto[n];
            ++n;  // schneller als n++;
        } else if (std::cin.eof()) {
            break;
        } else if (std::cin.fail()) {
            // Fehlerflag zuruecksetzen
            std::cin.clear();
            // Muell aus Eingabepuffer auslesen in ein C++ String:
            std::string muell;
            std::cin >> muell;
            std::cerr << "Fascheingabe: " << muell << std::endl;
        }
    }

    // Kontrollausgabe
    for (int i = 0; i < N; ++i) {
        std::cout << std::left << std::setw(4) << i << "|";
        std::cout << std::right << std::setw(8) << std::fixed << std::setprecision(2) << netto[i];
        std::cout << "  |  " << brutto[i] << std::endl;
        sum += brutto[i];
    }
    std::cout << "SUM | " << std::setw(16) << sum << std::endl;

    return 0;
}
