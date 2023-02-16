#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int recursive_power(int base, unsigned int power){
    if (power == 0){
        return 1;
    }
    return base*recursive_power(base, power - 1);
}

int main(){
    int base = 0;
    unsigned int power = 0;
    cin >> base >> power;
    cout << recursive_power(base, power) << endl;
    return 0;
}