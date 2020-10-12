#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H
#include "MotorVehicle.h"

//Name: Alan Yanovich
//St#: 021278106
//email: ayanovich@myseneca.ca
//date: Jul 12, 2020

namespace sdds {
	class MotorVehicle;
	class Truck : public MotorVehicle {
		double cargo_max;
		double cargo_current;
	public:
		Truck(const char* li, int yr, double capacity, const char* addr);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
		
	};
	std::ostream& operator<<(std::ostream& os, const Truck& tr);
	std::istream& operator>>(std::istream& is, Truck& tr);


}



#endif
