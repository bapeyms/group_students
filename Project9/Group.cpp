#include "Group.h"
#include <iostream>
#include <cstring>
using namespace std;

Group::Group() :groupName(nullptr), students(nullptr), subjects(nullptr), 
studentsCount(0), subjectsCount(0) {}
Group::~Group() 
{
    delete[] groupName;
    delete[] students;
    delete[] subjects;
}

Group::Group(const Group& gr)
{
    groupName = new char[strlen(gr.groupName) + 1];
    strcpy_s(groupName, strlen(gr.groupName) + 1, gr.groupName);

    studentsCount = gr.studentsCount;
    subjectsCount = gr.subjectsCount;

    if (gr.students != nullptr)
    {
        students = new Student[studentsCount];
        for (int i = 0; i < studentsCount; ++i) 
        {
            students[i] = gr.students[i];
        }
    }
    else 
    {
        students = nullptr;
    }

    if (gr.subjects != nullptr) 
    {
        subjects = new Subject[subjectsCount];
        for (int i = 0; i < subjectsCount; ++i) 
        {
            subjects[i] = gr.subjects[i];
        }
    }
    else 
    {
        subjects = nullptr;
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
void Group::SetStudents(Student* studs, int count) 
{
    if (students != nullptr)
    {
        delete[] students;
    }
    studentsCount = count;
    students = new Student[studentsCount]; 
    for (int i = 0; i < studentsCount; ++i) 
    {
        students[i] = studs[i];
    }
}
void Group::SetSubjects(Subject* subjs, int count)
{
    if (subjects != nullptr) 
    {
        delete[] subjects;
    }
    subjectsCount = count;
    subjects = new Subject[subjectsCount];
    for (int i = 0; i < subjectsCount; ++i) 
    {
        subjects[i] = subjs[i];
    }
}

void Group::PrintGradesTable() 
{
    for (int i = 0; i < studentsCount; ++i) 
    {
        students[i].PrintGrades(subjects, subjectsCount);
        cout << endl;
    }
}

void Group::PrintGroupAverage()
{
    double total = 0.0;
    int count = 0;
    for (int i = 0; i < subjectsCount; i++)
    {
        int** stGrades = students[i].GetGrades();
        int* grCounts = students[i].GetGradeCounts();
        for (int j = 0; j < studentsCount; j++)
        {
            for (int k = 0; k < grCounts[j]; k++)
            {
                total += stGrades[j][k];
                count++;
           }
        }
    }
    if (count > 0)
    {
        cout << total / count;
    }
    else
    {
        cout << 0.0;
    }
    cout << endl;
}



