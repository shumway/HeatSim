#include <gtest/gtest.h>
#include <sstream>
#include "Structure.h"
#include "Coordinates.h"
#include "Location.h"

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
        coords->setLocation(1, Location(1,1,1));
        return coords;
    }
};

TEST_F(StructureTest, testCreate) {
    Coordinates* coords = makeNewGeCoordinates();
    structure->setCoordinates(coords);
}

}
