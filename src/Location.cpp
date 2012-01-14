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
