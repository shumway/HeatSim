#include <gtest/gtest.h>
#include <sstream>
#include "DynamicalMatrix.h"
#include "DimerTestStructure.h"
#include "DimerSpringPotential.h"
#include "TotalEnergy.h"

namespace {

class DynamicalMatrixTest: public ::testing::Test {
protected:

    virtual void SetUp() {
        structure = new DimerTestStructure();
        potential = new DimerSpringPotential(1.0);
        totalEnergy = new TotalEnergy(structure, potential);
        matrix = new DynamicalMatrix(totalEnergy, structure);
    }

    virtual void TearDown() {
        delete matrix;
        delete potential;
        delete structure;
        delete totalEnergy;
    }

    DynamicalMatrix *matrix;
    Potential *potential;
    Structure *structure;
    TotalEnergy *totalEnergy;
};

TEST_F(DynamicalMatrixTest, checkMatrixSize) {
    int matrixSize = matrix->getSize();
    ASSERT_EQ(6, matrixSize);
}

}
