//Program Name: Magic Eight-Ball Program
//Programmer: Krishna Patel
//Date: July 9, 2017
//Assignment: CIS247 Week 1 Excercise (Question #1)
//Program Description: 

#include <iostream>
#include <string>

using namespace std;

int main()
{
	//Variables
	int num = 0;
	char letter = '\0';
	string question;

	cout << "Welcome to Magic Eight Ball!" << endl;

	while (letter != 'q' || letter != 'Q')
	{
		cout << "Would you like to ask a question about your future? \nEnter [Y]es or [N]o: " << endl;
		cin >> letter;

		letter = toupper(letter);

		while (letter != 'Y' && letter != 'N' && letter != 'Q')
		{
			cout << "ALRET: Invalid input!" << endl;
			cout << "Enter [Y]es or [N]o: " << endl;
			cin >> letter;
			letter = toupper(letter);
		}

		if (letter == 'Y')
		{
			cout << "Enter your question: ";
			cin >> question;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "\nPlease choose a number between 1 through 8: ";
			cin >> num;

			while (!(num >= 1 && num <= 9))
			{
				cout << "ALRET: Invalid input!" << endl;
				cout << "Please choose a number between 1 through 8: ";
				cin >> num;
			}

			switch (num)
			{
			case 1:
				cout << "It is certain." << endl;
				break;
			case 2:
				cout << "Don't count on it." << endl;
				break;
			case 3:
				cout << "Without a doubt." << endl;
				break;
			case 4:
				cout << "Outlook good." << endl;
				break;
			case 5:
				cout << "My sources say no." << endl;
				break;
			case 6:
				cout << "Signs point to yes." << endl;
				break;
			case 7:
				cout << "My reply is no." << endl;
				break;
			case 8:
				cout << "You may rely on it." << endl;
				break;
			}
		}
		else if (letter == 'N')
		{
			cout << "Are you sure you dont want you play? If you want to quit, enter Q." << endl;
		}
		else if (letter == 'Q')
		{
			break;
		}
	}

	cout << "Thank You for Playing Magic Eight Ball!" << endl;

	return 0;
}
