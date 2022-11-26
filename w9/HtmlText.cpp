#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "HtmlText.h"

namespace sdds {

    sdds::HtmlText::HtmlText(const char* title) {
        if (title != nullptr) {
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
        }
    }

    sdds::HtmlText::HtmlText(const HtmlText& rightHtml) {
        *this = rightHtml;
    }

    HtmlText& sdds::HtmlText::operator=(const HtmlText& rightHtml)
    {
        if (rightHtml.m_title != nullptr) {
            m_title = new char[strlen(rightHtml.m_title) + 1];
            strcpy(m_title, rightHtml.m_title);
        }
        return *this;
    }

    std::ostream& sdds::HtmlText::write(std::ostream& ostr) const {
        
    }
}
