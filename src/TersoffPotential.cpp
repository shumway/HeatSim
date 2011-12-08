#include "TersoffPotential.h"
#include <cmath>


TersoffPotential::TersoffPotential() {
	initializeForGermainium();
}

void TersoffPotential::initializeForGermainium() {
	// Table 1 of PRB 39, 5566 (1989).
	innerCutoff = 2.8 / angstromPerBohr;
	outerCutoff = 3.1 / angstromPerBohr;
	repulsiveEnergy = 1.769e3 / eVPerHartree;
	attractiveEnergy = 4.1923e2 / eVPerHartree;
    repulsiveDecay = 2.4451 * angstromPerBohr;
	attractiveDecay = 1.7047 * angstromPerBohr;
	inverseCutoffDifference = 1./(outerCutoff-innerCutoff);
	c2 = pow(1.0643e5, 2);
	d2 = pow(1.5652e1, 2);
	h = -4.3884e-1;
}

double TersoffPotential::evalCutoffTerm(double r) const {
	if (r < innerCutoff) {
		return 1.0;
	} else if (r < outerCutoff) {
        return 0.5 + 0.5 * cos(PI * (r-innerCutoff) * inverseCutoffDifference);
	} else {
        return 0.0;
	}
}

double TersoffPotential::evalAngularTerm(double cosTheta) const {
    return 1.0 + c2/d2 - c2 / ( d2 + (h-cosTheta)*(h-cosTheta) );
}

double TersoffPotential::evalRadialPotential(double r) const {
	double value = repulsiveEnergy*exp(-repulsiveDecay*r);
	value -= attractiveEnergy*exp(-attractiveDecay*r);
	value *= evalCutoffTerm(r);
	return value;
}


const double TersoffPotential::angstromPerBohr = 1./0.529177;
const double TersoffPotential::eVPerHartree = 27.211396;
const double TersoffPotential::PI = acos(-1.0);
