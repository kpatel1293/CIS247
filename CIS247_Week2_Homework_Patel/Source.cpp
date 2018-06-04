//****************************************************************************************
//****************************************************************************************
//Program Name: Paint Calculator
//Programmer: Krishna Patel
//Date: July 14, 2017
//Assignment: CIS247 Week 2 Exercise
//****************************************************************************************
//****************************************************************************************

//Include Files
#include <iostream>
#include <string>
#include <iomanip>

//Namespace STD
using namespace std;

//Class - Paint Calculator
class PaintCalculator
{
private:
	double squareFootage;				//...Square Footage
	int numDoors;						//...Number of Doors
	int numWindows;						//...Number of Windows
public:
	PaintCalculator() { squareFootage = 0; numDoors = 0; numWindows = 0; }
	PaintCalculator( double area, int doors, int windows ) { squareFootage = area; numDoors = doors; numWindows = windows; }
	
	//Area
	void setArea( double area ) { squareFootage = area; }				//...Setter
	double getArea() { return squareFootage; }							//...Getter
	
	//Doors
	void setDoors( int doors ) { numDoors = doors; }					//...Setter
	int getDoors() { return numDoors; }									//...Getter
	
	//Windows
	void setWindows( int window ) { numWindows = window; }				//...Setter
	int getWindows() { return numWindows; }								//...Getter
	
	//Calculate Gallons - Formula
	double calculateGallons() { return ((squareFootage - (numDoors * 20) - (numWindows * 15)) / 400); }
};

//Main
int main()
{
	//Variables
	double calcGal = 0.0;											//...Calculation for Gallons
	double sqFt = 0.0;												//...Square Footage
	int doors = 0;													//...Doors
	int windows = 0;												//...Windows

	cout << fixed << setprecision(1);								//...Rounds Number to 1 Decimal Points

	PaintCalculator HOUSE_ONE;										//...Class object for Paint Calculator

	cout << "Welcome to the Paint Calculator Program!" << endl;		//...Welcome Message
	cout << "Please enter the following: " << endl;

	//Input - Total Square Footage
	cout << "Enter the total square footage of your walls: ";		
	cin >> sqFt;
	HOUSE_ONE.setArea(sqFt);

	//Input - Number of Doors
	cout << "Enter the number of doors: ";
	cin >> doors;
	HOUSE_ONE.setDoors(doors);

	//Input - Number of Windows
	cout << "Enter the number of windows: ";
	cin >> windows;
	HOUSE_ONE.setWindows(windows);

	calcGal = HOUSE_ONE.calculateGallons();

	//Display Number of Gallons Needed
	cout << "The number of gallons calculated is " << calcGal << endl;

	cout << "Thank you for using the Paint Calculator Program!" << endl;
	
	return 0;
}