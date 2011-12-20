#ifndef BONDLIST_H_
#define BONDLIST_H_

class TersoffBond;

class BondList{
public:
    BondList(int count);
    ~BondList();

    TersoffBond* getBond(int index);
    const TersoffBond* getBond(int index) const;
private:
    TersoffBond* bonds;
    int count;
};
#endif
