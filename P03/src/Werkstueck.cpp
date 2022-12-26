#include "../include/Werkstueck.hpp"
#include "../include/Iterator_impl.hpp"
#include "../include/DeList_impl.hpp"
#include <stdexcept>
#include <string>

/* Werkstuek ~ public methods */
Werkstueck::Werkstueck(double xPos, double yPos, double h, double w)
    : Komponente(xPos, yPos), height{h}, width{w}, pathIsOptimized{false}, komponenten{} {}

inline double Werkstueck::getHeight() const {
    return height;
}

inline double Werkstueck::getWidth() const {
    return width;
}

void Werkstueck::add(IKomponente* k) {
    k->setParent(this);
    komponenten.push_back(k);
    pathIsOptimized = false;
}

void Werkstueck::remove(const IKomponente* k) {
    for (Iterator<IKomponente*> it = komponenten.begin(); it != komponenten.end(); ++it) {
        if (k == *it) {
            (*it)->setParent(nullptr);
            komponenten.erase(it);
            pathIsOptimized = false;
            break;
            /*if (komponenten.erase(it)) {
                std::cout << "Could not erase IKomponente k from komponeten!" << std::endl;
            } else {
                //(*it)->setParent(nullptr);
            }*/
        }
    }
}

const IKomponente* Werkstueck::getChild(int i) const {
    IKomponente* ret;
    if (i < 0 || i >= komponenten.size()) {
        // std::cout << "ERROR:  Given index out of range!" << std::endl;
        ret = nullptr;
    } else {
        int iCnt = 0;
        for (IKomponente* it : komponenten) {
            if (iCnt == i) {
                ret = it;
                break;
            }
            ++iCnt;
        }
    }
    return ret;
}

double Werkstueck::calcPathLength() const {
    Iterator<IKomponente*> it = komponenten.begin();
    Iterator<IKomponente*> prevIt;
    double pathLength = this->distance(*it);
    while (it != komponenten.end()) {
        prevIt = it;
        pathLength += (*it)->distance(*(++it));
    }
    pathLength += this->distance(*prevIt);
    return pathLength;
}

double Werkstueck::calcTotalPath() const {
    double totalPath = this->calcPathLength();
    for (IKomponente* it : komponenten) {
        totalPath += it->calcTotalPath();
    }
    return totalPath;
}

/*
 * @brief reorders all children stored in this->komponenten so that the euclidean distance between
 *        adjacent elements is  minimized
 *
 */
void Werkstueck::optimizePath() {
    if (!pathIsOptimized && komponenten.size()) {
        for (IKomponente* it : komponenten) {
            if (auto* childWerkstueck = dynamic_cast<Werkstueck*>(it)) {
                childWerkstueck->optimizePath(); // optimize path of all childs that are a an instance of Werkstueck
            }
        }

        DeList<IKomponente*> sortedKomponents{};
        IKomponente* current;
        for (Iterator<IKomponente*> nearest{getNearest(this)}; komponenten.size() > 0; nearest = getNearest(current)) {
            sortedKomponents.push_back(*nearest);
            current = *nearest;
            komponenten.erase(nearest);
        }
        komponenten = sortedKomponents;
        pathIsOptimized = true;
    }
}

void Werkstueck::output(std::ostream& os) const {
    std::string spaces;
    const IKomponente* parent;
    parent = Komponente::getParent();
    while (parent) { // indentation-depth
        spaces += "  ";
        parent = parent->getParent();
    }
    os << spaces << "Werkstueck:" << std::endl << spaces << "Verankerung: ";
    Komponente::output(os);
    os << std::endl << spaces << "height: " << getHeight() << ", width: " << getWidth() << std::endl
       << spaces << "Komponenten: " << std::endl;
    for (IKomponente* it : komponenten) {
        if (auto* childWerkstueck = dynamic_cast<Werkstueck*>(it)) {
            childWerkstueck->output(os);
        } else {
            os << spaces << *it << std::endl;
        }
    }
}

Werkstueck::~Werkstueck() {
    komponenten.clear();
}

/* Werkstueck ~ private methods */
Iterator<IKomponente*> Werkstueck::getNearest(const IKomponente* pk) const {
    if (!pk) {
        throw std::runtime_error("ERROR: Given const IKomponente*: pk is nullptr!");
    }
    double distance;
    double lowest_distance = std::numeric_limits<double>::max();
    Iterator<IKomponente*> ret;
    for (Iterator<IKomponente*> it{komponenten.begin()}; it != komponenten.end(); ++it) {
        if (*it != pk) {
            distance = pk->distance(*it);
            if (distance < lowest_distance) {
                lowest_distance = distance;
                ret = it;
            }
        }
    }
    return ret;
}
