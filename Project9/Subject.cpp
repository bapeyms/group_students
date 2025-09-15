#include <iostream>
#include "Group.h"
#include "Student.h"
#include "Subject.h"
using namespace std;

Subject::Subject() : subject(nullptr) {}
Subject::Subject(const char* subj)
{
	subject = new char[strlen(subj) + 1];
	strcpy_s(subject, strlen(subj) + 1, subj);
}

Subject::Subject(const Subject& subj) :subject(nullptr) 
{
	if (subj.subject)
	{
		subject = new char[strlen(subj.subject) + 1];
		strcpy_s(subject, strlen(subj.subject) + 1, subj.subject);
	}
}
Subject& Subject::operator=(const Subject& subj)
{
	if (this != &subj)
	{
		delete[] subject;
		subject = nullptr;
		if (subj.subject)
		{
			subject = new char[strlen(subj.subject) + 1];
			strcpy_s(subject, strlen(subj.subject) + 1, subj.subject);
		}
	}
	return *this;
}

char* Subject::GetSubject()
{
	return subject;
}
Subject::~Subject()
{
	delete[] subject;
}
