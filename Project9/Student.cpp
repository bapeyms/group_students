#include <iostream>
#include "Student.h"
using namespace std;

Student::Student() :name(nullptr), grades(nullptr) {}
void Student::EnterStudents()
{
	const int N = 256;
	char data[N];

	if (name != nullptr)
	{
		delete[] name;
	}
	cout << "Student name: ";
	cin.getline(data, N);
	name = new char[strlen(data) + 1];
	strcpy_s(name, strlen(data) + 1, data);
}
int Student::StudentCheck()
{
	int choice;
	cout << "Would you like to enter a student's name? (yes - 1, no - 0): ";
	cin >> choice;
	cin.ignore(1000, '\n');
	while (choice != 1 && choice != 0)
	{
		cout << "Enter only 1 or 0! Enter a value: ";
		cin >> choice;
		cin.ignore(1000, '\n');
	}
	return choice;
}
char* Student::GetStudents()
{
	return name;
}
void Student::EnterGrades()
{
	//
}
Student::~Student()
{
	delete[] name;
	delete[] grades;
}