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

	const int numberOfSubjs = 4;
	Subject allSubjs[numberOfSubjs] = {
		Subject("Programmimg"),
		Subject("Probability Theory and Mathematical Statistics"),
		Subject("Business English"),
		Subject("Operating Systems")
	};

	cout << "- SUBJECTS -" << endl;
	cout << "Number of subjects: " << numberOfSubjs << endl;
	for (int i = 0; i < numberOfSubjs; i++)
	{
		cout << "Subject #" << i + 1 << ": " << allSubjs[i].GetSubject() << endl;
	}
	cout << endl;

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
	app.SetStud(allStuds, numberOfStuds);
	app.SetSubj(allSubjs, numberOfSubjs);
	app.EnterGrades();

	cout << "- GRADES TABLE -" << endl;
	app.PrintGrades();
	delete[] allStuds;
}