#ifndef _SDDS_RECTANGLE_H_
#define _SDDS_RECTANGLE_H_
#include "LblShape.h"

namespace sdds {

    class Rectangle : public LblShape {
        private:
            int m_width;
            int m_height;
            bool m_empty = true;    // true if the class is empty
        public:
            Rectangle();
            Rectangle(const char* Cstring, const int width, const int height);
            void getSpecs(std::istream& is);
            void draw(std::ostream& os) const;
    };

}

#endif // !_SDDS_LINE_H_
