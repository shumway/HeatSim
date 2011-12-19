#include <gtest/gtest.h>
#include <sstream>
#include "Structure.h"
#include "Coordinates.h"
#include "Location.h"
#include "LatticeVectors.h"
#include "NeighborList.h"

namespace {

class StructureTest: public ::testing::Test {
protected:

    virtual void SetUp() {
        structure = new Structure();
    }

    virtual void TearDown() {
        delete structure;
    }

    Structure* structure;

    Coordinates* makeNewGeCoordinates() {
        int npart = 2;
        Coordinates* coords = new Coordinates(npart);
        coords->setCartesianLocation(1, Location(1,1,1));
        return coords;
    }

    LatticeVectors* makeNewGeLatticeVectors() {
        return new LatticeVectors(
                Displacement(1,0,0),
                Displacement(0,1,0),
                Displacement(0,0,1)
        );
    }

    NeighborList* makeNewGeNeighborList() {
        NeighborList* neighborList = new NeighborList(2);
        return neighborList;
    }
};

TEST_F(StructureTest, testCreate) {
    Coordinates* coords = makeNewGeCoordinates();
    structure->setCoordinates(coords);
    const LatticeVectors* latticeVectors = makeNewGeLatticeVectors();
    structure->setLatticeVectors(latticeVectors);
    const NeighborList* neighborList = makeNewGeNeighborList();
    structure->setNeighborList(neighborList);
}

}
