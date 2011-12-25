#include "NeighborList.h"
#include "Neighbor.h"

NeighborList::NeighborList(int atomCount)
    : atomCount(atomCount), theList(new Neighbor[MAX_NEIGHBORS*atomCount]) {
}

NeighborList::~NeighborList() {
    delete [] theList;
}

void NeighborList::addNeighbor(int atomIndex, int neighborIndex,
        LatticeDisplacement delta) {
    int index = getNeighborCount(atomIndex);
    theList[MAX_NEIGHBORS*atomIndex + index] = Neighbor(neighborIndex, delta);
}

int NeighborList::getNeighborCount(int atomIndex) const {
    int index = 0;
    while (index < MAX_NEIGHBORS) {
        Neighbor neighbor = theList[MAX_NEIGHBORS*atomIndex + index];
        if (neighbor.isNull()) break;
        ++index;
    }
    return index;
}

int NeighborList::getNeighborCount() const {
    int count = 0;
    for (int i = 0; i < atomCount; ++i) {
        count += getNeighborCount(i);
    }
    return count;
}

const Neighbor* NeighborList::getNeighbor(int atomIndex, int neighborIndex) const {
    return &theList[MAX_NEIGHBORS*atomIndex + neighborIndex];
}
