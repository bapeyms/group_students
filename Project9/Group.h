#pragma once
#include "Student.h"
#include "Subject.h"

class Group
{
	char* groupName;
	int** gradeList;
	Student* studList;
	int countOfStudents;
	Subject* sublist;
	int countOfSubjects;
public:
	Group(int numOfStuds, int numOfSubjs);
	~Group();

	void EnterGroupName();
	char* GetGroupName();

	void AddStudent(const char* studNames);

	void AddSubject(const char* name);
	void ShowAllInfo();
	
	
};

