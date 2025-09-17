#pragma once

class Subject {
private:
    char* name;

public:
    Subject();
    Subject(const char* subjName);
    ~Subject();

    Subject(const Subject& sb);

    const char* GetSubject() const;
    void SetSubject(const char* subjName);
};