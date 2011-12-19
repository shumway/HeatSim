#ifndef STRUCTURE_H_
#define STRUCTURE_H_

class Coordinates;
class LatticeVectors;
class NeighborList;

class Structure {
public:
    Structure();
    ~Structure();

    void setCoordinates(Coordinates* coordinates);
    void setLatticeVectors(const LatticeVectors* latticeVectors);
    void setNeighborList(const NeighborList* neighborList);
private:
    Coordinates* coordinates;
    const LatticeVectors* latticeVectors;
    const NeighborList* neighborList;
};
#endif
