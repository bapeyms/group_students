#pragma once
class Subject
{
	char* subject;
public:
	Subject();
	Subject(const char* subj);
	Subject(const Subject& subj);
	Subject& operator=(const Subject& subj);
	char* GetSubject();
	~Subject();
};