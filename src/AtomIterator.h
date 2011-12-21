#ifndef ATOMITERATOR_H_
#define ATOMITERATOR_H_

class Coordinates;
class NeighborList;
class Atom;

class AtomIterator {
public:
    AtomIterator(const Coordinates*, const NeighborList*);
    ~AtomIterator();
    bool isDone() const;
    void next();
    const Atom& getCurrentAtom();
private:
    int currentIndex;
    const int atomCount;
    const Coordinates* coordinates;
    const NeighborList* neighborList;
    Atom* atom;
    void updateAtomObject();
};
#endif
