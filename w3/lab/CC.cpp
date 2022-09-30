#include <iostream>
#include <string>
#include "CC.h"
#include "Utils.h"
using namespace std;

namespace sdds {

	bool CC::validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear)const {
		bool flag = true;

		int count = 0;
		while (name[count] != '\0') {    // Calculates the length of the name
			count++;
		}

		if (name == nullptr || count++ < 2 ) {    // Checks name
			flag = false;
		}
		if (cardNo < 4000000000000000 || cardNo > 4099999999999999) {    // Checks cardNo
			flag = false;
		}
		if (cvv < 100 || cvv > 999) {    // Checks cvv
			flag = false;
		}
		if (expMon < 1 || expMon > 12) {    // Checks month
			flag = false;
		}
		if (expYear < 22 || expYear > 33) {    // Checks year
			flag = false;
		}
		return flag;
	}

	void CC::prnNumber()const {

		unsigned long long number = m_cardNo;
		unsigned long long divisions[]{1000000000000,100000000,10000, 1};    // To be used to divide the numbers 

		for (int i = 0; i < 4; i++) {
			int print4 = number/divisions[i];
			number = number%divisions[i];

			cout.width(4);
			cout.fill('0');
			cout << print4 << ' ';
			cout.fill(' ');
		}
		
	}

	void CC::set() {
		m_cardNo = 0;
		m_cvv = 0;
		m_expMon = 0;
		m_expYear = 0;
		m_name = nullptr;
	}

	void CC::cleanUp() {
		delete[] m_name;
		set();
	}

	bool CC::isEmpty()const {
		bool flag = false;
		
		if (m_name != nullptr) {
			flag = true;
		}

		return flag;
	}

	void CC::set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear) {

		cleanUp();
		if (validate(cc_name, cc_no, cvv, expMon, expYear)) {

			int count = 0;
			while (cc_name[count] != '\0') {    // Calculates the length of the cc_name
				count++;
			}

			m_name = new char[count+1];
			strcpy(m_name, cc_name);
			m_cardNo = cc_no;
			m_cvv = cvv;
			m_expMon = expMon;
			m_expYear = expYear;
		}
	}

	bool CC::read() {

		char name[71];
		short cvv;
		short expMon;
		short expYear;
		unsigned long cardNo;

		cleanUp();

		cout << "Card holder name: ";
		cin.getline(name, 71);
		
		if (!cin.fail()) {
			cout << "Credit card number: ";
			cin >> cardNo;
		}
		if (!cin.fail()) {
			cout << "Card Verification Value (CVV): ";
			cin >> cvv;
		}
		if (!cin.fail()) {
			cout << "Expiry month and year (MM/YY): ";
			cin >> expMon;
			cin.ignore(1);
			cin >> expYear;
		}
		if (!cin.fail()) {
			set(name, cardNo, cvv, expMon, expYear);
		}
		else {
			cin.clear();
			cin.ignore(1000, '\n');
		}
	
		return !isEmpty();
	}

	void CC::display(int row)const {

		if (!isEmpty()) {
			cout << "Invalid Credit Card Record";
		}
		else {
			if (row > 0) {
				cout.width(3);
				cout.fill(' ');
				cout.setf(ios::right);
				cout << "|" << row;
				cout.unsetf(ios::right);
				cout.width(30);
				cout.fill(' ');
				cout.setf(ios::left);
				cout << " | " << m_name << " | ";
				cout.unsetf(ios::left);
				prnNumber();
				cout << " | " << m_cvv << " | ";
				cout.width(2);
				cout.fill(' ');
				cout.setf(ios::right);
				cout << m_expMon << "/" << m_expYear;
				cout.unsetf(ios::right);

				
			}
			else {
				cout << "Name : " << m_name << endl;
				cout << "Creditcard No : ";
				prnNumber();
				cout << endl << "Card Verification Value : " << m_cvv << endl;
				cout << "Expiry Date : " << m_expMon << "/" << m_expYear << endl;
			}
		}
	}
}