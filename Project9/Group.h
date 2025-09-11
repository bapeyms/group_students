#pragma once
#include "Student.h"
#include "Subject.h"

class Group
{
	char* groupName;
	/*Student* list;
	int countOfStudents;
	Subject* sublist;
	int countOfSubjects;*/
public:
	Group();
	void EnterGroupName();
	char* GetGroupName();
	void ShowAllInfo();
	~Group();
	
};

