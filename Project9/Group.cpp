#include <iostream>
#include "Group.h"
#include "Student.h"
#include "Subject.h"
using namespace std;

Group::Group() :groupName(nullptr), gradeList(nullptr), 
studList(nullptr), countOfStudents(0), subList(nullptr), countOfSubjects(0) {}
Group::Group(const char* g, int numOfStuds, int numOfSubjs)
{
	groupName = new char[strlen(g) + 1];
	strcpy_s(groupName, strlen(g) + 1, g);
	countOfStudents = numOfStuds;
	countOfSubjects = numOfSubjs;

	studList = new Student[countOfStudents];
	subList = new Subject[countOfSubjects];

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
	delete[] studList;
	delete[] subList;
	if (gradeList != nullptr)
	{
		for (int i = 0; i < countOfStudents; i++)
		{
			delete[] gradeList[i];
		}
		delete[] gradeList;
	}
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

void Group::EnterGrades() {
	if (countOfStudents == 0 || countOfSubjects == 0)
	{
		cout << "Information for entering grades is missing!" << endl;
		return;
	}
	gradeList = new int* [countOfStudents];
	for (int i = 0; i < countOfStudents; i++)
	{
		gradeList[i] = new int[countOfSubjects];
	}
	for (int i = 0; i < countOfStudents; i++)
	{
		cout << "Grades for " << studList[i].GetStudents() << ":\n";
		for (int j = 0; j < countOfSubjects; j++)
		{
			cout << "  " << subList[j].GetSubject() << ": ";
			cin >> gradeList[i][j];
		}
	}
	cin.ignore(1000, '\n');
}
void Group::PrintGrades()
{
	for (int i = 0; i < countOfStudents; i++)
	{
		cout << "Student #" << 1+i << ": " << studList[i].GetStudents() << "\n";
		for (int j = 0; j < countOfSubjects; j++)
		{
			cout << "  " << subList[j].GetSubject() << " " << gradeList[i][j] << "\n";
		}
		cout << "\n"; 
	}
}

void Group::SetSubj(Subject* subs, int numb1)
{
	if (subList != nullptr) {
		delete[] subList;
	}
	countOfSubjects = numb1;
	subList = new Subject[countOfSubjects];
	for (int i = 0; i < countOfSubjects; i++) {
		subList[i] = subs[i];
	}
}
void Group::SetStud(Student* studs, int numb2)
{
	if (studList != nullptr)
	{
		delete[] studList;
	}
	countOfStudents = numb2;
	studList = new Student[countOfStudents];
	for (int i = 0; i < countOfStudents; i++) {
		studList[i] = studs[i];
	}
}



