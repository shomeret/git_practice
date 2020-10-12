//Name: Alan Yanovich
//St#: 021278106
//email: ayanovich@myseneca.ca
//date: May 29, 2020

// I have done all coding work by myself and only copied the code that my professor provided me to complete my workshops.


#ifndef SDDS_MARKS_H
#define SDDS_MARKS_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define MAX_WORD_LEN 41
#define MAX_MARKS 50
//using namespace sdds;


struct Marks {
    char number[8];
    int marks_value[MAX_MARKS];
};

    void markstat();
    void checkMarks(int num, Marks* marks);
    int marksNum(Marks* marks);
    void sortArray(int num, Marks* marks);
    void printArray(int num, Marks* marks);
    void averageCalc(int num, Marks* marks);


#endif
