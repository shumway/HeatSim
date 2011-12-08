#include "DispersionCurveWriter.h"

DispersionCurveWriter::DispersionCurveWriter() {

}

DispersionCurveWriter::~DispersionCurveWriter() {
}

void DispersionCurveWriter::write(std::ostream &stream) const {
    stream << "# Phonon dispersion curve" << std::endl;
    stream << "# k omegas" << std::endl;
    setOStreamFormat(stream);
    for (int i = 0; i < kPointCount; ++i) {
        writeDataLine(stream, i);
    }
}

void DispersionCurveWriter::writeDataLine(std::ostream & stream, int i) const {
    stream << i;
    for (int j = 0;j < bandCount;++j){
        stream << " " << 0.0;
    }
    stream << std::endl;
}

void DispersionCurveWriter::setKPointCount(int n) {
	kPointCount = n;
}

void DispersionCurveWriter::setBandCount(int n) {
	bandCount = n;
}

void DispersionCurveWriter::setOStreamFormat(std::ostream & stream) const {
    stream.setf(std::ios::fixed);
    stream.setf(std::ios::showpoint);
    stream.precision(3);
}
