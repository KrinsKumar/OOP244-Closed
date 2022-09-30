#ifndef _SDDS_CC_H_
#define _SDDS_CC_H_

namespace sdds {

	class CC {
		private:
		char* m_name;
		short m_cvv;
		short m_expMon;
		short m_expYear;
		unsigned long long m_cardNo;
		bool validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear)const;
		void prnNumber()const;

		public:
		void set();
		void cleanUp();
		bool isEmpty() const;
		void set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear);
		bool read();
		void display(int row = 0) const;
	};
}
#endif // !_SDDS_CC_H_
