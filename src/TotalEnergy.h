#ifndef TOTALENERGY_H_
#define TOTALENERGY_H_

class Structure;
class Potential;
class BondGeometry;

class TotalEnergy {
public:
    TotalEnergy(const Structure* structure, const Potential* potential);
    ~TotalEnergy();

    double getEnergy() const;
private:

    const Structure *structure;
    const Potential *potential;
    BondGeometry *bondGeometry;
};
#endif
