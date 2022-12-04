/* Citation and Sources...
Final Project Milestone 4
Module: Menu
Filename: menu.cpp
Version 1.1
Author	Krinskumar Bhaveshkumar Vaghasia
Revision History
-----------------------------------------------------------
Date      Reason
2022/12/01  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/

#ifndef _SDDS_Vehicle_H_
#define _SDDS_Vehicle_H_

#include "ReadWritable.h"

namespace sdds {

    class Vehicle : public ReadWritable {
        private:
            char m_license[9];
            int m_parkingSpot;
            char* m_makeModel{};
            bool m_isEmpty = true;    // true when the class is empty

        protected:
            void setEmpty();
            bool isEmpty() const;
            const char* getLicensePlate() const;
            const char* getMakeModel() const;
            void setMakeModel(const char* newMakeModel);


        public:
            Vehicle();
            Vehicle(const char* license, const char* makeModel);
            Vehicle(const Vehicle& leftVehicle);
            virtual ~Vehicle();

            int getParkingSpot() const;
            void setParkingSpot(int newSpot);
            bool operator==(const char* licensePlate) const;
            bool operator==(const Vehicle& leftVehicle) const;
            Vehicle& operator=(const Vehicle& leftVehicle);
            virtual std::ostream& writeType(std::ostream& ostr = std::cout) const = 0;


            virtual std::istream& read(std::istream& istr = std::cin);
            virtual std::ostream& write(std::ostream& ostr = std::cout) const;
    };

}

#endif // !_SDDS_Vehicle_H_
