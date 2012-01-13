#include "TotalEnergy.h"
#include "Structure.h"
#include "TersoffPotential.h"
#include "BondGeometry.h"
#include "BondList.h"

TotalEnergy::TotalEnergy(const Structure* structure,
        const TersoffPotential* potential)
:   structure(structure), potential(potential),
    bondGeometry(new BondGeometry(structure->getBondCount())){

}

TotalEnergy::~TotalEnergy() {
}

double TotalEnergy::getEnergy() const {
    double energy = 0.0;
    bondGeometry->calculateCurrentBondGeometry(*structure);
    const BondList* bonds = bondGeometry->getBonds();
    for (int i=0; i<bonds->getCount(); ++i) {
        const TersoffBond *bond = bonds->getBond(i);
        energy += 0.5 * potential->evaluatePotential(*bond);
    }
    return energy;
}
