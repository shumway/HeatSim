#ifndef __TersoffPotential_h_
#define __TersoffPotential_h_

#include "Potential.h"
class TersoffBond;

class TersoffPotential : public Potential {
public:

    TersoffPotential();
    virtual ~TersoffPotential() {}

    virtual double evaluatePotential(const TersoffBond&) const;

    double getInnerCutoff() const {
        return innerCutoff;
    }
    double getOuterCutoff() const {
        return outerCutoff;
    }

    double evalCutoffTerm(double r) const;
    double evalAngularTerm(double cosTheta) const;
    double evalBTerm(const TersoffBond& bond) const;

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
