#pragma once
#include "Student.h"
#include "Subject.h"

class Group
{
	char* groupName;

	int** gradeList;

	Student* studList;
	int countOfStudents;

	Subject* subList;
	int countOfSubjects;
public:
	Group();
	Group(const char* g, int numOfStuds, int numOfSubjs);
	~Group();

	void EnterGroupName();
	char* GetGroupName();
	void EnterGrades();
	void PrintGrades();

	void SetSubj(Subject* subs, int numb1);
	void SetStud(Student* studs, int numb2);
};

