#include <iostream>

using std::endl;
using std::cout;
using std::cin;

int main(){
    long long arr[4] = {1, 1, 4, 0};
    int n = 0;
    cin >> n;
    int i = 3;
    while (i <= n){
        arr[i%4] = 2*arr[(i-1)%4] + 2*arr[(i-2)%4] - arr[(i-3)%4];
        i++;        
    }
    cout << arr[n%4] << endl;
    return 0;
}