#include "TersoffPotential.h"
#include <cmath>


TersoffPotential::TersoffPotential() {
	initializeForGermainium();
}

void TersoffPotential::initializeForGermainium() {
	// Table 1 of PRB 39, 5566 (1989).
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


const double TersoffPotential::angstromPerBohr = 1./0.529177;
const double TersoffPotential::PI = acos(-1.0);
