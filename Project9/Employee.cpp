#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>  
#include "Employee.h"
// [] {} \0 "" || << >>


 //Name: Alan Yanovich
 //St#: 021278106
 //email: ayanovich@myseneca.ca
 //date: Jul 21, 2020

// I did all coding by myself

namespace sdds {
	Employee::Employee(const int hrs, double salary): empWkHrs(hrs) {
		empSalary = salary;
	}
	Employee::~Employee() {}

	int Employee::showEmpHrs() {
		return empWkHrs;
	}
	double Employee::showEmpSalary() {
		return empSalary;
	}


	std::ostream& operator<<(std::ostream& os, Employee& emp) {
		emp.display(os);
		return os;
	}
	

}