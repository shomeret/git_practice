#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip> 
#include <string>
#include "Saiyan.h"
// || << >> \n "" '' {} []

//Name: Alan Yanovich
 //St#: 021278106
 //email: ayanovich@myseneca.ca
 //date: Jun 17, 2020

namespace sdds {
	Saiyan::Saiyan() {
		setEmpty();
	}
	Saiyan::~Saiyan() {
		clearMemory();
	}
	Saiyan::Saiyan(const char* name, int dob, int power) {
		setEmpty();
		set(name, dob, power);
		
}
	void Saiyan::setEmpty() {
		m_name = nullptr;
		m_dob = 0;
		m_power = 0;
		m_super = 0;
		m_level = 0;
	}
	
	void Saiyan::clearMemory() {
		delete[] m_name;
		m_name = nullptr;
	}

	bool Saiyan::isSuper() {
		return m_super;
	}

	void Saiyan::set(const char* name, int dob, int power, int level, bool super) {
		if (!name || strlen(name) == 0 || dob > 2020 || power <= 0 /*|| level < 0*/) {
			//std::cout << "test11" << std::endl;
			/*this->m_power = 0;
			this->m_name = nullptr;
			this->m_dob = 0;
			this->m_super = false;
			this->m_level = isSuper() ? level : 0;*/
			setEmpty();

		} else {
				clearMemory();
				m_name = new char[strlen(name) + 1];
				strcpy(this->m_name, name);
				this->m_dob = dob;
				this->m_power = power;
				this->m_level = level;
				this->m_super = super;
		}
	}
	

	bool Saiyan::isValid() const {
		return (m_name && m_name[0]);
	}

	void Saiyan::display() const {
		bool valid = isValid();
		if (valid) {
			std::cout << m_name << std::endl;
			std::cout.width(10);
			std::cout << std::right << "DOB: " << m_dob << std::endl;
			std::cout.width(10);
			std::cout << std::right << "Power: " << m_power << std::endl;
			if (m_super == true) {
				std::cout.width(13);
				std::cout << std::right << "Super: yes" << std::endl;
				std::cout.width(10);
				std::cout << std::right << "Level: " << m_level << std::endl;
			}
			else {
				std::cout.width(12);
				std::cout << std::right << "Super: no" << std::endl;
			}
		} else {
			std::cout << "Invalid Saiyan!" << std::endl;
		}
	}
	bool Saiyan::fight(Saiyan& other) {
		bool c_valid = isValid();
		bool o_valid = other.isValid();
		if (c_valid == o_valid) {
			if (m_super == true) {
				double tmp_level = ((m_level*10.0)/100.0);
				int tmp_power = (int)(m_power * tmp_level);
				m_power = m_power + tmp_power;
			}
			if (other.m_super == true) {
				double tmpo_level = ((other.m_level*10.0)/100.0);
				int tmpo_power = (int)(other.m_power * tmpo_level);
				other.m_power = other.m_power + tmpo_power;
			}
			if (m_power > other.m_power)
				return true;
			else
				return false;
		}
		else
			return false;
	}
}