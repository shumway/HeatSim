#include "Structure.h"
#include "Coordinates.h"

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
