#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int recur_two(int number){
    if (number == 1){
        return 0;
    } else if (number % 2 == 1) {
        return -1;
    }
    number /= 2;
    return recur_two(number);
}

int main(){
    int num = 0;
    cin >> num;
    if ((recur_two(num) == -1) or (num == 1)){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}