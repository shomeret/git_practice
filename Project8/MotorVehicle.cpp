#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>  
#include "MotorVehicle.h"
#include "Truck.h"

// [] {} \0 "" || << >>

 //Name: Alan Yanovich
 //St#: 021278106
 //email: ayanovich@myseneca.ca
 //date: Jul 12, 2020

// I did all coding by myself
namespace sdds{
	MotorVehicle::MotorVehicle(const char* li, int y) {
		strcpy(license, li);
		year = y;
		strcpy(v_address, "Factory");
	}
	void MotorVehicle::moveTo(const char* address) {
		if (strcmp(address, v_address)!= 0) {
			std::cout << "|" << std::setw(10) << std::right << license << std::setfill(' ') << "| |" << std::setw(20) << std::right << v_address << std::setfill(' ') << " --->--- " << std::setw(20) << std::left << address << std::setfill(' ') <<  "|" << std::endl;
			strncpy(v_address, address, strlen(address)+1);
		}
	}

	std::ostream& MotorVehicle::write(std::ostream& os) const {
		os << "| " << year << " | " << license << " | " << v_address;
		return os;
	}

	std::istream& MotorVehicle::read(std::istream& in) {
		std::cout << "Built year: ";
		in >> year;
		std::cout << "License plate: ";
		in >> license;
		std::cout << "Current location: ";
		in >> v_address;
		return in;
	}

	std::ostream& operator<<(std::ostream& os, const MotorVehicle& mv) {
		mv.write(os);
		return os;
	}

	std::istream& operator>>(std::istream& is, MotorVehicle& mv) {
		mv.read(is);
		return is;
	}




}