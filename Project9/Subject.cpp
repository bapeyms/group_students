#include "Subject.h"
#include <iostream>
#include <cstring>
using namespace std;

Subject::Subject() : name(nullptr) {}
Subject::Subject(const char* subjName) 
{
    name = new char[strlen(subjName) + 1];
    strcpy_s(name, strlen(subjName) + 1, subjName);

    name = nullptr;
}
Subject::~Subject()
{
    delete[] name;
}

Subject::Subject(const Subject& sb)
{
    name = new char[strlen(sb.name) + 1];
    strcpy_s(name, strlen(sb.name) + 1, sb.name);
}
Subject& Subject::operator=(const Subject& sb) 
{
    if (this == &sb) 
    {
        return *this;
    }
    delete[] name;
    if (sb.name) 
    {
        name = new char[strlen(sb.name) + 1];
        strcpy_s(name, strlen(sb.name) + 1, sb.name);
    }
    else 
    {
        name = nullptr;
    }
    return *this;
}

const char* Subject::GetSubject() const
{
    return name;
}
void Subject::SetSubject(const char* subjName) 
{
    if (name != nullptr)
    {
        delete[] name;
    }
    if (subjName != nullptr)
    {
        name = new char[strlen(subjName) + 1];
        strcpy_s(name, strlen(subjName) + 1, subjName);
    }
    else
    {
        name = nullptr;
    }
}
