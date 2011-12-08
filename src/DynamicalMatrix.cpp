#include "DynamicalMatrix.h"

DynamicalMatrix::DynamicalMatrix() {
}

DynamicalMatrix::~DynamicalMatrix() {
}

void DynamicalMatrix::initialize() {
}

void DynamicalMatrix::setPotential(const Potential *potential) {
	this->potential = potential;
}

void DynamicalMatrix::setCoordinates(Coordinates *coordinates) {
	this->coordinates = coordinates;
}
