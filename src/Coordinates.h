#ifndef __Coordinates_h_
#define __Coordinates_h_

#include <istream>

class Coordinates {
public:
	Coordinates();
	~Coordinates();

	void read(std::istream&);

private:
	int npart;
};

#endif
