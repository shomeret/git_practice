#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip> 
#include <string>
#include "Ship.h"
#include "Engine.h"
// || << >> \n "" '' {} []

//Name: Alan Yanovich
 //St#: 021278106
 //email: ayanovich@myseneca.ca
 //date: Jun 25, 2020


namespace sdds {
	Ship::Ship() {
		/*for (int i = 0; i < 10; i++) {
			m_engines[i] = Engine();
		}
		m_type[0] = '\0';
		m_engCnt = 0;
		tot_power = 0.0;*/
		setEmpty();
	}

	Ship::~Ship() {
		clearName();
		clearPtr();
	}

	void Ship::clearName(){
		delete[] m_type;
		m_type = nullptr;
	}
	
	void Ship::clearPtr(){
		delete[] m_engines;
		m_engines = nullptr;

	}
	void Ship::setEmpty() {
		m_engines = nullptr;
		m_type = nullptr;
		m_engCnt = 0;
		tot_power = 0.0;
	}

	double Ship::totOutputPower() const {
		double total = 0.0;
		for (int i=0; i < m_engCnt; i++) {
			 total += m_engines[i].get() * 5;
		}
		return total;
	}

	Ship::Ship(const char* type, Engine engine[], int engineCnt) {
		if (engine != nullptr && engineCnt > 0 && type != nullptr)
		{
			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);

			m_engines = new Engine[engineCnt];
			m_engCnt = engineCnt;
			for (int i = 0; i < m_engCnt; i++)
			{
				m_engines[i] = engine[i];
			}
		} else {
			setEmpty();
		}
	}
	
	bool Ship::isValid() const {
		if (m_engCnt <= 0 || !m_engines || strlen(m_type) == 0 || !m_type)
			return false;
		else
			return true;
	
	
	}
	Ship::operator bool () const {
		if (isValid())
			return true;
		else
			return false;
	}
	Ship& Ship::operator+=(Engine engine) {
			if (*this)
			{
				Engine* temp = new Engine[m_engCnt + 1];
				for (int i = 0; i < m_engCnt; i++)
				{
					temp[i] = m_engines[i];
				}
				temp[m_engCnt++] = engine;

				delete[] m_engines;

				m_engines = temp;
				temp = nullptr;
				tot_power = totOutputPower();
			}
			else
				std::cout << "The object is not valid! Engine cannot be added!" << std::endl;

			return *this;
	}
	
	bool Ship::operator<(double power) const {
		if (totOutputPower() < power) {
			return true;
		}
		else {
			return false;
		}
	}
	void Ship::display() const {
		if (m_engCnt > 0) {
			if (strcmp(m_type, "liner") == 0)
				printf("%s -  %.2lf\n", m_type, totOutputPower());
			else
			printf("%s - %.2lf\n", m_type, totOutputPower());
		//std::cout << m_type << " - " << totOutputPower() << std::endl;
		for (int i=0; i<m_engCnt; i++) {
			m_engines[i].display();
		}
		} else
			std::cout << "No available data" << std::endl;
	}
	bool operator<(double power, const Ship& theShip) {
		if (power < theShip.totOutputPower())
			return true;
		else
			return false;
	}





}