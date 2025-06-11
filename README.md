# Project Delivery - Task Manager

### Context
It is well known that it's important to have some organization in college as to keep track of our missing assignments and other miscellaneous tasks that we need to finish. To achieve this, everyone has a different method: some use agendas, some use digital tools, some even use their own memory. These tools help with the purpose of keeping track of tasks and to-do's, as well as organize one's own time to approach whichever task is the most urgent; basically, a task manager helps users keep track of these responsibilities in an organized way. This project simulates a basic task management system, which will focus on classifying and handling different types of tasks.

### Importance
It is very important to have these kinds of tools as a way to organize one's own tasks and things to do, since it gives structure to the work we do, as well as help to get everything done. However, in the focus of the class, this project will be important to the contents of the class as it will allow me to apply the concepts of OOP in a more real concepts, as well as the new concepts of Polymorphism (with a main class having some common methods that will be able to be used by all subclasses) as well as Pointers (to create a list or complilation of tasks which can be accessed and not just have a copy of the object created). 

### Description of each Class and its Purpose
- Task: the abstract superclass, serves to have common protected attributes for all its subclasses, as well as overridable methods for them. Has attributes of the Date and Subject type, in a relationship of aggregation. It has three subclasses:
    - NormalTask: represents a standard task with progress and due date. Has two private attribues, those being progress and urgency. It also has the overridden method of showDetail() first defined as virtual in Task.
    - EventTask: represents a one-time event like an appointment or an exam. Has an optional attribute of a startDate, for events that last more than one day. It also has the overriden method showDetail().
    - RoutineTask: represents a task that repeats in a cycle. It has the repetition type (daily, weekly, etc.) and the amount of repetitions as its attributes
- Date: support class for Task. Holds two arrays of date and time as attributes, as well as methods to access each. It also has a way to display the date in DD/MM/YYYY - HH : MM : SS format for easy reading.
- Subject: support class for Task. Holds three string attributes pertaining the subject info: name, schedule and teacher. It has methods to access each of these, as well as a way to print these attributes in a more accesible way.
- TaskList: a class to have easy access to a Task* vector. It has the vector as its only attribute, but has methods to facilitate working with the vector, such as adding or removing tasks.


![Integrative Project Delivery - UML Class Diagram](https://github.com/user-attachments/assets/6d9569a2-1157-4f6c-ac1a-c04553cbe342)
