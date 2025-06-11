#include "Date.h"
#include <string>

Date::Date(int day[3], std::string time[3]) {
    for (int i = 0; i < 3; ++i) {
        this->day[i] = day[i];
    }
    for (int i = 0; i < 3; ++i) {
        this->time[i] = time[i];
    }
}

std::string Date::printDate() {
    std::string dayFormatted = std::to_string(day[0]) + "/" + std::to_string(day[1]) + "/" + std::to_string(day[2]);
    std::string timeFormatted = time[0] + ":" + time[1] + ":" + time[2];
    return(dayFormatted + " - " + timeFormatted);
}

int Date::getDay() {
    return day[0];
}
int Date::getMonth() {
    return day[1];
}
int Date::getYear() {
    return day[2];
}

std::string Date::getHour() {
    return time[0];
}
std::string Date::getMinute() {
    return time[1];
}
std::string Date::getSecond() {
    return time[2];
}

bool Date::operator==(Date* otherDate) {
    if(this->getYear() == otherDate->getYear() && this->getMonth() == otherDate->getMonth() && this->getDay() == otherDate->getDay()) {
        return true; // for the purpose of this project, when checking if two dates are the same, only the date, not the time, is checked
    }
    else {
        return false;
    }
}

