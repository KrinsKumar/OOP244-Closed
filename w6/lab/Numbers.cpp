#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
using namespace std;
namespace sdds {


   Numbers::Numbers() { 
      setEmpty();
      m_isOriginal = false;
   } 

   Numbers::Numbers(const char* filename) { 
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         deallocate();
         setEmpty();
         m_isOriginal = false; 
      }
   }

   Numbers::~Numbers() {
      save();
      deallocate();
   }

   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }

   void Numbers::deallocate() {
      delete[] m_filename;
      delete[] m_numbers;
   }

   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }

   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }

   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }

   double Numbers::max() const {
      double maxVal = 0.0;
      if(!isEmpty()) {
         maxVal = m_numbers[0];
         for(int i = 1; i < m_numCount; i++)
            if(maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }
  




   Numbers::Numbers(const Numbers& rightNum) {
      setEmpty();
      m_isOriginal = false;
      *this = rightNum;
   }

   Numbers& Numbers::operator=(const Numbers& rightNum) {
		if (m_numbers != rightNum.m_numbers) {
			deallocate();
			setEmpty();
			m_isOriginal = false;
			m_numbers = new double[rightNum.m_numCount];
			for (int i = 0; i < rightNum.m_numCount; i++) {    // assigns the values from one class to another
				m_numbers[i] = rightNum.m_numbers[i];
			}
         m_numCount = rightNum.m_numCount;
		}
		return *this;
   }

   Numbers& Numbers::sort(bool ascending) {
		for (int i = 0; i < m_numCount; i++) {
			int index = i;
			for (int j = i + 1; j < m_numCount; j++) {
				if (ascending) {
					if (m_numbers[index] > m_numbers[j]) index = j;
            } else {
               if (m_numbers[index] < m_numbers[j]) index = j; 
				}
			}
         if (index != i) {
            double temp = m_numbers[i];
            m_numbers[i] = m_numbers[index];
            m_numbers[index] = temp;
         }
		}
		return *this;
   }

   Numbers Numbers::operator-() const {
		Numbers tempNumbers = *this;
		tempNumbers.sort(false);
		return tempNumbers;
   }

   Numbers Numbers::operator+() const {
		Numbers tempNumbers = *this;
		tempNumbers.sort(true);
		return tempNumbers;
   }

   int Numbers::numberCount() const {
		int lineCount = 0;
		ifstream file(m_filename);
		char ch[10];
		while (file) {
         file.getline(ch, 256, '\n');
			if (file) {
				lineCount++;
			}
		}
		return lineCount;
   }

   bool Numbers::load() {
		int count = 0;
      double temp;
		if (m_numCount > 0) {
			ifstream file(m_filename);
			m_numbers = new double[m_numCount];
			while (file) {
				file >> temp;    // reads one value from the file and stores it in an temp variable
				file.ignore(1000, '\n');
				if (file) {
               if (count < m_numCount)  m_numbers[count] = temp; // makes sure that there is no buffer overflow
               count++;
            }
			}
         file.ignore(1000, '\n');
		}
		return count == m_numCount;
   }

   void Numbers::save() {
		if (!isEmpty() && m_isOriginal) {
         ofstream file(m_filename);
         file.setf(ios::fixed);
         file.precision(2);
			for (int i = 0; i < m_numCount; i++) {
				file << m_numbers[i] << '\n';
         }
         file.unsetf(ios::fixed);
		}
   }

   Numbers Numbers::operator+=(const double rightNum) {
      double* tempDoubles = new double[m_numCount + 1];    // makes a new temp storage with one extra space
      for (int i = 0; i < m_numCount; i++) {
	      tempDoubles[i] = m_numbers[i];
      }
      tempDoubles[m_numCount] = rightNum;    // that one extra space gets assigned
      delete []m_numbers;    // old storge deleted
      m_numCount++;    
      m_numbers = new double[m_numCount];    // new storage with +1 storage
      for (int i = 0; i < m_numCount; i++) {
         m_numbers[i] = tempDoubles[i];
      }
      delete []tempDoubles;    // temp storge deleted
      return *this;
   }

   ostream& Numbers::display(ostream& ostr) const {
      if (isEmpty()) ostr << "Empty list";
      else {
         ostr << "=========================" << endl;
         if (m_isOriginal) ostr << m_filename << endl;
         else ostr << "*** COPY ***" << endl;
         ostr.setf(ios::fixed);
         ostr.precision(2);
         for (int i = 0; i < m_numCount; i++) {
            if (i != 0) ostr << ", ";
            ostr << m_numbers[i];
         }
         ostr << endl << "-------------------------" << endl;
         ostr << "Total of " << m_numCount << " number(s)" << endl;
         ostr << "Largest number:  " << max() << endl;
         ostr << "Smallest number: " << min() << endl;
         ostr << "Average:         " << average() << endl << "=========================";
      }
      ostr.unsetf(ios::fixed);
      return ostr;
   }

   std::ostream& operator<<(std::ostream& ostr, const Numbers& N) {
      return N.display(ostr);
   }

   std::istream& operator>>(std::istream& istr, Numbers& N) {
      double scanDouble;
      istr >> scanDouble;
      N += scanDouble;
      return istr;
   }
}
