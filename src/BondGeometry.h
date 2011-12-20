#ifndef BONDGEOMETRY_H_
#define BONDGEOMETRY_H_

class BondList;
class TersoffBond;
class Neighbor;
class Structure;

class BondGeometry {
public:
    BondGeometry(int bondCount);
    ~BondGeometry();

    void initializeBonds(int bondCount);

    void calculateCurrentBondGeometry(Structure& structure);

    const BondList* getBonds() const;

private:
    BondList* bonds;
    void setBond(TersoffBond* bond, int atomIndex, const Neighbor* neighbor);
};
#endif
