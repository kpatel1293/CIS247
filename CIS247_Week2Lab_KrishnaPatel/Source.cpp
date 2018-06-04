//***************************************************************************************************************
//***************************************************************************************************************
//Program Name: Employee Class
//Programmer: Krishna Patel
//Date: July 15, 2017
//Assignment: CIS247 Week 1 iLab
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
public:
	Employee() { firstName = "not given", lastName = "not given", empID = 0, gender = 'U', dependents = 0, annualSalary = 20000; }
	Employee( string first, string last, int ID, char gen, int dep, double sal ) { firstName = first; lastName = last; empID = ID; gender = gen; dependents = dep; annualSalary = sal; }

	//...Calculation for Weekly Pay
	double calcPay() { double weeklyPay; weeklyPay = annualSalary / 52; return weeklyPay; }

	//...Displays Employee Info
	void displayEmployee()
	{
		cout << "Name:				" << firstName << " " << lastName << endl;
		cout << "Employee ID:		" << empID << endl;
		cout << "Gender:			" << gender << endl;
		cout << "Dependents:		" << dependents << endl;
		cout << "Annual Salary:		$" << annualSalary << endl;
		cout << "Weekly Salary:		$" << calcPay() << endl;
 	}

	//...First Name
	string getFirstName() { return firstName; }									//...Getter
	void setFirstName( string first ) { firstName = first; }					//...Setter

	//...Last Name
	string getLastName() { return lastName; }									//...Getter
	void setLastName( string last ) { lastName = last; }						//...Setter

	//...Employee ID
	int getEmpID() { return empID; }											//...Getter
	void setEmpID( int ID ) { empID = ID; }										//...Setter
	
	//...Gender
	char getGender() { return gender; }											//...Getter
	void setGender( char gen ) { gender = gen; }								//...Setter

	//...Dependents	
	int getDependents() { return dependents; }									//...Getter
	void setDependents( int dep ) { dependents = dep; }							//...Setter

	//...Annual Salary
	double getAnnualSalary() { return annualSalary; }							//...Getter
	void setAnnualSalary( double sal ) { annualSalary = sal; }					//...Setter
};

string GetInput( string item );
void DisplayDivider( string title );

//Main
int main()
{
	//Variable
	string fName;																//...First Name
	string lName;																//...Last Name
	int eID;																	//...Employee ID
	char gen;																	//...Gender
	int deps;																	//...Dependents
	double aSal;																//...Annual Salary

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
	eID = atoi(strEmp.c_str());													//...Converts input (strEmp) to integer
	NUM_ONE.setEmpID(eID);

	strGen = GetInput("employee's gender as (M - Male & F - Female)");			//...User Input for Gender
	gen = strGen[0];															//...Converts input (strGen) to char
	NUM_ONE.setGender(gen);

	strDep = GetInput("number of dependents");									//...User Input for Dependents
	deps = atoi(strDep.c_str());												//...Converts input (strDep) to integer
	NUM_ONE.setDependents(deps);

	strAnSal = GetInput("annual salary");										//...User Input for Annual Salary
	aSal = atof(strAnSal.c_str());												//...Converts input (strAnSal) to double
	NUM_ONE.setAnnualSalary(aSal);

	//Employee Information
	DisplayDivider("Employee Information");
	cout << "-------------------------------------------------------------------------------------" << endl;
	NUM_ONE.displayEmployee();													//...Display Info for Employee 1

	Employee NUM_TWO;															//...Employee Object called NUM_TWO

	cout << "\n" << endl;														//...Empty Line

	DisplayDivider("Employee 2");												//...Employee Two

	//Defualt Values
	NUM_TWO.setFirstName("Emma");												//...Set Defualt First Name
	NUM_TWO.setLastName("Stone");												//...Set Defualt Last Name
	NUM_TWO.setEmpID(32423);													//...Set Defualt Employee ID
	NUM_TWO.setGender('F');														//...Set Defualt Gender
	NUM_TWO.setDependents(1);													//...Set Defualt Dependents
	NUM_TWO.setAnnualSalary(20333.32);											//...Set Defualt Annual Salary

	//Employee Information
	DisplayDivider("Employee Information");
	cout << "-------------------------------------------------------------------------------------" << endl;
	NUM_TWO.displayEmployee();													//...Display Info for Employee 2

	return 0;
}

string GetInput( string item )
{
	string strInput;
	cout << "Please enter the " << item << ": ";
	cin >> strInput;
	return strInput;
}

void DisplayDivider( string title )
{
	cout << "************************* " << title << " *************************" << endl;
}