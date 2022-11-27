// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Text.h"

namespace sdds {

    sdds::Text::Text() {
        m_isEmpty = true;
        m_content= NULL;
    }

    sdds::Text::Text(const Text& rightText) {
        m_content = NULL;
        *this = rightText;
        m_isEmpty = rightText.m_isEmpty;
    }

    sdds::Text::~Text() {
        delete[] m_content; 
    }

    const char& sdds::Text::operator[](int index) const {
        return m_content[index];
    }

    Text& sdds::Text::operator=(const Text& rightText) {
        delete[] m_content;
        if (!rightText.m_isEmpty) {
            m_content = new char[strlen(rightText.m_content) + 1];
            strcpy(m_content, rightText.m_content);
            m_isEmpty = rightText.m_isEmpty;
        }
        return *this;
    }

    std::istream& sdds::Text::read(std::istream& istr) {
        delete[] m_content;
        unsigned i;    // for the loop
        unsigned length = getFileLength(istr);
        if (length > 0) {
            m_content = new char[length + 1];
            for (i = 0; i < length && !istr.fail(); i++) {
                istr.get(m_content[i]);
            }
            if (i > 0) {
                istr.clear();
                istr.ignore(1000,'\n');
                m_isEmpty = false;
                m_content[i] = '\0';
            }
        }
        else {
            m_isEmpty = true;
            m_content = NULL;
        }
        return istr;
    }

    std::ostream& sdds::Text::write(std::ostream& ostr) const {
        if (!m_isEmpty) ostr << m_content;
        return ostr;
    }

    unsigned Text::getFileLength(std::istream& is) {
        unsigned len{};
        if (is) {
            std::streampos cur = is.tellg();
            is.seekg(0, std::ios::end);
            len = unsigned(is.tellg());
            is.seekg(cur);
        }
        return len;
    }

    std::istream& operator>>(std::istream& istr, Text& text)  {
        return text.read(istr);
    }

    std::ostream& operator<<(std::ostream& ostr, const Text& text)  {
        return text.write(ostr);
    }
}
    