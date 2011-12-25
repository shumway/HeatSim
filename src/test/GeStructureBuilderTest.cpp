#include <gtest/gtest.h>
#include <sstream>
#include <cmath>
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
        structure = GeStructureBuilder::makeNewStructure();
    }

    virtual void TearDown() {
        delete structure;
    }

    Structure* structure;
};

TEST_F(GeStructureBuilderTest, testNewCoordinates) {
    Coordinates* coordinates = structure->getCoordinates();
    ASSERT_EQ(2, coordinates->getAtomCount());
    ASSERT_EQ(Location(0,0,0), coordinates->getLocation(0));
    double bondLength = GeStructureBuilder::bondLength;
    double x = bondLength/sqrt(3.0);
    ASSERT_EQ(Location(x, x, x), coordinates->getLocation(1));
}

TEST_F(GeStructureBuilderTest, testNewNeighborList) {
    const NeighborList* neighbors = structure->getNeighborList();
    ASSERT_EQ(4, neighbors->getNeighborCount(0));
    ASSERT_EQ(4, neighbors->getNeighborCount(1));
}

TEST_F(GeStructureBuilderTest, testNewLatticeVectors) {
    const LatticeVectors* latticeVectors = structure->getLatticeVectors();
    double bondLength = GeStructureBuilder::bondLength;
    double a = 4.0 * bondLength / sqrt(3.0);
    ASSERT_EQ(Displacement(a/2, a/2, 0.0), latticeVectors->getVector(0));
    ASSERT_EQ(Displacement(a/2, 0.0, a/2), latticeVectors->getVector(1));
    ASSERT_EQ(Displacement(0.0, a/2, a/2), latticeVectors->getVector(2));
}

}
