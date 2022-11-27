// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
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

    HtmlText& sdds::HtmlText::operator=(const HtmlText& rightHtml) {
        if (rightHtml.m_title != nullptr) {
            Text::operator=(rightHtml);
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
        ostr << "<h1>" << m_title << "</h1>" << std::endl;

        const HtmlText &temp = *this;
        int i = 0;
        while (temp[i] != '\0') {
            if (temp[i] == '<') ostr << "&lt;";
            else if (temp[i] == '>') ostr << "&gt;";
            else if (temp[i] == '\n') ostr << "<br />\n";
            else if (isspace(temp[i])) {
                if (temp[i - 1] == '\n') ostr << ' ';
                else if (isspace(temp[i-1])) ostr << "&nbsp;";
                else ostr << ' ';
            }
            else ostr << temp[i];
            i++;
        }

        ostr << "</body>\n</html>";
        return ostr;
    }
}
