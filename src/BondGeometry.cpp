#include "BondGeometry.h"

#include "BondList.h"
#include "TersoffBond.h"
#include "Structure.h"
#include "AtomIterator.h"
#include "Atom.h"
#include <cmath>

BondGeometry::BondGeometry(int bondCount) {
    initializeBonds(bondCount);
}

const BondList* BondGeometry::getBonds() const {
    return bonds;
}

void BondGeometry::initializeBonds(int bondCount) {
    bonds = new BondList(bondCount);
}

void BondGeometry::calculateCurrentBondGeometry(const Structure& structure) {
    int bondIndex = 0;
    for (AtomIterator iterator = structure.getAtomIterator();
            !iterator.isDone(); iterator.next()) {
        Atom atom = iterator.getCurrentAtom();
        setBondsForAnAtom(atom, bondIndex);
    }
}

void BondGeometry::setBondsForAnAtom(const Atom& atom, int& bondIndex) {
    double distance[4];
    const int neighborCount = atom.getNeighborCount();
    for (int i = 0; i < neighborCount; ++i) {
        distance[i] = atom.getDisplacement(i).length();
    }
    for (int i = 0; i < neighborCount; ++i) {
        TersoffBond& bond = *bonds->getBond(bondIndex);
        double ri = distance[i];
        bond.r0 = ri;
        int index = 1;
        for (int j = 0; j < neighborCount; ++j) {
            if (i==j) continue;
            double rj = distance[j];
            double costheta = dot(atom.getDisplacement(i),
                                  atom.getDisplacement(j))/(ri*rj);
            switch (index) {
            case 1:
                bond.r1 = rj;
                bond.cosTheta1 = costheta;
                break;
            case 2:
                bond.r2 = rj;
                bond.cosTheta2 = costheta;
                break;
            case 3:
                bond.r3 = rj;
                bond.cosTheta3 = costheta;
                break;
            }
            ++index;
        }
        ++bondIndex;
    }
}
