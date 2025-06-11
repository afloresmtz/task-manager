#include "Task.cpp"
#include "Subject.cpp"
#include "Date.cpp"
#include "EventTask.cpp"
#include "NormalTask.cpp"
#include "RoutineTask.cpp"
#include "TaskList.cpp"

#include <string>
#include <vector>
#include <iostream>
#include <limits>

using namespace std;

int main() {
    // Subject creation (using examples of my own schedule)
    Subject physics("Analisis de sistemas electromagneticos", "Lunes, Miercoles y Jueves", "Claudia y Vladimir");
    Subject statistics("Analisis estadistico", "Martes y Jueves", "Christian");
    Subject programming("Programacion orientada a objetos", "Lunes y Jueves", "Silvana");
    Subject mentoring("Mentoria entre pares", "Miercoles", "Isabel");

    // vector of Subject type objects
    // not a pointer vector since its not a superclass
    // and, therefore, it isn't needed to deal with it polymorphically
    vector<Subject> subjectList;
    subjectList.push_back(physics);
    subjectList.push_back(statistics);
    subjectList.push_back(programming);
    subjectList.push_back(mentoring);

    bool isInMenu = true;
    TaskList tasks; // initialize the vector of tasks, it starts empty

    cout << "--- WELCOME TO TASK MANAGER ---\n" << endl; // Introduction for the user

    while(isInMenu == true) {
        int currentMenuChoice;
        cout << "\n-- MAIN MENU --\n" << " 1. Check list of tasks\n" << " 2. Add new task\n" << " 3. Remove task from list\n" << " 4. Exit\n" << "---------------\n" << endl;
        cin >> currentMenuChoice;

        switch(currentMenuChoice) {

            // checking list of tasks
            case 1: {
                cout << tasks.displayTasks(); // show task list

                // when filtering, method overloading is used
                // to be able to sort by different parameters

                bool isFiltering = true;
                while(isFiltering == true) {
                    int filterChoice;
                    cout << "\n-- FILTERING MENU --\n" << "What do you want to do?\n" << " 1. Filter by subject name\n" <<
                    " 2. Filter by date\n" << " 3. Return\n" << "--------------------\n" << endl;
                    cin >> filterChoice;
                    switch(filterChoice) {
                        case 1: {
                            cout << "By which subject?: \n";
                            int subjectCounter = 1;
                            for (auto subject : subjectList) { // for loop to show all subjects
                                cout << to_string(subjectCounter) << ". " << subject.getName() << endl;
                                subjectCounter += 1;
                            }
                            cout << "\n";

                            int subjectChoice;
                            cin >> subjectChoice;
                            subjectChoice -= 1; // to account for indexing (1st position -> [0])

                            TaskList filteredList = tasks.filterBy(subjectList[subjectChoice].getName()); // return a task list of all tasks with that subject name
                            cout << filteredList.displayTasks(); // show the filtered tasks
                            break;
                        }
                        case 2: {
                            int newYear, newMonth, newDay;
                            cout << "Enter day, month and year, separated by spaces: ";
                            cin >> newDay >> newMonth >> newYear;

                            if(newDay < 1 || newDay > 31 || newMonth < 1 || newMonth > 12) { // to account for mistakes in date entering
                                cout << "Invalid date!" << endl;
                                break;
                            }

                            int filterDay[3] = {newDay, newMonth, newYear};
                            string filterTime[3] = {"0", "0", "0"}; // since time does not matter in the comparison, this value is irrelevant
                            Date filteringDate(filterDay, filterTime);

                            TaskList filteredList = tasks.filterBy(filteringDate); // same as before, this will return a list of all tasks in a specific date
                            cout << filteredList.displayTasks();
                            break;

                        }
                        case 3:
                            isFiltering = false; // stops the filtering menu
                            break;
                        default:
                            cout << "Invalid input!" << endl; // accounts for mistakes when entering the menu
                            continue;
                    }
                }
                break;
            }

            // add new task
            case 2: {
                cout << "\n- Name or description of the task: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // to erase remaining "\n" characters that affect the 'getline' command
                string newDescription;
                getline(cin, newDescription);

                int newYear, newMonth, newDay;
                cout << "\n- Enter day, month and year of due date, separated by spaces: ";
                cin >> newDay >> newMonth >> newYear;

                if(newDay < 1 || newDay > 31 || newMonth < 1 || newMonth > 12) {
                    cout << "Invalid date!" << endl;
                    break;
                }

                int newDayNumber[3] = {newDay, newMonth, newYear};

                string includeTime;
                cout << "\n- Include time? (Y/N): ";
                cin >> includeTime;

                string newHour, newMinute, newSecond;
                if(includeTime == "Y" || includeTime == "y") {
                    cout << "\n- Enter hour, minute and second of due date, separated by spaces: ";
                    cin >> newHour >> newMinute >> newSecond;
                }
                else {
                    newHour = "23";
                    newMinute = "59";
                    newSecond = "59";
                }

                string newTime[3] = {newHour, newMinute, newSecond};
                Date* newDate = new Date(newDayNumber, newTime);

                cout << "\nSelect task from list of subjects:" << endl;
                int subjectCounter = 1;
                for (auto subject : subjectList) {
                    cout << to_string(subjectCounter) << ". " << subject.getName() << endl;
                    subjectCounter += 1;
                }
                cout << "\n";

                int subjectChoice;
                cin >> subjectChoice;
                subjectChoice -= 1;
                Subject* newSubject = new Subject(subjectList[subjectChoice].getName(), subjectList[subjectChoice].getSchedule(), subjectList[subjectChoice].getTeacher());
                // this line creates a reference to an object that is the exact same as the selected one in the subject list

                int taskType;
                cout << "\nWhat type of task do you want to create?\n" << " 1. Normal Task (standard task with progress and due date)\n" << " 2. Event Task (doesn't have progress, one time thing)\n" <<
                " 3. Routine Task (a task that is repeated over the course of days or weeks)\n" << " 4. Go back\n" << endl;
                cin >> taskType;
                switch(taskType) {
                    case 1: {
                        cout << "\n- Current progress (1/5): ";
                        int newProgress;
                        cin >> newProgress;

                        cout << "\n- Enter urgency level (1/5): ";
                        int newUrgency;
                        cin >> newUrgency;

                        Task* newTask = new NormalTask(newDescription, newDate, newSubject, newProgress, newUrgency);
                        tasks += newTask; // the task is added to the task list through operator overloading
                        cout << "\n- Task succesfuly created! -\n";
                        break;
                    }
                    case 2: {
                        string startDateInclusion;
                        cout << "\n- Do you want to include a start and end date? (Y/N): ";
                        cin >> startDateInclusion;

                        if (startDateInclusion == "Y" || includeTime == "y") {
                            // the same process to create a date is used here
                            int newYear2, newMonth2, newDay2;
                            cout << "\n- Enter day, month and year of the start date, separated by spaces: ";
                            cin >> newDay2 >> newMonth2 >> newYear2;
                            if(newDay2 < 1 || newDay2 > 31 || newMonth2 < 1 || newMonth2 > 12) {
                                cout << "Invalid date!" << endl;
                                break;
                            }

                            string includeTime2;
                            cout << "\n- Include time? (Y/N): ";
                            cin >> includeTime2;

                            string newHour2, newMinute2, newSecond2;

                            if(includeTime2 == "Y" || includeTime == "y") {
                                cout << "\n- Enter hour, minute and second of the start date, separated by spaces: ";
                                cin >> newHour2 >> newMinute2 >> newSecond2;

                            }
                            else {
                                newHour2 = "23";
                                newMinute2 = "59";
                                newSecond2 = "59";
                            }
                            int newDayNumber2[3] = {newDay2, newMonth2, newYear2};
                            string newTime2[3] = {newHour2, newMinute2, newSecond2};
                            Date* newDate2 = new Date(newDayNumber2, newTime2);

                            Task* newTask = new EventTask(newDescription, newDate2, newDate, newSubject);
                            tasks += newTask; // the task is added to the task list through operator overloading
                            cout << "\n- Task succesfuly created! -\n";
                        }
                        else {
                            Task* newTask = new EventTask(newDescription, newDate, newSubject);
                            tasks += newTask; // the task is added to the task list through operator overloading
                            cout << "\n- Task succesfuly created! -\n";
                        }
                        break;
                    }
                    case 3: {
                        string newRoutineType;
                        int newRepetitions;
                        cout << "\n- Insert type of repetition (daily/weekly/monthly, etc.): ";
                        cin >> newRoutineType;
                        cout << "\n- Insert amount of repetitions: ";
                        cin >> newRepetitions;

                        Task* newTask = new RoutineTask(newDescription, newDate, newSubject, newRoutineType, newRepetitions);
                        tasks += newTask; // the task is added to the task list through operator overloading
                        break;
                    }
                    case 4: {
                        break;
                    }
                    default:
                        cout << "Invalid input!" << endl;
                        continue;
                }
                break;
            }

            // remove task
            case 3: {
                // display tasks, then select an index to remove
                cout << tasks.displayTasks();

                int deleteSelection;
                cout << "Select index of task to delete: ";
                cin >> deleteSelection;

                tasks -= tasks.getTaskVector()[deleteSelection - 1]; // the task is removed from the task list through operator overloading

                cout << "\n- Task succesfuly deleted! -\n";
                break;
            }
            case 4: { // exit
                cout << "\nSee you soon!" << endl;
                isInMenu = false;
                break;
            }
            default: { // invalid input from the user
                cout << "Invalid input!" << endl;
                continue;
            }
        }
    }

    return 0;
}
