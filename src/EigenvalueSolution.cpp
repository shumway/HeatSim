#include "EigenvalueSolution.h"

EigenvalueSolution::EigenvalueSolution(int size)
    :   size(size), eigenvalueData(new double[size]),
        eigenvectorData(new Complex[size*size]) {
}

EigenvalueSolution::~EigenvalueSolution() {
    delete [] eigenvalueData;
    delete [] eigenvectorData;
}

double EigenvalueSolution::getEigenvalue(int i) const {
    return eigenvalueData[i];
}

double* EigenvalueSolution::getEigenvalueData() {
    return eigenvalueData;
}

EigenvalueSolution::Complex* EigenvalueSolution::getEigenvectorData() {
    return eigenvectorData;
}
