#include <gtest/gtest.h>
#include <sstream>
#include "Coordinates.h"

namespace {

class CoordinatesTest : public ::testing::Test {
protected:

	virtual void SetUp() {
		coordinates = new Coordinates();
	}

	virtual void TearDown() {
		delete coordinates;
	}

	Coordinates* coordinates;
};

TEST_F(CoordinatesTest, testReadPoscarFile) {
    std::stringstream infile;

    infile.str() += "Some comment";
    infile.str() += "1.0";
    infile.str() += "2.825 2.825 0.000";
    infile.str() += "2.825 0.000 2.825";
    infile.str() += "0.000 2.825 2.825";
    infile.str() += "2";
    infile.str() += "Ge 0 0 0\n";
    infile.str() += "Ge 0.25 0.25 0.25\n";
	coordinates->read(infile);


}


}
