#ifndef __Coordinates_h_
#define __Coordinates_h_

class Location;
class Displacement;

class Coordinates {
public:
    Coordinates(int npart);
    ~Coordinates();
    void setCartesianLocation(int index, const Location&);
    void shiftAtom(int index, const Displacement&);
    const Location& getLocation(int index) const;
    int getAtomCount() const;
private:
    int npart;
    Location* locations;
};

#endif
