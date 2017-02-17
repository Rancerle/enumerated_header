
#include "studentGrade.h"
const  int  MAX_LENGTH = 500;

class  SortedList	         
{
public: 	          

	SortedList();           
	bool IsEmpty() const;
	bool IsFull()  const;
	int  GetLength()  const; 

	void Insert(StudentGrade  item);
	void Delete(StudentGrade  item);
	bool IsPresent(StudentGrade  item)  const;
	void ResetList();

	StudentGrade GetNextItem();
	bool HasNext();

private:
	void BinarySearch(StudentGrade item, bool & found, int & position) const;

private:      
	int length; 
	StudentGrade data[MAX_LENGTH];
	int  currentPos;        
};
