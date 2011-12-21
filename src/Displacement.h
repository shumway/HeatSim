#ifndef DISPLACEMENT_H_
#define DISPLACEMENT_H_

#include <iostream>
class Location;

class Displacement {
public:
    Displacement();
    Displacement(double x, double y, double z);
    Displacement(const Location& to, const Location& from);

    bool operator==(const Displacement& disp) const;
    Displacement& operator+=(const Displacement& disp);
    Displacement operator*(const double scale) const;

    double x;
    double y;
    double z;
};

std::ostream& operator<<(std::ostream& os, const Displacement& disp);

double dot(const Displacement&, const Displacement&);

#endif
