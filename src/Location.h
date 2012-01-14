#ifndef __Location_h_
#define __Location_h_

#include <iostream>
class Displacement;

class Location {
public:
    Location(double x, double y, double z);
    Location();

    bool operator==(const Location& loc2) const;

    Location& operator+=(const Displacement& displacement);
    Location& operator-=(const Displacement& displacement);

    double x;
    double y;
    double z;
};



std::ostream& operator<<(std::ostream& os, const Location& loc);

#endif
