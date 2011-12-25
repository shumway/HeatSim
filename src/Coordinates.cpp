#include "Coordinates.h"
#include "Location.h"

Coordinates::Coordinates(int npart)
    :   npart(npart), locations(new Location[npart]) {
}

Coordinates::~Coordinates() {
    delete [] locations;
}

void Coordinates::setCartesianLocation(int index, const Location& location) {
    locations[index] = location;
}

const Location& Coordinates::getLocation(int index) const {
    return locations[index];
}

int Coordinates::getAtomCount() const {
    return npart;
}