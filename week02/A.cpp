#include <iostream>

using std::cout;
using std::cin;
using std::endl;

bool is_vis(int year){
    if (year % 400 == 0){
        return true;
    } else if (year % 100 == 0){
        return false;
    } else if (year % 4 == 0){
        return true;
    }
    return false;
}

int main(){
    int year = 0;
    cin >> year;
    if (is_vis(year)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}