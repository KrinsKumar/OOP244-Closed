#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Text.h"

namespace sdds {

    sdds::Text::Text() {
        m_isEmpty = true;
        m_content= NULL;
    }

    sdds::Text::Text(const Text& rightText) {
        *this = rightText;
    }

    sdds::Text::~Text() {
        delete[] m_content; 
    }

    const char& sdds::Text::operator[](int index) const {
        return m_content[index];
    }

    Text& sdds::Text::operator=(const Text& rightText) {
        if (!rightText.m_isEmpty) {
            m_content = new char[strlen(rightText.m_content) + 1];
            strcpy(m_content, rightText.m_content);
            m_isEmpty = false;
        }
        return *this;
    }

    std::istream& sdds::Text::read(std::istream& istr) {
        delete[] m_content;
        int i;    // for the loop
        unsigned length = getFileLength(istr);
        m_content = new char[length];
        for (i = 0; i < length && !istr.fail(); i++) {
            istr.get(m_content[i]);
        }
        if (i > 0) {
            istr.clear();
            m_isEmpty = false;
            m_content[i-1] = '\0';
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
    