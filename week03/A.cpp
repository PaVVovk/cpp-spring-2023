#include <iostream>

using std::endl;
using std::cout;
using std::cin;

#ifndef N
#define N 10  // actual size of the array
#endif

void swap(int& lha, int& rha){
    int tmp = lha;
    lha = rha;
    rha = tmp;
}

void swap_array(int (&array)[N]){
    for (int i = 0; i < N/2; i++){
        swap(array[i], array[N-i-1]);
    }
}

int main() {
    int a[N] = {0};
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    swap_array(a);
    for (int i = 0; i < N; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}