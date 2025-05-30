#ifndef EVENTTASK_H
#define EVENTTASK_H

#include <Task.h>
#include <string>

class EventTask : public Task {
private:
    Date startDate;
public:
    EventTask(std::string description, Date startDate, Date dueDate, int progress, Subject subject);
    EventTask(std::string description, Date dueDate, int progress, Subject subject);

    std::string showDetail() override;
    Date getStartDate();
    void setStartDate(Date newDate);
};

#endif