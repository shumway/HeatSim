#ifndef STRUCTURE_H_
#define STRUCTURE_H_

class Coordinates;
class LatticeVectors;
class NeighborList;
class Neighbor;

class Structure {
public:
    Structure();
    ~Structure();

    void setCoordinates(Coordinates* coordinates);
    Coordinates* getCoordinates();
    void setLatticeVectors(const LatticeVectors* latticeVectors);
    const LatticeVectors* getLatticeVectors() const;
    void setNeighborList(const NeighborList* neighborList);
    const NeighborList* getNeighborList() const;
private:
    Coordinates* coordinates;
    const LatticeVectors* latticeVectors;
    const NeighborList* neighborList;
};
#endif
