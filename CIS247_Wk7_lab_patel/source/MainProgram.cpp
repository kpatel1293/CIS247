#include <iostream>
#include <iomanip>
#include <string>
#include "student.h"
#include "grade5.h"

using namespace std;

int main()
{
	Student classSize[25];
	Grade5 grade5;

	cout << "Welcome to the Grade 5 Information Program" << endl;
	cout << "Prepare to enter your class roster with current grades" << endl;

	string techName;
	int sCount;

	cout << "Enter your full name: ";
	cin >> techName;
	grade5.setTeacher(techName);

	cout << "Enter the number of students in the class: ";
	cin >> sCount;
	grade5.setCount(sCount);

	string fullName;
	int Id;
	char grade;

	for (int k = 0; k < sCount; k++)
	{
		cout << "Enter student full name: ";
		cin >> fullName;
		classSize[k].setName(fullName);

		cout << "Enter student ID " << fullName << ": ";
		cin >> Id;
		classSize[k].setStudentID(Id);

		cout << "Enter current grade of " << fullName << ": ";
		cin >> grade;
		classSize[k].setGrade(grade);
	}

	grade5.setList(classSize);

	grade5.displayClass();

	return 0;
}


