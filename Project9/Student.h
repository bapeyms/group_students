#pragma once
#include "Subject.h"

class Student {
private:
    char* name;
    int** grades;
    int* gradeCounts;
    int subjectsCount;

public:
    Student();
    Student(const char* studName, int subjectsNum);
    ~Student();

    Student(const Student& st);
    Student& operator=(const Student& st);

    void SetSubjects(const Subject* allSubjects, int count);
    void EnterStudentName();
    void EnterGrades(const Subject* allSubjects, int subjectsNum);
    void PrintGrades(const Subject* allSubjects, int subjectsNum);
};

