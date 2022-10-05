#define _CRT_SECURE_NO_WARNINGS
#include "Seat.h"
#include "Utils.h"
namespace sdds {

	bool Seat::validate(int row, char letter)const {
		
		bool flag = true;

		if (row >= 1 && row <= 4) {
			if (!(letter == 'A' || letter == 'B' || letter == 'E' || letter == 'F')) {
				flag = false;
			}
		}
		else if ((row >= 7 && row <= 15) || (row >= 20 && row <= 38)) {
			if (!(letter == 'A' || letter == 'B' || letter == 'C' || letter == 'D' ||
				letter == 'E' || letter == 'F')) {
				flag = false;
			}
		}
		else {
			flag = false;
		}

		return flag;
	}

	Seat& Seat::alAndCp(const char* str) {
		m_name = nullptr;
		if (str != nullptr && sdds::strlen(str) > 0) {
			m_name = new char[sdds::strlen(str) + 1];
			sdds::strcpy(m_name, str);
		}
		return *this;
	}

	Seat::Seat() {
		reset();
	};

	Seat::Seat(const char* passengerName) {
		reset();
		alAndCp(passengerName);
	};

	Seat::Seat(const char* passengerName, int row, char letter) {
		reset();
		alAndCp(passengerName);
		m_seatChar = letter;
		m_seatNumber = row;
	};

	Seat::~Seat() {
		delete m_name;
	};

	Seat& Seat::reset() {
		if (m_name != nullptr)
			delete m_name;
		m_name = nullptr;
		m_seatChar = '0';
		m_seatNumber = 0;
		return *this;
	}

	bool Seat::isEmpty() const {
		return m_name == nullptr;
	}

	bool Seat::assigned() const {
		return validate(m_seatNumber, m_seatChar);
	}

	Seat& Seat::set(int row, char letter) {
		if (validate(row, letter)) {
			m_seatNumber = row;
			m_seatChar = letter;
		}
		else {
			m_seatNumber = 0;
			m_seatChar = '0';
		}
		return *this;
	}

	int Seat::row()const {
		return m_seatNumber;
	}

	char Seat::letter()const {
		return m_seatChar;
	}

	const char* Seat::passenger()const {
		return m_name;
	}

	std::ostream& Seat::display(std::ostream& coutRef)const {

		if (!isEmpty()) {
			if (sdds::strlen(m_name) > 40) {
				char name[41];
				sdds::strcpy(name, m_name, 40);
				coutRef << name;
			} else {
				coutRef.width(40);
				coutRef.fill('.');
				coutRef.setf(std::ios::left);
				if (m_name[0] == '\n') coutRef << m_name[1];
				else coutRef << m_name;
				coutRef.unsetf(std::ios::left);
				coutRef.fill(' ');
			}

			if (validate(m_seatNumber, m_seatChar)) {
				coutRef << ' ' << m_seatNumber << m_seatChar;
			}
			else {
				coutRef << " ___";
			}
		}
		else {
			coutRef << "Invalid Seat!";
		}
		return coutRef;
	}

	std::istream& Seat::read(std::istream& cinRef) {
		reset();
		char name[71];
		int row;
		char letter;

		cinRef.getline(name, 70, ',');
		cinRef >> row >> letter;

		if (!cinRef.fail()) {
			if (!alAndCp(name).isEmpty()) {
				set(row, letter);
			}
		}
		return cinRef;
	}
}