#ifndef _SDDS_LINE_H_
#define _SDDS_LINE_H_
#include "LblShape.h"

namespace sdds {

    class Line: public LblShape {
        private:
            int m_length;
        public:
         Line();
         Line(const char* Cstring,const int length);
         void draw(std::ostream& os) const;
         void getSpecs(std::istream& is);

    };

}

#endif // !_SDDS_LINE_H_
