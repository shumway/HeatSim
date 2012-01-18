#include "BondList.h"
#include "TersoffBond.h"

BondList::BondList(int count)
:   count(count), bonds(new TersoffBond[count]) {
}

BondList::~BondList() {
    delete [] bonds;
}

TersoffBond* BondList::getBond(int index) {
    return &bonds[index];
}

const TersoffBond* BondList::getBond(int index) const {
    return &bonds[index];
}

int BondList::getCount() const {
    return count;
}
