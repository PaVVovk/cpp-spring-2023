#include <iostream>

using std::endl;
using std::cout;
using std::cin;

#ifndef N
#define N 3
#endif

void unite(int (&arr1)[N], int (&arr2)[N], int (&res)[2*N]){
    int i = 0;
    int j = 0;
    int k = 0;
    while (k < 2*N){
        if (((arr1[i] <= arr2[j]) and (i<N)) or (j>=N)){
            res[k] = arr1[i];
            i++;
        } else {
            res[k] = arr2[j];
            j++;
        }
        k++;
    }
}

void swap(int& lha, int& rha){
    int tmp = lha;
    lha = rha;
    rha = tmp;
}

int main() { 
    int a[N] = {0};
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    
    int b[N] = {0};
    for (int i = 0; i < N; i++){
        cin >> b[i];
    }

    int c[2*N] = {0};
    unite(a, b, c);

    for (int i = 0; i < 2*N; i++){
        cout << c[i] << ' ';
    }
    cout << endl;
    return 0;
}