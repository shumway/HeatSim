#include "Location.h"
#include "Displacement.h"

Location::Location(double x, double y, double z)
    :   x(x), y(y), z(z) {
}
Location::Location()
    :   x(0), y(0), z(0) {
}

bool Location::operator==(const Location& loc2) const {
    return x==loc2.x && y==loc2.y && z==loc2.z;
}



std::ostream& operator<<(std::ostream& os, const Location& loc) {
    os << "(" << loc.x << ", " << loc.y << ", " << loc.z << ")";
    return os;
}

Location & Location::operator +=(const Displacement & displacement) {
    x += displacement.x;
    y += displacement.y;
    z += displacement.z;
    return *this;
}

Location & Location::operator -=(const Displacement & displacement) {
    x -= displacement.x;
    y -= displacement.y;
    z -= displacement.z;
    return *this;
}

Displacement operator -(const Location & r1, const Location & r2) {
    Displacement delta;
    delta.x = r1.x - r2.x;
    delta.y = r1.y - r2.y;
    delta.x = r1.z - r2.z;
}


