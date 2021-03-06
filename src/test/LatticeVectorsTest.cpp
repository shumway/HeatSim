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

TEST_F(LatticeVectorsTest, testDisplacementFromPrimativeBasis) {
    Displacement a1(2.0, 5.0, 2.0);
    Displacement a2(1.0, 3.0, 3.0);
    Displacement a3(3.0, 4.0, 4.0);
    LatticeVectors cell(a1, a2, a3);
    Displacement delta = cell.getDisplacementFromReducedCoordinates(0.1, 0.2, 0.3);
    ASSERT_NEAR(1.3, delta.x, 1e-14);
    ASSERT_NEAR(2.3, delta.y, 1e-14);
    ASSERT_NEAR(2.0, delta.z, 1e-14);
}
