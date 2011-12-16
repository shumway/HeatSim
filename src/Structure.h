#ifndef STRUCTURE_H_
#define STRUCTURE_H_

class Coordinates;

class Structure {
public:
    Structure();
    ~Structure();

    void setCoordinates(Coordinates* coordinates);
private:
    Coordinates* coordinates;
};
#endif
