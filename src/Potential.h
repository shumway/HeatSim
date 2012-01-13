#ifndef POTENTIAL_H_
#define POTENTIAL_H_

class TersoffBond;

class Potential {
public:
    virtual double evaluatePotential(const TersoffBond&) const=0;
    virtual ~Potential() {}
};
#endif
