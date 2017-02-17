#include "sortedList.h"
#include <fstream>
#include <iostream>

using namespace std;

class GradeBook
{
public:

	GradeBook(ifstream & inFile);

	void StudentsMaxGrade(ofstream & outFile);
	void StudentsAbove(ofstream & outFile);
	void StudentsBelow(ofstream & outFile);

	float GetAverageGrade() const;
	float GetMaxGrade() const;
	int GetAboveAverage() const;
	int GetBelowAverage() const;
	float GetMinGrade();

private:
	float average;
	float maxGrade;
	int numBelow;
	SortedList roster; // list of grade/name pairs
};
