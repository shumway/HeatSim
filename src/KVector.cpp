#include "KVector.h"
#include "Location.h"
#include "Displacement.h"
#include <cmath>

KVector::KVector(double x, double y, double z)
    :   x(x), y(y), z(z) {
}
KVector::KVector()
    :   x(0), y(0), z(0) {
}


bool KVector::operator==(const KVector& k) const {
    return x==k.x && y==k.y && z==k.z;
}

KVector KVector::operator*(double scale) const {
    return KVector(x*scale, y*scale, z*scale);
}

std::ostream& operator<<(std::ostream& os, const KVector& disp) {
    os << "(" << disp.x << ", " << disp.y << ", " << disp.z << ")";
    return os;
}

double dot(const KVector & k, const Location & r) {
    return k.x*r.x + k.y*r.y + k.z*r.z;
}

double dot(const KVector & k, const Displacement & r) {
    return k.x*r.x + k.y*r.y + k.z*r.z;
}

double KVector::length() const {
    return sqrt(x*x + y*y + z*z);
}
