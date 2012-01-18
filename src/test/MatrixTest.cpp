#include <gtest/gtest.h>
#include <sstream>
#include <complex>
#include "Matrix.h"
#include "EigenvalueSolution.h"

namespace {

class MatrixTest: public ::testing::Test {
protected:

    typedef std::complex<double> Complex;

    virtual void SetUp() {
        size = 3;
        matrix = new Matrix(size);
    }

    virtual void TearDown() {
        delete matrix;
    }

    int size;
    Matrix* matrix;

    void setupSymmetricTestMatrix() {
        int value = 1;
        for (int i=0; i<size; ++i) {
            for (int j=i; j<size; ++j) {
                (*matrix)(i,j) = (*matrix)(j,i) = value;
                ++value;
            }
        }
    }

    void setupZeroMatrix() {
        for (int i=0; i<size; ++i) {
            for (int j=0; j<size; ++j) {
                (*matrix)(i,j) = (*matrix)(j,i) = 0.0;
            }
        }
    }
};

TEST_F(MatrixTest, testAccessElements) {
    (*matrix)(1, 0) = 1.0;
    (*matrix)(0, 1) = 2.0;
    ASSERT_DOUBLE_EQ(1.0, (*matrix)(1,0).real());
    ASSERT_DOUBLE_EQ(2.0, (*matrix)(0,1).real());
}

TEST_F(MatrixTest, testEigenvalues) {
    setupSymmetricTestMatrix();
    EigenvalueSolution* solution = matrix->diagonalize();
    double expect[] = {-0.5157294715892572,  0.1709151888271787, 11.3448142827620835};
    for (int i = 0; i < size; ++i) {
        ASSERT_NEAR(expect[i], solution->getEigenvalue(i), 1e-13);
    }
    delete solution;
}

TEST_F(MatrixTest, testEigenvaluesOfComplexMatrix) {
    setupZeroMatrix();
    (*matrix)(0,0) = 1.0;
    (*matrix)(2,1) = Complex(0.0, -1.0);
    (*matrix)(1,2) = Complex(0.0, +1.0);
    EigenvalueSolution* solution = matrix->diagonalize();
    double expect[] = {-1.0, 1.0, 1.0};
    for (int i = 0; i < size; ++i) {
        ASSERT_NEAR(expect[i], solution->getEigenvalue(i), 1e-13);
    }
    delete solution;
}

}
