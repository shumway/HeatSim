#include "DynamicalMatrix.h"
#include "Structure.h"
#include "Matrix.h"
#include "EigenvalueSolution.h"
#include "TotalEnergy.h"
#include "Displacement.h"
#include <cmath>

DynamicalMatrix::DynamicalMatrix(const TotalEnergy *totalEnergy,
        Structure *structure)
    :   totalEnergy(totalEnergy), structure(structure),
        atomCount(structure->getAtomCount()),
        size(atomCount*3), displacement(new Displacement[3]),
        matrix(new Matrix(size)), solution(new EigenvalueSolution(size)),
        frequency(new double[size]) {
}

DynamicalMatrix::~DynamicalMatrix() {
    delete displacement;
    delete matrix;
    delete solution;
    delete frequency;
}

int DynamicalMatrix::getSize() const {
    return size;
}

void DynamicalMatrix::diagonalizeAtKPoint(const KVector &kvector) {
    matrix->diagonalize(solution);
    double *eigenvalue = solution->getEigenvalueData();
    for (int i = 0; i < size; ++i) {
        frequency[i] = sqrt(fabs(eigenvalue[i]))
                * (eigenvalue[i] > 0 ? 1 : -1);
    }
}

void DynamicalMatrix::calculateDynamicalMatrix(double delta) {
    this->delta = delta;

    displacement[0] = Displacement(delta, 0.0, 0.0);
    displacement[1] = Displacement(0.0, delta, 0.0);
    displacement[2] = Displacement(0.0, 0.0, delta);

    for (int index2 = 0; index2 < size; ++index2) {
        for (int index1 = 0; index1 <= index2; ++index1) {
            calculateMatrixElement(index1, index2);
        }
    }
}

void DynamicalMatrix::calculateMatrixElement(int index1, int index2) {
    double value = 0;
    int atomIndex1 = index1 / 3;
    int atomIndex2 = index2 / 3;
    Displacement &displacement1(displacement[index1%3]);
    Displacement &displacement2(displacement[index2%3]);
    double mass1 = structure->getMass(atomIndex1);
    double mass2 = structure->getMass(atomIndex2);

    structure->moveAtom(atomIndex1, displacement1);
    structure->moveAtom(atomIndex2, displacement2);
    value += totalEnergy->getEnergy();
    structure->moveAtom(atomIndex1, displacement1 * -2);
    value -= totalEnergy->getEnergy();
    structure->moveAtom(atomIndex1, displacement1 * 2);
    structure->moveAtom(atomIndex2, displacement2 * -2);
    value -= totalEnergy->getEnergy();
    structure->moveAtom(atomIndex1, displacement1 * -2);
    value += totalEnergy->getEnergy();
    structure->moveAtom(atomIndex1, displacement1);
    structure->moveAtom(atomIndex2, displacement2);
    value /= 4 * delta * delta * sqrt(mass1 * mass2);
    (*matrix)(index1, index2) = value;
}

double DynamicalMatrix::getFrequency(int index) const {
    return frequency[index];
}
