#ifndef NORMALTASK_H
#define NORMALTASK_H

#include <Task.h>
#include <string>

class NormalTask : public Task {
private:
    int urgencyLevel;
public:
    NormalTask(std::string description, Date dueDate, int progress, Subject subject, int urgency);

    std::string showDetail() override;
    int getUrgency();
    void setUrgency(int newUrgency);
};

#endif