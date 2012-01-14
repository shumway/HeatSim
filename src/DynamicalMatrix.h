#ifndef __DynamicalMatrix_h_
#define __DynamicalMatrix_h_

#include <blitz/array.h>

class TotalEnergy;
class Structure;
class Matrix;

class DynamicalMatrix {
public:
    DynamicalMatrix(const TotalEnergy*, Structure*);
    ~DynamicalMatrix();

    int getSize() const;
    void calculate(double delta);
    double getFrequency(int index) const;
private:
    const TotalEnergy *totalEnergy;
    Structure *structure;
    const int atomCount;
    const int size;
    Matrix *matrix;
    double *frequency;
    void calculateMatrix(double delta);
};

#endif
