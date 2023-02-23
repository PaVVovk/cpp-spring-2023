#include <iostream>

using std::endl;
using std::cout;
using std::cin;

#ifndef N
#define N 5
#endif

int binsearch(int (&arr)[N]){
    int ind = N-1;
    int st = 0;
    int fin = N-1;
    int mid = 0;
    
    while (arr[ind] != 0){
        mid = (st+fin)/2;
        if (arr[mid] == 1){
            fin = mid;
        } else if (arr[mid+1] == 1) {
            ind = mid;
        } else {
            st = mid;
        }
    }
    
    return ind;
}

int main() { 
    int a[N] = {0};
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    cout << binsearch(a) << endl;
    return 0;
}