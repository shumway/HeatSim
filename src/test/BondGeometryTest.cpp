#include <gtest/gtest.h>
#include "Structure.h"
#include "TersoffBond.h"
#include "NeighborList.h"
#include "Coordinates.h"
#include "Location.h"
#include "BondList.h"
#include "BondGeometry.h"

#include "GeStructureBuilder.h"

namespace {

class BondGeometryTest: public ::testing::Test {
protected:
    virtual void SetUp() {
        structure = GeStructureBuilder::makeNewStructure();
        bondGeometry = new BondGeometry(structure->getNeighborList()->getNeighborCount());
    }

    virtual void TearDown() {
        delete structure;
    }

    Structure* structure;
    BondGeometry* bondGeometry;

};

TEST_F(BondGeometryTest, testAllBonds) {
    bondGeometry->calculateCurrentBondGeometry(*structure);
    const BondList* bonds = bondGeometry->getBonds();
    for (int i=0; i<bonds->getCount(); ++i) {
        const TersoffBond* bond = bonds->getBond(i);
        const double bondLength = GeStructureBuilder::bondLength;
        ASSERT_FLOAT_EQ(bondLength, bond->r0);
        ASSERT_FLOAT_EQ(bondLength, bond->r1);
        ASSERT_FLOAT_EQ(-1.0/3.0, bond->cosTheta1);
        ASSERT_FLOAT_EQ(bondLength, bond->r2);
        ASSERT_FLOAT_EQ(-1.0/3.0, bond->cosTheta2);
        ASSERT_FLOAT_EQ(bondLength, bond->r3);
        ASSERT_FLOAT_EQ(-1.0/3.0, bond->cosTheta3);
    }
}




}
