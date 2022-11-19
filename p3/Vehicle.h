#ifndef _SDDS_VEHICAL_H_
#define _SDDS_VEHICAL_H_

#include "ReadWritable.h"

namespace sdds {

    class Vehical : public ReadWritable {
        private:
            char m_license[9];
            int m_parkingSpot;
            char* m_makeModel{};
            bool m_isEmpty = true;    // true when the class is empty
        public:
            Vehical();
            Vehical(const char* license, const char* makeModel);
            Vehical(const Vehical& leftVehical);
            ~Vehical();

            void setEmpty();
            bool isEmpty() const;
            const char* getLicensePlate() const;
            const char* getMakeModel() const;
            void setMakeModel(const char* newMakeModel);
            int getParkingSpot() const;
            void setParkingSpot(int newSpot);
            bool operator==(char* licensePlate) const;
            bool operator==(const Vehical& leftVehical) const;
            Vehical& operator=(const Vehical& leftVehical);

            
    };

}

#endif // !_SDDS_VEHICAL_H_
