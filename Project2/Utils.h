//Name: Alan Yanovich
//St#: 021278106
//email: ayanovich@myseneca.ca
//date: May 29, 2020



#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
#define _CRT_SECURE_NO_WARNINGS
#include "Marks.h"
#include <string>
#include <iostream>
#define MAX_WORD_LEN 41
#define MAX_MARKS 50
// <<  >> || \ "" 
using namespace std;

int marksNum(Marks* marks);
void sortArray(int num, Marks* marks);
void printArray(int num, Marks* marks);
void averageCalc(int num, Marks* marks);


#endif

