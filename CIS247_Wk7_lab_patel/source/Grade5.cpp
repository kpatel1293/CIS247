#include <iostream>
#include <iomanip>
#include <string>
#include "student.h"
#include "grade5.h"

using namespace std;

Grade5::Grade5()
{
	teacherName = "";
	stuCount = 0;
}

Grade5::Grade5(string name, int count, Student list[])
{
	teacherName = name;
	stuCount = count;
	for (int i = 0; i < stuCount; i++)
	{
		classList[i] = list[i];
	}
}

void Grade5::displayClass()
{
	cout << "------------------------------------------------------" << endl;
	cout << "\nGrade 5 Class Information" << endl;
	cout << "Teacher: " << teacherName << endl;
	cout << "Class List\n" << endl;
	cout << "------------------------------------------------------" << endl;
	for (int x = 0; x < stuCount; x++)
	{
		classList[x].displayStuInfo();
	}
}

void Grade5::setTeacher(string name)
{
	teacherName = name;
}

string Grade5::getTeacher()
{
	return teacherName;
}

void Grade5::setCount(int count)
{
	stuCount = count;
}
int Grade5::getCount()
{
	return  stuCount;
}
void Grade5::setList(Student list[])
{
	for (int y = 0; y < stuCount; y++)
	{
		classList[y] = list[y];
	}
}

Student *Grade5::getList()
{
	return &classList[0];
}




