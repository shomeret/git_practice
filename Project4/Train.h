#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

#include "Cargo.h"



namespace sdds {
	const int MAX_NAME = 30;

	class Train {
		char t_description[MAX_NAME + 1];
		int t_id;
		Cargo* t_cargo = nullptr;
	public:
		void initialize(const char*, int);
		bool isValid() const;
		void loadCargo(Cargo);
		void unloadCargo();
		void display() const;
		bool swapCargo(Train& other);
		bool increaseCargo(double weight);
		bool decreaseCargo(double weight);
	};

}




#endif
