#ifndef _SDDS_SHAPE_H_
#define _SDDS_SHAPE_H_
#include <iostream>

namespace sdds {

    class Shape {
        public:
            virtual ~Shape();
            virtual void draw(std::ostream& os) const = 0;
            virtual void getSpecs(std::istream& is) = 0;
    };
    std::istream& operator>>(std::istream& is, Shape& baseShape);
    std::ostream& operator<<(std::ostream& os, const Shape& baseShape);
    
}

#endif // !_SDDS_SHAPE_H_
