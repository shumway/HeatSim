#include <gtest/gtest.h>
#include <sstream>
#include <cmath>
#include "DynamicalMatrix.h"
#include "DimerTestStructure.h"
#include "DimerSpringPotential.h"
#include "TotalEnergy.h"

namespace {

class DynamicalMatrixTest: public ::testing::Test {
protected:

    virtual void SetUp() {
        structure = new DimerTestStructure();
        potential = new DimerSpringPotential(springConstant=1.0);
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
    double springConstant;
};

TEST_F(DynamicalMatrixTest, testMatrixSize) {
    int matrixSize = matrix->getSize();
    ASSERT_EQ(6, matrixSize);
}

TEST_F(DynamicalMatrixTest, testLowestFreqencyIsZero) {
    const double delta = 1e-6;
    matrix->calculate(delta);
    double lowFrequency = matrix->getFrequency(0);
    ASSERT_NEAR(0.0, lowFrequency, 1e-5);
}

TEST_F(DynamicalMatrixTest, testVibrationalFrequency) {
    const double delta = 1e-6;
    matrix->calculate(delta);
    int lastIndex = matrix->getSize() - 1;
    double highFrequency = matrix->getFrequency(lastIndex);
    double reducedMass = 0.5;
    double omega = sqrt(springConstant / reducedMass);
    ASSERT_NEAR(omega, highFrequency, 1e-5);
}


}
