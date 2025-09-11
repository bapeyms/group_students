#pragma once
class Subject
{
	char* subject;
public:
	Subject();
	void EnterSubjects();
	int SubjectCheck();
	char* GetSubjects();
	~Subject();
};