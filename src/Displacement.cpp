#include "Displacement.h"
#include "Location.h"
#include <cmath>

Displacement::Displacement(double x, double y, double z)
    :   x(x), y(y), z(z) {
}
Displacement::Displacement()
    :   x(0), y(0), z(0) {
}

Displacement::Displacement(const Location & to, const Location & from)
    :   x(to.x-from.x), y(to.y-from.y), z(to.z-from.z) {
}

bool Displacement::operator==(const Displacement& disp2) const {
    return x==disp2.x && y==disp2.y && z==disp2.z;
}



std::ostream& operator<<(std::ostream& os, const Displacement& disp) {
    os << "(" << disp.x << ", " << disp.y << ", " << disp.z << ")";
    return os;
}

Displacement& Displacement::operator +=(const Displacement& disp) {
    this->x += disp.x; this->y += disp.y; this->z += disp.z;
    return *this;
}

Displacement Displacement::operator *(const double scale) const {
    Displacement result(*this);
    result.x *= scale;
    result.y *= scale;
    result.z *= scale;
    return result;
}

double dot(const Displacement & d1, const Displacement & d2) {
    return d1.x*d2.x + d1.y*d2.y + d1.z*d2.z;
}

double Displacement::length() const {
    return sqrt(x*x + y*y + z*z);
}




