#pragma once
#include "Student.h"
#include "sorters/Compare.h"
bool compareIntegersAscending(int a, int b)
{
	if (a > b)
	{
		return true;
	}
	return false;
}

bool compareIntegersDescending(int a, int b)
{
	if (a <= b)
	{
		return true;
	}
	return false;
}

bool compareFloatAscending(float a, float b)
{
	if (a > b)
	{
		return true;
	}
	return false;
}

bool compareFloatDescending(float a, float b)
{
	if (a <= b)
	{
		return true;
	}
	return false;
}

bool compareStudentByAgeAscending(Student a, Student b)
{
	if (a.age > b.age)
	{
		return true;
	}
	return false;
}

bool compareStudentByAgeDescending(Student a, Student b)
{
	if (a.age <= b.age)
	{
		return true;
	}
	return false;
}

bool compareStudentByMeanMarkAscending(Student a, Student b)
{
	if (a.meanMark > b.meanMark)
	{
		return true;
	}
	return false;
}

bool compareStudentByMeanMarkDescending(Student a, Student b)
{
	if (a.meanMark <= b.meanMark)
	{
		return true;
	}
	return false;
}

bool compareStudentByGroupAscending(Student a, Student b)
{
	if (a.group > b.group)
	{
		return true;
	}
	return false;
}

bool compareStudentByGroupDescending(Student a, Student b)
{
	if (a.group <= b.group)
	{
		return true;
	}
	return false;
}