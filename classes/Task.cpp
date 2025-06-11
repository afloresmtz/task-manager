#include "Task.h"
#include "Date.h"
#include "Subject.h"

#include <string>

Task::Task(std::string description, Date* dueDate, Subject* subject) {
    this->description = description;
    this->dueDate = dueDate;
    this->subject = subject;
}

std::string Task::getDescription() {
    return description;
}
void Task::setDescription(std::string newDescription) {
    description = newDescription;
}

Date Task::getDueDate() {
    return *dueDate;
}
void Task::setDueDate(Date* newDate) {
    dueDate = newDate;
}

Subject Task::getSubject() {
    return *subject;
}

void Task::setSubject(Subject* newSubject) {
    subject = newSubject;
}

