#include "BondGeometry.h"

#include "BondList.h"
#include "TersoffBond.h"
#include "Coordinates.h"
#include "NeighborList.h"
#include "Structure.h"

BondGeometry::BondGeometry(int bondCount) {
    initializeBonds(bondCount);
}

const BondList* BondGeometry::getBonds() const {
    return bonds;
}

void BondGeometry::initializeBonds(int bondCount) {
    bonds = new BondList(bondCount);
}

void BondGeometry::calculateCurrentBondGeometry(Structure& structure) {
    int bondIndex = 0;
    for (int atomIndex = 0; atomIndex < structure.getCoordinates()->getAtomCount();
            ++atomIndex) {
        for (int neighborIndex = 0;
                neighborIndex < structure.getNeighborList()->getNeighborCount(atomIndex);
                ++atomIndex) {
            const Neighbor* neighbor
            = structure.getNeighborList()->getNeighbor(atomIndex, neighborIndex);
            setBond(bonds->getBond(bondIndex), atomIndex, neighbor);
        }
    }
}

void BondGeometry::setBond(TersoffBond* bond, int atomIndex,
        const Neighbor* neighbor) {
    bond->r0 = 1.0;
}
