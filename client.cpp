#include <iostream>
#include "gradeBook.h"
#include <fstream>
#include <string>

using namespace std;
void OpenFiles(ifstream & inFile, ofstream & outFile);

int main()
{
	ofstream outFile;
	ifstream inFile;
	OpenFiles(inFile, outFile);
	if (!inFile || !outFile)
	{
		cout<<"Error opening files "<<endl;
		return 1;
	}
	GradeBook grades(inFile);
	outFile << "Average: " << grades.GetAverageGrade() << endl;
	outFile << "Minimum grade: " << grades.GetMinGrade() << endl;
	outFile << "Maximum grade: " << grades.GetMaxGrade() << endl;
	outFile << grades.GetAboveAverage() << " students had above average grades." <<endl;
	outFile << grades.GetBelowAverage() << " students had below average grades." <<endl;
	grades.StudentsMaxGrade(outFile);
	grades.StudentsAbove(outFile);
	grades.StudentsBelow(outFile);
	inFile.close();
	outFile.close();
}

void OpenFiles(ifstream & inFile, ofstream & outFile)
{
	string inFileName;
	string outFileName;
	cout<<"Enter the name of the input file."<<endl;
	cin>>inFileName;
	inFile.open(inFileName);
	cout<<"Enter the name of the output file."<<endl;
	cin>>outFileName;
	outFile.open(outFileName);

	outFile<<"Statistics for grades in file "<<inFileName<<endl;
	outFile<<fixed;
}
