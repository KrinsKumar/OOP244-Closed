
#ifndef _SDDS_TEXT_H_
#define _SDDS_TEXT_H_

#include <iostream>

namespace sdds {

    class Text {
        private:
            char* m_content;
            bool m_isEmpty;    // true if the class is empty
        protected:
            const char& operator[](int index) const;
        public:
            Text();
            Text(const Text& rightText);
            virtual ~Text();

            Text& operator=(const Text& rightText);
            std::istream& read(std::istream& istr);
            std::ostream& write(std::ostream& ostr) const;

            unsigned getFileLength(std::istream& is);
    };

    std::istream& operator>>(std::istream& istr, Text& text);
    std::ostream& operator<<(std::ostream& ostr, const Text& text);

}

#endif // !_SDDS_TEXT_H_
