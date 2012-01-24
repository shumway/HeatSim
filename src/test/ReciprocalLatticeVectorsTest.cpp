#include <gtest/gtest.h>
#include "ReciprocalLatticeVectors.h"
#include "LatticeVectors.h"
#include "Displacement.h"

namespace {

class ReciprocalLatticeVectorsTest: public ::testing::Test {
protected:

    virtual void SetUp() {
        Displacement a1(1.0, 0.0, 0.0);
        Displacement a2(0.0, 1.0, 0.0);
        Displacement a3(0.0, 0.0, 1.0);
        rvectors = new LatticeVectors(a1, a2, a3);
        kvectors = new ReciprocalLatticeVectors(*rvectors);
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
};

const double ReciprocalLatticeVectorsTest::PI = 3.141592653589793;

TEST_F(ReciprocalLatticeVectorsTest, testOrthoNormalization) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++ j) {
            Displacement r = rvectors->getVector(i);
            KVector k = kvectors->getVector(j);
            ASSERT_NEAR(twoPiDelta(i,j), dot(k, r), 1e-14);
        }
    }


}

}
