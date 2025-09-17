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
    Subject* allSubjs = new Subject[numberOfSubjs];
    allSubjs[0].SetSubject("Programming");
    allSubjs[1].SetSubject("Probability Theory and Mathematical Statistics");
    allSubjs[2].SetSubject("Business English");
    allSubjs[3].SetSubject("Operating Systems");

    cout << "- SUBJECTS AND STUDENTS-" << endl;
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
        cout << "Only positive values are allowed! Number of students: ";
        cin >> numberOfStuds;
        cin.ignore(1000, '\n');
    }
    Student* allStuds = new Student[numberOfStuds];
    for (int i = 0; i < numberOfStuds; ++i)
    {
        allStuds[i].EnterStudentName();
        allStuds[i].EnterGrades(allSubjs, numberOfSubjs);
    }
    cout << "Input complete!" << endl << endl;

    app.SetStudents(allStuds, numberOfStuds);
    app.SetSubjects(allSubjs, numberOfSubjs);

    cout << "- GRADE TABLE -" << endl;
    app.PrintGradesTable();

    cout << "- AVERAGE VALUES -" << endl;
    cout << "Average for group: " << endl;
    app.PrintGroupAverage();
   // cout << "Average per students: " << endl;


    delete[] allStuds;
    delete[] allSubjs;
}