#include <iostream>

using std::cout;
using std::cin;
using std::endl;

unsigned long long fibonacci(int i){
    if ((i == 0) or (i == 1)){
        return 1;
    }
    return fibonacci(i-1)+fibonacci(i-2);
}

int main(){
    int i = 0;
    cin >> i;
    cout << fibonacci(i) << endl;
    return 0;
}