#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>  
#include "Engineer.h"


// [] {} \0 "" || << >>

namespace sdds {
	Engineer::Engineer(double sal, int level):Employee(30, sal) {
		engineerLevel = level;
	}
	double Engineer::getSalary(int workedHours) {
		int empHr = showEmpHrs();
		double empSal = showEmpSalary();
		double total = 0.0;
		total = ((double)workedHours * empSal) + ((double)engineerLevel * 40.0);
		if (workedHours < empHr) {
			total = total - (total * 0.2);
		}
		return total;
	}
	std::ostream& Engineer::display(std::ostream& out) {
		out << "Engineer" << std::endl;
		out << std::setw(20) << std::right << "Level: " << std::setfill(' ') << engineerLevel << std::endl;
		out << std::setw(20) << std::right << "Pay Rate: " << std::setfill(' ') << showEmpSalary() << std::endl;
		out << std::setw(20) << std::right << "Min Hours: " << std::setfill(' ') << showEmpHrs() << std::endl;
		return out;
	}


}

