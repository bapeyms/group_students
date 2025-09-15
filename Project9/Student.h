#pragma once
class Student
{
	char* name;
	int numberOfStuds;
	int* grades;
	int numberOfGrades;
public:
	Student();
	Student(const Student& n);
	~Student();

	void EnterStudents();
	int StudentCheck();

	char* GetStudents();
	void EnterGrades();
	
};

