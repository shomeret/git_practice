#ifndef SDDS_DOCTOR_H
#define SDDS_DOCTOR_H
#include "Employee.h"
// [] {} \0 "" || << >>

//Name: Alan Yanovich
 //St#: 021278106
 //email: ayanovich@myseneca.ca
 //date: Jul 21, 2020

// I did all coding by myself
namespace sdds {
	class Doctor : public Employee {
	public:
		Doctor(const char* type, double sal, const int minHrs, bool special = false);
		double getSalary(int workedHours);
		std::ostream& display(std::ostream& out);
	private:
		char drType[32];
		bool isSpecialist;


	};




}



#endif
