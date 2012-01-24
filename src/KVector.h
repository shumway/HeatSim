#ifndef KVECTOR_H_
#define KVECTOR_H_

#include <iostream>
class Location;
class Displacement;

class KVector {
public:
    KVector();
    KVector(double x, double y, double z);

    bool operator==(const KVector&) const;
    KVector operator*(double scale) const;
    double length() const;

    double x;
    double y;
    double z;
};

std::ostream& operator<<(std::ostream& os, const KVector& disp);

double dot(const KVector&, const Location&);
double dot(const KVector&, const Displacement&);

#endif
