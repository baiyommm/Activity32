#include "Date.hpp"
#include "Time.hpp"
#include "DateTime.hpp"
#include <iostream>

using namespace std;
using namespace DateTimeFunctions;

int main() {
    
    Date date1(2024, 12, 31);
    Time time1(23, 30, 0);

    DateTime dt1(date1, time1);

    Date date2(2025, 1, 15);
    Time time2(0, 30, 0);

    DateTime dt2(date2, time2);

    cout << "Today's Date And Time Is: " << dt1 << "\n";
    cout << "Future Date And Time Is: " << dt2 << "\n";

    DateTime::difference(dt1, dt2);

    cout << "Format of DateTime: " << dt1.format("YYYY-MM-DD HH:mm") << "\n";

    return 0;
}
