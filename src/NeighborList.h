
#ifndef NEIGHBORLIST_H_
#define NEIGHBORLIST_H_

#include "LatticeDisplacement.h"
class Neighbor;

class NeighborList {
public:
    NeighborList(int atomCount);
    ~NeighborList();

    void addNeighbor(int atomIndex, int neighborIndex, LatticeDisplacement delta);

    int getNeighborCount(int atomIndex) const;

private:
    Neighbor* theList;
    static const int MAX_NEIGHBORS = 4;
};
#endif
