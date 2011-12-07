#ifndef __TersoffPotential_h_
#define __TersoffPotential_h_

class TersoffPotential {
public:

	TersoffPotential();

	double evalCutoffTerm(double r) const;
	double evalRadialPotential(double r) const;

	double getInnerCutoff() const {return innerCutoff;}
	double getOuterCutoff() const {return outerCutoff;}

private:

	double innerCutoff;
	double outerCutoff;
	double inverseCutoffDifference;

	double repulsiveEnergy;
	double attractiveEnergy;
	double repulsiveDecay;
	double attractiveDecay;

	void initializeForGermainium();

	static const double angstromPerBohr;
	static const double eVPerHartree;
	static const double PI;
};


#endif
