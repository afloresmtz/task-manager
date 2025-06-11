#ifndef EVENTTASK_H
#define EVENTTASK_H

#include "Task.h"
#include <string>
#include "Date.h"
#include "Subject.h"

class EventTask : public Task {
private:
    Date* startDate;
public:
    EventTask(std::string description, Date* startDate, Date* dueDate, Subject* subject);
    EventTask(std::string description, Date* dueDate, Subject* subject);

    std::string showDetail() override; // overridden method from task
    Date getStartDate();
    void setStartDate(Date* newDate);
};

#endif
