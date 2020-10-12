#include <iostream>
#include <iomanip>
#include "Basket.h"
// [] {} << >> <> \n "" '' ||


//Name: Alan Yanovich
 //St#: 021278106
 //email: ayanovich@myseneca.ca
 //date: Jul 7, 2020

// I did all coding by myself 
namespace sdds{
	Basket::Basket() {
		setEmpty();
	}

	void Basket::setEmpty() {
		m_fruits = nullptr;
		m_cnt = 0;
		m_price = 0.0;
	}

	Basket::Basket(Fruit fruit[], int size, double price) {
		if (fruit!=nullptr && size > 0 && price > 0.0) {
			m_fruits = new Fruit[size];
			m_cnt = size;
			m_price = price;
			for (int i=0; i < m_cnt; i++) {
				m_fruits[i] = fruit[i];
			}
		} else {
			setEmpty();
		}
	}

	Basket::Basket(const Basket& src) {
		m_cnt = src.m_cnt;
		m_price = src.m_price;
		
		if (src.m_fruits != nullptr) {
			m_fruits = new Fruit[m_cnt];
			for (int i=0; i<m_cnt; i++) {
				m_fruits[i] = src.m_fruits[i];
			}
		}
		else
			m_fruits = nullptr;
	}

	Basket& Basket::operator=(const Basket& src) {
		if (this != &src) {
			m_cnt = src.m_cnt;
			m_price = src.m_price;
		
			delete[] m_fruits;

			if (src.m_fruits != nullptr) {
				m_fruits = new Fruit[m_cnt];
				for (int i = 0; i < m_cnt; i++) {
					m_fruits[i] = src.m_fruits[i];
			}
		} else 
				m_fruits = nullptr;
	}
		return *this;
	}

	Basket::~Basket() {
		clearPtr();
	}
	
	void Basket::clearPtr() {
		delete[] m_fruits;
		m_fruits = nullptr;
	}

	void Basket::setPrice(double price) {
		m_price = price;
	}

	Basket::operator bool() const {
		if (m_cnt > 0)
			return true;
		else
			return false;
	}

	Basket& Basket::operator+=(Fruit fruit) {
			Fruit* temp = new Fruit[m_cnt+1];
			for (int i = 0; i < m_cnt; i++)
			{
				temp[i] = m_fruits[i];
			}
			temp[m_cnt++] = fruit;
			
			delete[] m_fruits;

			m_fruits = temp;
			temp = nullptr;

			return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Basket& basket) {
		if (basket.m_cnt == 0) {
			os << "The basket is empty!" << std::endl;
		} else {
		
			os << "Basket Content:" << std::endl;
			for (int i=0; i<basket.m_cnt; i++) {
				os.width(10);
				os << std::right << basket.m_fruits[i].m_name << ": ";
				printf("%.2lf", basket.m_fruits[i].m_qty);
				os << "kg" << std::endl;
			}
			os << "Price: ";
			printf("%.2lf", basket.m_price);
			os << std::endl;
		}
		return os;
	}
}


