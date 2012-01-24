#include "ReciprocalLatticeVectors.h"
#include "LatticeVectors.h"

ReciprocalLatticeVectors::ReciprocalLatticeVectors(const KVector& b1,
        const KVector& b2, const KVector& b3)
    :   b1(b1), b2(b2), b3(b3) {
}

ReciprocalLatticeVectors::ReciprocalLatticeVectors(const LatticeVectors& vectors) {
    double normalization = 2*PI / vectors.getSignedVolume();
    Displacement a1 = vectors.getVector(0);
    Displacement a2 = vectors.getVector(1);
    Displacement a3 = vectors.getVector(2);
    b1 = cross(a2, a3) * normalization;
    b2 = cross(a3, a1) * normalization;
    b3 = cross(a1, a2) * normalization;
}

KVector ReciprocalLatticeVectors::cross(const Displacement &v1, const Displacement &v2) {
    return KVector(v1.y*v2.z-v1.z*v2.y, v1.z*v2.x-v1.x*v2.z, v1.x*v2.y-v1.y*v2.x);
}


const KVector& ReciprocalLatticeVectors::getVector(int index) const {
    if (index==0) {
        return b1;
    } else if (index==1) {
        return b2;
    } else {
        return b3;
    }
}

const double ReciprocalLatticeVectors::PI = 3.141592653589793;
