#include "Displacement.h"
#include "Location.h"

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
