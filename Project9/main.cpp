#include <iostream>
#include "Subject.h"
#include "Student.h"
#include "Group.h"
using namespace std;

int main()
{
	cout << "- GROUP OF STUDENTS -" << endl << endl;
	Group app;
	app.EnterGroupName();
	cout << endl;

	int numberOfSubjs;
	cout << "Desired number of subjects: ";
	cin >> numberOfSubjs;
	cin.ignore(1000, '\n');
	while (numberOfSubjs <= 0)
	{
		cout << "Only possitive values are allowed! Number of subjects: ";
		cin >> numberOfSubjs;
		cin.ignore(1000, '\n');
	}

	Subject* allSubjs = new Subject[numberOfSubjs];
	int realnumberOfSubjs = 0;
	int choice1 = allSubjs[0].SubjectCheck();
	while (choice1 == 1 && realnumberOfSubjs < numberOfSubjs)
	{
		allSubjs[realnumberOfSubjs].EnterSubjects();
		realnumberOfSubjs++;
		choice1 = allSubjs[realnumberOfSubjs -1].SubjectCheck();
	}
	cout << "Input complete!" << endl << endl;
	numberOfSubjs = realnumberOfSubjs;
	cout << "- SUBJECTS -" << endl;
	cout << "Actual number of subjects: " << numberOfSubjs << endl;
	for (int i = 0; i < numberOfSubjs; i++)
	{
		cout << "Subject #" << i + 1 << allSubjs[i].GetSubjects() << endl;
	}
	cout << endl << endl;


	int numberOfStuds;
	cout << "Desired number of students: ";
	cin >> numberOfStuds;
	cin.ignore(1000, '\n');
	while (numberOfStuds <= 0)
	{
		cout << "Only possitive values are allowed! Number of subjects: ";
		cin >> numberOfStuds;
		cin.ignore(1000, '\n');
	}
	Student* allStuds = new Student[numberOfStuds];
	int realnumberOfStuds = 0;
	int choice2 = allStuds[0].StudentCheck();
	while (choice2 == 1 && realnumberOfStuds < numberOfStuds)
	{
		allStuds[realnumberOfStuds].EnterStudents();
		realnumberOfStuds++;
		choice2 = allStuds[realnumberOfStuds - 1].StudentCheck();
	}
	cout << "Input complete!" << endl << endl;
	numberOfStuds = realnumberOfStuds;
	cout << "- STUDENTS -" << endl;
	cout << "Actual number of students: " << numberOfStuds << endl;
	for (int i = 0; i < numberOfStuds; i++)
	{
		cout << "Student #" << i + 1 << allStuds[i].GetStudents();
	}
	cout << endl << endl;



	cout << "- GRADES -" << endl;
	for (int i = 0; i < numberOfStuds; i++)
	{
		cout << "Student #" << i + 1 << ": " << allStuds[i].GetStudents();
		cout << allSubjs[i].GetSubjects();
	}
}