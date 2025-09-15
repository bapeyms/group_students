#include <iostream>
#include "Group.h"
#include "Student.h"
using namespace std;

Group::Group(int numOfStuds, int numOfSubjs)
{
	countOfStudents = numOfStuds;
	countOfSubjects = numOfSubjs;

	studList = new Student[countOfStudents];
	sublist = new Subject[countOfSubjects];

	gradeList = new int* [countOfStudents];
	for (int i = 0; i < countOfStudents; i++)
	{
		gradeList[i] = new int[countOfSubjects];
		for (int j = 0; j < countOfSubjects; j++)
		{
			gradeList[i][j] = 0;
		}
	}
}
Group::~Group()
{
	delete[] groupName;
}

void Group::EnterGroupName()
{
	const int N = 256;
	char data[N];

	if (groupName != nullptr)
	{
		delete[] groupName;
	}
	cout << "Group name: ";
	cin.getline(data, N);
	groupName = new char[strlen(data) + 1];
	strcpy_s(groupName, strlen(data) + 1, data);
}
char* Group::GetGroupName()
{
	return groupName;
}

void Group::AddStudent(const char* studNames)
{
	
}

void Group::AddSubject(const char* name)
{

}

void Group::ShowAllInfo()
{
	//
}



