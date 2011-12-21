#include <gtest/gtest.h>

#include "DimerTestStructure.h"
#include "GeStructureBuilder.h"
#include "AtomIterator.h"
#include "Atom.h"

#include <iostream>

namespace {

class AtomIteratorTest: public ::testing::Test {
protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }

};


TEST_F(AtomIteratorTest, testIteratorCount) {
    DimerTestStructure structure;
    int count = 0;
    for (AtomIterator iterator = structure.getAtomIterator();
            !iterator.isDone(); iterator.next()) {
        ++count;
    }
    int expect = structure.getAtomCount();
    ASSERT_EQ(expect, count);
}

TEST_F(AtomIteratorTest, testFirstDimerAtom) {
    DimerTestStructure structure;
    AtomIterator iterator = structure.getAtomIterator();
    Atom atom = iterator.getCurrentAtom();
    int neighborCount = atom.getNeighborCount();
    Displacement displacement = atom.getDisplacement(0);
    ASSERT_EQ(1, neighborCount);
    ASSERT_EQ(Displacement(1,0,0), displacement);
}


TEST_F(AtomIteratorTest, testSecondDimerAtom) {
    DimerTestStructure structure;
    AtomIterator iterator = structure.getAtomIterator();
    iterator.next();
    Atom atom = iterator.getCurrentAtom();
    int neighborCount = atom.getNeighborCount();
    Displacement displacement = atom.getDisplacement(0);
    ASSERT_EQ(1, neighborCount);
    ASSERT_EQ(Displacement(-1,0,0), displacement);
}

TEST_F(AtomIteratorTest, testFirstGeAtom) {
    Structure* structure = GeStructureBuilder::makeNewStructure();
    AtomIterator iterator = structure->getAtomIterator();
    Atom atom = iterator.getCurrentAtom();
    int neighborCount = atom.getNeighborCount();
    double bondLength = GeStructureBuilder::bondLength;
    double a = 4.0 * bondLength / sqrt(3.0);
    ASSERT_EQ(4, neighborCount);
    ASSERT_EQ(Displacement( a/4, a/4, a/4), atom.getDisplacement(0));
    ASSERT_EQ(Displacement(-a/4,-a/4, a/4), atom.getDisplacement(1));
    ASSERT_EQ(Displacement(-a/4, a/4,-a/4), atom.getDisplacement(2));
    ASSERT_EQ(Displacement( a/4,-a/4,-a/4), atom.getDisplacement(3));
    delete structure;
}



}
