#include "EventTask.h"
#include "Task.h"
#include "Date.h"
#include "Subject.h"

#include <string>

EventTask::EventTask(std::string description, Date* startDate, Date* dueDate, Subject* subject)
    : Task(description, dueDate, subject), startDate(startDate) {}

EventTask::EventTask(std::string description, Date* dueDate, Subject* subject)
    : Task(description, dueDate, subject) {
    startDate = dueDate;
}

std::string EventTask::showDetail() {
    std::string mainString;
    if(getStartDate() == getEndDate()) {
        mainString = "Task: " + getDescription() +
        "\nEvent Date: " + getDueDate().printDate() +
        "\nSubject: " + getSubject().getName();
    }
    else {
        mainString = "Task: " + getDescription() +
        "\nStart Date: " + getStartDate().printDate() +
        "\nEnd Date: " + getDueDate().printDate() +
        "\nSubject: " + getSubject().getName();
    }
    return mainString;
}

Date EventTask::getStartDate() {
    return *startDate;
}

void EventTask::setStartDate(Date* newDate) {
    startDate = newDate;
}
