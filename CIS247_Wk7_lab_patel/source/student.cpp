#include <iostream>
#include <iomanip>
#include <string>
#include "student.h"

using namespace std;

Student::Student()
{
	name = "";
	studentID = 0;
	grade = '\0';
}

Student::Student(string n, int ID, char g)
{
	name = n;
	studentID = ID;
	grade = g;
}

void Student::setName(string nm)
{
	name = nm;
}

string Student::getName()
{
	return name;
}

void Student::setStudentID(int ID)
{
	studentID = ID;
}

int Student::getStudentID()
{
	return studentID;
}

void Student::setGrade(char g)
{
	grade = g;
}

char Student::getGrade()
{
	return grade;
}

void Student::displayStuInfo()
{
	cout << name << " Student ID: " << studentID << " Grade: " << grade << endl;
}

