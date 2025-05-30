#ifndef TASK_H
#define TASK_H

#include <string>
#include "Date.h"
#include "Subject.h"

class Task {
protected:
    std::string description;
    Date dueDate;
    int progress;
    Subject subject;
public:
    Task(std::string description, Date dueDate, int progress, Subject subject);

    virtual std::string showDetail() = 0;
    
    std::string getDescription();
    void setDescription(std::string newDescription);

    Date getDueDate();
    void setDueDate(Date newDate);

    int getProgress();
    void setProgress(int newProgress);

    Subject getSubject();
    void setSubject(Subject newSubject);

};

#endif