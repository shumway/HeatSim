#ifndef DIMERTESTSTRUCTURE_CPP_
#define DIMERTESTSTRUCTURE_CPP_

#include "DimerTestStructure.h"
#include "Coordinates.h"
#include "NeighborList.h"
#include "LatticeDisplacement.h"
#include "Location.h"

DimerTestStructure::DimerTestStructure() {
    int npart = 2;
    Coordinates* coordinates = new Coordinates(npart);
    coordinates->setCartesianLocation(1, Location(1, 0, 0));
    setCoordinates(coordinates);

    NeighborList* neighborList = new NeighborList(2);
    neighborList->addNeighbor(0, 1, LatticeDisplacement( 0, 0, 0));
    neighborList->addNeighbor(1, 0, LatticeDisplacement( 0, 0, 0));
    setNeighborList(neighborList);
}

DimerTestStructure::~DimerTestStructure() {
}
#endif
