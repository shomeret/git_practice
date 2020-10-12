#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip> 
#include <string>
#include "Engine.h"
// || << >> \n "" '' {} []

//Name: Alan Yanovich
 //St#: 021278106
 //email: ayanovich@myseneca.ca
 //date: Jun 25, 2020


namespace sdds {

	Engine::Engine() {
		setEmpty();
	}

	Engine::Engine(const char* name, double size) {
		if (!name || strlen(name) == 0 || size < 0) {
			setEmpty();
		} else {
			m_size = size;
			strcpy(m_type, name);
	}
	}
	double Engine::get() const {
		return m_size;
	}

	void Engine::display() const {
		printf("%.2lf liters - %s\n", m_size, m_type);
		//std::cout << m_size << " liters - " << m_type << std::endl;
	}

	void Engine::setEmpty() {
		m_type[0] = '\0';
		m_size = 0.0;
	}
}