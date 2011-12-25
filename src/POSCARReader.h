#ifndef POSCARREADER_H_
#define POSCARREADER_H_

#include <istream>
class Coordinates;

class POSCARReader {
public:
    static Coordinates* read(std::istream&);
};
#endif
