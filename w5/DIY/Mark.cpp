#include "Mark.h"

namespace sdds {

	Mark::Mark() {
		calculate(0);
	}

	Mark::Mark(int mark) {
		if (mark >= 0 && mark <= 100) calculate(mark);
		else calculate(-1);
	}

	void Mark::calculate(int mark)
	{
		if (mark == -1) {
			m_mark = mark;
			m_grade = '-';
			m_scale4 = 0;
		} else {
			m_mark = mark;
			if (mark >= 0 && mark < 50) {m_grade = 'F'; m_scale4 = 0.0;}
			if (mark >= 50 && mark < 60) { m_grade = 'D'; m_scale4 = 1.0; }
			if (mark >= 60 && mark < 70) { m_grade = 'C'; m_scale4 = 2.0; }
			if (mark >= 70 && mark < 80) { m_grade = 'B'; m_scale4 = 3.0; }
			if (mark >= 80 && mark < 100) { m_grade = 'A'; m_scale4 = 4.0; }
		}
	}

	Mark::operator int() const {
		return m_mark;
	}

	Mark::operator double() const {
		return m_scale4;
	}

	Mark::operator char() const {
		return m_grade;
	}

	Mark::operator bool() const {
		return (m_mark >= 0 && m_mark <= 100);
	}

	bool Mark::operator==(const Mark& rightMark) const {
		bool flag = false;
		if (bool(rightMark) && m_mark != -1) {
			if (int(rightMark) == m_mark) {
				flag = true;
			}
		}
		return flag;
	}

	bool Mark::operator!=(const Mark& rightMark) const {
		bool flag = false;
		if (bool(rightMark) && m_mark != -1) {
			if (m_mark != int(rightMark)) {
				flag = true;
			}
		}
		return flag;
	}

	bool Mark::operator<(const Mark& rightMark) const {
		bool flag = false;
		if (bool(rightMark) && m_mark != -1) {
			if (m_mark < int(rightMark)) {
				flag = true;
			}
		}
		return flag;
	}

	bool Mark::operator>(const Mark& rightMark) const {
		bool flag = false;
		if (bool(rightMark) && m_mark != -1) {
			if (m_mark > int(rightMark)) {
				flag = true;
			}
		}
		return flag;
	}

	bool Mark::operator<=(const Mark& rightMark) const {
		bool flag = false;
		if (bool(rightMark) && m_mark != -1) {
			if (m_mark <= int(rightMark)) {
				flag = true;
			}
		}
		return flag;
	}

	bool Mark::operator>=(const Mark& rightMark) const {
		bool flag = false;
		if (bool(rightMark) && m_mark != -1) {
			if (m_mark >= int(rightMark)) {
				flag = true;
			}
		}
		return flag;
	}

	Mark& Mark::operator=(const int newMark) {
		if (newMark >= 0 && newMark <= 100) calculate(newMark);
		else calculate(-1);
		return *this;
	}

	Mark& Mark::operator=(const Mark rigthMark) {
		if (int(rigthMark) >= 0 && int(rigthMark) <= 100) calculate(int(rigthMark));
		else calculate(-1);
		return *this;
	}

	Mark& Mark::operator+=(int newMark) {
		if (m_mark != -1) {
			if (newMark >= 0 && newMark <= 100) {
				int newTotal = m_mark + newMark;
				if (newTotal >= 0 && newTotal <= 100) calculate(newTotal);
			}
			else calculate(-1);
		}
		return *this;
	}

	Mark& Mark::operator-=(int newMark) {
		if (m_mark != -1) {
			if (newMark >= 0 && newMark <= 100) {
				int newTotal = m_mark - newMark;
				if (newTotal >= 0 && newTotal <= 100) calculate(newTotal);
			}
			else calculate(-1);
		}
		return *this;
	}

	Mark& Mark::operator>>(Mark& rightMark) {
		if (m_mark != -1 && bool(rightMark)) {
			int newMark = m_mark + int(rightMark);
			if (newMark >= 0 && newMark <= 100) {
				rightMark.calculate(newMark);
				calculate(0);
			}
		}
		return *this;
	}

	Mark& Mark::operator<<(Mark& rightMark) {
		if (m_mark != -1 && bool(rightMark)) {
			int newMark = m_mark + int(rightMark);
			if (newMark >= 0 && newMark <= 100) {
				calculate(newMark);
				rightMark.calculate(0);
			}
		}
		return *this;
	}

	int operator+=(int& leftInt, Mark rightMark) {
		 if (bool(rightMark) && leftInt >= 0 && leftInt <= 100) leftInt += int(rightMark);
		 return leftInt;
	}

	int operator-=(int& leftInt, Mark rightMark) {
		 if (bool(rightMark) && leftInt >= 0 && leftInt <= 100) leftInt -= int(rightMark);
		 return leftInt;
	}

	Mark operator+(const Mark leftMark, const int rightInt)
	{
		Mark tempMark;
		if (bool(leftMark)) {
			int newMark = rightInt + int(leftMark);
			if (newMark >= 0 && newMark <= 100) tempMark.calculate(newMark);
			else tempMark.calculate(-1);
		}
		return tempMark;
	}

	Mark operator+(const Mark leftMark, const Mark rightMark)
	{
		Mark tempMark;
		if (bool(leftMark) && bool(rightMark)) {
			int newMark = int(rightMark) + int(leftMark);
			if (newMark >= 0 && newMark <= 100) tempMark.calculate(newMark);
			else tempMark.calculate(-1);
		}
		return tempMark;
	}

	Mark operator+(const int leftInt, const Mark rightMark)
	{
		Mark tempMark;
		if (bool(rightMark)) {
			int newMark = leftInt + int(rightMark);
			if (newMark >= 0 && newMark <= 100) tempMark.calculate(newMark);
			else tempMark.calculate(-1);
		}
		return tempMark;
	}
}