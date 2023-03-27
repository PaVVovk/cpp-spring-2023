#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

struct Time{
    int hour;
    int min;
    int sec;
};

Time add_time(Time time1, Time time2){
    Time new_time;
    int sec = time1.sec + time2.sec;
    new_time.sec = sec % 60;
    int min = time1.min + time2.min + sec/60;
    new_time.min = min%60;
    int hour = time1.hour + time2.hour + min/60;
    new_time.hour = hour%24;
    return new_time;
}

Time get_time(){
    Time time;
    cin >> time.hour >> time.min >> time.sec;
    return time;
}

void print_time(Time time){
    cout << time.hour << ':' << time.min << ':' << time.sec << endl;
}

int main(){
    Time time_start = get_time();
    Time time_add = get_time();
    Time time_end = add_time(time_start, time_add);
    print_time(time_end);    
    return 0;
}