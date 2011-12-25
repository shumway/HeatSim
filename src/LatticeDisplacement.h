#ifndef LATTICEDISPLACEMENT_H_
#define LATTICEDISPLACEMENT_H_

class LatticeDisplacement {
public:
    LatticeDisplacement(int x, int y, int z)
        : x(x), y(y), z(z) {
    }
    int x;
    int y;
    int z;

    LatticeDisplacement operator-() const {
        return LatticeDisplacement(-x, -y, -z);
    }

};
#endif
