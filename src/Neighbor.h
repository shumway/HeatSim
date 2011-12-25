#ifndef NEIGHBOR_H_
#define NEIGHBOR_H_

#include "LatticeDisplacement.h"

class Neighbor {
public:
    Neighbor()
        : index(-1), delta(LatticeDisplacement(0,0,0) ){
    }

    Neighbor(int index, LatticeDisplacement delta)
        : index(index), delta(delta) {
    }

    bool isNull() const {
        return index < 0;
    }

    int index;
    LatticeDisplacement delta;
};

#endif
