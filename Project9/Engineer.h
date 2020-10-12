#ifndef SDDS_ENGINEER_H
#define SDDS_ENGINEER_H
#include "Employee.h"
// [] {} \0 "" || << >>
 
//Name: Alan Yanovich
 //St#: 021278106
 //email: ayanovich@myseneca.ca
 //date: Jul 21, 2020

// I did all coding by myself

namespace sdds {
	class Engineer: public Employee {
	public:
		Engineer(double sal, int level);
		double getSalary(int workedHours);
		std::ostream& display(std::ostream& out);
	private:
		int engineerLevel;
	
	};






}
#endif

