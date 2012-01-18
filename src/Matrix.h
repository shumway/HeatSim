#ifndef __Matrix_h_
#define __Matrix_h_

#include <complex>
class EigenvalueSolution;

class Matrix {
public:
    typedef std::complex<double> Complex;

    Matrix(int size);
    ~Matrix();

    Complex& operator()(int row, int col);

    void diagonalize(EigenvalueSolution *solution) const;
    EigenvalueSolution* diagonalize() const;
private:
    int size;
    Complex* data;
};

#endif
