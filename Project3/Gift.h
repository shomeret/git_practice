#ifndef SDDS_GIFT_H
#define SDDS_GIFT_H
#include <iostream>

//Name: Alan Yanovich
//St#: 021278106
//email: ayanovich@myseneca.ca
//date: Jun 5, 2020

namespace sdds {
	const int MAX_WRAP = 20;
	const int MAX_DESC = 15;
	const double MAX_PRICE = 999.999;
	

	struct Wrapping {
		char* m_pattern = nullptr;
		
	
	};
	struct Gift {
		char m_description[MAX_DESC + 1];
		double m_price;
		int m_units;
		Wrapping* m_wrap;
		int m_wrapLayers;
	};
	void gifting(char* desc);
	void gifting(double& price);
	void gifting(int& units);
	void display(const Gift& theGift);
	bool wrap(Gift& theGift);
	bool unwrap(Gift& theGift);
	void gifting(Gift& theGift);
}



#endif
