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
        matrix(new Matrix(size)), frequency(new double[size]) {
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

    Displacement *displace = new Displacement[3];
    displace[0] = Displacement(delta, 0.0, 0.0);
    displace[1] = Displacement(0.0, delta, 0.0);
    displace[2] = Displacement(0.0, 0.0, delta);

    for (int index1 = 0; index1 < size; index1 += 3) {
        for (int index2 = 0; index2 < size; index2 += 3) {
            for (int direction1 = 0; direction1 < 3; ++direction1) {
                for (int direction2 = 0; direction2 < 3; ++direction2) {
                    calculateMatrixElement(coordinates,
                            index1+direction1,   displace[direction1],
                            index2+direction2,   displace[direction2], delta);
                }
            }
        }
    }
    delete [] displace;
}


void DynamicalMatrix::calculateMatrixElement(Coordinates *& coordinates,
        int index1, Displacement & displacement1,
        int index2, Displacement & displacement2, double delta) {
    double value = 0;
    int atomIndex1 = index1 / 3;
    int atomIndex2 = index2 / 3;
    coordinates->shiftAtom(atomIndex1, displacement1);
    coordinates->shiftAtom(atomIndex2, displacement2);
    value += totalEnergy->getEnergy();
    coordinates->shiftAtom(atomIndex1, displacement1 * (-2));
    value -= totalEnergy->getEnergy();
    coordinates->shiftAtom(atomIndex1, displacement1 * 2);
    coordinates->shiftAtom(atomIndex2, displacement2 * (-2));
    value -= totalEnergy->getEnergy();
    coordinates->shiftAtom(atomIndex1, displacement1 * (-2));
    value += totalEnergy->getEnergy();
    coordinates->shiftAtom(atomIndex1, displacement1);
    coordinates->shiftAtom(atomIndex2, displacement2);
    value /= 4 * delta * delta;
    (*matrix)(index1, index2) = value;
}

double DynamicalMatrix::getFrequency(int index) const {
    return frequency[index];
}
