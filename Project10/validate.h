#ifndef SICT_VALIDATE_H
#define SICT_VALIDATE_H

//Name: Alan Yanovich
 //St#: 021278106
 //email: ayanovich@myseneca.ca
 //date: Jul 27, 2020

// I did all coding by myself, except for size_t which I have found online

namespace sict {
	template<typename T>
	bool validate(T const& minimum, T const* testvalues, size_t numElements, bool* arrResults) {

		int count_of_correct = 0;
		for (size_t i = 0; i < numElements; i++) {
			if (testvalues[i] >= minimum) {
				count_of_correct++;
				arrResults[i] = true;
			}
			else
				arrResults[i] = false;
		}
		if (count_of_correct == numElements)
			return true;

		return false;
	};

}





#endif