#include <gtest/gtest.h>
#include <sstream>
#include <cmath>
#include "DynamicalMatrix.h"
#include "DimerTestStructure.h"
#include "DimerSpringPotential.h"
#include "TotalEnergy.h"
#include "GeStructureBuilder.h"
#include "TersoffPotential.h"
#include "KVector.h"
#include "ReciprocalLatticeVectors.h"

namespace {

class DynamicalMatrixTest: public ::testing::Test {
protected:

    virtual void SetUp() {
        matrix = 0;
        potential = 0;
        structure = 0;
        totalEnergy = 0;
        gammaPoint = KVector(0.0, 0.0, 0.0);
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
    const ReciprocalLatticeVectors *kvectors;
    TotalEnergy *totalEnergy;
    double springConstant;
    double mass0;
    double mass1;
    KVector gammaPoint;
    static const double hartreePerCentimeterInverse;

    void setUpDimer() {
        structure = new DimerTestStructure();
        structure->setMass(0, mass0 = 2.0);
        structure->setMass(1, mass1 = 3.0);
        potential = new DimerSpringPotential(springConstant=1.0);
        totalEnergy = new TotalEnergy(structure, potential);
        matrix = new DynamicalMatrix(totalEnergy, structure);
    }

    void setUpGe() {
        structure = GeStructureBuilder::makeNewStructure();
        kvectors = structure->getReciprocalLatticeVectors();
        potential = new TersoffPotential();
        totalEnergy = new TotalEnergy(structure, potential);
        matrix = new DynamicalMatrix(totalEnergy, structure);
    }
};

const double DynamicalMatrixTest::hartreePerCentimeterInverse = 1.0 / 219474.63;


TEST_F(DynamicalMatrixTest, testMatrixSize) {
    setUpDimer();
    int matrixSize = matrix->getSize();
    ASSERT_EQ(6, matrixSize);
}

TEST_F(DynamicalMatrixTest, testLowestFreqenciesAreZero) {
    setUpDimer();
    const double delta = 1e-6;
    matrix->calculateDynamicalMatrix(delta);
    matrix->diagonalizeAtKPoint(gammaPoint);
    int lastIndex = matrix->getSize() - 1;
    for (int i = 0; i < lastIndex; ++i) {
        double lowFrequency = matrix->getFrequency(i);
        ASSERT_NEAR(0.0, lowFrequency, 1e-5);
    }
}

TEST_F(DynamicalMatrixTest, testVibrationalFrequency) {
    setUpDimer();
    const double delta = 1e-6;
    matrix->calculateDynamicalMatrix(delta);
    matrix->diagonalizeAtKPoint(gammaPoint);
    int lastIndex = matrix->getSize() - 1;
    double highFrequency = matrix->getFrequency(lastIndex);
    double reducedMass = 1.0 / (1./mass0 + 1./mass1);
    double omega = sqrt(springConstant / reducedMass);
    ASSERT_NEAR(omega, highFrequency, 1e-5);
}

TEST_F(DynamicalMatrixTest, testGeOpticalPhononAtgammaPoint) {
    setUpGe();
    const double delta = 1e-6;
    matrix->calculateDynamicalMatrix(delta);
    matrix->diagonalizeAtKPoint(gammaPoint);
    int lastIndex = matrix->getSize() - 1;
    double opticalFrequency = matrix->getFrequency(lastIndex);
    ASSERT_NEAR(319.0753709186 * hartreePerCentimeterInverse, opticalFrequency, 1e-5);
}

TEST_F(DynamicalMatrixTest, testDegeneracyOfGeOpticalPhononAtgammaPoint) {
    setUpGe();
    const double delta = 1e-6;
    matrix->calculateDynamicalMatrix(delta);
    matrix->diagonalizeAtKPoint(gammaPoint);
    double omega1 = matrix->getFrequency(3);
    double omega2 = matrix->getFrequency(4);
    double omega3 = matrix->getFrequency(5);
    ASSERT_NEAR(omega1, omega2, 1e-5);
    ASSERT_NEAR(omega1, omega3, 1e-5);
}

//TEST_F(DynamicalMatrixTest, testLowestFrequencyAtX) {
//    setUpGe();
//    const double delta = 1e-6;
//    matrix->calculateDynamicalMatrix(delta);
//    KVector xPoint = kvectors->getKVectorFromReducedCoordinates(0.5, 0, 0.5);
//    matrix->diagonalizeAtKPoint(xPoint);
//    double omega = matrix->getFrequency(0);
//    ASSERT_NEAR(100.0 * hartreePerCentimeterInverse, omega, 1e-5);
//}

}
