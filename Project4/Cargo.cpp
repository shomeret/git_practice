#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip> 
#include <string>
#include "Cargo.h"



namespace sdds {
	void Cargo::initialize(const char* desc, double weight) {
		/* temp_desc[MAX_DESC];
		strcpy(temp_desc,getDesc());
		double temp_weight = getWeight();*/
		setDesc(desc);
		setWeight(weight);

	};
	const char* Cargo::getDesc() const {
		return c_description;
	};
	double Cargo::getWeight() const {
		return c_weight;
	};
	void Cargo::setDesc(const char* description) {
		//int len = 0;
		//len = strlen(description);
		//std::cout << "length is: " << len << "\n";
		//if (len > MAX_DESC) {
		strcpy(c_description, description);
		//std::cout << "description is: " << c_description << "\n";
		c_description[MAX_DESC + 1] = '\0';
		//}
		/*else {
			strncpy(c_description, description, len);
			c_description[len + 1] = '\0';
		}*/
	};
	void Cargo::setWeight(double weight) {
		double temp_weight = MIN_WEIGHT;
		if (weight < MIN_WEIGHT || weight > MAX_WEIGHT) {
			//std::cout << std::setprecision(4);
			c_weight = temp_weight;
		} else {
			c_weight = weight;
		}
	};
}