#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class ProSportsTeam
{
protected:
	string name;
	string homeTown;
	string uniformColors;
	double wins;
	double losses;
	double ties;
public:
	ProSportsTeam(string nm, string hTown, string uColors, double w, double l, double t) : name(nm), homeTown(hTown), uniformColors(uColors), wins(w), losses(l), ties(t) {}
	virtual double calcRecord() = 0;
	virtual void printInfo() = 0;
};

class Football : public ProSportsTeam
{
private:
	int touchdowns;
	int fieldGoals;
public:
	Football(string nm, string hTown, string uColors, double w, double l, double t, int tdowns, int fgoals) : ProSportsTeam(nm, hTown, uColors, w, l, t), touchdowns(tdowns), fieldGoals(fgoals) {}
	double calcRecord();
	void printInfo();
};

double Football::calcRecord()
{
	double calcRec;
	calcRec = (wins + (ties / 2)) / (wins + losses);
	return calcRec;
}

void Football::printInfo()
{
	cout << "       TEAM INFORMATION FOR " << homeTown << " " << name << endl;
	cout << "Uniform Colors: " << uniformColors << endl;
	cout << "----------------------------------------------" << endl;
	cout << "2016 Record: " << endl;
	cout << "WINS:              " << wins << endl;
	cout << "LOSSES:            " << losses << endl;
	cout << "TIES:              " << ties << endl;
	cout << "PERCENTAGE:        " << fixed << setprecision(2) << calcRecord() << endl;
	cout << "----------------------------------------------" << endl;
	cout << "SCORING HISTORY: " << endl;
	cout << "Touchdowns:        " << touchdowns << endl;
	cout << "Field Goals:       " << fieldGoals << endl;
}

int main()
{
	ProSportsTeam *ftPtr = new Football("Bears", "Chicago", "Blue and Orange", 125, 128, 3, 32, 18);
	ftPtr->printInfo();

	return 0;
}

