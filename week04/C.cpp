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

void heap_sort(int (&arr)[N], int i, int max_len){
    //для сортировки кучи по возрастанию
    int max = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if ((left < max_len) and (arr[max] < arr[left])){
        max = left;
    }
    if ((right < max_len) and (arr[max] < arr[right])){
        max = right;
    }
    if (max!=i){
        swap(arr[max], arr[i]);
        heap_sort(arr, max, max_len);
    }
    
}

void cheops_sort(int (&arr)[N]){
    //Сортировка по возрастанию
    for (int i = N/2; i>=0; i--){
        heap_sort(arr, i, N);
    }
    
    for (int i = N-1; i>=0; i--){
        swap(arr[0], arr[i]);
        heap_sort(arr, 0, i);
    }
}

int main(){
    int a[N] = {0};
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    cheops_sort(a);
    for (int i = 0; i < N; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}