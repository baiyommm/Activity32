#ifndef DATE_HPP
#define DATE_HPP
#include <iostream>

using namespace std;
namespace DateTimeFunctions {

class Date {
private:
    int year, month, day;

public:
    
    Date(int year = 2000, int month = 1, int day = 1);

    int getYear() const;
    int getMonth() const;
    int getDay() const;

    void addDays(int days);
    void addMonths(int months);
    void addYears(int years);

    friend ostream& operator<<(ostream& os, const Date& date);
};

}

#endif
