#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "Truck.h"
#include "MotorVehicle.h"
// [] {} \0 "" || << >>


 //Name: Alan Yanovich
 //St#: 021278106
 //email: ayanovich@myseneca.ca
 //date: Jul 12, 2020

// I did all coding by myself
namespace sdds {
	Truck::Truck(const char* li, int yr, double capacity, const char* addr) : MotorVehicle(li, yr) {
		cargo_current = 0.0;
		cargo_max = capacity;
		moveTo(addr);
	}
	
	bool Truck::addCargo(double cargo){
		if ((cargo_current + cargo) < cargo_max) {
			cargo_current = cargo_current + cargo;
			return true;
		} else if ((cargo_current + cargo) >= cargo_max) {
			if (cargo_current == cargo_max) {
				return false;}
			cargo_current = cargo_max;
			return true;
		}	
		return true;
	}

	bool Truck::unloadCargo() {
		if (cargo_current != 0) {
			cargo_current = 0.0;
			return true;
		}
		else
			return false;
			
	}
	std::ostream& Truck::write(std::ostream& os) const {
		MotorVehicle::write(os);
		os << " | " << cargo_current << "/" << cargo_max;
		return os;
	}
	std::istream& Truck::read(std::istream& in) {
		MotorVehicle::read(in);
		std::cout << "Capacity: ";
		in >> cargo_max;
		std::cout << "Cargo: ";
		in >> cargo_current;
		return in;
	}
		
	std::ostream& operator<<(std::ostream& os, const Truck& tr) {
		tr.write(os);
		return os;
	}
	std::istream& operator>>(std::istream& is, Truck& tr) {
		tr.read(is);
		return is;
	}

	}


