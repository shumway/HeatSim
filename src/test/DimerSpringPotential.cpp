#include "DimerSpringPotential.h"
#include "TersoffBond.h"

DimerSpringPotential::DimerSpringPotential(double springConstant)
    :   springConstant(springConstant) {
}

double DimerSpringPotential::evaluatePotential(
        const TersoffBond & bond) const {
    double delta = bond.r0 - 1.0;
    return 0.5 * springConstant * delta * delta;
}
