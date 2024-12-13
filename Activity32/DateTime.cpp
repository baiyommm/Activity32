#include "DateTime.hpp"
#include <sstream>

using namespace std;
namespace DateTimeFunctions {

DateTime::DateTime(Date date, Time time) : date(date), time(time) {}

// Difference Calculation Algorithm
void DateTime::difference(const DateTime& dt1, const DateTime& dt2) {
    int totalSeconds1 = dt1.date.getDay() * 24 * 3600 + dt1.time.getHour() * 3600 +
                        dt1.time.getMinute() * 60 + dt1.time.getSecond();
    int totalSeconds2 = dt2.date.getDay() * 24 * 3600 + dt2.time.getHour() * 3600 +
                        dt2.time.getMinute() * 60 + dt2.time.getSecond();
    int diffSeconds = abs(totalSeconds1 - totalSeconds2);

    cout << "Total Time Difference Is: " << diffSeconds / (24 * 3600) << " days, "
              << (diffSeconds % (24 * 3600)) / 3600 << " hours, "
              << ((diffSeconds % 3600) / 60) << " minutes, "
              << (diffSeconds % 60) << " seconds.\n";
}

string DateTime::format(const string& formatString) const {
    ostringstream oss;
    
    for (size_t i = 0; i < formatString.size(); ++i) {
        if (formatString[i] == 'Y' && formatString.substr(i, 4) == "YYYY") {
            oss << date.getYear();
            i += 3;
        }
        else if (formatString[i] == 'M' && formatString.substr(i, 2) == "MM") {
            if (date.getMonth() < 10) oss << "0";
            oss << date.getMonth();
            i += 1;
        }
        else if (formatString[i] == 'D' && formatString.substr(i, 2) == "DD") {
            if (date.getDay() < 10) oss << "0";
            oss << date.getDay();
            i += 1;
        }
        else if (formatString[i] == 'H' && formatString.substr(i, 2) == "HH") {
            if (time.getHour() < 10) oss << "0";
            oss << time.getHour();
            i += 1;
        }
        else if (formatString[i] == 'm' && formatString.substr(i, 2) == "mm") {
            if (time.getMinute() < 10) oss << "0";
            oss << time.getMinute();
            i += 1;
        }
        else if (formatString[i] == 'S' && formatString.substr(i, 2) == "SS") {
            if (time.getSecond() < 10) oss << "0";
            oss << time.getSecond();
            i += 1;
        }
        else {
            oss << formatString[i];
        }
    }
    return oss.str();
}

ostream& operator<<(ostream& os, const DateTime& dateTime) {
    os << dateTime.date << " " << dateTime.time;
    return os;
}

}
