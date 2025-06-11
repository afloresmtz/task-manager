#ifndef TASK_H
#define TASK_H

#include <string>
#include "Date.h"
#include "Subject.h"

class Task {
protected:
    std::string description;
    Date* dueDate;
    Subject* subject;
public:
    Task(std::string description, Date* dueDate, Subject* subject);

    virtual std::string showDetail() = 0; // abstract class definition here
                                          // this way no objects of the Task class can be created

    std::string getDescription();
    void setDescription(std::string newDescription);

    Date getDueDate();
    void setDueDate(Date* newDate);

    Subject getSubject();
    void setSubject(Subject* newSubject);

};

#endif
