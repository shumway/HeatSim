#ifndef BONDGEOMETRY_H_
#define BONDGEOMETRY_H_

class BondList;
class Structure;
class Atom;

class BondGeometry {
public:
    BondGeometry(int bondCount);
    ~BondGeometry();

    void initializeBonds(int bondCount);

    void calculateCurrentBondGeometry(Structure& structure);

    const BondList* getBonds() const;

private:
    BondList* bonds;
    void setBondsForAnAtom(const Atom&, int& bondIndex);
};
#endif
