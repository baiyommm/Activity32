#include "Date.hpp"
#include <array>
#include <iostream>

using namespace std;
namespace DateTimeFunctions {

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Specifies each month
int getDaysInMonth(int year, int month) {
    static const array<int, 12> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29; // LeapYear function
    }
    return daysInMonths[month - 1];
}

Date::Date(int year, int month, int day) : year(year), month(month), day(day) {}

int Date::getYear() const {
    return year;
}
int Date::getMonth() const {
    return month;
}
int Date::getDay() const {
    return day;
}

void Date::addDays(int days) {
    while (days > 0) {
        int daysInCurrentMonth = getDaysInMonth(year, month);
        if (day + days <= daysInCurrentMonth) {
            day += days;
            return;
        }
        else {
            days -= (daysInCurrentMonth - day + 1);
            day = 1; // Resets the day
            addMonths(1); // Adjusts the month/year
        }
    }
}

void Date::addMonths(int months) {
    month += months;
    while (month > 12) {
        month -= 12;
        addYears(1);
    }
}

void Date::addYears(int years) {
    year += years;
}

ostream& operator<<(ostream& os, const Date& date) {
    if (date.year < 10) os << "000";
    else if (date.year < 100) os << "00";
    else if (date.year < 1000) os << "0";
    os << date.year << "-";

    if (date.month < 10) os << "0";
    os << date.month << "-";

    if (date.day < 10) os << "0";
    os << date.day;

    return os;
}

}
