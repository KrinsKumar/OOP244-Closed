#pragma once
#ifndef SDDS_APARTMENT_H_
#define SDDS_APARTMENT_H_
#include <iostream>

namespace sdds
{
	class Apartment
	{
		int m_number = -1;
		double m_balance = 0.0;

	public:
		Apartment(int number, double balance);
		std::ostream& display()const;

		operator bool()const;
		operator int()const;
		operator double()const;
		bool operator~()const;
		Apartment& operator=(int apartmentNumber);
		Apartment& operator=(Apartment& newApartment);
		Apartment& operator+=(double extraRent);
		Apartment& operator-=(double lessRent);
		Apartment& operator<<(Apartment& leftApartment);
		Apartment& operator>>(Apartment& leftApartment);
	};
	double operator+(const Apartment& leftApartment, const Apartment& rightApartment);
	double operator+=(double& extraBalance, const Apartment& rightApartment);
}

#endif // SDDS_APARTMENT_H_
