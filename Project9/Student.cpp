#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;

Student::Student() : name(nullptr), grades(nullptr), gradeCounts(nullptr), subjectsCount(0) {}
Student::Student(const char* studName, int subjectsNum) :subjectsCount(subjectsNum)
{
    name = new char[strlen(studName) + 1];
    strcpy_s(name, strlen(studName) + 1, studName);

    grades = new int* [subjectsCount];
    gradeCounts = new int[subjectsCount];
    for (int i = 0; i < subjectsCount; ++i) 
    {
        grades[i] = nullptr;
        gradeCounts[i] = 0;
    }
}
Student::~Student() 
{
    delete[] name;
    if (grades) {
        for (int i = 0; i < subjectsCount; ++i)
        {
            delete[] grades[i];
        }
        delete[] grades;
    }
    delete[] gradeCounts;
}

Student::Student(const Student& st)
{
    subjectsCount = st.subjectsCount;
    name = new char[strlen(st.name) + 1];
    strcpy_s(name, strlen(st.name) + 1, st.name);

    gradeCounts = new int[subjectsCount];
    for (int i = 0; i < subjectsCount; ++i) 
    {
        gradeCounts[i] = st.gradeCounts[i];
    }

    grades = new int* [subjectsCount];
    for (int i = 0; i < subjectsCount; ++i)
    {
        grades[i] = new int[gradeCounts[i]];
        for (int j = 0; j < gradeCounts[i]; ++j) 
        {
            grades[i][j] = st.grades[i][j];
        }
    }

}
Student& Student::operator=(const Student& st)
{
    if (this == &st) 
    {
        return *this;
    }
    delete[] name;
    if (grades != nullptr) 
    {
        for (int i = 0; i < subjectsCount; ++i) 
        {
            delete[] grades[i];
        }
        delete[] grades;
    }
    delete[] gradeCounts;
    subjectsCount = st.subjectsCount;
    name = new char[strlen(st.name) + 1];
    strcpy_s(name, strlen(st.name) + 1, st.name);
    gradeCounts = new int[subjectsCount];
    for (int i = 0; i < subjectsCount; ++i) 
    {
        gradeCounts[i] = st.gradeCounts[i];
    }
    grades = new int* [subjectsCount];
    for (int i = 0; i < subjectsCount; ++i) 
    {
        if (st.grades[i]) 
        {
            grades[i] = new int[gradeCounts[i]];
            for (int j = 0; j < gradeCounts[i]; ++j) 
            {
                grades[i][j] = st.grades[i][j];
            }
        }
        else 
        {
            grades[i] = nullptr;
        }
    }
    return *this;
}

void Student::EnterStudentName()
{
    const int N = 256;
    char temp[N];

    cout << "Enter student name: ";
    cin.getline(temp, N);
    if (name != nullptr)
    {
        delete[] name;
    }
    name = new char[strlen(temp) + 1];
    strcpy_s(name, strlen(temp) + 1, temp);
}
void Student::EnterGrades(const Subject* allSubjects, int subjectsNum)
{
    this->subjectsCount = subjectsNum;
    if (grades != nullptr) 
    {
        for (int i = 0; i < subjectsCount; ++i)
        {
            delete[] grades[i];
        }
        delete[] grades;
    }
    if (gradeCounts != nullptr)
    {
        delete[] gradeCounts;
    }

    grades = new int* [subjectsNum];
    gradeCounts = new int[subjectsNum];
    for (int i = 0; i < subjectsNum; ++i) 
    {
        cout << "How many grades for " << allSubjects[i].GetSubject() << "? ";
        cin >> gradeCounts[i];
        grades[i] = new int[gradeCounts[i]];
        cout << "Enter " << gradeCounts[i] << " grades (use space for each value): ";
        for (int j = 0; j < gradeCounts[i]; ++j) 
        {
            cin >> grades[i][j];
        }
    }
    cin.ignore(1000, '\n');
}

void Student::PrintGrades(const Subject* allSubjects, int subjectsNum) 
{
    cout << "Grades for " << name << ":\n";
    for (int i = 0; i < subjectsNum; ++i)
    {
        cout << "  " << allSubjects[i].GetSubject() << ": ";
        for (int j = 0; j < gradeCounts[i]; ++j) 
        {
            cout << grades[i][j] << " ";
        }
        cout << "\n";
    }
}

char* Student::GetStudentName()
{
    return name;
}
int** Student::GetGrades()
{
    return grades;
}

int* Student::GetGradeCounts()
{
    return gradeCounts;
}

double Student::GetAverageGrade()
{
    double totalGrades = 0.0;
    int count = 0;
    for (int i = 0; i < subjectsCount; i++)
    {
        for (int j = 0; j < gradeCounts[i]; j++)
        {
            totalGrades += grades[i][j];
        }
        count += gradeCounts[i];
    }
    if (count > 0)
    {
        return totalGrades / count;
    }
    else
    {
        return 0.0;
    }
}
