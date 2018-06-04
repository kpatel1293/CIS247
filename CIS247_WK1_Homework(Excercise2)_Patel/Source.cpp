//Program Name: Practice with Functions and Parameters
//Programmer: Krishna Patel
//Date: July 9, 2017
//Assignment: CIS247 Week 1 Excercise (Question #2)
#include <iostream>
#include <string>

using namespace std;

void getName(string first, string middle, string last)
{
	cout << "Please enter the full name of customer: " << endl;
	cout << "First Name: ";
	cin >> first;
	cout << "Middle Name: ";
	cin >> middle;
	cout << "Last Name: ";
	cin >> last;
}

bool checkNew(char letter)
{
	cout << "Are you a new customer or returning customer? Enter (N) for new or (R) for returning: ";
	cin >> letter;

	while (letter != 'N' && letter != 'R')
	{
		cout << "ALRET: Invalid input!" << endl;
		cout << "Enter (N) for new or (R) for returning: " << endl;
		cin >> letter;
		letter = toupper(letter);
	}

	if (letter == 'N' || letter == 'n')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void displayInfo(string first, string middle, string last)
{
	cout << first + middle + last << endl;
}

int main()
{
	string first, middle, last;
	char letter = '\0';

	getName(first, middle, last);

	checkNew(letter);
	if (letter == true) {
		cout << "Welcome, " << first << "!";
	}
	else if (letter == false)
	{
		cout << "Welcome back, " << first << "!";
	}

	displayInfo(first, middle, last);

	return 0;
}


