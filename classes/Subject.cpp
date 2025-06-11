#include "Subject.h"
#include <string>

Subject::Subject(std::string name, std::string schedule, std::string teacher) {
    this->name = name;
    this->schedule = schedule;
    this->teacher = teacher;
}

std::string Subject::displaySubjectInfo() {
    std::string mainString;
    mainString.append("Name: " + name + "\n");
    mainString.append("Schedule: " + schedule + "\n");
    mainString.append("Teacher: " + teacher + "\n");
    return mainString;
}

std::string Subject::getName() {
    return name;
}
void Subject::setName(std::string newName) {
    name = newName;
}

std::string Subject::getSchedule() {
    return schedule;
}
void Subject::setSchedule(std::string newSchedule) {
    schedule = newSchedule;
}

std::string Subject::getTeacher() {
    return teacher;
}
void Subject::setTeacher(std::string newTeacher) {
    teacher = newTeacher;
}
