#ifndef _SDDS_LINE_H_
#define _SDDS_LINE_H_
#include "LblShape.h"

namespace sdds {

    class Line: public LblShape {
        private:
            int m_length;
        public:
         Line();
         void draw(std::ostream& os) const;
         void getSpecs(std::istream& is);
         Line(const char* Cstring,const int length);

    };

}

#endif // !_SDDS_LINE_H_
