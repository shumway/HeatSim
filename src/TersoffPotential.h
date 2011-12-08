#ifndef __TersoffPotential_h_
#define __TersoffPotential_h_

class TersoffPotential {
public:

	TersoffPotential();

	double evalPotential(double r,
			double r1, double cosTheta1,
			double r2, double cosTheta2,
			double r3, double cosTheta3) const;

	double getInnerCutoff() const {return innerCutoff;}
	double getOuterCutoff() const {return outerCutoff;}

	double evalCutoffTerm(double r) const;
	double evalAngularTerm(double cosTheta) const;
    double evalBTerm(double r1, double cosTheta1,
    		double r2, double cosTheta2, double r3, double cosTheta3) const;

private:

	double innerCutoff;
	double outerCutoff;
	double inverseCutoffDifference;

	double repulsiveEnergy;
	double attractiveEnergy;
	double repulsiveDecay;
	double attractiveDecay;

	double c2;
	double d2;
	double h;
	double exponent;
	double beta;

	void initializeForGermainium();

	static const double angstromPerBohr;
	static const double eVPerHartree;
	static const double PI;
};


#endif
