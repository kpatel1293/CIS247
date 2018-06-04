class Student
{
private:
	std::string name;
	int studentID;
	char grade;
public:
	Student();
	Student(std::string n, int ID, char g);
	void setName(std::string nm);
	std::string getName();
	void setStudentID(int ID);
	int getStudentID();
	void setGrade(char g);
	char getGrade();
	void displayStuInfo();
};


