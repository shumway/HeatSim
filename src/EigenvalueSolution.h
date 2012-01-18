#ifndef EIGENVALUESOLUTION_H_
#define EIGENVALUESOLUTION_H_
#include <complex>

class EigenvalueSolution {
public:
    typedef std::complex<double> Complex;
    EigenvalueSolution(int size);
    ~EigenvalueSolution();

    double getEigenvalue(int i) const;
    double* getEigenvalueData();
    Complex* getEigenvectorData();
private:
    int size;
    double *eigenvalueData;
    Complex *eigenvectorData;
};

#endif
