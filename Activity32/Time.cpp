#include "Time.hpp"

using namespace std;
namespace DateTimeFunctions {

Time::Time(int hour, int minute, int second) : hour(hour), minute(minute), second(second) {}

int Time::getHour() const {
    return hour;
}

int Time::getMinute() const {
    return minute;
}

int Time::getSecond() const {
    return second;
}

void Time::addSeconds(int seconds) {
    second += seconds;
    while (second >= 60) {
        second -= 60;
        addMinutes(1);
    }
}

void Time::addMinutes(int minutes) {
    minute += minutes;
    while (minute >= 60) {
        minute -= 60;
        addHours(1);
    }
}

void Time::addHours(int hours) {
    hour = (hour + hours) % 24;
}

ostream& operator<<(ostream& os, const Time& time) {
    if (time.hour < 10) os << "0";
    os << time.hour << ":";

    if (time.minute < 10) os << "0";
    os << time.minute << ":";

    if (time.second < 10) os << "0";
    os << time.second;

    return os;
}

}
