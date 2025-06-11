#ifndef ROUTINETASK_H
#define ROUTINETASK_H

#include "Task.h"
#include "Date.h"
#include "Subject.h"
#include <string>

class RoutineTask : public Task {
private:
    std::string routineType;
    int repetitions;
public:
    RoutineTask(std::string description, Date* dueDate, Subject* subject, std::string routine, int repeat);

    std::string showDetail() override; // overridden method from Task
    std::string getRoutineType();
    void setRoutineType(std::string type);
    int getRepetitions();
    void setRepetitions(int amount);

};

#endif
