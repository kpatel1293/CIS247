//***************************************************************************************************************
//***************************************************************************************************************
//Program Name: Overloaded Methods and Static Methods / Variables
//Programmer: Krishna Patel
//Date: July 19, 2017
//Assignment: CIS247 Week 3 iLab
//***************************************************************************************************************
//***************************************************************************************************************

//Include Files
#include <iostream>
#include <string>
#include <iomanip>

//Using Namespace Std
using namespace std;

//Employee Class
class Employee
{
private:
	string firstName;						//...First Name
	string lastName;						//...Last Name
	int empID;								//...Employee ID
	char gender;							//...Gender
	int dependents;							//...Dependents
	double annualSalary;					//...Annual Salary
	static int numEmployees;                //...Number of Employees
public:
	Employee() { firstName = "not given", lastName = "not given", empID = 0, gender = 'U', dependents = 0, annualSalary = 20000; numEmployees = numEmployees + 1; }
	Employee(string first, string last, int ID, char gen, int dep, double sal) { firstName = first; lastName = last; empID = ID; gender = gen; dependents = dep; annualSalary = sal; numEmployees = numEmployees + 1; }

	//...Calculation for Weekly Pay
	double calcPay() { double weeklyPay; weeklyPay = annualSalary / 52; return weeklyPay; }

	//...Displays Employee Info
	void displayEmployee()
	{
		cout << "Name:  " << firstName << " " << lastName << endl;
		cout << "Employee ID:  " << empID << endl;
		cout << "Gender:  " << gender << endl;
		cout << "Dependents:  " << dependents << endl;
		cout << "Annual Salary:  $" << annualSalary << endl;
		cout << "Weekly Salary:  $" << calcPay() << endl;
	}

	//...Number of Employees
	static int getNumEmployees() { return numEmployees; }

	//...First Name
	string getFirstName() { return firstName; }									//...Getter
	void setFirstName(string first) { firstName = first; }					//...Setter

																			//...Last Name
	string getLastName() { return lastName; }									//...Getter
	void setLastName(string last) { lastName = last; }						//...Setter

																			//...Employee ID
	int getEmpID() { return empID; }											//...Getter
	void setEmpID(int ID) { empID = ID; }										//...Setter

	void setEmpID(string ID) { empID = atoi(ID.c_str()); }                    //...Overload

																			  //...Gender
	char getGender() { return gender; }											//...Getter
	void setGender(char gen) { gender = gen; }								//...Setter

	void setGender(string gen) { gender = gen[0]; }                           //...Overload

																			  //...Dependents
	int getDependents() { return dependents; }									//...Getter
	void setDependents(int dep) { dependents = dep; }							//...Setter

	void setDependents(string dep) { dependents = atoi(dep.c_str()); }        //...Overload

																			  //...Annual Salary
	double getAnnualSalary() { return annualSalary; }							//...Getter
	void setAnnualSalary(double sal) { annualSalary = sal; }					//...Setter

	void setAnnualSalary(string sal) { annualSalary = stod(sal.c_str()); }    //...Overload
};

int Employee::numEmployees = 0;

string GetInput(string item);
void DisplayDivider(string title);

//Main
int main()
{
	//Variable
	string fName;																//...First Name
	string lName;																//...Last Name
																				//int eID;																	//...Employee ID
																				//char gen;																	//...Gender
																				//int deps;																	//...Dependents
																				//double aSal;																//...Annual Salary

																				//Input Variables
	string strEmp;																//...Input for Employee ID
	string strGen;																//...Input for Gender
	string strDep;																//...Input for Dependents
	string strAnSal;															//...Input for Annual Salary

	cout << fixed << setprecision(2);											//...Rounds Number To 2 Decimal Points

	Employee NUM_ONE;															//...Employee Object called NUM_ONE

	DisplayDivider("Employee 1");												//...Employee One Divider

	fName = GetInput("first name");												//...User Input for First Name
	NUM_ONE.setFirstName(fName);

	lName = GetInput("last name");												//...User Input for Last Name
	NUM_ONE.setLastName(lName);

	strEmp = GetInput("employee's ID number");									//...User Input for Employee ID
	NUM_ONE.setEmpID(strEmp);


	strGen = GetInput("employee's gender as (M - Male & F - Female)");			//...User Input for Gender
	NUM_ONE.setGender(strGen);

	strDep = GetInput("number of dependents");									//...User Input for Dependents
	NUM_ONE.setDependents(strDep);

	strAnSal = GetInput("annual salary");										//...User Input for Annual Salary
	NUM_ONE.setAnnualSalary(strAnSal);

	//Employee Information
	DisplayDivider("Employee Information");
	cout << "-------------------------------------------------------------------------------------" << endl;
	NUM_ONE.displayEmployee();													//...Display Info for Employee 1
	cout << "Number of Employee(s):  " << NUM_ONE.getNumEmployees() << endl;

	Employee NUM_TWO("Mary", "Jones", 5689, 'F', 5, 24000.00);					//...Employee Object called NUM_TWO

	cout << "\n" << endl;														//...Empty Line

	DisplayDivider("Employee 2");												//...Employee Two

																				//Employee Information
	DisplayDivider("Employee Information");
	cout << "-------------------------------------------------------------------------------------" << endl;
	NUM_TWO.displayEmployee();													//...Display Info for Employee 2
	cout << "Number of Employee(s):  " << NUM_TWO.getNumEmployees() << endl;

	return 0;
}

string GetInput(string item)
{
	string strInput;
	cout << "Please enter the " << item << ": ";
	cin >> strInput;
	return strInput;
}

void DisplayDivider(string title)
{
	cout << "************************* " << title << " *************************" << endl;
}



