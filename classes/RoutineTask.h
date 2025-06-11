#ifndef ROUTINETASK_H
#define ROUTINETASK_H

#include <Task.h>
#include <string>

class RoutineTask : public Task {
private:
    int routineType;
    int repetitions;
public:
    RoutineTask(std::string description, int progress, Subject subject, int routine, int repeat);

    std::string showDetail() override;
    int getRoutineType();
    void setRoutineType(int type);
    int getRepetitions();
    void setRepetitions(int amount);

}

#endif
