#include <gtest/gtest.h>
#include "BondGeometry.h"
#include "Structure.h"
#include "TersoffBond.h"
#include "BondList.h"
#include "Location.h"
#include "Coordinates.h"
#include "Displacement.h"

#include <iostream>

#include "GeStructureBuilder.h"

namespace {

class BondGeometryTest: public ::testing::Test {
protected:
    virtual void SetUp() {
        structure = GeStructureBuilder::makeNewStructure();
        bondGeometry = new BondGeometry(structure->getBondCount());
    }

    virtual void TearDown() {
        delete structure;
    }

    Structure* structure;
    BondGeometry* bondGeometry;
    static const double bondLength;


    void shiftFirstAtom() {
        Coordinates* coordinate = structure->getCoordinates();
        Location firstAtomPositon = coordinate->getLocation(0);
        const double delta = 0.1 * GeStructureBuilder::bondLength / sqrt(3.0);
        firstAtomPositon += Displacement(delta, delta, delta);
        coordinate->setCartesianLocation(0, firstAtomPositon);
    }

};

const double BondGeometryTest::bondLength = GeStructureBuilder::bondLength;


TEST_F(BondGeometryTest, testAllBonds) {
    bondGeometry->calculateCurrentBondGeometry(*structure);
    const BondList* bonds = bondGeometry->getBonds();
    for (int i=0; i<bonds->getCount(); ++i) {
        const TersoffBond* bond = bonds->getBond(i);
        ASSERT_DOUBLE_EQ(bondLength, bond->r0);
        ASSERT_DOUBLE_EQ(bondLength, bond->r1);
        ASSERT_DOUBLE_EQ(-1.0/3.0, bond->cosTheta1);
        ASSERT_DOUBLE_EQ(bondLength, bond->r2);
        ASSERT_DOUBLE_EQ(-1.0/3.0, bond->cosTheta2);
        ASSERT_DOUBLE_EQ(bondLength, bond->r3);
        ASSERT_DOUBLE_EQ(-1.0/3.0, bond->cosTheta3);
    }
}

TEST_F(BondGeometryTest, testBondCompressedWhenFirstAtomMoved) {
    shiftFirstAtom();
    bondGeometry->calculateCurrentBondGeometry(*structure);
    const BondList* bonds = bondGeometry->getBonds();
    const TersoffBond* bond = bonds->getBond(0);
    ASSERT_DOUBLE_EQ(0.9*bondLength, bond->r0);
}

TEST_F(BondGeometryTest, testOtherBondsStretchedWhenFirstAtomMoved) {
    shiftFirstAtom();
    bondGeometry->calculateCurrentBondGeometry(*structure);
    const BondList* bonds = bondGeometry->getBonds();
    const TersoffBond* bond = bonds->getBond(0);
    ASSERT_DOUBLE_EQ(1.0376254944182253*bondLength, bond->r1);
    ASSERT_DOUBLE_EQ(1.0376254944182253*bondLength, bond->r2);
    ASSERT_DOUBLE_EQ(1.0376254944182253*bondLength, bond->r3);
}


TEST_F(BondGeometryTest, testBondAnglesStretchedWhenFirstAtomMoved) {
    shiftFirstAtom();
    bondGeometry->calculateCurrentBondGeometry(*structure);
    const BondList* bonds = bondGeometry->getBonds();
    const TersoffBond* bond = bonds->getBond(0);
    ASSERT_DOUBLE_EQ(-0.41762016803210311, bond->cosTheta1);
    ASSERT_DOUBLE_EQ(-0.41762016803210311, bond->cosTheta2);
    ASSERT_DOUBLE_EQ(-0.41762016803210311, bond->cosTheta3);
}

}
