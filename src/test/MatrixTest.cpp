#include <gtest/gtest.h>
#include <sstream>
#include "Matrix.h"
#include "EigenvalueSolution.h"

namespace {

class MatrixTest: public ::testing::Test {
protected:

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
};

TEST_F(MatrixTest, testAccessElements) {
    (*matrix)(1, 0) = 1.0;
    (*matrix)(0, 1) = 2.0;
    ASSERT_DOUBLE_EQ(1.0, (*matrix)(1,0));
    ASSERT_DOUBLE_EQ(2.0, (*matrix)(0,1));
}

TEST_F(MatrixTest, testEigenvalues) {
    setupSymmetricTestMatrix();
    EigenvalueSolution* solution = matrix->diagonalize();
    double expect[] = {-0.5157294715892572,  0.1709151888271787, 11.3448142827620835};
    for (int i = 0; i < size; ++i) {
        ASSERT_DOUBLE_EQ(expect[i], solution->getEigenvalue(i));
    }
    delete solution;
}

}
