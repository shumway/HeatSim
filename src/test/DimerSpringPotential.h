#ifndef DIMERSPRINGPOTENTIAL_H_
#define DIMERSPRINGPOTENTIAL_H_

#include "Potential.h"

class DimerSpringPotential : public Potential {
public:
    DimerSpringPotential(double springConstant);
    virtual ~DimerSpringPotential() {}
    virtual double evaluatePotential(const TersoffBond&) const;
private:
    double springConstant;
};


#endif
