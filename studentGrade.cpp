#include "studentGrade.h"

StudentGrade::StudentGrade()
{
}

StudentGrade::StudentGrade(string name, float grade)
{
 this->name = name;
 this->grade = grade;
}

int StudentGrade::CompareTo(StudentGrade other) const
{
 if (grade > other.grade)
    return 1; 
 if (grade < other.grade)
    return -1; 
 //if (grade == other.grade)
    return 0; 
}

string StudentGrade::GetName()
{
  return name;
}

float StudentGrade::GetGrade() const
{
  return grade;
}
