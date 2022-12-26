#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include <cstdlib>

int main() {
    std::string filename{"test.txt"};
    std::ofstream file(filename, std::ios::out);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    std::string print = "Hello World!";
    for(int i = 0; i < print.length(); ++i) {
        file << i << " ";
        for (int j = 0; j < i; ++j) {
            file << print[j];
        }
        file << std::endl;
    }
    // file << print << std::endl;
    if(file.is_open()) {
        file.close();
    }

    std::ifstream file2(filename, std::ios::in);
    if (!file2.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    int count;
    std::string line;
    while (!file2.bad()) {
        if (file2.good()) {
        file2 >> count >> line;
        } else if (file2.eof()) {
            break;
        } else if (file2.fail()) {
            file2.clear();
        }
        std::cout << line << std::endl;
    }

    return 0;
}
