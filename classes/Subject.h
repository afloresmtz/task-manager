#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>

class Subject {
private:
    std::string name;
    std::string schedule;
    std::string teacher;
public:
    Subject(std::string name, std::string schedule, std::string teacher);

    std::string displaySubjectInfo();

    std::string getName();
    void setName(std::string newName);
    std::string getSchedule();
    void setSchedule(std::string newSchedule);
    std::string getTeacher();
    void setTeacher(std::string newTeacher);

};
