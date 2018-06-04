//***************************************************************************************************************
//***************************************************************************************************************
//Program Name: Inheritance
//Programmer: Krishna Patel
//Date: August 25, 2017
//Assignment: CIS247 Week 6 iLab
//***************************************************************************************************************
//***************************************************************************************************************

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Benefit
{
private:
	string healthInsurance;
	double lifeInsurance;
	int vacation;
public:
	Benefit() { healthInsurance = ""; lifeInsurance = 0.0; vacation = 0; }
	Benefit(string health, double life, int vacation) { healthInsurance = health; lifeInsurance = life; this->vacation = vacation; }
	void displayBenfits()
	{
		cout << "\nBenefit Information" << endl;
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << "Health Insurance:  " << fixed << setprecision(2) << healthInsurance << endl;
		cout << "Life Insurance:	" << fixed << setprecision(2) << lifeInsurance << endl;
		cout << "Vacation Time:		" << vacation << " days" << endl;
	}
	string getHealthInsurance() { return healthInsurance; }
	void setHealthInsurance(string hins) { healthInsurance = hins; }
	double getLifeInsurance() { return lifeInsurance; }
	void setLifeInsurance(double lifeins) { lifeInsurance = lifeins; }
	int getVacation() { return vacation; }
	void setVacation(int vac) { vacation = vac; }
};

class Employee
{
protected:
	string firstName;
	string lastName;
	int empID;
	char gender;
	int dependents;
	double annualSalary;
	Benefit benefit;
private:
	static int numEmployees;
public:
	Employee() { firstName = "not given", lastName = "not given", empID = 0, gender = 'U', dependents = 0, annualSalary = 20000; numEmployees = numEmployees + 1; Benefit(benefit); }
	Employee(string first, string last, int ID, char gen, int dep, double sal, Benefit bfit) { firstName = first; lastName = last; empID = ID; gender = gen; dependents = dep; annualSalary = sal; numEmployees = numEmployees + 1; benefit = bfit; }
	virtual double calcPay() = 0; /*{ double weeklyPay; weeklyPay = annualSalary / 52; return weeklyPay; }*/
	virtual void displayEmployee() = 0;
	/*{
	cout << "Name:              " << firstName << " " << lastName << endl;
	cout << "Employee ID:       " << empID << endl;
	cout << "Gender:            " << gender << endl;
	cout << "Dependents:        " << dependents << endl;
	cout << "Annual Salary:     $" << fixed << setprecision(2) << annualSalary << endl;
	cout << "Weekly Salary:     $" << fixed << setprecision(2) << calcPay() << endl;
	benefit.displayBenfits();
	}*/
	static int getNumEmployees() { return numEmployees; }
	string getFirstName() { return firstName; }
	void setFirstName(string first) { firstName = first; }
	string getLastName() { return lastName; }
	void setLastName(string last) { lastName = last; }
	int getEmpID() { return empID; }
	void setEmpID(int ID) { empID = ID; }
	void setEmpID(string ID) { empID = atoi(ID.c_str()); }
	char getGender() { return gender; }
	void setGender(char gen) { gender = gen; }
	void setGender(string gen) { gender = gen[0]; }
	int getDependents() { return dependents; }
	void setDependents(int dep) { dependents = dep; }
	void setDependents(string dep) { dependents = atoi(dep.c_str()); }
	double getAnnualSalary() { return annualSalary; }
	virtual void setAnnualSalary(double sal) { annualSalary = sal; }
	virtual void setAnnualSalary(string sal) { annualSalary = stod(sal.c_str()); }
	void setBenefit(Benefit bfit) { benefit = bfit; }
	Benefit getBenefit() { return Benefit(); }
};

int Employee::numEmployees = 0;

