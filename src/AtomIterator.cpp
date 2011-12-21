#include "AtomIterator.h"

#include "Coordinates.h"
#include "Atom.h"
#include "NeighborList.h"
#include "Neighbor.h"
#include "Location.h"
#include "Displacement.h"
#include "LatticeVectors.h"

AtomIterator::AtomIterator(const Coordinates* coordinates,
        const NeighborList* neighborList, const LatticeVectors* latticeVectors)
:   currentIndex(0), atomCount(coordinates->getAtomCount()),
    coordinates(coordinates), neighborList(neighborList),
    latticeVectors(latticeVectors), atom(new Atom()) {

}

AtomIterator::~AtomIterator() {
    delete atom;
}

bool AtomIterator::isDone() const {
    return currentIndex >= atomCount;
}

void AtomIterator::next() {
    ++currentIndex;
}

const Atom& AtomIterator::getCurrentAtom() {
    updateAtomObject();
    return *atom;
}

void AtomIterator::updateAtomObject() {
    const Location atomLocation = coordinates->getLocation(currentIndex);

    int neighborCount = neighborList->getNeighborCount(currentIndex);
    atom->setNeighborCount(neighborCount);
    for (int neighborIndex = 0; neighborIndex < neighborCount; ++neighborIndex) {
        const Neighbor* neighbor = neighborList->getNeighbor(currentIndex, neighborIndex);
        const Location neighborLocation = coordinates->getLocation(neighbor->index);

        Displacement displacement(neighborLocation, atomLocation);

        if (latticeVectors!=0) {
            displacement += latticeVectors->getVector(0) * neighbor->delta.x;
            displacement += latticeVectors->getVector(1) * neighbor->delta.y;
            displacement += latticeVectors->getVector(2) * neighbor->delta.z;
        }
        atom->setDisplacement(neighborIndex, displacement);
    }
}
