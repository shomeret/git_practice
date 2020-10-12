#ifndef SDDS_SHIP_H
#define SDDS_SHIP_H
// || << >> \n "" '' {} []
#include "Engine.h"

//Name: Alan Yanovich
 //St#: 021278106
 //email: ayanovich@myseneca.ca
 //date: Jun 25, 2020

namespace sdds {
	const int MAX_TYPE_SIZE = 30;
	const double MIN_STD_POWER = 90.111;
	const double MAX_STD_POWER = 99.999;
	//class Engine;

	class Ship {
		Engine* m_engines;
		//Engine* newer_engines;
		char* m_type;
		int m_engCnt;
		double tot_power;
	public:
		Ship();
		~Ship();
		Ship(const char* type, Engine engine[], int engineCnt);
		void setEmpty();
		void clearName();
		void clearPtr();
		bool isValid() const;
		double totOutputPower() const;
		explicit operator bool() const;
		Ship& operator+=(Engine engine);
		bool operator<(double power) const;
		void display() const;
		friend bool operator<(double power, const Ship& theShip);
	};

	//friend bool operator<(double power, const Ship& theShip);
}


#endif
