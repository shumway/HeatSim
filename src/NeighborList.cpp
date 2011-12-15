#include "NeighborList.h"
#include "Neighbor.h"

NeighborList::NeighborList(int atomCount)
    : theList(new Neighbor[MAX_NEIGHBORS*atomCount]) {
}

NeighborList::~NeighborList() {
    delete [] theList;
}

void NeighborList::addNeighbor(int atomIndex, int neighborIndex,
        LatticeDisplacement delta) {
    int index = getNeighborCount(atomIndex);
    theList[MAX_NEIGHBORS*atomIndex + index] = Neighbor(neighborIndex, delta);
}

int NeighborList::getNeighborCount(int atomIndex) {
    int index = 0;
    while (index < MAX_NEIGHBORS) {
        Neighbor neighbor = theList[MAX_NEIGHBORS*atomIndex + index];
        if (neighbor.isNull()) break;
        ++index;
    }
    return index;
}
