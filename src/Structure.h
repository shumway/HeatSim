#ifndef STRUCTURE_H_
#define STRUCTURE_H_

class Coordinates;
class LatticeVectors;
class ReciprocalLatticeVectors;
class NeighborList;
class Neighbor;
class AtomIterator;
class Displacement;
class Location;

class Structure {
public:
    Structure(int natom);
    virtual ~Structure();

    void setCoordinates(Coordinates* coordinates);
    Coordinates* getCoordinates();
    const Location& getCoordinate(int) const;
    void setLatticeVectors(const LatticeVectors* latticeVectors);
    const LatticeVectors* getLatticeVectors() const;
    const ReciprocalLatticeVectors *getReciprocalLatticeVectors() const;
    void setNeighborList(const NeighborList* neighborList);
    const NeighborList* getNeighborList() const;

    int getAtomCount() const;
    AtomIterator getAtomIterator() const;
    int getBondCount() const;

    void moveAtom(int index, const Displacement&);
    void setMass(int index, double mass);
    double getMass(int index) const;
private:
    const int atomCount;
    Coordinates *coordinates;
    const LatticeVectors *latticeVectors;
    const ReciprocalLatticeVectors *reciprocalLatticeVectors;
    const NeighborList *neighborList;
    double *mass;
};
#endif
