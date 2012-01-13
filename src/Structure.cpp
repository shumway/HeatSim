#include "Structure.h"
#include "Coordinates.h"
#include "LatticeVectors.h"
#include "NeighborList.h"
#include "Neighbor.h"
#include "AtomIterator.h"

Structure::Structure()
    :   coordinates(0), latticeVectors(0), neighborList(0) {
}

Structure::~Structure() {
    delete coordinates;
    delete latticeVectors;
    delete neighborList;
}

void Structure::setCoordinates(Coordinates* coordinates) {
    this->coordinates = coordinates;
}

Coordinates* Structure::getCoordinates() {
    return coordinates;
}

void Structure::setLatticeVectors(const LatticeVectors* latticeVectors) {
    this->latticeVectors = latticeVectors;
}

const LatticeVectors* Structure::getLatticeVectors() const {
    return latticeVectors;
}

void Structure::setNeighborList(const NeighborList* neighborList) {
    this->neighborList = neighborList;
}

const NeighborList* Structure::getNeighborList() const {
    return neighborList;
}

int Structure::getAtomCount() const {
    return coordinates->getAtomCount();
}

AtomIterator Structure::getAtomIterator() const {
    AtomIterator iterator(coordinates, neighborList, latticeVectors);
    return iterator;
}

int Structure::getBondCount() const {
    return neighborList->getNeighborCount();
}


