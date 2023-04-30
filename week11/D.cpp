#include <iostream>

using std::endl;
using std::cout;
using std::cin;

int main(){
    long arr[4] = {1, 1, 2, 0};
    int x = 0;
    cin >> x;
    int i = 3;
    while (i <= x){
        arr[i%4] = arr[(i-1)%4] + arr[(i-2)%4] + arr[(i-3)%4];
        i++;        
    }
    cout << arr[x%4] << endl;
    return 0;
}