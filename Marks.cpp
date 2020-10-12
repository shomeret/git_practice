//Name: Alan Yanovich
//St#: 021278106
//email: ayanovich@myseneca.ca
//date: May 29, 2020



#include "Marks.h"
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>


using namespace std;
// <<  >> || \ "" [] {}

void markstat() {
	Marks marks;
	char name[MAX_WORD_LEN];
	int num;
	cout << "Mark Stats Program.\n" << endl;
	cout << "Please enter the assessment name: ";
	cin.getline(name,40);
	cout << "Please enter the number of marks: ";
	num = marksNum(&marks);
	checkMarks(num, &marks);
	cout << "Thank you..." << endl;
	cout << "Assessment Name: " << name << endl;
	cout << "----------------" << endl;
	sortArray(num, &marks);
	printArray(num, &marks);
	averageCalc(num, &marks);
	
}


void checkMarks(int num, Marks* marks) {
	int i;
	cout << "Please enter " << num << " marks (0<=Mark<=100):" << endl;

	for (i=0; i < num; i++) {
		printf("%d> ", i+1);
		cin >> marks->marks_value[i];

		while (marks->marks_value[i] < 0 || marks->marks_value[i] > 100) {
			cout << "Invalid value (0<=value<=100), try again: ";
			cin >> marks->marks_value[i];
		}
		
		
	}
}