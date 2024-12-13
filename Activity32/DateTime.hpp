#ifndef DATETIME_HPP
#define DATETIME_HPP

#include "Date.hpp"
#include "Time.hpp"
#include <iostream>

using namespace std;
namespace DateTimeFunctions {

class DateTime {
private:
    Date date;
    Time time;

public:
    
    DateTime(Date date, Time time);

    static void difference(const DateTime& dt1, const DateTime& dt2);

    string format(const string& formatString) const;

    friend ostream& operator<<(ostream& os, const DateTime& dateTime);
};

}

#endif
