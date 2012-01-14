#include "DynamicalMatrix.h"
#include "Structure.h"
#include "Matrix.h"
#include "EigenvalueSolution.h"
#include "Coordinates.h"
#include "TotalEnergy.h"
#include "Displacement.h"
#include <cmath>

DynamicalMatrix::DynamicalMatrix(const TotalEnergy *totalEnergy,
        Structure *structure)
    :   totalEnergy(totalEnergy), structure(structure),
        atomCount(structure->getAtomCount()),
        size(atomCount*3),
        matrix(new Matrix(2)), frequency(new double[size]) {
}

DynamicalMatrix::~DynamicalMatrix() {
    delete matrix;
    delete frequency;
}

int DynamicalMatrix::getSize() const {
    return size;
}

void DynamicalMatrix::calculate(double delta) {
    calculateMatrix(delta);
    EigenvalueSolution *solution = matrix->diagonalize();
    double *eigenvalue = solution->getEigenvalueData();
    for (int i = 0; i < size; ++i) {
        frequency[i] = sqrt(fabs(eigenvalue[i]))
                * (eigenvalue[i] > 0 ? 1 : -1);
    }
    delete solution;
}

void DynamicalMatrix::calculateMatrix(double delta) {
    Coordinates* coordinates = structure->getCoordinates();

    Displacement displacement(delta, 0, 0);

    for (int index1 = 0; index1 < atomCount; ++index1) {
        for (int index2 = 0; index2 < atomCount; ++index2) {
            double value = 0;

            coordinates->shiftAtom(index1, displacement);
            coordinates->shiftAtom(index2, displacement);
            value += totalEnergy->getEnergy();

            coordinates->shiftAtom(index1, displacement*(-2));
            value -= totalEnergy->getEnergy();

            coordinates->shiftAtom(index1, displacement*2);
            coordinates->shiftAtom(index2, displacement*(-2));
            value -= totalEnergy->getEnergy();

            coordinates->shiftAtom(index1, displacement*(-2));
            value += totalEnergy->getEnergy();

            coordinates->shiftAtom(index1, displacement);
            coordinates->shiftAtom(index2, displacement);

            (*matrix)(index1,index2) = value / (4*delta*delta);
        }
    }
}

double DynamicalMatrix::getFrequency(int index) const {
    return frequency[index];
}


