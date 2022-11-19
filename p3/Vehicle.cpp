#include "Vehicle.h"
#include "Utils.h"

namespace sdds {

    sdds::Vehical::Vehical() {
        setEmpty();
    }

    sdds::Vehical::Vehical(const char* license, const char* makeModel) {
        if (license != NULL && makeModel != NULL) {
            m_parkingSpot = 0;
            ut.strcpy(m_license, license);
            m_makeModel = ut.alcpy(makeModel);
            m_isEmpty = false;
        } else setEmpty();
    }

    sdds::Vehical::Vehical(const Vehical& leftVehical) {
        *this = leftVehical;
    }

    sdds::Vehical::~Vehical() {
        delete[] m_makeModel;
    }

    void Vehical::setEmpty() {
        m_parkingSpot = 0;
        ut.strcpy(m_license, "");
        delete[] m_makeModel;
        m_makeModel = NULL;
        m_isEmpty = true;
    }

    bool Vehical::isEmpty() const {
        return m_isEmpty;
    }

    const char* Vehical::getLicensePlate() const {
        return m_license;
    }

    const char* Vehical::getMakeModel() const {
        return m_makeModel;
    }

    void Vehical::setMakeModel(const char* newMakeModel) {
        if (newMakeModel != NULL) {
            delete[] m_makeModel;
            m_makeModel = ut.alcpy(newMakeModel);
        } else setEmpty();
    }

    int Vehical::getParkingSpot() const{
        return m_parkingSpot;
    }

    void Vehical::setParkingSpot(int newSpot) {
        if (newSpot > 0) {
            m_parkingSpot = newSpot;
        } else setEmpty();
    }

    bool Vehical::operator==(char* licensePlate) const {
        bool returnFlag;    
        returnFlag = ut.strcmp(); // remains left here have to convert both of them to lower case
        return returnFlag;
    }

    bool Vehical::operator==(const Vehical& leftVehical) const  {
        bool returnFlag;

        return returnFlag;
    }

    Vehical& sdds::Vehical::operator=(const Vehical& leftVehical) {
        m_isEmpty = false;
        ut.strcpy(m_license, leftVehical.m_license);
        m_parkingSpot = leftVehical.m_parkingSpot;
        m_makeModel = ut.alcpy(leftVehical.m_makeModel);
        return *this;
    }
}