#include "gradeBook.h"
#include <iostream>

GradeBook::GradeBook(ifstream & inFile)
{
 float grade;
 float sum=0;
 float maxGrade=0; 
 float numBelow=0; 
 string name;

 inFile >> grade;

	 while (inFile)
	{
		getline(inFile, name);
		StudentGrade studentGrade(name, grade); 
		roster.Insert(studentGrade);
		sum = sum+grade;
		if (grade > maxGrade)
		{
			maxGrade = grade;
		}	
		inFile >> grade;
	}

 average = sum / roster.GetLength();
 while (roster.HasNext()&&roster.GetNextItem().GetGrade() < average)
    numBelow++;
}
   
float GradeBook::GetAverageGrade() const
{
	return average;
}

float GradeBook::GetMaxGrade() const
{
	return maxGrade;
}

int GradeBook::GetAboveAverage() const
{
	return roster.GetLength()-numBelow;
}

int GradeBook::GetBelowAverage() const
{
	return numBelow;
}

float GradeBook::GetMinGrade()
{
	roster.ResetList();
	return roster.GetNextItem().GetGrade();
}

void GradeBook::StudentsMaxGrade(ofstream & outFile)
{
	outFile << endl << "The following students has the maximum grade: " << endl;
	
	roster.ResetList();
	StudentGrade aStudent = roster.GetNextItem();

	while (maxGrade > aStudent.GetGrade())
	{
		aStudent = roster.GetNextItem();
	}	

	outFile << aStudent.GetName() << endl;

	while (roster.HasNext())
	{
		outFile << roster.GetNextItem().GetName() << endl;
	}
}

void GradeBook::StudentsAbove(ofstream & outFile)
{
	outFile << endl << "The following students had an above average grade: " << endl;

	roster.ResetList();
	for (int count=1; count<=numBelow; count++)
		roster.GetNextItem();
	outFile << roster.GetNextItem().GetName() << endl;
	while (roster.HasNext())
		outFile << roster.GetNextItem().GetName() << endl;
}

void GradeBook::StudentsBelow(ofstream & outFile)
{
	outFile << endl << "The following students had a below average grade: " << endl;

	roster.ResetList();
	for (int count=1; count<=numBelow; count++)
		outFile << roster.GetNextItem().GetName() << endl;
}
