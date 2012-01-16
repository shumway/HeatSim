#include <gtest/gtest.h>
#include "TotalEnergy.h"
#include "Structure.h"
#include "TersoffPotential.h"
#include "GeStructureBuilder.h"
#include "DimerTestStructure.h"
#include "DimerSpringPotential.h"
#include "Location.h"
#include "Coordinates.h"
#include "Displacement.h"

namespace {

class TotalEnergyTest: public ::testing::Test {
protected:
    virtual void SetUp() {
        structure = 0;
        potential = 0;
        totalEnergy = 0;
    }

    virtual void TearDown() {
        delete structure;
        delete potential;
        delete totalEnergy;
    }

    TotalEnergy* totalEnergy;
    Structure* structure;
    Potential* potential;

    void shiftFirstAtom() {
        Coordinates* coordinate = structure->getCoordinates();
        Location firstAtomPositon = coordinate->getLocation(0);
        const double delta = 0.1;
        firstAtomPositon += Displacement(delta, 0, 0);
        coordinate->setCartesianLocation(0, firstAtomPositon);
    }


};

TEST_F(TotalEnergyTest, testGermaniumTotalEnergy) {
    structure = GeStructureBuilder::makeNewStructure();
    potential = new TersoffPotential();
    totalEnergy = new TotalEnergy(structure, potential);
    double energy = totalEnergy->getEnergy();
    ASSERT_DOUBLE_EQ(-0.070740113832587104 * 4, energy);
}

TEST_F(TotalEnergyTest, testDimerTotalEnergy) {
    structure = new DimerTestStructure();
    potential = new DimerSpringPotential(1.37);
    totalEnergy = new TotalEnergy(structure, potential);
    double energy = totalEnergy->getEnergy();
    ASSERT_DOUBLE_EQ(0.0, energy);
}

TEST_F(TotalEnergyTest, testStretchedDimerTotalEnergy) {
    structure = new DimerTestStructure();
    shiftFirstAtom();
    potential = new DimerSpringPotential(1.37);
    totalEnergy = new TotalEnergy(structure, potential);
    double energy = totalEnergy->getEnergy();
    ASSERT_DOUBLE_EQ(0.5 * 1.37 * 0.01, energy);
}

}
