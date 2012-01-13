#ifndef TOTALENERGY_H_
#define TOTALENERGY_H_

class Structure;
class TersoffPotential;
class BondGeometry;

class TotalEnergy {
public:
    TotalEnergy(const Structure* structure, const TersoffPotential* potential);
    ~TotalEnergy();

    double getEnergy() const;
private:

    const Structure *structure;
    const TersoffPotential *potential;
    BondGeometry *bondGeometry;
};
#endif
