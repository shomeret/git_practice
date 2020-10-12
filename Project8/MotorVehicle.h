#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H

// [] {} \0 "" || << >>

 //Name: Alan Yanovich
 //St#: 021278106
 //email: ayanovich@myseneca.ca
 //date: Jul 12, 2020

namespace sdds {
class Truck;
class MotorVehicle {
	char license[32];
	char v_address[64];
	int year;
public:
	MotorVehicle(const char* li, int y);
	void moveTo(const char* address);
	std::ostream& write(std::ostream& os) const;
	std::istream& read(std::istream& in);
	
};
std::ostream& operator<<(std::ostream& os, const MotorVehicle& mv);
std::istream& operator>>(std::istream& is, MotorVehicle& mv);

}
#endif
