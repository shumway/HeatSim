#include <gtest/gtest.h>
#include "LatticeVectors.h"
#include "Displacement.h"

class LatticeVectorsTest: public ::testing::Test {
};

TEST_F(LatticeVectorsTest, testSignedVolumeOfCubicCell) {
    Displacement a1(1.0, 0.0, 0.0);
    Displacement a2(0.0, 1.0, 0.0);
    Displacement a3(0.0, 0.0, 1.0);
    LatticeVectors cell(a1, a2, a3);
    ASSERT_NEAR(1.0, cell.getSignedVolume(), 1e-14);
}

TEST_F(LatticeVectorsTest, testSignedVolumeOfRectangularCell) {
    Displacement a1(2.0, 0.0, 0.0);
    Displacement a2(0.0, 3.0, 0.0);
    Displacement a3(0.0, 0.0, 4.0);
    LatticeVectors cell(a1, a2, a3);
    ASSERT_NEAR(24.0, cell.getSignedVolume(), 1e-14);
}

TEST_F(LatticeVectorsTest, testNegativeSignedVolumeOfInverseRectangularCell) {
    Displacement a1(0.0, 2.0, 0.0);
    Displacement a2(3.0, 0.0, 0.0);
    Displacement a3(0.0, 0.0, 4.0);
    LatticeVectors cell(a1, a2, a3);
    ASSERT_NEAR(-24.0, cell.getSignedVolume(), 1e-14);
}

TEST_F(LatticeVectorsTest, testSignedVolumeOfSkewedCell) {
    Displacement a1(2.0, 5.0, 2.0);
    Displacement a2(1.0, 3.0, 3.0);
    Displacement a3(3.0, 4.0, 4.0);
    LatticeVectors cell(a1, a2, a3);
    ASSERT_NEAR(15.0, cell.getSignedVolume(), 1e-14);
}
