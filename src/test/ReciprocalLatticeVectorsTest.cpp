#include <gtest/gtest.h>
#include "ReciprocalLatticeVectors.h"
#include "LatticeVectors.h"
#include "Displacement.h"

namespace {

class ReciprocalLatticeVectorsTest: public ::testing::Test {
protected:

    virtual void SetUp() {
        rvectors = 0;
        kvectors = 0;
    }

    virtual void TearDown() {
        delete rvectors;
        delete kvectors;
    }

    LatticeVectors* rvectors;
    ReciprocalLatticeVectors* kvectors;
    static const double PI;

    static double twoPiDelta(int i, int j) {
        return (i==j) ? 2*PI : 0.0;
    }

    void setupSkewedVectors() {
        Displacement a1(1.0, 2.0, 4.0);
        Displacement a2(3.0, 1.0, 0.0);
        Displacement a3(2.0, 3.0, 1.0);
        rvectors = new LatticeVectors(a1, a2, a3);
        kvectors = new ReciprocalLatticeVectors(*rvectors);
    }

    void setupFCCVectors() {
        Displacement a1(0.0, 0.5, 0.5);
        Displacement a2(0.5, 0.0, 0.5);
        Displacement a3(0.5, 0.5, 0.0);
        rvectors = new LatticeVectors(a1, a2, a3);
        kvectors = new ReciprocalLatticeVectors(*rvectors);
    }

};

const double ReciprocalLatticeVectorsTest::PI = 3.141592653589793;


TEST_F(ReciprocalLatticeVectorsTest, testOrthoNormalization) {
    setupSkewedVectors();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++ j) {
            Displacement r = rvectors->getVector(i);
            KVector k = kvectors->getVector(j);
            ASSERT_NEAR(twoPiDelta(i,j), dot(k, r), 1e-14);
        }
    }
}

TEST_F(ReciprocalLatticeVectorsTest, testKVectorFromReducedCoordinates) {
    setupFCCVectors();
    KVector k = kvectors->getKVectorFromReducedCoordinates(0.1, 0.2, 0.4);
    KVector expect(3.14159265,  1.88495559, -0.62831853);
    ASSERT_NEAR(expect.x, k.x, 1e-7);
    ASSERT_NEAR(expect.y, k.y, 1e-7);
    ASSERT_NEAR(expect.z, k.z, 1e-7);
}

}
