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
			/*Mark& operator++();
			Mark& operator++();
			Mark& operator--();
			Mark& operator--();*/

			// binary operators
			Mark& operator=(int newMark);
			Mark& operator=(const Mark rigthMark);
			Mark& operator+=(int newMark);
			Mark& operator-=(int newMark);
			Mark& operator>>(Mark& rightMark);
			Mark& operator<<(Mark& rightMark);
	};

	// helper functions with operators
	int operator+=(int& leftInt, Mark rightMark);
	int operator-=(int& leftInt, Mark rightMark);
	Mark operator+(const Mark leftMark, const int rightInt);
	Mark operator+(const Mark leftMark, const Mark rightMark);
	Mark operator+(const int leftInt, const Mark rightMark);
}


#endif // !_SDDS_MARK_H_
