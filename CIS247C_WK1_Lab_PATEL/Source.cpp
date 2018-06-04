//************************************** INFO **************************************************
//****************************************************************************************
//Program Name: Basic User Interface
//Programmer: Krishna Patel
//Date: July 2nd, 2017
//Assignment: CIS247 Week 1 iLab
//Program Description: 
//****************************************************************************************
//****************************************************************************************

//***Include Files***
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void DisplayAppInfo();
void DisplayDivider(string title);
string GetInput(string item);
void TerminationMsg();

void main() //Start main
{
	//...declare variables
	string input; //...input as string
	string name; //...name as string
	string integer; //...age as integer
	double GPA = 0.0; //...GPA as double

	int age;

	DisplayAppInfo();//...call DisplayAppInfo

	DisplayDivider("Start Program"); //...call DisplayDivider("Start Program")

	DisplayDivider("Get Name"); //...call DisplayDivider("Get Name")
	name = GetInput("Your Name"); //...set name = GetInput("Your Name")
	cout << "Your name is: " << name << endl; //...display "Your name is: " + name

	DisplayDivider("Get Age"); //...call DisplayDivider("Get Age")
	input = GetInput("Your Age"); //...set input = GetInput(“Your Age”)
	age = atoi(input.c_str()); //...set age = convert input to integer
	cout << "Your age is: " << age << endl; //...display “Your age is: “ + age

	DisplayDivider("Get GPA"); //...call DisplayDivider(“Get GPA”)
	input = GetInput("Your Grade Point Average"); //...set input = GetInput(“Your Grade Point Average”)
	GPA = atof(input.c_str()); //...set GPA = convert input to double

	setprecision(2); //display GPA to 2 decimal places
	cout << "Your GPA is: " << GPA << endl; //...display “Your GPA is: “ + GPA

	TerminationMsg(); //...call TerminationMsg
	
	system("pause");
} //End main program

void DisplayAppInfo() //procedure DisplayAppInfo
{
	cout << "Welcome to the Basic User Interface Program" << endl; //...display “Welcome to the Basic User Interface Program”
	cout << "CIS247 Week 1 Lab" << endl; //...display “CIS247 Week 1 Lab”
	cout << "Name: Krishna Patel" << endl; //...display “Name: YOUR OWN NAME”
	cout << "This program accepts user input as a string and makes the appropriate data conversion" << endl; //...display “This program accepts user input as a string and makes the appropriate data conversion”
} //end procedure

void DisplayDivider(string title) //procedure DisplayDivider(string title)
{
	cout << "**************** " << title << " ****************" << endl; //...display “**************** “ + title + “****************”
} //end procedure

string GetInput(string item) //function GetInput(string item) as string
{
	string strInput; //...strInput as string
	cout << "Please enter " << item << endl; //...display “Please enter “ +  item
	cin >> strInput; //...get strInput
	return strInput; //...return strInput
} //end function

void TerminationMsg() //procedure TerminationMsg
{
	cout << "Thank you for using the Basic User Interface program" << endl; //...display “Thank you for using the Basic User Interface program”
} //end procedure
