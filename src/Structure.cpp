#include "Structure.h"
#include "Coordinates.h"

Structure::Structure()
    :   coordinates(0) {
}

Structure::~Structure() {
    delete coordinates;
}

void Structure::setCoordinates(Coordinates* coordinates) {
    this->coordinates = coordinates;
}
