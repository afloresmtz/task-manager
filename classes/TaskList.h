#ifndef TASKLIST_H
#define TASKLIST_H

#include "Task.h"
#include "Date.h"
#include "Subject.h"
#include <string>
#include <vector>

class TaskList {
private:
    std::vector<Task*> tasks;
public:
    TaskList(); // to create the list in blank
    TaskList(std::vector<Task*> newTasks); // to create the list with a vector already created

    std::string displayTasks();
    std::vector<Task*> getTaskVector();

    // Overloaded methods, in order to search for specific tasks with different parameters
    std::vector<Task*> filterBy(std::string subjectName) const;
    std::vector<Task*> filterBy(Date& specificDate) const;

    // Operator overloading, to add or remove tasks to the list
    void operator+=(Task* newTask);
    void operator-=(Task* oldTask);

};

#endif
