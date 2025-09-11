#include <iostream>
#include "Subject.h"
#include "Student.h"
using namespace std;

int main()
{
	cout << "- GROUP OF STUDENTS -" << endl << endl;

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
	int realnumberOfSubjs = 1;
	int choice1 = allSubjs->SubjectCheck();
	while (choice1 == 1 && realnumberOfSubjs < numberOfSubjs)
	{
		allSubjs->EnterSubjects(realnumberOfSubjs);
		realnumberOfSubjs++;
		choice1 = allSubjs->SubjectCheck();
	}
	cout << "Input complete!" << endl;
	numberOfSubjs = realnumberOfSubjs;
	cout << "Actual number of subjects: " << numberOfSubjs - 1;
}