#ifndef STUDENT_H
#define STUDENT_H


class Grade5
{
private:
	std::string teacherName;
	int stuCount;
	Student classList[25];
public:
	Grade5();
	Grade5(std::string name, int count, Student list[]);
	void displayClass();
	void setTeacher(std::string name);
	std::string getTeacher();
	void setCount(int count);
	int getCount();
	void setList(Student list[]);
	Student* getList();
};

#endif
