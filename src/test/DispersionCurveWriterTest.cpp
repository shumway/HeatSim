#include <gtest/gtest.h>
#include <sstream>
#include "DispersionCurveWriter.h"

namespace {

class DispersionCurveWriterTest : public ::testing::Test {
 protected:

  virtual void SetUp() {
	  writer = new DispersionCurveWriter();
	  writer->setKPointCount(3);
	  writer->setBandCount(6);
  }

  virtual void TearDown() {
	  delete writer;
  }

  DispersionCurveWriter* writer;
};

TEST_F(DispersionCurveWriterTest, TestWrite) {
	std::stringstream outStream;
	writer->write(outStream);
	std::string result(outStream.str());
	std::string expect;
	expect += "# Phonon dispersion curve\n";
	expect += "# k omegas\n";
	expect += "0 0.000 0.000 0.000 0.000 0.000 0.000\n";
	expect += "1 0.000 0.000 0.000 0.000 0.000 0.000\n";
	expect += "2 0.000 0.000 0.000 0.000 0.000 0.000\n";
    ASSERT_STREQ(expect.c_str(), result.c_str());
}


}
