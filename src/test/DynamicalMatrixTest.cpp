#include <gtest/gtest.h>
#include <sstream>
#include "DynamicalMatrix.h"

namespace {

class DynamicalMatrixTest : public ::testing::Test {
protected:

	virtual void SetUp() {
		matrix = new DynamicalMatrix();
		matrix->setPotential(0);
		matrix->setCoordinates(0);
	}

	virtual void TearDown() {
		delete matrix;
	}

	DynamicalMatrix* matrix;
};

TEST_F(DynamicalMatrixTest, testSetup) {
	matrix->initialize();
}


}
