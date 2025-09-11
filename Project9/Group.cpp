#include <iostream>
#include "Group.h"
using namespace std;

Group::Group() :groupName(nullptr) {}

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

void Group::ShowAllInfo()
{
	//
}

Group::~Group()
{
	delete[] groupName;
}

