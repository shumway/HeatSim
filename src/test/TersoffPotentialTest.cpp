#include <gtest/gtest.h>

#include "TersoffPotential.h"

namespace {

class TersoffPotentialTest : public ::testing::Test {
 protected:

  virtual void SetUp() {
	  tersoff = new TersoffPotential();
  }

  virtual void TearDown() {
	  delete tersoff;
  }

  TersoffPotential* tersoff;
};

TEST_F(TersoffPotentialTest, TestCutoffAtZero) {
	double value = tersoff->evalCutoffTerm(0);
    ASSERT_DOUBLE_EQ(1., value);
}

TEST_F(TersoffPotentialTest, TestCutoffBeforeInnerCutoff) {
	double r = tersoff->getInnerCutoff();
	double value = tersoff->evalCutoffTerm(0.5*r);
    ASSERT_DOUBLE_EQ(1., value);
}

TEST_F(TersoffPotentialTest, TestCutoffAtInnerCutoff) {
	double r = tersoff->getInnerCutoff();
	double value = tersoff->evalCutoffTerm(r);
    ASSERT_DOUBLE_EQ(1., value);
}

TEST_F(TersoffPotentialTest, TestCutoffOneFourthBetweenCutoffs) {
	double rin = tersoff->getInnerCutoff();
	double rout = tersoff->getOuterCutoff();
	double rmid = 0.75*rin + 0.25*rout;
	double value = tersoff->evalCutoffTerm(rmid);
	double expect = 0.5 + 0.25*sqrt(2.0);
    ASSERT_DOUBLE_EQ(expect, value);
}

TEST_F(TersoffPotentialTest, TestCutoffHalfWayBetweenCutoffs) {
	double rin = tersoff->getInnerCutoff();
	double rout = tersoff->getOuterCutoff();
	double rmid = 0.5 * (rin + rout);
	double value = tersoff->evalCutoffTerm(rmid);
    ASSERT_DOUBLE_EQ(0.5, value);
}

TEST_F(TersoffPotentialTest, TestCutoffThreeFourthsBetweenCutoffs) {
	double rin = tersoff->getInnerCutoff();
	double rout = tersoff->getOuterCutoff();
	double rmid = 0.25*rin + 0.75*rout;
	double value = tersoff->evalCutoffTerm(rmid);
	double expect = 0.5 - 0.25*sqrt(2.0);
    ASSERT_DOUBLE_EQ(expect, value);
}

TEST_F(TersoffPotentialTest, TestCutoffAtOuterCutoff) {
	double r = tersoff->getOuterCutoff();
	double value = tersoff->evalCutoffTerm(r);
    ASSERT_DOUBLE_EQ(0., value);
}


TEST_F(TersoffPotentialTest, TestCutoffPastOuterCutoff) {
	double r = tersoff->getOuterCutoff();
	double value = tersoff->evalCutoffTerm(1.5*r);
    ASSERT_DOUBLE_EQ(0., value);
}

TEST_F(TersoffPotentialTest, TestRadialPotentialAtOrigin) {
	double value = tersoff->evalRadialPotential(0.0);
	ASSERT_DOUBLE_EQ(49.60311481263218, value);
}

TEST_F(TersoffPotentialTest, TestRadialPotentialAtInnerCutoff) {
	double r = tersoff->getInnerCutoff();
	double value = tersoff->evalRadialPotential(r);
	ASSERT_NEAR(-0.061108622898086933, value, 1e-15);
}



}
