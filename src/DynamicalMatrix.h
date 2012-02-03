#ifndef __DynamicalMatrix_h_
#define __DynamicalMatrix_h_

class TotalEnergy;
class Structure;
class Matrix;
class Displacement;
class EigenvalueSolution;
class KVector;

class DynamicalMatrix {
public:
    DynamicalMatrix(const TotalEnergy*, Structure*);
    ~DynamicalMatrix();

    int getSize() const;
    void calculateDynamicalMatrix(double delta);
    void diagonalizeAtKPoint(const KVector&);
    double getFrequency(int index) const;
private:
    const TotalEnergy *totalEnergy;
    Structure *structure;
    const int atomCount;
    const int size;
    double delta;
    Displacement* displacement;
    Matrix *matrixAtGammaPoint;
    Matrix *matrixAtKPoint;
    EigenvalueSolution *solution;
    double *frequency;
    void calculateMatrixAtKPoint(const KVector&);
    void calculateMatrixElement(int index1, int index2);
    void calculateMatrix(double delta);
};
#endif
