#pragma once
class Student
{
	char* name;
	int* grades;
public:
	Student();
	void EnterStudents();
	int StudentCheck();
	char* GetStudents();
	void EnterGrades();
	~Student();
};

