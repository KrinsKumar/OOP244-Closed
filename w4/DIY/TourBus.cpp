#include <iostream>
#include "TourBus.h"

using namespace std;

namespace sdds {

	TourBus::TourBus(int noOfPassangers) {
		if (noOfPassangers == 4 || noOfPassangers == 16 || noOfPassangers == 22) {
			 m_passengers = new TourTicket[noOfPassangers];
			 m_noOfPassangers = noOfPassangers;
		}
		else {
			m_passengers = nullptr;
			m_noOfPassangers = 0;
		}
		m_isBoarded = false;
	};

	TourBus::~TourBus() {
		delete[] m_passengers; 
	}

	bool TourBus::validTour()const {
		return !(m_passengers == nullptr);
	}

	TourBus& TourBus::board() {

		cout << "Boarding " << m_noOfPassangers << " Passengers:" << endl;

		for (int i = 0; i < m_noOfPassangers; i++) {
			char name[41];
			cout << i+1 << "/" << m_noOfPassangers << "- Passenger Name: ";
			cin.getline(name, 40);

			m_passengers[i].issue(name);
		}
		m_isBoarded = true;
		return *this;
	}

	void TourBus::startTheTour()const {

		if (m_isBoarded) {
			cout << "Starting the tour...." << endl << "Passenger List:" << endl;
			cout << "|Row | Passenger Name                           | Num |" << endl;
			cout << "+----+------------------------------------------+-----+" << endl;
			for (int i = 0; i < m_noOfPassangers; i++) {
				cout << '|';

				cout.fill(' ');
				cout.width(3);
				cout.setf(ios::right);
				cout << i+1;
				cout.unsetf(ios::right);
				cout << ' ';

				m_passengers[i].display();
				cout << endl;
			}
			cout << "+----+------------------------------------------+-----+" << endl;
		}
		else {
			cout << "Cannot start the tour, the bus is not fully boarded!" << endl;
		}
	}
}