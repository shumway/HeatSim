#include <gtest/gtest.h>
#include <sstream>
#include "GeStructureBuilder.h"
#include "Structure.h"
#include "Coordinates.h"
#include "Location.h"
#include "LatticeVectors.h"
#include "NeighborList.h"
#include "Displacement.h"

namespace {

class GeStructureBuilderTest: public ::testing::Test {
protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

TEST_F(GeStructureBuilderTest, testNewCoordinates) {
    Coordinates* coordinates = GeStructureBuilder::makeNewCoordinates();
    ASSERT_EQ(2, coordinates->getAtomCount());
    ASSERT_EQ(Location(0,0,0), coordinates->getLocation(0));
    double bondLength = GeStructureBuilder::bondLength;
    double x = bondLength/sqrt(3.0);
    ASSERT_EQ(Location(x, x, x), coordinates->getLocation(1));
    delete coordinates;
}

TEST_F(GeStructureBuilderTest, testNewNeighborList) {
    NeighborList* neighbors = GeStructureBuilder::makeNewNeighborList();
    ASSERT_EQ(4, neighbors->getNeighborCount(0));
    ASSERT_EQ(4, neighbors->getNeighborCount(1));
    delete neighbors;
}

TEST_F(GeStructureBuilderTest, testNewLatticeVectors) {
    LatticeVectors* latticeVectors = GeStructureBuilder::makeNewLatticeVectors();
    double bondLength = GeStructureBuilder::bondLength;
    double a = 4.0 * bondLength / sqrt(3.0);
    ASSERT_EQ(Displacement(a/2, a/2, 0.0), latticeVectors->getVector(0));
    ASSERT_EQ(Displacement(a/2, 0.0, a/2), latticeVectors->getVector(1));
    ASSERT_EQ(Displacement(0.0, a/2, a/2), latticeVectors->getVector(2));
    delete latticeVectors;
}

}
