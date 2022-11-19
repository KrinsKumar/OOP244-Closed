#ifndef _SDDS_READWRITABLE_H_
#define _SDDS_READWRITABLE_H_

#include <iostream>

namespace sdds {

    class ReadWritable {
        private:
            bool m_isComma;
        public:
            ReadWritable();
            virtual ~ReadWritable();
            bool isCsv() const;    // returns the value of m_isComma
            void setCsv(bool value);    // changes the value of the m_isComma
            virtual std::istream& read(std::istream& istr = std::cin) = 0;
            virtual std::ostream& write(std::ostream& ostr = std::cout) const = 0;
    };
    // helper functions 
    std::istream& operator>>(std::istream& istr, ReadWritable& readWrite);
    std::ostream& operator<<(std::ostream& ostr, const ReadWritable& readWrite);


}

#endif // !_SDDS_READWRITABLE_H_
