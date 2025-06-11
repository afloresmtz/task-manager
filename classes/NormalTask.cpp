#include "TaskList.h"
#include "Task.h"
#include "Date.h"
#include <string>
#include <vector>

TaskList::TaskList() {} // default constructor
TaskList::TaskList(std::vector<Task*> newTasks) {
    tasks = newTasks;
}

std::string TaskList::displayTasks() {
    std::string mainDisplay;
    int taskCounter = 1;
    mainDisplay.append("-------------\n");

    for (Task* task : tasks) {
        // polymorphism is applied here
        // to treat all objects in the 'tasks' vector as the Task* type
        // even though they will always be NormalTask, EventTask and RoutineTask
        // that way, we can call the (virtual) method 'showDetail()' to all of them
        mainDisplay.append(std::to_string(taskCounter) + ". \n");
        mainDisplay.append(task->showDetail() + "\n-------------\n");
        taskCounter += 1;
    }
    return mainDisplay;
}

std::vector<Task*> TaskList::getTaskVector() {
    return tasks;
}

std::vector<Task*> TaskList::filterBy(std::string subjectName) const {
    std::vector<Task*> result;
    for (Task* task : tasks) {
        // polymorphic behavior with the getSubject() method applied to all Task* objects in the vector
        if (task->getSubject().getName() == subjectName) {
            result.push_back(task);
        }
    }
    return result;
}

std::vector<Task*> TaskList::filterBy(Date& specificDate) const {
    std::vector<Task*> result;
    for (Task* task : tasks) {
        // polymorphic behavior with the getDueDate() method applied to all Task* objects in the vector
        if (task->getDueDate() == &specificDate) {
            result.push_back(task);
        }
    }
    return result;
}

void TaskList::operator+=(Task* newTask) {
    // add the Task* object to the 'tasks' vector
    tasks.push_back(newTask);
}

void TaskList::operator-=(Task* oldTask) {
    for (size_t i = 0; i < tasks.size(); ++i) {
        // iterates through all tasks in the 'tasks' vector and finds the match
        if (tasks[i] == oldTask) {
            tasks.erase(tasks.begin() + i);
            break;
        }
    }
}
