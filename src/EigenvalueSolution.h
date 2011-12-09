#ifndef EIGENVALUESOLUTION_H_
#define EIGENVALUESOLUTION_H_

class EigenvalueSolution {
public:
    EigenvalueSolution(int size);
    ~EigenvalueSolution();

    double getEigenvalue(int i) const;
    double* getEigenvalueData();
    double* getEigenvectorData();
private:
    int size;
    double *eigenvalueData;
    double *eigenvectorData;
};

#endif
