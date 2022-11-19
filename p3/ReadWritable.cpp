#include "ReadWritable.h"

namespace sdds {

    sdds::ReadWritable::ReadWritable() {
        m_isComma = false;
    }

    sdds::ReadWritable::~ReadWritable() {

    }

    bool ReadWritable::isCsv() const {
        return m_isComma;
    }

    void ReadWritable::setCsv(bool value) {
        m_isComma = value;
    }

    std::istream& operator>>(std::istream& istr, ReadWritable& readWrite) {
        return readWrite.read(istr);
    }

    std::ostream& operator<<(std::ostream& ostr, const ReadWritable& readWrite)  {
        return readWrite.write(ostr);
    }
}
