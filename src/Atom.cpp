#include "Atom.h"

int Atom::getNeighborCount() const {
    return neighborCount;
}

void Atom::setNeighborCount(int neighborCount) {
    this->neighborCount = neighborCount;
}

const Displacement& Atom::getDisplacement(int index) {
    return displacement[index];
}

void Atom::setDisplacement(int index, const Displacement& value) {
    displacement[index] = value;
}








