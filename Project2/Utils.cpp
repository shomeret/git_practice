//Name: Alan Yanovich
//St#: 021278106
//email: ayanovich@myseneca.ca
//date: May 29, 2020


#include "Utils.h"
#include "Marks.h"
#include <cctype>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <iomanip>



using namespace std;
// <<  >> || \ "" [] {}
int marksNum(Marks* marks) {
	unsigned int i;
	int count_digit = 0;
	int count_nondigit = 0;
	int flag = 0;
	int sToInt;
	while (flag == 0 ) {
	scanf("%7[^\n]%*c", marks->number);


	for(i=0; i < strlen(marks->number); i++) {
		if (isdigit(marks->number[i]) != 0) {
			count_digit++;
		} else {
			count_nondigit++;	
	}
	}

	
	if (count_nondigit == 0 && count_digit > 0) {
		sToInt = stoi(marks->number);
			if (sToInt >= 5 && sToInt <= 50) {
				return sToInt;
			} else {
				cout << "Invalid value (5<=value<=50), try again: ";
			}
	} else if (count_nondigit > 0 && count_digit > 0) {
		cout << "Invalid trailing characters, try again: ";
	}
	else if (count_nondigit > 0 && count_digit == 0) {
		cout << "Invalid Number, try again: ";
	}

	count_digit = 0;
	count_nondigit = 0;

	}
	return 0;
}

void sortArray(int num, Marks* marks) {
	int i, j, temp;
	for (i = 0; i < (num - 1); i++) {
		for (j = 0; j < num - i - 1; j++) {
			if (marks->marks_value[j] < marks->marks_value[j + 1]) {
				temp = marks->marks_value[j];
				marks->marks_value[j] = marks->marks_value[j + 1];
				marks->marks_value[j + 1] = temp;
			}
			
		}

	}
	
}

void printArray(int num, Marks* marks) {
	int i;
	for (i = 0; i < num; i++) {
		if (i == num - 1) {
			cout << marks->marks_value[i] << "\n";
		}
		else {
			cout << marks->marks_value[i] << ", ";
		}
	} 
}

void averageCalc(int num, Marks* marks) {
	int i, sum = 0, count = 0;
	float average;
	for (i=0; i < num; i++) {
		if (marks->marks_value[i] >= 50) {
			count++;
		}
	sum = sum + marks->marks_value[i];
	}
	
	average = (float)sum / (float)num;
	cout << "Average: " << fixed << setprecision(1) << average << endl;
	cout << "Number of Passing Marks: " << count << endl;
}