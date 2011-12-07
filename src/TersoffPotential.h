#ifndef __TersoffPotential_h_
#define __TersoffPotential_h_

class TersoffPotential {
public:

	TersoffPotential();

	double evalCutoffTerm(double r) const;

	double getInnerCutoff() const {return innerCutoff;}
	double getOuterCutoff() const {return outerCutoff;}

private:

	double innerCutoff;
	double outerCutoff;
	double inverseCutoffDifference;

	void initializeForGermainium();

	static const double angstromPerBohr;
	static const double PI;
};


#endif
