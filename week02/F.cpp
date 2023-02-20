#include <iostream>

using std::cout;
using std::cin;
using std::endl;

unsigned long recursive_factorial(int n){
    if (n > 0){
        return n*recursive_factorial(n - 1);
    }
    return 1;
}

int main(){
    int n = 0;
    cin >> n;
    cout << recursive_factorial(n) << endl;
    return 0;
}