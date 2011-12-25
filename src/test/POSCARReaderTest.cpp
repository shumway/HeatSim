#include <gtest/gtest.h>
#include <sstream>
#include "POSCARReader.h"

namespace {

class POSCARReaderTest: public ::testing::Test {
protected:

    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

TEST_F(POSCARReaderTest, testReadPoscarFile) {
    std::stringstream infile;

    infile.str() += "#Some comment";
    infile.str() += "1.0";
    infile.str() += "2.825 2.825 0.000";
    infile.str() += "2.825 0.000 2.825";
    infile.str() += "0.000 2.825 2.825";
    infile.str() += "Ge";
    infile.str() += "2";
    infile.str() += "Direct";
    infile.str() += "0 0 0\n";
    infile.str() += "0.25 0.25 0.25\n";
    POSCARReader::read(infile);

}

}
