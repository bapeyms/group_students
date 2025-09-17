#pragma once
#include "Student.h"
#include "Subject.h"

class Group {
private:
    char* groupName;
    Student* students;
    Subject* subjects;
    int studentsCount;
    int subjectsCount;

public:
    Group();
    ~Group();

    Group(const Group& gr);

    void EnterGroupName();
    void SetStudents(Student* studs, int count);
    void SetSubjects(Subject* subjs, int count);

    void PrintGradesTable();
    void PrintStAverages();
    void PrintGroupAverage();
};

