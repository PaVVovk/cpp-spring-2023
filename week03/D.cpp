#include <iostream>

using std::endl;
using std::cout;
using std::cin;

#ifndef N
#define N 5
#endif

void swap(int& lha, int& rha){
    int tmp = lha;
    lha = rha;
    rha = tmp;
}

void sign_sort(int (&array)[N]){
    int i = 0;
    int j = 0;
    int n = N;
    while (i < n) {
        if (array[i] < 0){
            j = i;
            while (j < N-1){
                swap(array[j], array[j+1]);
                j++;
            }
            n--;
        } else {
            i++;
        }
    }
}

int main() { 
    int a[N] = {0};
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    sign_sort(a);
    for (int i = 0; i < N; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}