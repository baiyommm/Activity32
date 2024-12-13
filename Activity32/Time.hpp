#ifndef TIME_HPP
#define TIME_HPP
#include <iostream>

using namespace std;
namespace DateTimeFunctions {

class Time {
private:
    int hour, minute, second;

public:
    
    Time(int hour = 0, int minute = 0, int second = 0);

    int getHour() const;
    int getMinute() const;
    int getSecond() const;


    void addSeconds(int seconds);
    void addMinutes(int minutes);
    void addHours(int hours);

    friend ostream& operator<<(ostream& os, const Time& time);
};

}

#endif
