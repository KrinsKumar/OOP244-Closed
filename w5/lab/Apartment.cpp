#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Apartment.h"

using namespace std;

namespace sdds
{
	Apartment::Apartment(int number, double balance)
	{

		if (number >= 1000 && number <= 9999
			&& balance >= 0)
		{
			m_number = number;
			m_balance = balance;
		}
	}

	std::ostream& Apartment::display() const
	{
		if (*this)
		{
			cout.width(4);
			cout << m_number;
			cout << " | ";
			cout.width(12);
			cout.precision(2);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout << m_balance;
			cout.unsetf(ios::right);
			cout << " ";
		}
		else
		{
			cout << "Invld|  Apartment   ";
		}
		return cout;
	}

	Apartment::operator bool()const {
		return m_number != -1;
	}

	Apartment::operator int()const {
		return m_number;
	}

	Apartment::operator double()const {
		return m_balance;
	}

	bool Apartment::operator~() const {
		return m_balance < 0.00001;
	}

	Apartment& Apartment::operator=(int apartmentNumber) {
		if (apartmentNumber >= 1000 && apartmentNumber <= 9999)
			m_number = apartmentNumber;
		else { 
			m_number = -1;
			m_balance = 0;
		}
		return *this;
	}

	Apartment& Apartment::operator=(Apartment& newApartment) {
		if (newApartment.m_number >= 1000 && newApartment.m_number <= 9999
			&& newApartment.m_balance >= 0 ) {
			Apartment tempApartment(newApartment.m_number, newApartment.m_balance);
			newApartment.m_number = m_number;
			newApartment.m_balance = m_balance;
			m_number = tempApartment.m_number;
			m_balance = tempApartment.m_balance;
		}
		return *this;
	}

	Apartment& Apartment::operator+=(double extraRent) {
		if (extraRent > 0 && m_number != -1) {
			m_balance += extraRent;
		}
		return *this;
	}

	Apartment& Apartment::operator-=(double lessRent) {
		if (lessRent > 0 && m_number != -1) {
			if (m_balance > lessRent)
				m_balance -= lessRent;
		}
		return *this;
	}

	Apartment& Apartment::operator<<(Apartment& leftApartment) {
		if (leftApartment.m_number >= 1000 && leftApartment.m_number <= 9999   // checks the left operand
			&& leftApartment.m_balance >= 0 &&
			m_number >= 1000 && m_number <= 9999 && m_balance >= 0) {    // checks the right operand

			// makes sure that the operands are not same.
			if (!(leftApartment.m_number == m_number && leftApartment.m_balance == m_balance)) {
				m_balance += leftApartment.m_balance;
				leftApartment.m_balance = 0;
			}
		}
		return *this;
	}

	Apartment& Apartment::operator>>(Apartment& leftApartment) {
		if (leftApartment.m_number >= 1000 && leftApartment.m_number <= 9999   // checks the left operand
			&& leftApartment.m_balance >= 0 &&
			m_number >= 1000 && m_number <= 9999 && m_balance >= 0) {    // checks the right operand

			// makes sure that the operands are not same.
			if (!(leftApartment.m_number == m_number && leftApartment.m_balance == m_balance)) {
				leftApartment.m_balance += m_balance;
				m_balance = 0;
			}
		}
		return *this;
	}

	double operator+(const Apartment& leftApartment, const Apartment& rightApartment) {
		double returnDouble = 0;
		if (int(leftApartment) >= 1000 && int(leftApartment) <= 9999 && // checks the left operand
			double(leftApartment) >= 0 &&
			int(rightApartment) >= 1000 && int(rightApartment) <= 9999 &&    // checks the right operand
			double(rightApartment) >= 0 ) 
			returnDouble = double(leftApartment) + double(rightApartment);
		return returnDouble;
	}

	double operator+=(double& extraBalance, const Apartment& rightApartment) {
		if (int(rightApartment) >= 1000 && int(rightApartment) <= 9999 &&    // checks the right operand
			double(rightApartment) >= 0 ) 
			extraBalance += double(rightApartment);
		return extraBalance;
	}
}