class Salaried : public Employee
{
protected:
	static const int MIN_MANAGEMENT_LEVEL = 0;
	static const int MAX_MANAGEMENT_LEVEL = 3;
	static const double BONUS_PERCENT;
	int managementLevel;
public:
	Salaried() { managementLevel = 0; }
	Salaried(string first, string last, int ID, char gen, int dep, double sal, Benefit bfit, int manLevel) {
		firstName = first; lastName = last; empID = ID; gender = gen; dependents = dep; annualSalary = sal; benefit = bfit; managementLevel = manLevel;
		if (manLevel <= 0)
			manLevel = MIN_MANAGEMENT_LEVEL;
		if (manLevel >= 3)
			manLevel = MAX_MANAGEMENT_LEVEL;
	}
	Salaried(double sal, int manLevel) {
		annualSalary = sal; managementLevel = manLevel;
		if (manLevel <= 0)
			manLevel = MIN_MANAGEMENT_LEVEL;
		if (manLevel >= 3)
			manLevel = MAX_MANAGEMENT_LEVEL;
	}
	double calcPay() { double weeklyPay; weeklyPay = annualSalary / 52; weeklyPay = weeklyPay + (weeklyPay * managementLevel * BONUS_PERCENT); return weeklyPay; }
	int getManagementLevel() { return managementLevel; }
	void setManagementLevel(int manLevel) {
		managementLevel = manLevel;
		if (manLevel <= 0)
			manLevel = MIN_MANAGEMENT_LEVEL;
		if (manLevel >= 3)
			manLevel = MAX_MANAGEMENT_LEVEL;
	}
	void setManagementLevel(string manLevel) {
		managementLevel = atoi(manLevel.c_str());
		if (atoi(manLevel.c_str()) <= 0)
			managementLevel = MIN_MANAGEMENT_LEVEL;
		if (atoi(manLevel.c_str()) >= 3)
			manLevel = MAX_MANAGEMENT_LEVEL;
	}
	void displayEmployee()
	{
		cout << "Name:              " << firstName << " " << lastName << endl;
		cout << "Employee ID:       " << empID << endl;
		cout << "Gender:            " << gender << endl;
		cout << "Dependents:        " << dependents << endl;
		cout << "Mgmt Level:        " << managementLevel << endl;
		cout << "Annual Salary:     $" << fixed << setprecision(2) << annualSalary << endl;
		cout << "Weekly Salary:     $" << fixed << setprecision(2) << calcPay() << endl;
		benefit.displayBenfits();
	}
};

const double Salaried::BONUS_PERCENT = 0.10;

class Hourly : public Employee
{
private:
	static const double MIN_WAGE;
	static const double MAX_WAGE;
	static const double MIN_HOURS;
	static const double MAX_HOURS;
	double wage;
	double hours;
	string category;
public:
	Hourly() {}
	Hourly(double wage, double hours, string category) {
		this->wage = wage;
		if (wage <= 10)
			wage = MIN_WAGE;
		if (wage >= 75)
			wage = MAX_WAGE;
		this->hours = hours;
		if (hours <= 0)
			hours = MIN_HOURS;
		if (hours >= 50)
			hours = MAX_HOURS;
		this->category = category;
		if (category == "full time")
			this->category = category;
		if (category == "part time")
			this->category = category;
		else
			category = "temporary";
	}
	Hourly(string first, string last, int ID, char gen, int dep, Benefit bfit, double wage, double hours, string category) {
		firstName = first; lastName = last; empID = ID; gender = gen; dependents = dep; benefit = bfit; this->wage = wage;
		if (wage <= 10)
			wage = MIN_WAGE;
		if (wage >= 75)
			wage = MAX_WAGE;
		this->hours = hours;
		if (hours <= 0)
			hours = MIN_HOURS;
		if (hours >= 50)
			hours = MAX_HOURS;
		this->category = category; annualSalary = wage * hours * 50;
	}
	double calcPay() { double weekly; weekly = wage * hours; return weekly; }
	double getAnnualSalary() { return annualSalary; }
	void setAnnualSalary(double sal) { annualSalary = sal; sal = (sal / 52) * 50; }
	double getWage() { return wage; }
	void setWage(double wage) { this->wage = wage; if (wage <= 10) { wage = MIN_WAGE; } if (wage >= 75) { wage = MAX_WAGE; } }
	void setWage(string wage) { this->wage = atof(wage.c_str()); }
	double getHours() { return hours; }
	void setHours(double hours) { this->hours = hours; if (hours <= 0) { hours = MIN_HOURS; } if (hours >= 50) { hours = MAX_HOURS; } }
	void setHours(string hours) { this->hours = atof(hours.c_str()); }
	void setCategory(string category) { this->category = category; }
	string getCategory() { return category; }
	void displayEmployee()
	{
		cout << "Name:              " << firstName << " " << lastName << endl;
		cout << "Employee ID:       " << empID << endl;
		cout << "Gender:            " << gender << endl;
		cout << "Dependents:        " << dependents << endl;
		if (wage <= 10)
		{
			wage = MIN_WAGE;
		}
		if (wage >= 75)
		{
			wage = MAX_WAGE;
		}
		cout << "Hourly Wage:       " << fixed << setprecision(2) << wage << endl;
		if (hours <= 0)
		{
			hours = MIN_HOURS;
		}
		if (hours >= 50)
		{
			hours = MAX_HOURS;
		}
		cout << "Hours:             " << hours << endl;
		cout << "Category:          " << category << endl;
		cout << "Annual Salary:     " << fixed << setprecision(2) << hours * wage * 50 << endl;
		cout << "Weekly Salary:     " << fixed << setprecision(2) << calcPay() << endl;
		benefit.displayBenfits();
	}
};

