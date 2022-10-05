//Full Name : Krinskumar Bhaveshkumar Vaghasia
//Student ID# : 169722212
//Email : kvaghasia@myseneca.ca
//Date : 30-Sept=2022

#include <iostream>
#include "TagList.h"
#include "Utils.h"

using namespace std;

namespace sdds {

	int currentIndex = 0;
	int longestName = 0;

	void TagList::set() {
		m_names = nullptr;
	}

	void TagList::set(int num) {
		set();
		m_names = new NameTag[num];
	}

	void TagList::add(const NameTag& nt) {
		m_names[currentIndex] = nt;
		currentIndex++;
		
		int length = nt.getLength();
		if (length > longestName)  
			longestName = length;
	}

	void TagList::print() {

		for (int i = 0; i < currentIndex + 1; i++) {
			m_names[i].printName(longestName);
			cout << endl;
		}
	}

	void TagList::cleanup() {
		delete [] m_names;
		set();
	}
}