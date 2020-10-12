//Name: Alan Yanovich
//St#: 021278106
//email: ayanovich@myseneca.ca
//date: Jun 5, 2020





#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "Gift.h"


namespace sdds {
void gifting(char* desc) {
	std::cout << "Enter gift description: ";
	std::cin.width(MAX_DESC + 1);
	std::cin >> desc;
}

void gifting(double& price) {
	int test = 1;
	while (test == 1) {
		std::cout << "Enter gift price: ";
		std::cin >> price;
		if (price >= 0 && price <= MAX_PRICE) {
			test = 0;
		}
		else {
			std::cout << "Gift price must be between 0 and "
			<< MAX_PRICE << std::endl;
		}
	}
}

void gifting(int& units) {
	int test = 1;
	while (test == 1) {
		std::cout << "Enter gift units: ";
		std::cin >> units;
		if (units >= 1) {
			test = 0;
		}
		else {
			std::cout << "Gift units must be at least 1" << std::endl;
		}
	}

}

void display(const Gift& theGift) {
	std::cout << "Gift Details:" << std::endl;
	std::cout.width(14);
	std::cout << "Description: " << theGift.m_description << std::endl;
	std::cout.width(14);
	std::cout << "Price: " << theGift.m_price << std::endl;
	std::cout.width(14);
	std::cout << "Units: " << theGift.m_units << std::endl;
	if (theGift.m_wrapLayers == 0) {
		std::cout << "Unwrapped!" << std::endl;
	} else {
		std::cout << "Wrap Layers: " << theGift.m_wrapLayers << std::endl;

		for (int i=0; i < theGift.m_wrapLayers; i++) {
		std::cout << "Wrap #" << i + 1 << " -> " 
			<< theGift.m_wrap[i].m_pattern << std::endl;
		}
	}
}

bool wrap(Gift& theGift) {
	if (theGift.m_wrapLayers > 0) {
		std::cout << "Gift is already wrapped!" << std::endl;
		return false;
	} else {
		std::cout << "Wrapping gifts..." << std::endl;
		std::cout << "Enter the number of wrapping layers for the Gift: ";
		std::cin >> theGift.m_wrapLayers;
		while (theGift.m_wrapLayers < 1) {
			std::cout << "Layers at minimum must be 1, try again." << std::endl;
			std::cout << "Enter the number of wrapping layers for the Gift: ";
			std::cin >> theGift.m_wrapLayers;
		} 
		theGift.m_wrap = new Wrapping[theGift.m_wrapLayers];
		
		for (int i=0; i<theGift.m_wrapLayers; i++) {
			char wrapPattern[MAX_WRAP + 1];
			int len = 0;
			std::cout << "Enter wrapping pattern #" << i + 1 << ": ";
				//std::cin.getline(wrapPattern,sizeof(wrapPattern));
			std::cin >> wrapPattern;
			len = strlen(wrapPattern);

			theGift.m_wrap[i].m_pattern = new char[len + 1];
			strncpy(theGift.m_wrap[i].m_pattern, wrapPattern, len);
			theGift.m_wrap[i].m_pattern[len] = '\0';
			}
			
		return true;
	}
}

bool unwrap(Gift& theGift) {
	if (theGift.m_wrapLayers == 0) {
		std::cout << "Gift isn't wrapped! Cannot unwrap." << std::endl;
		return false;
	} else {
		std::cout << "Gift being unwrapped." << std::endl;
		for (int i = 0; i < theGift.m_wrapLayers; i++) {
			delete [] theGift.m_wrap[i].m_pattern;
			theGift.m_wrap[i].m_pattern = nullptr;
		}
		theGift.m_wrapLayers = 0;
		delete [] theGift.m_wrap;
		return true;
	}
}

void gifting(Gift& theGift) {
	std::cout << "Preparing a gift..." << std::endl;
	gifting(theGift.m_description);
	gifting(theGift.m_price);
	gifting(theGift.m_units);
	wrap(theGift);

}
}