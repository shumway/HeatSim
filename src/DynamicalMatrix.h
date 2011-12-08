#ifndef __DynamicalMatrix_h_
#define __DynamicalMatrix_h_

class Potential;
class Coordinates;

class DynamicalMatrix {
public:
	DynamicalMatrix();
	~DynamicalMatrix();

	void initialize();
	void setPotential(const Potential*);
	void setCoordinates(Coordinates*);

private:
	const Potential *potential;
	Coordinates *coordinates;
};

#endif
