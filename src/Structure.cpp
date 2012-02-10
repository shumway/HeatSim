#include "Structure.h"
#include "Coordinates.h"
#include "LatticeVectors.h"
#include "NeighborList.h"
#include "Neighbor.h"
#include "AtomIterator.h"
#include "ReciprocalLatticeVectors.h"

Structure::Structure(int atomCount)
    :   atomCount(atomCount),
        coordinates(0), latticeVectors(0),
        reciprocalLatticeVectors(0), neighborList(0),
        mass(new double [atomCount]) {
    for (int index = 0; index < atomCount; ++index) {
        mass[index] = 1.0;
    }
}

Structure::~Structure() {
    delete coordinates;
    delete latticeVectors;
    delete reciprocalLatticeVectors;
    delete neighborList;
    delete mass;
}

void Structure::setCoordinates(Coordinates* coordinates) {
    this->coordinates = coordinates;
}

Coordinates* Structure::getCoordinates() {
    return coordinates;
}

void Structure::setLatticeVectors(const LatticeVectors* latticeVectors) {
    this->latticeVectors = latticeVectors;
    reciprocalLatticeVectors = new ReciprocalLatticeVectors(*latticeVectors);
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
    return atomCount;
}

AtomIterator Structure::getAtomIterator() const {
    AtomIterator iterator(coordinates, neighborList, latticeVectors);
    return iterator;
}

int Structure::getBondCount() const {
    return neighborList->getNeighborCount();
}

void Structure::moveAtom(int index, const Displacement & delta) {
    coordinates->moveAtom(index, delta);
}

void Structure::setMass(int index, double mass) {
    this->mass[index] = mass;
}

const ReciprocalLatticeVectors
*Structure::getReciprocalLatticeVectors() const {
    return reciprocalLatticeVectors;
}

const Location& Structure::getCoordinate(int index) const {
    return coordinates->getLocation(index);
}

double Structure::getMass(int index) const {
    return mass[index];
}
