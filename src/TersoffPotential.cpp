#include "TersoffPotential.h"
#include <cmath>
#include "TersoffBond.h"


TersoffPotential::TersoffPotential() {
    initializeForGermainium();
}

double TersoffPotential::evaluatePotential(const TersoffBond& bond) const {
    double value = repulsiveEnergy * exp(-repulsiveDecay * bond.r0);
    double bterm = evalBTerm(bond);
    value -= bterm * attractiveEnergy * exp(-attractiveDecay * bond.r0);
    value *= evalCutoffTerm(bond.r0);
    return value;
}

double TersoffPotential::evalCutoffTerm(double r) const {
    if (r < innerCutoff) {
        return 1.0;
    } else if (r < outerCutoff) {
        return 0.5 + 0.5 * cos(PI * (r - innerCutoff) * inverseCutoffDifference);
    } else {
        return 0.0;
    }
}

double TersoffPotential::evalAngularTerm(double cosTheta) const {
    return 1.0 + c2 / d2 - c2 / (d2 + (h - cosTheta) * (h - cosTheta));
}

double TersoffPotential::evalBTerm(const TersoffBond& bond) const {
    double zeta = 0.0;
    zeta += evalCutoffTerm(bond.r1) * evalAngularTerm(bond.cosTheta1);
    zeta += evalCutoffTerm(bond.r2) * evalAngularTerm(bond.cosTheta2);
    zeta += evalCutoffTerm(bond.r3) * evalAngularTerm(bond.cosTheta3);
    double bterm = pow(1.0 + pow(beta * zeta, exponent), -0.5 / exponent);
    return bterm;
}
void TersoffPotential::initializeForGermainium() {
    // Table 1 of PRB 39, 5566 (1989).
    repulsiveEnergy = 1.769e3 / eVPerHartree;
    attractiveEnergy = 4.1923e2 / eVPerHartree;
    repulsiveDecay = 2.4451 * angstromPerBohr;
    attractiveDecay = 1.7047 * angstromPerBohr;
    beta = 9.0166e-7;
    exponent = 7.5627e-1;
    c2 = pow(1.0643e5, 2);
    d2 = pow(1.5652e1, 2);
    h = -4.3884e-1;
    innerCutoff = 2.8 / angstromPerBohr;
    outerCutoff = 3.1 / angstromPerBohr;
    inverseCutoffDifference = 1. / (outerCutoff - innerCutoff);
}

const double TersoffPotential::angstromPerBohr = 0.529177;
const double TersoffPotential::eVPerHartree = 27.211396;
const double TersoffPotential::PI = acos(-1.0);
