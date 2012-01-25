#ifndef RECIPROCALLATTICEVECTORS_H_
#define RECIPROCALLATTICEVECTORS_H_

#include "KVector.h"
class LatticeVectors;
class Displacement;

class ReciprocalLatticeVectors {
public:
    ReciprocalLatticeVectors(const KVector& b1,
            const KVector& b2,const KVector& b3);
    ReciprocalLatticeVectors(const LatticeVectors&);

    const KVector& getVector(int index) const;
    KVector getKVectorFromPrimativeBasis(
            double c1, double c2, double c3) const;
private:
    KVector b1;
    KVector b2;
    KVector b3;
    static const double PI;
    static KVector cross(const Displacement&, const Displacement&);
};
#endif
