#ifndef __DynamicalMatrix_h_
#define __DynamicalMatrix_h_

class TotalEnergy;
class Structure;

class DynamicalMatrix {
public:
    DynamicalMatrix(const TotalEnergy*, Structure*);
    ~DynamicalMatrix();

    int getSize() const;
private:
    const TotalEnergy *totalEnergy;
    Structure *structure;
    const int size;
};

#endif
