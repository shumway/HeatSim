#ifndef __DispersionCurveWriter_h_
#define __DispersionCurveWriter_h_

#include <iostream>

class DispersionCurveWriter {
public:
    DispersionCurveWriter();
    ~DispersionCurveWriter();

    void write(std::ostream&) const;
    void setKPointCount(int n);
    void setBandCount(int n);

private:
    int kPointCount;
    int bandCount;
    void writeDataLine(std::ostream & stream, int i) const;
    void setOStreamFormat(std::ostream & stream) const;
};

#endif
