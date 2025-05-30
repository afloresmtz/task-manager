#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
private:
    int day[3];
    int time[3];
public:
    Date(int day[3]);
    Date(int day[3], int time[3]);

    std::string printDate();

    int getYear();
    int getMonth();
    int getDay();
    int getHour();
    int getMinute();
    int getSecond();
    
};

#endif