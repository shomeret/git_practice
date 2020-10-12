#ifndef SDDS_SAIYAN_H
#define SDDS_SAIYAN_H
// || << >> \n "" '' {} []

//Name: Alan Yanovich
 //St#: 021278106
 //email: ayanovich@myseneca.ca
 //date: Jun 17, 2020

namespace sdds {
	const int MAX_NAME = 32;
	const int MAX_YEAR = 2020;
	

	class Saiyan { // The Mighty Saiyans
		char* m_name;
		int m_dob;
		int m_power;
		bool m_super;
		int m_level;
		//int ms;
	public:
		Saiyan();
		Saiyan(const char* name, int dob, int power);
		~Saiyan();
		void set(const char* name, int dob, int power, int level = 0, bool super = false);
		void setEmpty();
		void clearMemory();
		bool isValid() const;
		void display() const;
		bool fight(Saiyan& other);
		bool isSuper();
	}; 
}




#endif
