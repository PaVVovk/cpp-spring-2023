#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

bool prime(int n){
    for(int i = 2; i < round(sqrt(n)); i++){
        if ((n % i) == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n = 0;
    cin >> n;
    bool flag = prime(n);
    if (flag){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}