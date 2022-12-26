#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include "buch.h"

// typedef std::vector<Buch> tBuch; // C style
using TBib = std::vector<Buch>;

Buch parseBook(const std::string& line) {
    std::string author, title;
    int year, rating;
    size_t p[3];
    size_t pos = 0;
    for (size_t& pi : p) {
        pi = line.find(';', pos + 1);
        if (pi == std::string::npos) {
            throw std::runtime_error("Delimiter not found in line " + line);
        }
        pos = pi;
    }
    author = line.substr(0, p[0]); // substring returns string between pos (^=start & pos + n chars)
    title = line.substr(p[0] + 1, p[1] - p[0] + 1);
    year = std::stoi(line.substr(p[1] + 1, p[1] - p[0] + 1)); // strToInt
    rating = std::stoi(line.substr(p[2] + 1, p[2] - p[1] + 1));
    std::cout << author << title << year << rating << std::endl;
    Buch ret{std::move(author), std::move(title), static_cast<size_t>(year), static_cast<size_t>(rating)};
    return ret;
}

void printUniqueAuthorNames(const TBib& bib) {
    std::set<std::string> uniques;
    for (auto& book : bib) {
        uniques.insert(book.getAutor());
    }
    for (auto& author : uniques) {
        std::cout << author << std::endl;
    }
}

void sortBooksByRating(TBib* const bib) { // const pointer
    std::function<bool (const Buch&, const Buch&)> fo = bib->back();
    std::sort(std::begin(*bib), std::end(*bib),
              //[](const Buch& a, const Buch& b) { return a.getBewertung() > b.getBewertung(); });
              //bib->back());
              fo);
}

std::map<size_t, TBib> sortBooksByYear(const TBib& bib) {
    std::map<size_t, TBib> bibMap;
    for (auto& book : bib) {
        bibMap[book.getJahr()].push_back(book);
    }
    for (auto& it : bibMap) {
        std::cout << "Year " << it.first << " : " << it.second.size() << " book(s):" << std::endl;
        sortBooksByRating(&it.second);
/*        for (const auto& book : it.second) {
            std::cout << "  " << book;
        }*/
    }
    return bibMap;
}

void readBib(const std::string& fn, TBib* bib) {
    std::ifstream file(fn, std::ios::in);
    if (!file) {
        throw std::runtime_error("Couldn't open file {" + fn + "}");
    }
    std::string line;
    while (file.good()) {
        std::getline(file, line);
        if (file.good()) {
            //std::cout << line << std::endl;
            bib->push_back(parseBook(line));
        } else if (file.eof()) {
            break;
        } else if (line.empty()) {
            continue;
        }
    }
    if (file) {
        file.close();
    }
}

int main() {
    std::string filename = "csWithRating.txt";
    TBib bib;
    readBib(filename, &bib);
    std::cout << std::endl << std::endl;
    for (const Buch& book : bib) {
        std::cout << "  " << book << std::endl;
    }
    printUniqueAuthorNames(bib);
    sortBooksByYear(bib);
    return 0;
}
