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
    cout << endl;
}

void Group::PrintStAverages()
{
    for (int i = 0; i < studentsCount; i++)
    {
        cout << students[i].GetStudentName() << ": " << students[i].GetAverageGrade() << endl;
    }
    cout << endl;
}
void Group::PrintSubjAverages()
{
    for (int i = 0; i < subjectsCount; ++i)
    {
        double total = 0.0;
        int count = 0;
        for (int j = 0; j < studentsCount; ++j)
        {
            int** studentGrades = students[j].GetGrades();
            int* gradeCounts = students[j].GetGradeCounts();
            for (int k = 0; k < gradeCounts[i]; ++k)
            {
                total += studentGrades[i][k];
                count++;
            }
        }
        cout << subjects[i].GetSubject() << ": ";
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
    cout << endl;
}
void Group::PrintGroupAverage()
{
    double total = 0.0;
    int count = 0;
    for (int i = 0; i < studentsCount; i++)
    {
        int** stGrades = students[i].GetGrades();
        int* grCounts = students[i].GetGradeCounts();
        for (int j = 0; j < subjectsCount; j++)
        {
            for (int k = 0; k < grCounts[j]; k++)
            {
                total += stGrades[j][k];
                count++;
           }
        }
    }
    cout << total / count;
    cout << endl << endl;
}

void Group::FindMinGrade(int subjectIndex, int& minGrade, char*& minStudentName, bool& found)
{
    found = false;
    for (int j = 0; j < studentsCount; ++j)
    {
        int** studentGrades = students[j].GetGrades();
        int* gradeCounts = students[j].GetGradeCounts();
        for (int k = 0; k < gradeCounts[subjectIndex]; ++k) 
        {
            if (!found) 
            {
                minGrade = studentGrades[subjectIndex][k];
                if (minStudentName) delete[] minStudentName;
                minStudentName = new char[strlen(students[j].GetStudentName()) + 1];
                strcpy_s(minStudentName, strlen(students[j].GetStudentName()) + 1, students[j].GetStudentName());
                found = true;
            }
            else if (studentGrades[subjectIndex][k] < minGrade) 
            {
                minGrade = studentGrades[subjectIndex][k];
                if (minStudentName) delete[] minStudentName;
                minStudentName = new char[strlen(students[j].GetStudentName()) + 1];
                strcpy_s(minStudentName, strlen(students[j].GetStudentName()) + 1, students[j].GetStudentName());
            }
        }
    }
}
void Group::FindMaxGrade(int subjectIndex, int& maxGrade, char*& maxStudentName, bool& found)
{
    found = false;
    for (int j = 0; j < studentsCount; ++j)
    {
        int** studentGrades = students[j].GetGrades();
        int* gradeCounts = students[j].GetGradeCounts();
        for (int k = 0; k < gradeCounts[subjectIndex]; ++k) 
        {
            if (!found) 
            {
                maxGrade = studentGrades[subjectIndex][k];
                if (maxStudentName) delete[] maxStudentName;
                maxStudentName = new char[strlen(students[j].GetStudentName()) + 1];
                strcpy_s(maxStudentName, strlen(students[j].GetStudentName()) + 1, students[j].GetStudentName());
                found = true;
            }
            else if (studentGrades[subjectIndex][k] > maxGrade) 
            {
                maxGrade = studentGrades[subjectIndex][k];
                if (maxStudentName) delete[] maxStudentName;
                maxStudentName = new char[strlen(students[j].GetStudentName()) + 1];
                strcpy_s(maxStudentName, strlen(students[j].GetStudentName()) + 1, students[j].GetStudentName());
            }
        }
    }
}
void Group::PrintMinMaxGrades() 
{
    for (int i = 0; i < subjectsCount; ++i) 
    {
        int minGrade;
        char* minStudentName = nullptr;
        bool minFound;

        int maxGrade;
        char* maxStudentName = nullptr;
        bool maxFound;

        FindMinGrade(i, minGrade, minStudentName, minFound);
        FindMaxGrade(i, maxGrade, maxStudentName, maxFound);

        cout << subjects[i].GetSubject() << ":" << endl;
        if (minFound) 
        {
            cout << "  Min: " << minGrade << " (Student: ";
            if (minStudentName != nullptr) 
            {
                cout << minStudentName << ")";
            }
            else 
            {
                cout << "N/A";
            }
            cout << endl;
        }
        else 
        {
            cout << "  No grades found for this subject :(" << endl;
        }

        if (maxFound) 
        {
            cout << "  Max: " << maxGrade << " (Student: ";
            if (maxStudentName != nullptr) 
            {
                cout << maxStudentName << ")";
            }
            else 
            {
                cout << "N/A";
            }
            cout << endl;
        }
        else 
        {
            cout << "  No grades found for this subject :(" << endl;
        }
        delete[] minStudentName;
        delete[] maxStudentName;
    }
}


