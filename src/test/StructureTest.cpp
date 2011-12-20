#include <gtest/gtest.h>
#include "Structure.h"
#include "TersoffBond.h"
#include "NeighborList.h"
#include "Coordinates.h"
#include "Location.h"
#include "BondList.h"
#include "BondGeometry.h"

namespace {

class StructureTest: public ::testing::Test {
protected:
    virtual void SetUp() {
        structure = makeDimer();
    }

    virtual void TearDown() {
        delete structure;
    }


    Structure* structure;
    BondGeometry* bondGeometry;

    Structure* makeDimer() {
        Structure* structure = new Structure();

        int npart = 2;
        Coordinates* coordinates = new Coordinates(npart);
        coordinates->setCartesianLocation(1, Location(1, 0, 0));
        structure->setCoordinates(coordinates);

        NeighborList* neighborList = new NeighborList(2);
        neighborList->addNeighbor(0, 1, LatticeDisplacement( 0, 0, 0));
        neighborList->addNeighbor(1, 0, LatticeDisplacement( 0, 0, 0));
        structure->setNeighborList(neighborList);

        bondGeometry = new BondGeometry(neighborList->getNeighborCount());

        return structure;
    }
};

TEST_F(StructureTest, testGetBonds) {
    bondGeometry->calculateCurrentBondGeometry(*structure);
    const BondList* bonds = bondGeometry->getBonds();
    const TersoffBond* bond = bonds->getBond(0);
    ASSERT_FLOAT_EQ(1.0, bond->r0);
}



}
