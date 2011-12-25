#ifndef __Location_h_
#define __Location_h_

#include <iostream>

class Location {
public:
    Location(double x, double y, double z);
    Location();

    bool operator==(const Location& loc2) const;

    double x;
    double y;
    double z;
};



std::ostream& operator<<(std::ostream& os, const Location& loc);

#endif
