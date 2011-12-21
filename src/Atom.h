#ifndef ATOM_H_
#define ATOM_H_

#include "Displacement.h"

class Atom {
public:
    int getNeighborCount() const;
    void setNeighborCount(int neighborCount);
    const Displacement& getDisplacement(int index) const;
    void setDisplacement(int index, const Displacement&);
private:
    static const int MAX_NEIGHBORS=4;
    Displacement displacement[MAX_NEIGHBORS];
    int neighborCount;
};

#endif
