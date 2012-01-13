#include "DynamicalMatrix.h"
#include "Structure.h"

DynamicalMatrix::DynamicalMatrix(const TotalEnergy *totalEnergy,
        Structure *structure)
    :   totalEnergy(totalEnergy), structure(structure),
        size(structure->getAtomCount()*3) {
}

DynamicalMatrix::~DynamicalMatrix() {
}

int DynamicalMatrix::getSize() const {
    return size;
}
