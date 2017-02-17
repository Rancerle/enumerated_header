#include "sortedList.h"

SortedList::SortedList()
{
	length = 0;
	currentPos = 0;
}

bool SortedList::IsEmpty() const
{
	return length == 0;
}

bool SortedList::IsFull() const
{
	return length == MAX_LENGTH;
}

int SortedList::GetLength() const
{
	return length;
}

void SortedList::Insert(StudentGrade item)
{
	int index = length - 1;
	
	while (index>-1 && data[index].GetGrade()>item.GetGrade())
	{
		data[index + 1] = data[index];
		index--;
	}
	
	data[index + 1] = item;
	length++;
}

void SortedList::Delete(StudentGrade item)
{
	bool found;
	int index;

	BinarySearch(item, found, index);
	if (found) 
	{
		while (index<length - 1) 
		{
			data[index] = data[index + 1];
			index++;
		}
		length--;
	}
}

void SortedList::BinarySearch(StudentGrade item, bool & found, int & position) const 
{
	int left, right, middle;
	found = false;
	left = 0;
	right = length - 1;
	while (left <= right && !found) 
	{
		middle = (left + right) / 2;
		
		if (data[middle].GetGrade() == item.GetGrade()) 
		{
			found = true;
			position = middle;
			break;
		}
		
		else if (data[middle].GetGrade() < item.GetGrade()) 
		{
			left = middle + 1;
		}

		else 
		{
			right = middle - 1;
		}
	}
}

bool SortedList::IsPresent(StudentGrade item) const
{
	bool found;
	int position;

	BinarySearch(item, found, position);
	return found;
}

void SortedList::ResetList()
{
	currentPos = 0;
}

bool SortedList::HasNext()
{
	return currentPos < length;
}

StudentGrade SortedList::GetNextItem()
{
	++currentPos;
	return data[currentPos - 1];
}
