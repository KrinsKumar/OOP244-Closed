#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
   class Numbers {
      double* m_numbers{};
      char* m_filename{};
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty()const;
      void setEmpty();
      void deallocate();
      void setFilename(const char* filename);
   public:
      Numbers();
      Numbers(const char* filename);
      double average()const;
      double max()const;
      double min()const;
      ~Numbers();

	  // My functions
	  Numbers(const Numbers& rightNum);
	  Numbers& operator=(const Numbers& rightNum);
	  Numbers& sort(bool ascending);
	  Numbers operator-()const;
	  Numbers operator+()const;
	  int numberCount()const;
	  bool load();
	  void save();
	  Numbers operator+=(const double rightNum);
      std::ostream& display(std::ostream& ostr)const;
   };
   std::ostream& operator<<(std::ostream& ostr, const Numbers& N);
   std::istream& operator>>(std::istream& istr, Numbers& N);
}
#endif // !SDDS_NUMBERS_H_

