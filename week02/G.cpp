#include <iostream>

using std::cout;
using std::cin;
using std::endl;

long long reverse(long long n, long long temp){
    if (n == 0){
        return temp;
    }
    temp = (temp * 10) + (n % 10);
    return reverse(n / 10, temp);
}

int main(){
    long long n = 0;
    cin >> n;
    if (n < 0){
        n *= -1;
    }
    if (n == reverse(n, 0)){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}