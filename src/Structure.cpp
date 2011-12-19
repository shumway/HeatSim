#include "Structure.h"
#include "Coordinates.h"

Structure::Structure()
    :   coordinates(0) {
}

Structure::~Structure() {
    delete coordinates;
}

void Structure::setCoordinates(Coordinates* coordinates) {
    this->coordinates = coordinates;
}

void Structure::setLatticeVectors(const LatticeVectors* latticeVectors) {
    this->latticeVectors = latticeVectors;
}

void Structure::setNeighborList(const NeighborList* neighborList) {
    this->neighborList = neighborList;
}
