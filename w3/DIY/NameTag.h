//Full Name : Krinskumar Bhaveshkumar Vaghasia
//Student ID# : 169722212
//Email : kvaghasia@myseneca.ca
//Date : 30-Sept=2022

#ifndef _SDDS_NAMETAG_H
#define _SDDS_NAMETAG_H

namespace sdds {
	
	class NameTag {
		private:
			char m_name[50];

		public:
			void set(const char* name);
			int getLength()const;
			void printName(int length);
	};

}

#endif // !_SDDS_NAMETAG_H