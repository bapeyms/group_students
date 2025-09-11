#include <iostream>
#include "Subject.h"
using namespace std;

void Subject::EnterSubjects(int& realSize)
{
	const int N = 256;
	char data[N];

	cout << "Subject name: ";
	cin.getline(data, N);
	subject = new char[strlen(data) + 1];
	strcpy_s(subject, strlen(data) + 1, data);
}
int Subject::SubjectCheck()
{
	int choice;
	cout << "Would you like to enter a subject? (yes - 1, no - 0): ";
	cin >> choice;
	cin.ignore(1000, '\n');
	while (choice != 1 && choice && 0)
	{
		cout << "Enter only 1 or 0! Enter a value: ";
		cin >> choice;
		cin.ignore(1000, '\n');
	}
	cin.ignore(1000, '\n');
	return choice;
}
