
#ifndef _SDDS_HTMLTEXT_H_
#define _SDDS_HTMLTEXT_H_

#include <iostream>
#include "Text.h"

namespace sdds {

    class HtmlText : public Text {
        private:   
            char* m_title{};
        public:
            HtmlText();
            HtmlText(const char* title);
            HtmlText(const HtmlText& rightHtml);
            ~HtmlText();

            HtmlText& operator=(const HtmlText& rightHtml);

            std::ostream& write(std::ostream& ostr) const;

    };

}

#endif // !_SDDS_HTMLTEXT_H_
