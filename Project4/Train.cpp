#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>   
#include "Train.h"



using namespace std;
namespace sdds {

	void Train::initialize (const char* name, int id) {
		if (name == nullptr || name[0] == '\0' || id < 0) {
		//bool valid = (name != "" && name != nullptr && id > 0);
		//if (valid) {
			t_description[0] = '\0'; //if not set object to safe empty state
			t_id = 0;
			t_cargo = nullptr;
		}
		else { //otherwise copy inputs to object
			for (int i = 0; i < MAX_NAME; i++) {

				t_description[i] = name[i];
			}
			t_id = id;

		}
		t_cargo = nullptr;
	};
	bool Train::isValid() const {
		if (t_id != 0)
			return true;
		else
			return false;
	};

	void Train::loadCargo(Cargo car) {
		unloadCargo();
		//int len = 0;
		t_cargo = new Cargo;
		//len = strlen(car.c_description);
		//len = strlen(car.getDesc());
		//char temp[MAX_DESC+1];
		//strncpy(temp, car.getDesc(), len);
		t_cargo->setDesc(car.getDesc());
		t_cargo->setWeight(car.getWeight());
		//std::cout << "weight is: " << std::setprecision(4) << t_cargo->c_weight << std::endl;
	};
	void Train::unloadCargo() {	
		delete t_cargo;
		t_cargo = nullptr;
	};
	void Train::display() const {
		//std::cout << "test";
		bool valid = isValid();
		//if (t_description[0] != '\0' && t_description != nullptr && t_id > 0) {
		if (valid) {
			if (t_cargo == nullptr) {
				std::cout << "***Train Summary***" << std::endl;
				std::cout.width(10);
				std::cout << "Name: " << t_description << std::endl;
				std::cout.width(10);
				std::cout << "ID: " << t_id << std::endl;
				std::cout << "No cargo on this train." << std::endl;
			} else {
				std::cout << "***Train Summary***" << std::endl;
				std::cout.width(10);
				std::cout << "Name: " << t_description << std::endl;
				std::cout.width(10);
				std::cout << "ID: " << t_id << std::endl;
				std::cout.width(10);
				std::cout << "Cargo: " << t_cargo->getDesc() << std::endl;
				std::cout.width(10);
				printf("  Weight: %.2lf", t_cargo->getWeight());
				std::cout << std::endl;
				//std::cout << "Weight: " /*<< std::fixed << std::setprecision(2)*/ << t_cargo->getWeight() << std::endl;
				//auto precision = cout.precision(2);
				//std::cout.precision(precision);


			}
		} 
		else {
			std::cout << "***Train Summary***" << std::endl;
			std::cout << "This is an invalid train." << std::endl;
		}
	};
	bool Train::swapCargo(Train& other) {
		if(/*(strcmp(t_description, "") != 0) &&*/ t_description != nullptr && t_id > 0 /*&& (strcmp(other.t_description, "") != 0)*/ && other.t_description != nullptr && other.t_id > 0 && /*(strcmp(other.t_cargo->getDesc(), "") != 0) &&*/ other.t_cargo->getDesc() != nullptr) {

			double temp;
			char temp_n[MAX_DESC];

			strcpy(temp_n, t_cargo->getDesc());
			t_cargo->setDesc(other.t_cargo->getDesc());
			other.t_cargo->setDesc(temp_n);

			temp = t_cargo->getWeight();
			t_cargo->setWeight(other.t_cargo->getWeight());
			other.t_cargo->setWeight(temp);

			return true;
		} else {
			return false;
		}
	};
	bool Train::increaseCargo(double weight) {
		bool validator = isValid();
		double weight_validator = t_cargo->getWeight();

		if (validator == true && weight_validator != 0.0) {
			double total_weight = 0.0;
			total_weight = t_cargo->getWeight() + weight;
			if (total_weight <= MAX_WEIGHT) {
				t_cargo->setWeight(total_weight);
				return true;
			} else {
				double tot_weight = t_cargo->getWeight();
				double max_w = MAX_WEIGHT;
				if (tot_weight == MAX_WEIGHT) {
				return false;
				} else {
				t_cargo->setWeight(max_w);
				return true;
			}
		} 
		}
		return false;
	};
	bool Train::decreaseCargo(double weight) {
		
		bool validator = isValid();
		//int test = strlen(t_cargo->getDesc());
		//std::cout << "int test is: "<< test;
		if (validator == true && t_cargo->getDesc() != nullptr) {
			double total_weight = 0.0;
			total_weight = t_cargo->getWeight() - weight;
			if (total_weight >= MIN_WEIGHT) {
				t_cargo->setWeight(total_weight);
				return true;
			}
			else {
				double tot_weight = t_cargo->getWeight();
				if (tot_weight == MIN_WEIGHT) {
					return false;
				}
				else {
					double min_w = MIN_WEIGHT;
					t_cargo->setWeight(min_w);
					return true;
				}
			}
		}
		return false;
	};

		/*bool validator = isValid();
		double weight_validator = t_cargo->getWeight();

		if (validator == true && weight_validator != 0.0) {
			double total_weight = 0.0;
			total_weight = t_cargo->getWeight() - weight;

			if (total_weight >= MIN_WEIGHT) {
				t_cargo->setWeight(total_weight);
				return true;
			}
			else {
				double tot_weight = t_cargo->getWeight();
				if (tot_weight == MIN_WEIGHT) {
					return false;
				}
				else {
					t_cargo->setWeight(MIN_WEIGHT);
					return true;
				}
			}
		}*/

		/*bool validator = isValid();

		if (validator == true && t_cargo->getDesc() != "" && t_cargo->getDesc() != nullptr) {
			double total_weight = 0.0;
			total_weight = t_cargo->getWeight() - weight;
			if (total_weight >= MIN_WEIGHT) {
				t_cargo->setWeight(total_weight);
				return true;
			} else {
				t_cargo->setWeight(MIN_WEIGHT);
				return true;
			}
		} else {
			return false;
		}*/
	}





