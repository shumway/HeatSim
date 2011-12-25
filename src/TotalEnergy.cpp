#include "TotalEnergy.h"

TotalEnergy::TotalEnergy(const Structure* structure,
        const TersoffPotential* potential)
:   structure(structure), potential(potential) {

}

TotalEnergy::~TotalEnergy() {
}

double TotalEnergy::getEnergy() const {
    return 0.0;
}
