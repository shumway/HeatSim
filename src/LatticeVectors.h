#ifndef LATTICEVECTORS_H_
#define LATTICEVECTORS_H_

#include "Displacement.h"

class LatticeVectors {
public:
    LatticeVectors(const Displacement& a1,
            const Displacement& a2,const Displacement& a3);
    const Displacement& getVector(int index) const;
private:
    Displacement a1;
    Displacement a2;
    Displacement a3;
};
#endif
