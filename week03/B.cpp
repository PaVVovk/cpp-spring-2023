#include <iostream>

using std::endl;
using std::cout;
using std::cin;

#ifndef N
#define N 10
#endif

int main() {
    int k = 1;
    //cin >> k; 
    int a[N] = {0};
    int b[N] = {0};
    for (int i = 0; i < N; i++){
        cin >> a[i];
        b[((i+k) % N)] = a[i];
    }
    for (int i = 0; i < N; i++){
        cout << b[i] << ' ';
    }
    cout << endl;
    return 0;
}