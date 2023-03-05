#include <iostream>

using std::endl;
using std::cout;
using std::cin;

#ifndef N
#define N 10
#endif

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void qsort(int (&arr)[N], int ind_left_base, int ind_right_base){
    //Сортировка по возрастанию
    int pivot = arr[(ind_left_base + ind_right_base)/2];
    int ind_left = ind_left_base;
    int ind_right = ind_right_base;
    while (ind_left < ind_right){
        while(arr[ind_left] < pivot){
            ind_left++;
        }
        while(arr[ind_right] > pivot){
            ind_right--;
        }
        if (ind_left <= ind_right){
            swap(arr[ind_left], arr[ind_right]);
            ind_left++;
            ind_right--;
        }
    }
    
    if (ind_left < ind_right_base){
        qsort(arr, ind_left, ind_right_base);
    }
    if (ind_right > ind_left_base) {
        qsort(arr, ind_left_base, ind_right);
    }
}

int main(){
    int a[N] = {0};
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    qsort(a, 0, N-1);
    for (int i = 0; i < N; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}