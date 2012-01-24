#include "Matrix.h"
#include "EigenvalueSolution.h"
#include <complex>

extern "C" void zheev_(const char *jobz, const char *uplo, const int *n,
        Matrix::Complex* a, const int *lda, const double *w,
        Matrix::Complex *work, const int *lwork, const double *rwork,
        int *info);

Matrix::Matrix(int size) :
        size(size), data(new Complex[size * size]) {
    for (int i = 0; i < size; ++i) {
        data[i] = 0;
    }
}

Matrix::~Matrix() {
    delete[] data;
}

Matrix::Complex& Matrix::operator()(int row, int col) {
    return data[row + size * col];
}

void Matrix::diagonalize(EigenvalueSolution *solution) const
{
    double *eigenvalues = solution->getEigenvalueData();
    Complex *eigenvectors = solution->getEigenvectorData();
    for(int i = 0;i < size * size;++i){
        eigenvectors[i] = data[i];
    }
    const char jobz = 'V', uplo = 'U';
    int info;
    int lwork = 2 * size;
    Complex *work = new Complex[lwork];
    double *rwork = new double[3*size];
    zheev_(&jobz, &uplo, &size, eigenvectors, &size, eigenvalues, work,
            &lwork, rwork, &info);
    delete [] work;
    delete [] rwork;
}

EigenvalueSolution* Matrix::diagonalize() const {
    EigenvalueSolution* solution = new EigenvalueSolution(size);
    diagonalize(solution);
    return solution;
}
