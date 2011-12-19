#include "LatticeVectors.h"

LatticeVectors::LatticeVectors(const Displacement& a1,
        const Displacement& a2, const Displacement& a3)
    :   a1(a1), a2(a2), a3(a3) {
}

const Displacement& LatticeVectors::getVector(int index) const {
    if (index==0) {
        return a1;
    } else if (index==1) {
        return a2;
    } else {
        return a3;
    }
}
