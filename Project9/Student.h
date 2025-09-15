#pragma once
class Student
{
	char* name;
public:
	Student();
	Student(const Student& stud);
	Student& operator=(const Student& stud);
	~Student();

	void EnterStudents();
	int StudentCheck();

	char* GetStudents();
};

