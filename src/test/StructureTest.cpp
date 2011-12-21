#include <gtest/gtest.h>
#include "Structure.h"
#include "TersoffBond.h"
#include "NeighborList.h"
#include "Coordinates.h"
#include "Location.h"
#include "BondList.h"
#include "BondGeometry.h"

#include "DimerTestStructure.h"

namespace {

class StructureTest: public ::testing::Test {
protected:
    virtual void SetUp() {
        structure = new DimerTestStructure();
        bondGeometry = new BondGeometry(structure->getNeighborList()->getNeighborCount());
    }

    virtual void TearDown() {
        delete structure;
    }

    Structure* structure;
    BondGeometry* bondGeometry;

};

TEST_F(StructureTest, testGetBonds) {
    bondGeometry->calculateCurrentBondGeometry(*structure);
    const BondList* bonds = bondGeometry->getBonds();
    const TersoffBond* bond = bonds->getBond(0);
    ASSERT_FLOAT_EQ(1.0, bond->r0);
}



}
