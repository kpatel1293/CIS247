//***************************************************************************************************************
//***************************************************************************************************************
//Program Name: Excercise 3
//Programmer: Krishna Patel
//Date: July 19, 2017
//Assignment: CIS247 Week 3 Excercise
//***************************************************************************************************************
//***************************************************************************************************************

//Include Files
#include <iostream>
#include <string>

//Namespace
using namespace std;

//Class: Arithmetic
class Arithmetic
{
	//Private
private:
	double num1;                                                                        //number 1
	double num2;                                                                        //number 2
																						//Public
public:
	Arithmetic() { num1 = 0.0; num2 = 0.0; }                                            //defualt constructors should zero both attributes
	Arithmetic(double nOne, double nTwo) { num1 = nOne; num2 = nTwo; }                  //initialize both attributes with arguments
	void setNumbers(double nOne, double nTwo) { num1 = nOne; num2 = nTwo; }
	double add() { double addNum; addNum = num1 + num2; return addNum; }                //add num1 & num2
	double subtract() { double subNum; subNum = num2 - num1; return subNum; }           //subtract num2 from num1
	double multiply() { double multNum; multNum = num1 * num2; return multNum; }
	double divide() { double divNum; divNum = num2 / num1; return divNum; }             //divide num1 by num2
	double getLarger() { if (num1 >= num2) { return num1; } else { return num2; } }     //return largest of the two attributes; return either number if equal
	double getSmaller() { if (num1 <= num2) { return num1; } else { return num2; } }    //return the smaller of the two attributes; return either number if equal
};

//Main
int main()
{
	//Variables
	double numOne = 0.0;
	double numTwo = 0.0;

	//Welcome Message
	cout << "Welcome to Arithmetic!" << endl;

	//Object: ARTH_ONE
	Arithmetic ARTH_ONE;

	//Input Two Numbers
	cout << "Enter two numbers of your choice: " << endl;
	cout << "   1: ";
	cin >> numOne;
	cout << "   2: ";
	cin >> numTwo;
	ARTH_ONE.setNumbers(numOne, numTwo);

	cout << "***********************************************************" << endl;

	//Display Results
	cout << "Results 1: " << endl;
	cout << "   Addition: " << ARTH_ONE.add() << endl;
	cout << "   Multiplied: " << ARTH_ONE.multiply() << endl;
	cout << "   Largest number: " << ARTH_ONE.getLarger() << endl;

	//Object: ARTH_TWO
	Arithmetic ARTH_TWO(10, 34);

	cout << "***********************************************************" << endl;

	//Display Results
	cout << "Results 2: " << endl;
	cout << "   Substraction: " << ARTH_TWO.subtract() << endl;
	cout << "   Divided: " << ARTH_TWO.divide() << endl;
	cout << "   Smallest Number: " << ARTH_TWO.getSmaller() << endl;

	//End Message
	cout << "Goodbye!\n";

	return 0; //return expression
}