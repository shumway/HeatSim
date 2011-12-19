#ifndef DISPLACEMENT_H_
#define DISPLACEMENT_H_

#include <iostream>

class Displacement {
public:
    Displacement();
    Displacement(double x, double y, double z);
    double x;
    double y;
    double z;
    bool operator==(const Displacement& disp) const;
};

std::ostream& operator<<(std::ostream& os, const Displacement& disp);

#endif
