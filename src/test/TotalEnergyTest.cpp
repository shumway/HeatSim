#include <gtest/gtest.h>
#include "TotalEnergy.h"
#include "Structure.h"
#include "TersoffPotential.h"

namespace {

class TotalEnergyTest: public ::testing::Test {
protected:
    virtual void SetUp() {
        structure = makeDimer();
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

    Structure* makeDimer() {
        Structure* structure = new Structure();
        return structure;
    }
};

TEST_F(TotalEnergyTest, testInitialTotalEnergy) {
    double energy = totalEnergy->getEnergy();
    ASSERT_FLOAT_EQ(0.0, energy);
}



}
