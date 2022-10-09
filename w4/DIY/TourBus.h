#ifndef _SDDS_TOURBUS_H_
#define _SDDS_TOURBUS_H_

#include "TourTicket.h"

namespace sdds {

	class TourBus {
		private:
			sdds::TourTicket* m_passengers;
			int m_noOfPassangers;
			bool m_isBoarded;
		public:
			TourBus(int noOfPassangers);
			~TourBus();
			bool validTour()const;
			TourBus& board();
			void startTheTour()const;
	};

}




#endif // !_SDDS_TOURBUS_H_
