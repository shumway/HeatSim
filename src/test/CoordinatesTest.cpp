#include <gtest/gtest.h>
#include <sstream>
#include "Coordinates.h"
#include "Location.h"

namespace {

class CoordinatesTest: public ::testing::Test {
protected:

    virtual void SetUp() {
        coordinates = 0;
    }

    virtual void TearDown() {
        delete coordinates;
    }

    Coordinates* coordinates;
};

TEST_F(CoordinatesTest, testCreate) {
    int npart = 2;
    coordinates = new Coordinates(npart);
    coordinates->setLocation(0, Location(0,0,0));
    coordinates->setLocation(1, Location(0.25,0.25,0.25));
    Location location0 = coordinates->getLocation(0);
    Location location1 = coordinates->getLocation(1);
    ASSERT_EQ(Location(0,0,0), location0);
    ASSERT_EQ(Location(0.25,0.25,0.25), location1);
}

}
