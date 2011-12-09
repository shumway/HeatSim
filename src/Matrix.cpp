#include "Matrix.h"
#include "EigenvalueSolution.h"
#include <complex>

//extern "C" void zhpev_(const char *jobz, const char *uplo, const int *n,
//  const std::complex<double>* ap, const double *w,
//  std::complex<double>* z, const int *ldz, std::complex<double> *work,
//  const double *rwork, const int *info);

extern "C" void dsyev_(const char *jobz, const char *uplo, const int *n,
  const double* a, const int* lda,const double *w,
  double *work, const int *rwork, const int *info);

Matrix::Matrix(int size) :
        size(size), data(new double[size * size]) {
    for (int i = 0; i < size; ++i) {
        data[i] = 0;
    }
}

Matrix::~Matrix() {
    delete[] data;
}

double& Matrix::operator()(int row, int col) {
    return data[row + size * col];
}

EigenvalueSolution* Matrix::diagonalize() const {
    EigenvalueSolution* solution = new EigenvalueSolution(size);
    double *eigenvalues = solution->getEigenvalueData();
    double *eigenvectors = solution->getEigenvectorData();
    for (int i = 0; i < size*size; ++i) {
        eigenvectors[i] = data[i];
    }
    const char jobz='V', uplo='U';
    int info;
    int lwork = 10*size;
    double* work = new double[lwork];
    dsyev_(&jobz, &uplo, &size, eigenvectors, &size, eigenvalues,
           work, &lwork, &info);
    delete [] work;
    return solution;
}
