#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>  
#include "Doctor.h"

// [] {} \0 "" || << >>


 //Name: Alan Yanovich
 //St#: 021278106
 //email: ayanovich@myseneca.ca
 //date: Jul 21, 2020

// I did all coding by myself
namespace sdds {

	Doctor::Doctor(const char* type, double sal, const int minHrs, bool special):Employee(minHrs, sal){
		strcpy(drType, type);
		isSpecialist = special;
	}
	double Doctor::getSalary(int workedHours) {
		int empHr = showEmpHrs();
		double empSal = showEmpSalary();
		double total = 0.0;
		if (workedHours <= empHr)
			total = empSal * (double)workedHours;
		else {
			int difference = workedHours - empHr;
			total = ((double)empHr * empSal) + ((double)difference * empSal * 1.5);
		}

		if (isSpecialist)
			total += 2000.0;

		return total;
	}
	std::ostream& Doctor::display(std::ostream& out) {
		out << "Doctor" << std::endl;
		if (isSpecialist)
			out << std::setw(16) << std::right << "Type: " << std::setfill(' ') << drType << " (specialist)" << std::endl;
		else
			out << std::setw(16) << std::right << "Type: " << std::setfill(' ') << drType << std::endl;
		out << std::setw(16) << std::right << "Pay Rate: " << std::setfill(' ') << showEmpSalary() << std::endl;
		out << std::setw(16) << std::right << "Min Hours: " << std::setfill(' ') << showEmpHrs() << std::endl;
		return out;
	}


}