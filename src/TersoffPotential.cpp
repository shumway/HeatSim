#include "TersoffPotential.h"
#include <cmath>


TersoffPotential::TersoffPotential() {
	initializeForGermainium();
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
	inverseCutoffDifference = 1./(outerCutoff-innerCutoff);
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


double TersoffPotential::evalBTerm(double r1, double cosTheta1, double r2, double cosTheta2, double r3, double cosTheta3) const
{
    double zeta = 0.0;
    zeta += evalCutoffTerm(r1) * evalAngularTerm(cosTheta1);
    zeta += evalCutoffTerm(r2) * evalAngularTerm(cosTheta2);
    zeta += evalCutoffTerm(r3) * evalAngularTerm(cosTheta3);
    double bterm = pow(1.0 + pow(beta * zeta, exponent), -0.5 / exponent);
    return bterm;
}

double TersoffPotential::evalPotential(double r,
		double r1, double cosTheta1,
		double r2, double cosTheta2,
		double r3, double cosTheta3) const {
	double value = repulsiveEnergy*exp(-repulsiveDecay*r);
	double bterm = evalBTerm(r1, cosTheta1, r2, cosTheta2, r3, cosTheta3);
	value -= bterm * attractiveEnergy*exp(-attractiveDecay*r);
	value *= evalCutoffTerm(r);
	return value;
}


const double TersoffPotential::angstromPerBohr = 1./0.529177;
const double TersoffPotential::eVPerHartree = 27.211396;
const double TersoffPotential::PI = acos(-1.0);
