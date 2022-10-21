//Full Name : Krinskumar Bhaveshkumar Vaghasia
//Student ID# : 169722212
//Email : kvaghasia@myseneca.ca
//Date : 16-Oct-2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef _SDDS_MARK_H_
#define _SDDS_MARK_H_
#include <iostream>

namespace sdds {

	class Mark {
		private:
			int m_mark;
			char m_grade;
			double m_scale4;
		public:
			Mark();
			Mark(int mark);
			void calculate(int mark);    // calculates the other values of the variables in private

			// type conversions operators
			operator int()const;
			operator double()const;
			operator char()const;
			operator bool()const;

			// comparison operators
			bool operator==(const Mark& rightMark)const;
			bool operator!=(const Mark& rightMark)const;
			bool operator<(const Mark& rightMark)const;
			bool operator>(const Mark& rightMark)const;
			bool operator<=(const Mark& rightMark)const;
			bool operator>=(const Mark& rightMark)const;

			// unary operators
			Mark& operator++();
			Mark operator++(int);
			Mark& operator--();
			Mark operator--(int);

			// binary operators
			Mark& operator=(int newMark);
			Mark& operator=(const Mark rigthMark);
			Mark& operator+=(int newMark);
			Mark& operator-=(int newMark);
			Mark& operator>>(Mark& rightMark);
			Mark& operator<<(Mark& rightMark);

			bool operator~();
	};

	// helper functions with operators
	int operator+=(int& leftInt, Mark rightMark);
	int operator-=(int& leftInt, Mark rightMark);
	Mark operator+(const Mark leftMark, const int rightInt);
	Mark operator+(const Mark leftMark, const Mark rightMark);
	int operator+(const int leftInt, const Mark rightMark);
}


#endif // !_SDDS_MARK_H_