const double Hourly::MIN_WAGE = 10;
const double Hourly::MAX_WAGE = 75;
const double Hourly::MIN_HOURS = 0;
const double Hourly::MAX_HOURS = 50;

string GetInput(string item);
void DisplayDivider(string title);
string GetInputTwo(string item);

int main()
{
	Benefit bfit;
	Benefit bfit2;

	Employee *emptr1 = new Salaried(1000, 3);

	DisplayDivider("Salaried");

	cout << "Prepare to enter data for salaried employee" << endl;

	emptr1->setFirstName(GetInput("First Name"));
	emptr1->setLastName(GetInput("Last Name"));
	emptr1->setEmpID(GetInput("Employee ID"));
	emptr1->setGender(GetInput("Gender (M or F)"));
	emptr1->setDependents(GetInput("Number of Dependents"));
	bfit.setHealthInsurance(GetInput("Health Insurance Company"));
	bfit.setLifeInsurance(atof(GetInput("Life Insurance Amount").c_str()));
	bfit.setVacation(atoi(GetInput("Number of Vacation Days").c_str()));
	emptr1->setBenefit(bfit);


	DisplayDivider("Employee Information");
	cout << "-------------------------------------------------------------------------------------" << endl;
	emptr1->displayEmployee();

	cout << "Number of Employee(s): " << emptr1->getNumEmployees() << endl;

	Employee *emptr2 = new Hourly(50, 40, "Full Time");

	DisplayDivider("Hourly");

	cout << "Prepare to enter data for hourly employee" << endl;

	emptr2->setFirstName(GetInput("First Name"));
	emptr2->setLastName(GetInput("Last Name"));
	emptr2->setEmpID(GetInput("Employee ID"));
	emptr2->setGender(GetInput("Gender (M or F)"));
	emptr2->setDependents(GetInput("Number of Dependents"));
	bfit2.setHealthInsurance(GetInput("Health Insurance Company"));
	bfit2.setLifeInsurance(atof(GetInput("Life Insurance Amount").c_str()));
	bfit2.setVacation(atoi(GetInput("Number of Vacation Days").c_str()));
	emptr2->setBenefit(bfit2);

	DisplayDivider("Employee Information");
	cout << "-------------------------------------------------------------------------------------" << endl;
	emptr2->displayEmployee();

	cout << "\nNumber of Employee(s):     " << emptr2->getNumEmployees() << endl;

	/* DisplayDivider("Employee 1");

	Benefit bfit("Aetna", 100000, 15);
	Employee emp("Krishna", "Patel", 3579, 'F', 2, 45000, bfit);
	DisplayDivider("Employee Information");
	cout << "-------------------------------------------------------------------------------------" << endl;
	emp.displayEmployee();

	cout << "\nNumber of Employee(s):  " << emp.getNumEmployees() << endl;

	DisplayDivider("Employee 2");

	Benefit bfitTWO("Prudential", 200000, 10);
	Salaried salOne("Brad", "Pitt", 4393, 'M', 6, 500000, bfitTWO, 3);
	DisplayDivider("Employee Information");
	cout << "-------------------------------------------------------------------------------------" << endl;
	salOne.displayEmployee();

	cout << "\nNumber of Employee(s):  " << salOne.getNumEmployees() << endl;

	Benefit bfitTHREE("Hancock", 344000, 15);
	Hourly hour("Joe", "Smith", 9223, 'M', 3, bfitTHREE, 25, 40, "full");
	DisplayDivider("Employee Information");
	cout << "-------------------------------------------------------------------------------------" << endl;
	hour.displayEmployee();

	cout << "\nNumber of Employee(s):  " << hour.getNumEmployees() << endl; */

	return 0;
}

string GetInputTwo(string item)
{
	string strInput;
	cout << "Please enter your " << item << ": ";
	cin >> strInput;
	return strInput;
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
	cout << "\n************************* " << title << " *************************" << endl;
}

