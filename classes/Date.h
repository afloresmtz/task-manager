#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
private:
    int day[3]; // day, month, year
    std::string time[3]; // hour, minute, second
public:
    Date(int day[3], std::string time[3]);

    std::string printDate();

    int getYear();
    int getMonth();
    int getDay();
    std::string getHour();
    std::string getMinute();
    std::string getSecond();

    bool operator==(Date* otherDate); // to check if dates are the same

};

#endif
