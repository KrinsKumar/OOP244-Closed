//Full Name : Krinskumar Bhaveshkumar Vaghasia
//Student ID# : 169722212
//Email : kvaghasia@myseneca.ca
//Date : 30-Sept=2022

#include <iostream>
#include "NameTag.h"
#include "Utils.h"
#include "Utils.cpp"

using namespace std;

namespace sdds {

	void NameTag::set(const char* name) {
		strcpy(m_name, name);
	}

	int NameTag::getLength()const {
		return strlen(m_name);
	}

	void NameTag::printName(int length) {
		for (int i = 0; i < length + 4; i++) {
			cout << '*';
		}
		cout << endl << '*' << ' ';
		cout.width(length);
		cout.fill(' ');
		cout.setf(ios::left);
		cout << m_name;
		cout.unsetf(ios::left);
		cout << ' ' << '*' << endl;
		for (int i = 0; i < length + 4; i++) {
			cout << '*';
		}
	}
}