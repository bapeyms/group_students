#pragma once

class Subject {
private:
    char* name;

public:
    Subject();
    Subject(const char* subjName);
    ~Subject();

    Subject(const Subject& sb);
    Subject& operator=(const Subject& other);

    const char* GetSubject() const;
    void SetSubject(const char* subjName);
};