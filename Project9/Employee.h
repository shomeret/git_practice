#ifndef SDDS_EMPLOYEE_H
#define SDDS_EMPLOYEE_H
// [] {} \0 "" || << >>

 //Name: Alan Yanovich
 //St#: 021278106
 //email: ayanovich@myseneca.ca
 //date: Jul 21, 2020

// I did all coding by myself

namespace sdds {
    class Employee {
    public:
        //Employee();
        Employee(const int hours, double salary);
        virtual double getSalary(int workedHours) = 0;
        virtual std::ostream& display(std::ostream& out = std::cout) = 0;
        friend std::ostream& operator<<(std::ostream& os, Employee& emp);
        virtual ~Employee();
    protected:
        int showEmpHrs();
        double showEmpSalary();
    private:
        const int empWkHrs; // MINIMUM num of hours employee must work
        double empSalary; // hourly salary of employee

    };
    //std::ostream& operator<<(std::ostream& os, Employee& emp);
    //std::istream& operator>>(std::istream& is, Employee& emp);



}


#endif
