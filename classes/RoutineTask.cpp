#include "RoutineTask.h"
#include "Task.h"
#include "Date.h"
#include "Subject.h"

#include <string>

RoutineTask::RoutineTask(std::string description, Date* dueDate, Subject* subject, std::string routine, int repeat)
    : Task(description, dueDate, subject), routineType(routine), repetitions(repeat) {}

std::string RoutineTask::showDetail() {
    std::string mainString = "Task: " + getDescription() +
    "\nEnd Date: " + getDueDate().printDate() +
    "\nSubject: " + getSubject().getName() +
    "\nRoutine: Repeat " + std::to_string(getRepetitions()) + " times, " + getRoutineType();
    return mainString;
}

std::string RoutineTask::getRoutineType() {
    return routineType;
}
void RoutineTask::setRoutineType(std::string type) {
    routineType = type;
}
int RoutineTask::getRepetitions() {
    return repetitions;
}
void RoutineTask::setRepetitions(int amount) {
    repetitions = amount;
}
