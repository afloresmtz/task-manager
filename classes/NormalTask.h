#ifndef NORMALTASK_H
#define NORMALTASK_H

#include "Task.h"
#include <string>

class NormalTask : public Task {
private:
    int progress;
    int urgencyLevel;
public:
    NormalTask(std::string description, Date* dueDate, Subject* subject, int progress, int urgency);

    std::string showDetail() override; // overridden method from task
    int getProgress();
    void setProgress(int newProgress);
    int getUrgency();
    void setUrgency(int newUrgency);
};

#endif
