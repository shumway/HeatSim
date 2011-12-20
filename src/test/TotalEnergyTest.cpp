#include <gtest/gtest.h>
#include "TotalEnergy.h"
#include "GeStructureBuilder.h"
#include "Structure.h"
#include "TersoffPotential.h"

namespace {

class TotalEnergyTest: public ::testing::Test {
protected:
    virtual void SetUp() {
        structure = GeStructureBuilder::makeNewStructure();
        potential = new TersoffPotential();
        totalEnergy = new TotalEnergy(structure, potential);
    }

    virtual void TearDown() {
        delete structure;
        delete potential;
        delete totalEnergy;
    }

    TotalEnergy* totalEnergy;
    Structure* structure;
    TersoffPotential* potential;
};

TEST_F(TotalEnergyTest, testInitialTotalEnergy) {
    double energy = totalEnergy->getEnergy();
    ASSERT_FLOAT_EQ(0.0, energy);
}



}
