#include <gtest/gtest.h>
#include "NeighborList.h"
#include "Neighbor.h"
#include "LatticeDisplacement.h"

namespace {

class NeighborListTest: public ::testing::Test {
protected:

    virtual void SetUp() {
    }

    virtual void TearDown() {
    }

    NeighborList* list;

    void createLoneAtom() {
        int atomCount = 1;
        list = new NeighborList(atomCount);
    }

    void createDimer() {
        int atomCount = 2;
        list = new NeighborList(atomCount);
        int atomIndex = 0;
        int neighborIndex = 1;
        LatticeDisplacement delta(0,0,0);
        list->addNeighbor(atomIndex, neighborIndex, delta);
        list->addNeighbor(neighborIndex, atomIndex, -delta);
    }

};

TEST_F(NeighborListTest, testLoneAtomHasNoNeighbors) {
    createLoneAtom();
    int atomIndex = 0;
    int count = list->getNeighborCount(atomIndex);
    ASSERT_EQ(0, count);
}

TEST_F(NeighborListTest, testFirstDimerAtomHasOneNeighbor) {
    createDimer();
    int atomIndex = 0;
    int count = list->getNeighborCount(atomIndex);
    ASSERT_EQ(1, count);
}
TEST_F(NeighborListTest, testSecondDimerAtomHasOneNeighbor) {
    createDimer();
    int atomIndex = 1;
    int count = list->getNeighborCount(atomIndex);
    ASSERT_EQ(1, count);
}

}
