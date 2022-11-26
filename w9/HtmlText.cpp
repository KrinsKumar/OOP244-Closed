#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "HtmlText.h"

namespace sdds {

    HtmlText::HtmlText() {
        
    }

    sdds::HtmlText::HtmlText(const char* title) {
        if (title != nullptr) {
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
        }
    }

    sdds::HtmlText::HtmlText(const HtmlText& rightHtml) {
        *this = rightHtml;
    }

    HtmlText::~HtmlText() {
        delete[] m_title; 
    }

    HtmlText& sdds::HtmlText::operator=(const HtmlText& rightHtml)
    {
        if (rightHtml.m_title != nullptr) {
            delete[] m_title;
            m_title = new char[strlen(rightHtml.m_title) + 1];
            strcpy(m_title, rightHtml.m_title);
        }
        return *this;
    }

    std::ostream& sdds::HtmlText::write(std::ostream& ostr) const {
        ostr << "<html><head><title>";
        if (m_title != nullptr) ostr << m_title;
        else ostr << "No Title";
        ostr << "</title></head>\n<body>\n";
        int i = 0;
        //while (Text::operator[] != '\0') {
        

            i++;
       //} 

        ostr << "</body>\n</html>";
        return ostr;
    }
}
