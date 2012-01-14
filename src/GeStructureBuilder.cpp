#include "GeStructureBuilder.h"

#include "Coordinates.h"
#include "Location.h"
#include "LatticeVectors.h"
#include "NeighborList.h"
#include "Structure.h"
#include <cmath>

Structure* GeStructureBuilder::makeNewStructure() {
    Structure* structure = new Structure(2);
    Coordinates* coordinates = makeNewCoordinates();
    structure->setCoordinates(coordinates);
    LatticeVectors* latticeVectors = makeNewLatticeVectors();
    structure->setLatticeVectors(latticeVectors);
    NeighborList* neighborList = makeNewNeighborList();
    structure->setNeighborList(neighborList);
    return structure;
}

Coordinates* GeStructureBuilder::makeNewCoordinates() {
    int npart = 2;
    Coordinates* coordinates = new Coordinates(npart);
    double x = bondLength/sqrt(3.0);
    coordinates->setCartesianLocation(1, Location(x, x, x));
    return coordinates;
}

LatticeVectors* GeStructureBuilder::makeNewLatticeVectors() {
    double a = 4 * bondLength / sqrt(3.0);
    Displacement a1(a/2, a/2, 0.0);
    Displacement a2(a/2, 0.0, a/2);
    Displacement a3(0.0, a/2, a/2);
    return new LatticeVectors(a1, a2, a3);
}

NeighborList* GeStructureBuilder::makeNewNeighborList() {
    NeighborList* neighborList = new NeighborList(2);
    neighborList->addNeighbor(0, 1, LatticeDisplacement( 0, 0, 0));
    neighborList->addNeighbor(0, 1, LatticeDisplacement(-1, 0, 0));
    neighborList->addNeighbor(0, 1, LatticeDisplacement( 0,-1, 0));
    neighborList->addNeighbor(0, 1, LatticeDisplacement( 0, 0,-1));
    neighborList->addNeighbor(1, 0, LatticeDisplacement( 0, 0, 0));
    neighborList->addNeighbor(1, 0, LatticeDisplacement( 1, 0, 0));
    neighborList->addNeighbor(1, 0, LatticeDisplacement( 0, 1, 0));
    neighborList->addNeighbor(1, 0, LatticeDisplacement( 0, 0, 1));
    return neighborList;
}

const double GeStructureBuilder::bondLength = 2*0.122/0.0529177;
