#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Class List
//...Student
class Student
{
private:
	string name;
	int studentID;
	char grade;
public:
	Student() { name = ""; studentID = 0; grade = '\0'; }
	Student(string n, int ID, char g) { name = n; studentID = ID; grade = g; }
	void setName(string nm) { name = nm; }
	string getName() { return name; }
	void setStudentID(int ID) { studentID = ID; }
	int getStudentID() { return studentID; }
	void setGrade(char g) { grade = g; }
	char getGrade() { return grade; }
	void displayStuInfo() { cout << name << " Student ID: " << studentID << " Grade: " << grade << endl; }
};

//...Grade 5
class Grade5
{
private:
	string teacherName;
	int stuCount;
	Student classList[25];
public:
	Grade5() { teacherName = ""; stuCount = 0; }
	Grade5(string name, int count, Student list[]) { teacherName = name; stuCount = count; for (int i = 0; i < stuCount; i++) { classList[i] = list[i]; } }
	void displayClass()
	{
		cout << "------------------------------------------------------" << endl;
		cout << "\nGrade 5 Class Information" << endl;
		cout << "Teacher: " << teacherName << endl;
		cout << "Class List\n" << endl;
		cout << "------------------------------------------------------" << endl;
		for (int x = 0; x < stuCount; x++) { classList[x].displayStuInfo(); }
	}
	void setTeacher(string name) { teacherName = name; }
	string getTeacher() { return teacherName; }
	void setCount(int count) { stuCount = count; }
	int getCount() { return  stuCount; }
	void setList(Student list[]) { for (int y = 0; y < stuCount; y++) { classList[y] = list[y]; } }
	Student * getList() { return &classList[0]; }
};

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


