//Full Name : Krinskumar Bhaveshkumar Vaghasia
//Student ID# : 169722212
//Email : kvaghasia@myseneca.ca
//Date : 30-Sept=2022

#ifndef _SDDS_TAGLIST_H
#define _SDDS_TAGLIST_H

#include "NameTag.h"

namespace sdds {

	class TagList {
	private:
		NameTag* m_names;
	public:
		void set();
		void set(int num);
		void add(const NameTag& nt);
		void print();
		void cleanup();
		NameTag* getList();
	};
}

#endif // !_SDDS_TAGLIST_H
