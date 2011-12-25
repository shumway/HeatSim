#ifndef GESTRUCTUREBUILDER_H_
#define GESTRUCTUREBUILDER_H_

class Coordinates;
class LatticeVectors;
class NeighborList;
class Structure;

class GeStructureBuilder {
public:
    static Structure* makeNewStructure();
    static const double bondLength;
private:
    static Coordinates* makeNewCoordinates();
    static LatticeVectors* makeNewLatticeVectors();
    static NeighborList* makeNewNeighborList();
};

#endif
