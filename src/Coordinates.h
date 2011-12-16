#ifndef __Coordinates_h_
#define __Coordinates_h_

class Location;

class Coordinates {
public:
    Coordinates(int npart);
    ~Coordinates();
    void setLocation(int index, const Location& location);
    const Location& getLocation(int index);
private:
    int npart;
    Location* locations;
};

#endif
