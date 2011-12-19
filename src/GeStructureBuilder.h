#ifndef GESTRUCTUREBUILDER_H_
#define GESTRUCTUREBUILDER_H_

class Coordinates;
class LatticeVectors;
class NeighborList;

class GeStructureBuilder {
public:
    static Coordinates* makeNewCoordinates();
    static LatticeVectors* makeNewLatticeVectors();
    static NeighborList* makeNewNeighborList();
    static const double bondLength;
};

#endif
